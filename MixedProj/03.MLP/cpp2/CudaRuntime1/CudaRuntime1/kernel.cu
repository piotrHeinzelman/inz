
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>

 
#include <iostream>
#include <ctime>
#include <fstream>
#include <string.h>
#include <vector>

using namespace std;

cudaError_t addWithCuda(int *c, const int *a, const int *b, unsigned int size);
cudaError_t mullAndaddFloatWithCuda(float* c, const float* a, const float* b, unsigned int size);
void saveFloatsToFile(char* filename, float* floats, int size);
void loadFloatsToFile(char* filename, float* floats, int arySize);

__global__ void addKernel(int *c, const int *a, const int *b)
{
    int i = threadIdx.x;
    c[i] = a[i] + b[i];
}

__global__ void mullFloatArrays(float* c, const float* a, const float* b)
{
    int i = threadIdx.x;
    //c[i] = a[i] * b[i]; 
    c[i] = 1.0/(1.0+ exp ( a[i]+b[i]));
    //c[i] = .1;
}

__global__ void sumOfC(float* d, float* c)
{
    int i = threadIdx.x;
    if (i % 2 == 0) { d[i/2] = c[i] + c[i + 1];  c[i + 1] = 0; c[i] = 0; }  
}

int main()
{
    int const percent = 1; // 50 0.010; // change to 50 !
    int const len = percent; // *100;
    int const lenx = len * 6;
    
    int const IMGSIZE = 784; // ; 28 * 28
    int const Lay1out = 64; // neurons = layer out numbers

    //printf( "#  --- C++ ---\n+lenx:%i", lenx);
    srand((int)time(0));

    float** X = new float* [lenx];
    for (int i = 0; i < lenx; i++) {
        X[i] = new float[ IMGSIZE ];
    }

    float** W = new float* [ 64 ];
    for (int i = 0; i < Lay1out; i++) {
        W[i] = new float[ IMGSIZE ];
        for (int j = 0; j < IMGSIZE; j++) {
            W[i][j] = -1.0f + (rand() % 1000) / 500.0f;
        }
    }

    uint8_t* Y = new uint8_t[lenx];


    
    ifstream  inputFileStreamX("../../../data/train-images-idx3-ubyte", ios::in | ios::binary); // 16, percent, 6)
    ifstream  inputFileStreamY("../../../data/train-labels-idx1-ubyte", ios::in | ios::binary); //  8, percent, 6)


    inputFileStreamX.ignore(16 * sizeof(uint8_t));
    inputFileStreamY.ignore(8 * sizeof(uint8_t));
    uint8_t* tmp = new uint8_t[784];
    for (int i = 0; i < lenx; i++) {
        inputFileStreamX.read((char*)tmp, 784 * sizeof(char));
        for (int j = 0; j < 784; j++) {
            X[i][j] = tmp[j]/255.0f;
        }
        inputFileStreamY.read((char*)&Y[i],  sizeof(char));
    }

    inputFileStreamX.close();
    inputFileStreamY.close();

//    for (int i = 0; i < 50; i++) {
//        printf( "%i: %f\n", Y[i], X[i][300+i]);
//    }
    

//    if ( true ) return 0;

//    vector<double>* Z = new vector<double>[lenx];
//    vector<double>* X1 = new vector<double>[lenx];
//    vector<double>* Y1 = new vector<double>[lenx];
    //const int arySize = 8;
    //float X_[arySize] = { 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f }; //new float [8];
    //float W_ [arySize] = { -0.4f, 0.2f, -.3f, .3f, -.1f, .5f, -.2f, .4f };
    //float* W_ = new float[arySize]; // null; { -0.4f, 0.2f, -.3f, .3f, -.1f, .5f, -.2f, .4f }; //new float [8];
    float* YLay1 = new float[Lay1out];
    float* D = new float[IMGSIZE];
    float* C = new float[IMGSIZE];
     

    //saveFloatsToFile((char*)"Weights.bin", W_, arySize);
    //loadFloatsToFile((char*)"Weights.bin", W_, arySize);
    //printf( "\n->%f",W_[0]);


    //-- start
    clock_t before = clock();

    cudaError_t cudaStatus1 = mullAndaddFloatWithCuda( C, X[0], W[0], IMGSIZE); // X[0] - first X, W[0] - weights first neutron = first Y

    clock_t duration = clock() - before;
    printf("\r\nduration: %d [clocks tick], %d[sek]\r\n", duration, duration/CLOCKS_PER_SEC );

    printf ( "\nC[14*28+14]:%f, X[0][14*28+14]%f, W[0][14*28+14]%f\n", C[14 * 28 + 14], X[0][14*28+14], W[0][14 * 28 + 14]);
    printf("Y[0]:%f \n", C[0]);

    cudaStatus1 = cudaDeviceReset();
    if (cudaStatus1 != cudaSuccess) {
        fprintf(stderr, "cudaDeviceReset failed!");
        return 1;
    }
    exit(0);
    return 0;
   



    const int arraySize = 5;
    const int a[arraySize] = { 1, 2, 3, 4, 5 };
    const int b[arraySize] = { 10, 20, 30, 40, 50 };
    int c[arraySize] = { 0 };



    // Add vectors in parallel.
    cudaError_t cudaStatus = addWithCuda(c, a, b, arraySize);
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "addWithCuda failed!");
        return 1;
    }

    printf("{1,2,3,4,5} + {10,20,30,40,50} = {%d,%d,%d,%d,%d}\n",
        c[0], c[1], c[2], c[3], c[4]);

    // cudaDeviceReset must be called before exiting in order for profiling and
    // tracing tools such as Nsight and Visual Profiler to show complete traces.
    cudaStatus = cudaDeviceReset();
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaDeviceReset failed!");
        return 1;
    }

    return 0;
}





