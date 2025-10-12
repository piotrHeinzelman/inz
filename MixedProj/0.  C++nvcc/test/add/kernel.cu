
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include <ctime>
#include <fstream>
#include <string.h>
#include <vector>

using namespace std;

cudaError_t addWithCuda(float *c, float *d, unsigned int size);

__global__ void sumOfC(float* c, float* d)
{
    int i = threadIdx.x;
    if (i%2 == 0) { d[ i >> 1] = c[i] + c[i + 1];  c[i + 1] = 0; c[i] = 0; d[512+i]=0;}
}

int main()
{
    int const IMGSIZE =1024;

    //printf( "#  --- C++ ---\n+lenx:%i", lenx);
    srand((int)time(0));



    //testLoadAndSave();
    float* C = new float [IMGSIZE];
    for (int i = 0; i < IMGSIZE; i++) {
        C[i] = 0.001f*i;
    }
    float* D = new float[IMGSIZE];

    printf("value: %f, %f\r\n", C[1], C[1023]);




    //-- start
    clock_t before = clock();

    cudaError_t cudaStatus1 = addWithCuda(C, D, IMGSIZE);

    clock_t duration = clock() - before;
    printf("\r\nduration: %lu [clocks tick], %ld[sek]\r\n", duration, duration/CLOCKS_PER_SEC );

//    printf ( "\nC[14*28+14]:%f, X[0][14*28+14]%f, W[0][14*28+14]%f\n", C[14 * 28 + 14], X[0][14*28+14], W[0][14 * 28 + 14]);
    printf("C[0]:%f, C[1]:%f, C[2]:%f, D[0]:%f, D[1]:%f, D[2]:%f \n", C[0], C[1], C[2], D[0], D[1], D[2]);

    cudaStatus1 = cudaDeviceReset();
    if (cudaStatus1 != cudaSuccess) {
        fprintf(stderr, "cudaDeviceReset failed!");
        return 1;
    }
    exit(0);
    return 0;

}




// Helper function for using CUDA to add vectors in parallel.
cudaError_t addWithCuda(float *c, float *d, unsigned int size)
{
    float *dev_c = 0;
    float *dev_d = 0;
    cudaError_t cudaStatus;

    // Choose which GPU to run on, change this on a multi-GPU system.
    cudaStatus = cudaSetDevice(0);
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaSetDevice failed!  Do you have a CUDA-capable GPU installed?");
        goto Error;
    }

    // Allocate GPU buffers for three vectors (two input, one output)    .
    cudaStatus = cudaMalloc((void**)&dev_c, size * sizeof(float));
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaMalloc failed!");
        goto Error;
    }

    cudaStatus = cudaMalloc((void**)&dev_d, size * sizeof(float));
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaMalloc failed!");
        goto Error;
    }

    // Copy input vectors from host memory to GPU buffers.
    cudaStatus = cudaMemcpy(dev_c, c, size * sizeof(float), cudaMemcpyHostToDevice);
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaMemcpy failed!");
        goto Error;
    }

    // Launch a kernel on the GPU with one thread for each element.
    for (int i=0;i<5;i++){
    sumOfC<<< 1, size >>>(dev_c, dev_d);
    sumOfC<<< 1, size >>>(dev_d, dev_c);
    }

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

Error:
    cudaFree(dev_c);
    cudaFree(dev_d);
    return cudaStatus;

}

