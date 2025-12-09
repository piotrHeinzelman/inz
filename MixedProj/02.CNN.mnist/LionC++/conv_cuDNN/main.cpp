// https://forums.developer.nvidia.com/t/how-use-the-cudnn-graph-api-for-do-a-convolution/321806
// https://hpc.pku.edu.cn/docs/20170830182053891231.pdf
// https://www.youtube.com/watch?v=GPBeiKYkuZE
// https://docs.nvidia.com/deeplearning/cudnn/archives/cudnn-892/pdf/cuDNN-Developer-Guide.pdf
// https://docs.nvidia.com/deeplearning/cudnn/backend/v9.15.0/api/cudnn-cnn-library.html
// https://docs.nvidia.com/deeplearning/cudnn/backend/v9.15.0/api/cudnn-graph-library.html#cudnncreate
//
// run:
// nvcc -lcuda -lcublas -lcudnn *.cu -o CNN




// CONVOLUTIONS
// https://gist.github.com/odashi/1c20ba90388cf02330e1b95963d78039
//
// https://www.goldsborough.me/cuda/ml/cudnn/c++/2017/10/01/14-37-23-convolutions_with_cudnn/
//
// PDF z adresu: https://images.nvidia.com/content/gtc-kr/part_2_vuno.pdf
//
// https://search.brave.com/search?q=cudnnConvolutionForward%28%29+example&summary=1&conversation=1011742db2ef7b775c69f1
// https://gist.github.com/odashi/1c20ba90388cf02330e1b95963d78039
// https://stackoverflow.com/questions/37302344/how-to-compute-a-full-convolution-with-nvidia-cudnn
// https://forums.developer.nvidia.com/t/fully-connected-layer-using-cudnn-library/66998
// https://docs.nvidia.com/deeplearning/performance/index.html#optimizing-performance
// https://forums.developer.nvidia.com/t/why-is-2-d-convolution-slower-than-the-matrix-product/35754/8

// MLP
// https://docs.nvidia.com/deeplearning/performance/dl-performance-fully-connected/index.html

// MM https://docs.nvidia.com/deeplearning/performance/dl-performance-matrix-multiplication/index.html#cublas-tile-dim
// cuBlas GEMM:  C = alpha*AB + beta*C
// Forward:  A- weight, X-(incoming activations)-B, alpha=1, beta=0

// https://docs.nvidia.com/cuda/cutensor/latest/index.html
// https://docs.nvidia.com/cuda/cutensor/latest/getting_started.html
// https://github.com/NVIDIA/CUDALibrarySamples/tree/main/cuBLAS/Level-3/gemm

// https://github.com/temporal-hpc/cublas-gemm
// https://github.com/temporal-hpc/cublas-gemm/blob/master/main.cu


// CNN
// https://docs.nvidia.com/deeplearning/performance/dl-performance-convolutional/index.html


#include <iostream>
#include <ctime>
#include <random>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <cuda_runtime.h>
#include <cudnn.h>
//#include <cublas.h>
#include <cublas_v2.h>
#include <cuda.h>
#include <cuda_fp16.h>
#include "cublas_utils.h"
#include "tools.cu"


// https://forums.developer.nvidia.com/t/fully-connected-layer-using-cudnn-library/66998/2

/*

Hi there,
I’m building a neural network with 2 convolution layers and 2 fully connected layer for one of my application. I would like to use cuDNN library API calls to perform
these operations. I was able to find cuDNN APIs for convolution layers but I could not get any for fully connected layers. Is there any such APIs? Or should
I manually convert outputs of conv layer to right format and feed them to SGEMM?
Thanks in advance.

post by KingDudman on Nov 10, 2018
You don’t need to use another library. Although the performance might be better with another library.
Just set up the convolution with the weights being the same size as the input parameters. So, if you had a 4d NCHW tensor of dims of [4,1,28,28].
Then you would set the 2d convolution to have a slide of [1,1] dilation of [1,1] and a padding of [0,0].
The filter dims will be [x,1,28,28]. The output of the convolution will be [4,x,1,1].
The next convolution will have the same settings. This time though your filter will be [y,x,1,1].
Then after that same convolution settings. Your filter will be [z,y,1,1]. So on and so forth.

Convolution 2D settings will always be: slide [1,1], padding [0,0], dilation [1,1].
PL == previous layer

Filter NCHW dims will be: [ (# of channels), (# of channels PL), (H of PL), (W of PL)].
*/