// Helper function for using CUDA to add vectors in parallel.
cudaError_t mullAndaddFloatWithCuda(float* c, const float* a, const float* b, unsigned int size)
{
    // size = 88; 88 is OK, 89 throw error !
    float* dev_a = 0;
    float* dev_b = 0;
    float* dev_c = 0;
    float* dev_d = 0;
    cudaError_t cudaStatus;

    // Choose which GPU to run on, change this on a multi-GPU system.
    cudaStatus = cudaSetDevice(0);
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaSetDevice failed!  Do you have a CUDA-capable GPU installed?");
        goto Error;
    }


    // Allocate GPU buffers for three vectors (two input, one output)    .
    cudaStatus = cudaMalloc( (void**)&dev_c, size * sizeof(float));
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaMalloc failed!");
        goto Error;
    }

    // Allocate GPU buffers for three vectors (two input, one output)    .
    cudaStatus = cudaMalloc((void**) &dev_d, size * sizeof(float));
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaMalloc failed!");
        goto Error;
    }


    cudaStatus = cudaMalloc((void**)&dev_a, size * sizeof(float));
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaMalloc failed!");
        goto Error;
    }


    cudaStatus = cudaMalloc((void**)&dev_b, size * sizeof(float));
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaMalloc failed!");
        goto Error;
    }

    // Copy input vectors from host memory to GPU buffers.
    cudaStatus = cudaMemcpy(dev_a, a, size * sizeof(float), cudaMemcpyHostToDevice);
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaMemcpy failed!");
        goto Error;
    }

    cudaStatus = cudaMemcpy(dev_b, b, size * sizeof(float), cudaMemcpyHostToDevice);
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaMemcpy failed!");
        goto Error;
    }



    // Launch a kernel on the GPU with one thread for each element.
    mullFloatArrays <<< 1, size >> > (dev_c, dev_a, dev_b);
    cudaDeviceSynchronize();

    // log(2) 784 < log(2) 1024 = 10 circles
    for (int i = 0; i < 5; i++) {
        sumOfC <<< 1, size >> > ( dev_d, dev_c );
        //cudaDeviceSynchronize(); 
        sumOfC <<< 1, size >> > ( dev_c, dev_d );
        //cudaDeviceSynchronize(); 
    }



    //dev_c[0] = dev_d[0];

    // Check for any errors launching the kernel
    cudaStatus = cudaGetLastError();
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "addKernel launch failed: %s\n", cudaGetErrorString(cudaStatus));
        goto Error;
    }

    // cudaDeviceSynchronize waits for the kernel to finish, and returns
    // any errors encountered during the launch.
    cudaStatus = cudaDeviceSynchronize();
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaDeviceSynchronize returned error code %d after launching addKernel!\n", cudaStatus);
        goto Error;
    }
     

    // Copy output vector from GPU buffer to host memory.
    cudaStatus = cudaMemcpy(c, dev_c, size * sizeof(float), cudaMemcpyDeviceToHost);
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaMemcpy failed!");
        goto Error;
    }

    return cudaStatus;

