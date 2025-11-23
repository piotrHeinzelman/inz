
#include <iostream>
#include <ctime>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <cuda_runtime.h>
#include <cudnn.h>
#include <cublas.h>
#include <cuda.h>


#define checkCUDNN(expression)                       \
{                                                    \
cudnnStatus_t status = (expression);                 \
if (status != CUDNN_STATUS_SUCCESS) {                \
std::cerr << "Error on line " << __LINE__ << ": "    \
<< cudnnGetErrorString(status) << std::endl;         \
std::exit(EXIT_FAILURE);                             \
}                                                    \
}


#define checkCUDA(expression)                       \
{                                                   \
cudaError_t status = (expression);                  \
if (status != cudaSuccess) {                        \
std::cerr << "Error on line " << __LINE__ << ": "   \
<< status << std::endl;                             \
std::exit(EXIT_FAILURE);                            \
}                                                   \
}








cudnnHandle_t createHandle() {
    checkCUDA(cudaSetDevice(0)); // use GPU0
    int device;
    struct cudaDeviceProp devProp;
    checkCUDA(cudaGetDevice(&device));
    checkCUDA(cudaGetDeviceProperties(&devProp, device));
    if (false) std::cout << "Compute capability:" << devProp.major << "." << devProp.minor << std::endl;

    cudnnHandle_t handle_;
    checkCUDNN(cudnnCreate(&handle_));
    if (false) std::cout << "Created cuDNN handle" << std::endl;
    return handle_;
}


void destroyHandle(cudnnHandle_t handle) {
    checkCUDNN(cudnnDestroy(handle));
    if (false) std::cout << std::endl << "Destroyed cuDNN handle." << std::endl;
}

















void showImage(const double* ary, int h, int w){
   for (int i=0;i<h;i++){
     for (int j=0;j<w;j++){
        int ii=(int)0+16*ary[i*w+j];
        if (ii==0)
          std::cout <<".";
        else if(ii<=1)
          std::cout <<"+";
        else if(ii<=10)
          std::cout <<"*";
        else
          std::cout <<"#";

     }
     std::cout << std::endl;
   }
}

void load_images( double* out, const std::string& filename, int num_images, int rows, int cols) {
    char* buff = new char[ num_images*rows*cols ];
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) { throw std::runtime_error("Cannot open image file!"); } else { std::cout << "file open" << std::endl;  }
    file.read( reinterpret_cast<char*>(buff), 16);
    file.read( reinterpret_cast<char*>(buff), num_images*rows*cols );
    for (int im=0;im<num_images;im++){
       for (int r=0;r<rows;r++){
          for (int c=0;c<cols;c++){
            int i=im*rows*cols + r*cols + c;
            //std::cout<<i<<std::endl;
            out[i]= ((unsigned char)buff[i])/256.0;
          }
       }
    }
    file.close();
}

void load_labels( double* out, const std::string& filename, int num_images, int class_num ) {
    char* buff = new char[ num_images ];
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) { throw std::runtime_error("Cannot open image file!"); } else { std::cout << "file open" << std::endl;  }
    file.read( reinterpret_cast<char*>(buff), 8);
    file.read( reinterpret_cast<char*>(buff), num_images );
    for (int im=0;im<num_images;im++){
       for (int c=0;c<class_num;c++){
            int i=im*class_num + c;
            out[i]=0;
       }
       out[im*class_num+buff[im]]=1;
    }
    file.close();
}




