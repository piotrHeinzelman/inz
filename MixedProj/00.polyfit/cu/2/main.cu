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


cudaError_t all     ( unsigned int size_bl, unsigned int size_th , unsigned int page, double* results );
cudaError_t sum     ( double* source, double * result, unsigned int size_bl, unsigned int size_th , double multi);
cudaError_t sumMulti( double* ary,    double * avg,    double* ary2, double * avg2, unsigned int sizex, unsigned int sizey, double* value);


__global__ void fillCU(double* ary, double* dest, float multi)
{
int i = threadIdx.x + blockIdx.x * blockDim.x;
    if (i<250000){
       double sum=0.0;
       for (int j=0;j<256;j++){
          double val=(i*256+j)*multi;
          ary[i*256+j]=val;
          sum+=val;
       }
       dest[i]=sum;
    }
}










__global__ void  sumDest(double* source, double* destination, unsigned int vector_size, unsigned int dest_size ) //<<<1,sizex>>>(dev_destination, dev_destination_lev2 );
{
int i = threadIdx.x; // one block
    double sum=0.0;
    if (i<dest_size ){
       for (int j=0;j<vector_size;j++){
          sum+=source[i*vector_size+j];
       }
    }
    destination[i]=sum;
}

/*   vector_size
     -----------
     |  |  |  |   ->   } dest_size
     |  |  |  |   ->
     ----------
*/


__global__ void divVal( double* ary ){
    ary[0]=ary[0]/64000000;
}


// sumTop    = E (X[i]-xsr )*( Y[i]-ysr )
// sumBottom = E (X[i]-xsr )*( X[i]-xsr )
__global__ void sumMultiCU(double* ary, double* avg, double* ary2, double* avg2, double* dest)
{
int i = threadIdx.x + blockIdx.x * blockDim.x;
    if (i<250000){
       double sum=0.0;
       for (int j=0;j<256;j++){
          double xi   =  ary[i*256+j];
          double xyi  = ary2[i*256+j];
          xi = xi- avg[0];
          xyi=xyi-avg2[0];
          sum+=xi*xyi;
       }
       dest[i]=sum;
    }
}


















int main()
{
    unsigned int const SIZE_TH = 500; //=64*1000 / 10;
    unsigned int const SIZE_BL = 500; //=1*1000 / 10;
    unsigned int const PAGE    = 256;
    double * results = new double[10];

    for (int i=0;i<10;i++){
       results[i]=(double)0.99*i;
    }

    printf("\r\nResults[2]: %f\r\n", results[2] );


    clock_t start = clock();

    cudaError_t cudaStatus;
    cudaStatus = cudaDeviceReset();
    if (cudaStatus == cudaSuccess) {
        cudaStatus = all( SIZE_BL, SIZE_TH, PAGE, results);
    }
    printf("\r\nXsm (OK): %f \r\n", results[0] );

//    cudaStatus = sumMulti( X, Xsm, X, Xsm, SIZE_BL, SIZE_TH, sumT);
//    cudaStatus = sumMulti( X, Xsm, Y, Xsm, SIZE_BL, SIZE_TH, sumB);


    clock_t end = clock();
    clock_t myTime = end - start;
    printf("\r\ntime: %lu [clocks tick], %ld[sek]\r\n", myTime, myTime/CLOCKS_PER_SEC );
    return 0;

}


// --------------- WORKING --------------




















cudaError_t all( unsigned int sizex, unsigned int sizey, unsigned int page, double* results)
{

    double *dev_results = 0;
    double *dev_X = 0;//=new double[sizex*sizey*page];
    double *dev_Y = 0;//=new double[sizex*sizey*page];
    double *dev_tmp = 0;//=new double[sizex*sizey*page];

/*

    double * Xsm=new double[1];
    double * Ysm=new double[1];

    double srX=0.0;
    double srY=0.0;
    double * sumT = new double[1];
    double * sumB = new double[1];
    double * w1=new double[1];
    double * w0=new double[1];


    double *dev_ary = 0;
    double *dev_ary2 = 0;
    double *dev_avg = 0;
    double *dev_avg2 = 0;
    double *dev_destination = 0;
    double *dev_destination_lev2 = 0;
    double *dev_value = 0;
 */
    cudaError_t cudaStatus;

    // Choose which GPU to run on, change this on a multi-GPU system.
    cudaStatus = cudaSetDevice(0);
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaSetDevice failed!  Do you have a CUDA-capable GPU installed?");
        goto Error;
    }


    cudaStatus = cudaMalloc((void**)&dev_results, 10*sizeof(double));
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaMalloc failed!");
        goto Error;
    }

    // Copy input vector from host memory to GPU buffer.
//    cudaStatus = cudaMemcpy(dev_results, results, 10*sizeof(double), cudaMemcpyHostToDevice);
//    if (cudaStatus != cudaSuccess) {
//        fprintf(stderr, "cudaMemcpy 1 failed!");
//        goto Error;
//    }


    // Allocate GPU buffers for three vectors (two input, one output)    .
    cudaStatus = cudaMalloc((void**)&dev_X, 256*sizex*sizey * sizeof(double));
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaMalloc2 failed!");
        goto Error;
    }

    // Allocate GPU buffers for three vectors (two input, one output)    .
    cudaStatus = cudaMalloc((void**)&dev_Y, 256*sizex*sizey * sizeof(double));
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaMalloc3 failed!");
        goto Error;
    }

    // Allocate GPU buffers for three vectors (two input, one output)    .
    cudaStatus = cudaMalloc((void**)&dev_tmp, sizex*sizey * sizeof(double));
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaMalloc3 failed!");
        goto Error;
    }



    // Copy input vector from host memory to GPU buffer.
