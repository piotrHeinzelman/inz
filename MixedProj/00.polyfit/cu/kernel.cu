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

cudaError_t prepareArrays( unsigned int sizex, unsigned int sizey );

__global__ void prepareX(double* x)
{
int i = threadIdx.x + blockIdx.x * blockDim.x;
    x[i]=i*.1;
}

__global__ void prepareY(double* y)
{
int i = threadIdx.x + blockIdx.x * blockDim.x;
    y[i]=i*.2;
}



int main()
{

//  int const IMGSIZE =64000000;
    int const IMGSIZE_X =64*1000;
    int const IMGSIZE_Y = 1*1000;
    clock_t tableStart = clock();
    cudaError_t cudaStatus;

        cudaStatus = cudaDeviceReset();
    if (cudaStatus == cudaSuccess) {
        cudaStatus = prepareArrays(IMGSIZE_X, IMGSIZE_Y);
    }

    clock_t tableEnd = clock();
    clock_t durationTable = tableEnd - tableStart;
    printf("\r\nprepare table: %lu [clocks tick], %ld[sek]\r\n", durationTable, durationTable/CLOCKS_PER_SEC );

	if (true) return 0;


    //-- start
    clock_t before = clock();


    clock_t duration = clock() - before;
    printf("\r\nduration: %lu [clocks tick], %ld[sek]\r\n", duration, duration/CLOCKS_PER_SEC );

    cudaStatus = cudaDeviceReset();
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaDeviceReset failed!");
        return 1;
    }
    exit(0);
    return 0;

}




// Helper function for using CUDA to add vectors in parallel.
cudaError_t prepareArrays( unsigned int sizex, unsigned int sizey )
{
    double *dev_x = 0;
    double *dev_y = 0;
    cudaError_t cudaStatus;

    // Choose which GPU to run on, change this on a multi-GPU system.
    cudaStatus = cudaSetDevice(0);
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaSetDevice failed!  Do you have a CUDA-capable GPU installed?");
        goto Error;
    }

    // Allocate GPU buffers for three vectors (two input, one output)    .
    cudaStatus = cudaMalloc((void**)&dev_x, sizex*sizey * sizeof(double));
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaMalloc failed!");
        goto Error;
    }

    cudaStatus = cudaMalloc((void**)&dev_y, sizex*sizey * sizeof(double));
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaMalloc failed!");
        goto Error;
    }

    // Launch a kernel on the GPU with one thread for each element.
    prepareX<<< sizex, sizey >>>(dev_x);

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

    prepareY<<< sizex, sizey >>>(dev_x);


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
    //cudaStatus = cudaMemcpy(c, dev_c, size * sizeof(float), cudaMemcpyDeviceToHost);
    //if (cudaStatus != cudaSuccess) {
    //    fprintf(stderr, "cudaMemcpy failed!");
    //    goto Error;
    //}

Error:
    //cudaFree(dev_c);
    //cudaFree(dev_d);
    return cudaStatus;

}









/*
// Inside kernel:
	// Block index
	int bx = blockIdx.x;
	int by = blockIdx.y;

	// Thread index
	int tx = threadIdx.x;
	int ty = threadIdx.y;

	// Grid dimensions
        int gx = gridDim.x
        int gy = gridDim.y

	// Element index
	int I = bx*BLOCK_SIZE_SQ*gy + by*BLOCK_SIZE + tx*BLOCK_SIZE*gy + ty;

//Example use:

// Ignore first row and first and last columns

        if( (by == 0 && ty == 0) || (k == 0 && bx == 0 && tx == 0) || (k == N && bx == gx-1 && tx == BLOCK_SIZE-1) )
	{	}
	else if( act_s[ty+1][tx] && act_s[ty][tx] )
	{

		float ttmp = gplus[I-1] + gminus[I];
		tvde[I] = ttmp * detm1[I];
		tvdu[I] = ttmp * dqxm1[I];
		tvdv[I] = ttmp * dqym1[I];
	}
*/
