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



#include <iostream>
#include <ctime>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <cuda_runtime.h>
#include <cudnn.h>
//#include <cublas.h>
#include <cuda.h>
#include "tools.cu"
//using namespace std;


int main() {
   int const percent = 1;
   int const class_num=10;
   long const len = percent*100;
   const long CYCLES = 5;

   if ( true ) { // load images from file
   std::cout << "#  --- C++ ---\n";

   double* X = new double[ len*784*6 ];
   double* Y = new double[ len* class_num*6 ];

   load_images( X,  "/home/john/inz/MixedProj/01.MPL/data/train-images-idx3-ubyte", len*6, 28, 28);
   load_labels( Y,  "/home/john/inz/MixedProj/01.MPL/data/train-labels-idx1-ubyte", len, class_num);

   showImage(X,28,28);
   showImage(Y,28,10);

   delete X;
   delete Y;
   }


   if (true){ // *************

    cudaSetDevice(0); // use GPU0
    int device;
    struct cudaDeviceProp devProp;
    cudaGetDevice(&device);
    cudaGetDeviceProperties(&devProp, device);
    std::cout << "Compute capability:" << devProp.major << "." << devProp.minor << std::endl;

    cudnnHandle_t handle_;
    cudnnCreate(&handle_);
    std::cout << "Created cuDNN handle" << std::endl;

    // create the tensor descriptor
    cudnnDataType_t dtype = CUDNN_DATA_FLOAT;
    cudnnTensorFormat_t format = CUDNN_TENSOR_NHWC;
    int n = 1, h = 1, w = 10, c = 1 ;
    int NUM_ELEMENTS = n*h*w*c;
    cudnnTensorDescriptor_t x_desc;
    cudnnCreateTensorDescriptor(&x_desc);
    cudnnSetTensor4dDescriptor(x_desc, format, dtype, n, h, w, c);




    // create the tensor
    float *x;
    cudaMallocManaged(&x, NUM_ELEMENTS * sizeof(float));
    for(int i=0;i<NUM_ELEMENTS;i++) x[i] = i * 1.00f;
    std::cout << "Original array: ";
    for(int i=0;i<NUM_ELEMENTS;i++) std::cout << x[i] << " ";










    // create activation function descriptor
    float alpha[1] = {1};
    float beta[1] = {0.0};
    cudnnActivationDescriptor_t sigmoid_activation;
    cudnnActivationMode_t mode = CUDNN_ACTIVATION_SIGMOID;
    cudnnNanPropagation_t prop = CUDNN_NOT_PROPAGATE_NAN;
    cudnnCreateActivationDescriptor(&sigmoid_activation);
    cudnnSetActivationDescriptor(sigmoid_activation, mode, prop, 0.0f);




    cudnnActivationForward(
        handle_,
        sigmoid_activation,
        alpha,
        x_desc,
        x,
        beta,
        x_desc,
        x
    );




    cudnnDestroy(handle_);
    std::cout << std::endl << "Destroyed cuDNN handle." << std::endl;
    std::cout << "New array: ";
    for(int i=0;i<NUM_ELEMENTS;i++) std::cout << x[i] << " ";
    std::cout << std::endl;


    cudaFree(x);
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