//    cudaStatus = cudaMemcpy(ary, dev_ary, 256*sizex*sizey * sizeof(double), cudaMemcpyHostToDevice);
//    if (cudaStatus != cudaSuccess) {
//        fprintf(stderr, "cudaMemcpy1 failed!");
//        goto Error;
//    }

    // Launch a kernel on the GPU with one thread for each element.
    cudaStatus = cudaDeviceSynchronize();
    fillCU<<<sizey, sizex>>>(dev_X, dev_tmp, 0.1);


/*
    sumMultiCU<<<sizey, sizex>>>(dev_ary, dev_avg, dev_ary2, dev_avg2, dev_destination);
    cudaStatus = cudaDeviceSynchronize();
    sumDest<<<1,sizex>>>(dev_destination, dev_destination_lev2, sizey, sizex );
    cudaStatus = cudaDeviceSynchronize();
    sumDest<<<1,1>>>(dev_destination_lev2, dev_value, sizex, 1 );
    cudaStatus = cudaDeviceSynchronize();
*/

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
    //cudaStatus = cudaMemcpy(results, dev_results, 10 * sizeof(double), cudaMemcpyDeviceToHost);
    //if (cudaStatus != cudaSuccess) {
    //    fprintf(stderr, "cudaMemcpy failed!");
    //    goto Error;
    // }

Error:
    cudaFree(dev_results);
    cudaFree(dev_X);
    cudaFree(dev_Y);
//    cudaFree(dev_destination);
//    cudaFree(dev_destination_lev2);
End:
    return cudaStatus;
}








// ************* OK ****************







/*


cudaError_t sum( double* source, double * destination, unsigned int sizex, unsigned int sizey, double multi )
{
    goto Error;
    double *dev_X = 0;
    double *dev_Y = 0;


    double *dev_source = 0;
    double *dev_destination = 0;
    double *dev_destination_lev2 = 0;
    double *dev_value = 0;
    cudaError_t cudaStatus;

    // Choose which GPU to run on, change this on a multi-GPU system.
    cudaStatus = cudaSetDevice(0);
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaSetDevice failed!  Do you have a CUDA-capable GPU installed?");
        goto Error;
    }

    // Allocate GPU buffers for three vectors (two input, one output)    .
    cudaStatus = cudaMalloc((void**)&dev_source, 256*sizex*sizey * sizeof(double));
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaMalloc failed!");
        goto Error;
    }

    cudaStatus = cudaMalloc((void**)&dev_destination, sizey*sizex* sizeof(double));
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaMalloc failed!");
        goto Error;
    }

    cudaStatus = cudaMalloc((void**)&dev_destination_lev2, sizey* sizeof(double));
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaMalloc failed!");
        goto Error;
    }


    cudaStatus = cudaMalloc((void**)&dev_value, 1* sizeof(double));
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaMalloc failed!");
        goto Error;
    }

    // Copy input vector from host memory to GPU buffer.
//    cudaStatus = cudaMemcpy(source, dev_source, sizex*sizey * sizeof(double), cudaMemcpyHostToDevice);
//    if (cudaStatus != cudaSuccess) {
//        fprintf(stderr, "cudaMemcpy failed!");
//        goto Error;
//    }

    // Launch a kernel on the GPU with one thread for each element.
    sumCU<<< sizex, sizey >>>(dev_source, dev_destination, multi);
//    sumCU<<< 1, sizex >>>    (dev_destination, dev_source );

    cudaStatus = cudaDeviceSynchronize();

    sumDest<<<1,sizex>>>(dev_destination, dev_destination_lev2, sizey, sizex );

    cudaStatus = cudaDeviceSynchronize();

    sumDest<<<1,1>>>(dev_destination_lev2, dev_value, sizex, 1 );
    divVal<<<1,1>>>(dev_value);


//    sumCU<<< (sizex/sizey), sizex >>>(dev_destination, dev_);
//    mulCU<<< sizex, sizey >>>(dev_source, dev_destination, multi);

//    cudaStatus = cudaDeviceSynchronize();


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
    cudaStatus = cudaMemcpy(destination, dev_value, 1 * sizeof(double), cudaMemcpyDeviceToHost);
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaMemcpy failed!");
        goto Error;
    }

    cudaStatus = cudaMemcpy(source, dev_source, sizex*sizey*256 * sizeof(double), cudaMemcpyDeviceToHost);
    if (cudaStatus != cudaSuccess) {
        fprintf(stderr, "cudaMemcpy failed!");
        goto Error;
    }

Error:
    cudaFree(dev_source);
    cudaFree(dev_destination);
    cudaFree(dev_destination_lev2);
    cudaFree(dev_value);
    return cudaStatus;

}



*/