using data_type = float;


//using namespace std;


int main() {
    int const percent = 80;
    int const class_num=10;
    long const     LEN = 6 ;// percent*100*6;
    long const TESTLEN = LEN *  percent*100;
    const long epochs = 5;
    int imgW=28, imgH=28;
    int Lay0In  = imgW * imgH;
    int Lay0Out = 64;
    int Lay1In  = Lay0Out;
    int Lay1Out = class_num;

    // create the tensor descriptor
    cudnnDataType_t dtype = CUDNN_DATA_FLOAT;
    cudnnTensorFormat_t format = CUDNN_TENSOR_NHWC;
    int n0 = LEN, h0 = imgH, w0 = imgW, c0 = 1 ;
    int f0size=5, fnum=20;
    int n1 = LEN, h1 = 24, w1 = 24, c1 = 20 ;
    int NUM_ELEMENTS0 = n0*h0*w0*c0;
    int alpha = 1;
    int beta  = 2;


    int requestedAlgoCount = 1000;
    int* returnedAlgoCount  = new int;
    float* perfResults = new float[1000];


    if ( true ) { // load images from file
        std::cout << "#  --- C++ ---\n";

        float* Xhost = new float[ LEN * Lay0In ];
        float* Shost = new float[ LEN * class_num ];
        float* Whost = new float[ Lay0In * Lay0Out ];
        float* Yhost = new float[ LEN*Lay0Out];

        float* W1host = new float[ Lay1In * Lay1Out ];


        float *x0_dev = nullptr;
        float *Filter0_dev = nullptr;
        float* workSpace_dev = nullptr;
        float* z0_dev = nullptr;
        float *W0 = nullptr;

        load_images( Xhost,  "/home/john/inz/MixedProj/01.MPL/data/train-images-idx3-ubyte", LEN, imgW, imgH);
        load_labels( Shost,  "/home/john/inz/MixedProj/01.MPL/data/train-labels-idx1-ubyte", LEN, class_num);
        rand(); for (int i=0;i<Lay0In*Lay0Out;i++){ Whost[i] =  -1+  ( rand()%2000 ) *0.001 ; }
                for (int i=0;i<Lay1In*Lay1Out;i++){ W1host[i] =  -1+  ( rand()%2000 ) *0.001 ; }

        showImage(Xhost,imgH,imgW);
        showImage(Shost,imgH,10);

//    checkCUDA(cudaMalloc(reinterpret_cast<void **>(&X0), sizeof(double)*LEN*imgW*imgH ));
        //    cublasSetMatrixAsync(Lay0In, LEN,    sizeof(double), Xhost, Lay0In, X0, Lay0In,  stream);
        // Pion   Poziom                       Pion A      Pion B


        checkCUDA(cudaSetDevice(0)); // use GPU0
        int device;
        struct cudaDeviceProp devProp;
        checkCUDA(cudaGetDevice(&device));
        checkCUDA(cudaGetDeviceProperties(&devProp, device));
        std::cout << "Compute capability:" << devProp.major << "." << devProp.minor << std::endl;
        cudnnHandle_t handle_;
        checkCUDNN(cudnnCreate(&handle_));
        std::cout << "Created cuDNN handle" << std::endl;


        checkCUDA(cudaMalloc(reinterpret_cast<void **>(&x0_dev), sizeof(double)*LEN*imgW*imgH ));
        checkCUDA(cudaMalloc(reinterpret_cast<void **>(&Filter0_dev), sizeof(double)*LEN*imgW*imgH ));
        checkCUDA(cudaMalloc(reinterpret_cast<void **>(&workSpace_dev), sizeof(double)*LEN*imgW*imgH ));
        checkCUDA(cudaMalloc(reinterpret_cast<void **>(&z0_dev), sizeof(double)*LEN*h1*w1*c1 ));


        cudnnTensorDescriptor_t x0_desc;
        checkCUDNN(cudnnCreateTensorDescriptor(&x0_desc));
        checkCUDNN(cudnnSetTensor4dDescriptor(x0_desc, format, dtype, n0, c0, w0, h0));

        cudnnTensorDescriptor_t z0_desc;
        checkCUDNN(cudnnCreateTensorDescriptor(&z0_desc));
        checkCUDNN(cudnnSetTensor4dDescriptor(z0_desc, format, dtype, n0, c1, h1, w1));

        cudnnFilterDescriptor_t Filter0_desc;
        checkCUDNN(cudnnCreateFilterDescriptor(&Filter0_desc));
        checkCUDNN(cudnnSetFilter4dDescriptor(Filter0_desc, dtype, CUDNN_TENSOR_NCHW, c1, c0, f0size, f0size));





   int* padA = new int[4]{1,5,5,20};
   int* filterStrideA = new int[4]{1,1,1,1};
   int* dilationA = new int[4]{1,1,1,1};


        cudnnConvolutionDescriptor_t conv_desc;
        checkCUDNN(cudnnCreateConvolutionDescriptor( &conv_desc));
        checkCUDNN(cudnnSetConvolutionNdDescriptor(
   /* cudnnConvolutionDescriptor_t */   conv_desc,
   /* int                          */   4,
   /* const int                    */   padA,
   /* const int    filterStrideA   */   filterStrideA,
   /* const int       dilationA    */   dilationA,
   /* cudnnConvolutionMode_t       */   CUDNN_CONVOLUTION,
   /* cudnnDataType_t              */   CUDNN_DATA_FLOAT));



        checkCUDNN(cudnnConvolutionForward(
           /* cudnnHandle_t                   */    handle_,
           /* const void                      */    &alpha,
           /* const cudnnTensorDescriptor_t   */    x0_desc,
           /* const void                      */    x0_dev,
           /* const cudnnFilterDescriptor_t   */    Filter0_desc,
           /* const void                      */    Filter0_dev,
           /* const cudnnConvolutionDescriptor_t */ conv_desc,
           /* cudnnConvolutionFwdAlgo_t       */    CUDNN_CONVOLUTION_FWD_ALGO_GEMM,
           /* void                            */    workSpace_dev,
           /* size_t                          */    10000,
           /* const void                      */    &beta,
           /* const cudnnTensorDescriptor_t   */    z0_desc,
           /* void                            */    z0_dev));



        cudaFree(x0_dev);
        return 0;







        checkCUDNN(cudnnDestroy( handle_ ));
        // END OF MLP **********


        delete Xhost;
        delete Shost;


     //   return (0); // END


        if (true){ // *************





















            // create activation function descriptor
            float alpha[1] = {1};
            float beta[1] = {0.0};
            cudnnActivationDescriptor_t sigmoid_activation;
            cudnnActivationMode_t mode = CUDNN_ACTIVATION_SIGMOID;
            cudnnNanPropagation_t prop = CUDNN_NOT_PROPAGATE_NAN;
            cudnnCreateActivationDescriptor(&sigmoid_activation);
            cudnnSetActivationDescriptor(sigmoid_activation, mode, prop, 0.0f);


/*

            cudnnActivationForward(
                handle_,
                sigmoid_activation,
                alpha,
                x0_desc,
                x,
                beta,
                x0_desc,
                x
            );

*/


            cudnnDestroy(handle_);
            std::cout << std::endl << "Destroyed cuDNN handle." << std::endl;
            std::cout << "New array: ";
      //      for(int i=0;i<NUM_ELEMENTS0;i++) std::cout << x[i] << " ";
            std::cout << std::endl;

   //     if (false) cudaFree(x);
            //    return 0;

        }  // ***********


        return 0;




        // CNN
        // https://www.goldsborough.me/cuda/ml/cudnn/c++/2017/10/01/14-37-23-convolutions_with_cudnn/


        cudnnTensorDescriptor_t input_descriptor;
        checkCUDNN(cudnnCreateTensorDescriptor(&input_descriptor));
        checkCUDNN(cudnnSetTensor4dDescriptor(input_descriptor,
                                              /*format=*/CUDNN_TENSOR_NHWC,
                                              /*dataType=*/CUDNN_DATA_FLOAT,
                                              /*batch_size=*/1,
                                              /*channels=*/3,
                                              /*image_height=*/28,
                                              /*image_width=*/28));


    }
};