Error:
    cudaFree(dev_d);
    cudaFree(dev_c);
    cudaFree(dev_a);
    cudaFree(dev_b);

    return cudaStatus;
}


















// Helper function for using CUDA to add vectors in parallel.
cudaError_t addWithCuda(int *c, const int *a, const int *b, unsigned int size)
{
    int *dev_a = 0;
    int *dev_b = 0;
    int *dev_c = 0;
    cudaError_t cudaStatus;

    // Choose which GPU to run on, change this on a multi-GPU system.
    cudaStatus = cudaSetDevice(0);
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaSetDevice failed!  Do you have a CUDA-capable GPU installed?");
        goto Error;
    }

    // Allocate GPU buffers for three vectors (two input, one output)    .
    cudaStatus = cudaMalloc((void**)&dev_c, size * sizeof(int));
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaMalloc failed!");
        goto Error;
    }

    cudaStatus = cudaMalloc((void**)&dev_a, size * sizeof(int));
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaMalloc failed!");
        goto Error;
    }

    cudaStatus = cudaMalloc((void**)&dev_b, size * sizeof(int));
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaMalloc failed!");
        goto Error;
    }

    // Copy input vectors from host memory to GPU buffers.
    cudaStatus = cudaMemcpy(dev_a, a, size * sizeof(int), cudaMemcpyHostToDevice);
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaMemcpy failed!");
        goto Error;
    }

    cudaStatus = cudaMemcpy(dev_b, b, size * sizeof(int), cudaMemcpyHostToDevice);
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaMemcpy failed!");
        goto Error;
    }

    // Launch a kernel on the GPU with one thread for each element.
    addKernel<<< 1, size >>>(dev_c, dev_a, dev_b);

    // Check for any errors launching the kernel
    cudaStatus = cudaGetLastError();
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "addKernel launch failed: %s\n", cudaGetErrorString(cudaStatus));
        goto Error;
    }
    
    // cudaDeviceSynchronize waits for the kernel to finish, and returns
    // any errors encountered during the launch.
    cudaStatus = cudaDeviceSynchronize();
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaDeviceSynchronize returned error code %d after launching addKernel!\n", cudaStatus);
        goto Error;
    }

    // Copy output vector from GPU buffer to host memory.
    cudaStatus = cudaMemcpy(c, dev_c, size * sizeof(int), cudaMemcpyDeviceToHost);
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaMemcpy failed!");
        goto Error;
    }

Error:
    cudaFree(dev_c);
    cudaFree(dev_a);
    cudaFree(dev_b);
    
    return cudaStatus;
}



void saveFloatsToFile(char* filename, float* floats, int arySize) {
    FILE* fb;
    fb = fopen( (char*) filename, "wb");
    for (int i = 0; i < arySize; i++) {
        fwrite(&floats[i], sizeof(float), 1, fb);
    }
    fclose(fb);
}


void loadFloatsToFile(char* filename, float* floats, int arySize) {
    FILE* fb;
    fb = fopen((char*)filename, "rb");
    for (int i = 0; i < arySize; i++) {
        fread(&floats[i], sizeof(float), 1, fb);
    }
    fclose(fb);
}