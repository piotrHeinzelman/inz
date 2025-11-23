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

using data_type = double;


//using namespace std;


int main() {
    int const percent = 1;
    int const class_num=10;
    long const     LEN = percent*100*6;
    long const TESTLEN = percent*100;
    const long epochs = 5;
    int imgW=28, imgH=28;
    int Lay0In  = imgW * imgH;
    int Lay0Out = 64;
    int Lay1In  = Lay0Out;
    int Lay1Out = class_num;

    if ( true ) { // load images from file
        std::cout << "#  --- C++ ---\n";

        double* Xhost = new double[ LEN*784 ];
        double* Shost = new double[ LEN*class_num ];
        double* Whost = new double[ Lay0In * Lay0Out ];
        double* Yhost = new double[ LEN*Lay0Out];

        double* W1host = new double[ Lay1In * Lay1Out ];


        load_images( Xhost,  "/home/john/inz/MixedProj/01.MPL/data/train-images-idx3-ubyte", LEN, imgW, imgH);
        load_labels( Shost,  "/home/john/inz/MixedProj/01.MPL/data/train-labels-idx1-ubyte", LEN, class_num);
        rand(); for (int i=0;i<Lay0In*Lay0Out;i++){ Whost[i] =  -1+  ( rand()%2000 ) *0.001 ; }
                for (int i=0;i<Lay1In*Lay1Out;i++){ W1host[i] =  -1+  ( rand()%2000 ) *0.001 ; }

        showImage(Xhost,imgH,imgW);
        showImage(Shost,imgH,10);



        // MLP *****************
        cudnnHandle_t handle = createHandle();


        // ************ START MMULL


    cublasHandle_t cublasH = NULL;
    cudaStream_t stream = NULL;

    double *X0 = nullptr;
    double *Y0 = nullptr;
    double *W0 = nullptr;

    const data_type alpha = 1.0;
    const data_type beta = 0.0;

    const int m = 2;
    const int n = 2;
    const int k = 2;
    const int lda = 2;
    const int ldb = 2;
    const int ldc = 2;
    /*
     *   A = | 1.0 | 2.0 |
     *       | 3.0 | 4.0 |
     *
     *   B = | 5.0 | 6.0 |
     *       | 7.0 | 8.0 |
     */






    data_type *d_A = nullptr;
    data_type *d_B = nullptr;
    data_type *d_C = nullptr;

    cublasOperation_t transa = CUBLAS_OP_N;
    cublasOperation_t transb = CUBLAS_OP_N;





    /* step 1: create cublas handle, bind a stream */
    checkCUBLAS(cublasCreate(&cublasH));

    checkCUDA(cudaStreamCreateWithFlags(&stream, cudaStreamNonBlocking));
    checkCUBLAS(cublasSetStream(cublasH, stream));

    /* step 2: copy data to device */
    // copy X
    checkCUDA(cudaMalloc(reinterpret_cast<void **>(&X0), sizeof(double)*LEN*imgW*imgH ));
    //checkCUDA(cudaMemcpyAsync(X0, Xhost, sizeof(double)*LEN*imgH*imgW, cudaMemcpyHostToDevice, stream));
    // copy as vector !!!
    // cublasSetMatrixAsync(int rows, int cols, int elemSize, const void *A, int lda, void *B, int ldb, cudaStream_t stream)
    cublasSetMatrixAsync(LEN, Lay0In, sizeof(double), Xhost, Lay0In, X0, LEN,  stream);


    checkCUDA(cudaMalloc(reinterpret_cast<void **>(&W0), sizeof(double)*imgW*imgH*Lay0Out ));
    cublasSetMatrixAsync(Lay0Out, Lay0In, sizeof(double), Whost, Lay0In, W0, Lay0Out,  stream);
    //checkCUDA(cudaMemcpyAsync(W0, Whost, sizeof(double)*imgW*imgH*Lay0Out, cudaMemcpyHostToDevice, stream));

    checkCUDA(cudaMalloc(reinterpret_cast<void **>(&Y0), sizeof(double)*LEN*Lay0Out ));


/*
        cublasStatus_t cublasDgemm(cublasHandle_t handle,
                                   cublasOperation_t transa, cublasOperation_t transb,
                                   int m, int n, int k,
                                   const double          *alpha,
                                   const double          *A, int lda,
                                   const double          *B, int ldb,
                                   const double          *beta,
                                   double          *C, int ldc)

        C = alpha A * B + beta * C    |  forward  |  Y = alpha W * H + 0* C
        m - Number of rows of matrix op(A) and C.    Output (neuron numbers)
        n - Number of columns of matrix op(B) and C.    LEN (images num)
        k - Number of columns of op(A) and rows of op(B).  Input (28*28)

 */
  //  checkCUBLAS(cublasDgemm(cublasH, CUBLAS_OP_T, transb, 200, 200, 200, &alpha, W0, 200, X0, 200, &beta, Y0, 200));


/*
        cublasStatus_t cublasLtMatmul(
              cublasLtHandle_t               lightHandle,
              cublasLtMatmulDesc_t           computeDesc,
              const void                    *alpha,
              const void                    *A,
              cublasLtMatrixLayout_t         Adesc,
              const void                    *B,
              cublasLtMatrixLayout_t         Bdesc,
              const void                    *beta,
              const void                    *C,
              cublasLtMatrixLayout_t         Cdesc,
              void                          *D,
              cublasLtMatrixLayout_t         Ddesc,
              const cublasLtMatmulAlgo_t    *algo,
              void                          *workspace,
              size_t                         workspaceSizeInBytes,
              cudaStream_t                   stream);

 */





        checkCUBLAS(cublasLtMatmul());//
    // cublasSetMatrixAsync(int rows, int cols, int elemSize, const void *A, int lda, void *B, int ldb, cudaStream_t stream)
//    checkCUBLAS( cublasSetMatrixAsync ( LEN, imgW*imgH, sizeof(double), Xhost, 1, X0, 1, stream));

/*    checkCUDA(cudaMalloc(reinterpret_cast<void **>(&d_A), sizeof(data_type) * A.size()));
    checkCUDA(cudaMalloc(reinterpret_cast<void **>(&d_B), sizeof(data_type) * B.size()));
    checkCUDA(cudaMalloc(reinterpret_cast<void **>(&d_C), sizeof(data_type) * C.size()));

    checkCUDA(cudaMemcpyAsync(d_A, A.data(), sizeof(data_type) * A.size(), cudaMemcpyHostToDevice, stream));
    checkCUDA(cudaMemcpyAsync(d_B, B.data(), sizeof(data_type) * B.size(), cudaMemcpyHostToDevice, stream));
*/



    // step 4: copy data to host
    //checkCUDA(cudaMemcpyAsync(C.data(), d_C, sizeof(data_type) * C.size(), cudaMemcpyDeviceToHost, stream));

    checkCUDA(cudaMemcpyAsync(Yhost, Y0, sizeof(data_type) *LEN*Lay0Out , cudaMemcpyDeviceToHost, stream));
    checkCUDA(cudaStreamSynchronize(stream));


    for (int i=0;i<(LEN*Lay0Out);i++){ std::cout<<"  "<< Yhost[i];}





    /* free resources */
    checkCUDA(cudaFree(X0));
    checkCUDA(cudaFree(W0));
    checkCUDA(cudaFree(Y0));

return 0;
    checkCUBLAS(cublasDestroy(cublasH));

    checkCUDA(cudaStreamDestroy(stream));

    checkCUDA(cudaDeviceReset());


        // https://docs.nvidia.com/cuda/cublas/index.html#cublassetmatrix
        /*
cublasSetMatrixAsync()
cublasStatus_t
cublasSetMatrixAsync(int rows, int cols, int elemSize, const void *A,
                     int lda, void *B, int ldb, cudaStream_t stream)

cublasSetMatrix()
cublasStatus_t
cublasSetMatrix(int rows, int cols, int elemSize,
                const void *A, int lda, void *B, int ldb)
         */


        //matmul(a, b, epilog=Epilog.RELU)
        /* step 3: compute */
        /*
         *https://docs.nvidia.com/cuda/cublas/index.html#cublas-t-gemm

                cublasStatus_t cublasDgemm(cublasHandle_t handle,
                                           cublasOperation_t transa, cublasOperation_t transb,
                                           int m, int n, int k,
                                           const double          *alpha,
                                           const double          *A, int lda,
                                           const double          *B, int ldb,
                                           const double          *beta,
                                           double          *C, int ldc)
         */
















        //END MMULL !!


        destroyHandle( handle );
        // END OF MLP **********


        delete Xhost;
        delete Shost;


        return (0); // END


        if (false){ // *************

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

        if (false) cudaFree(x);
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
