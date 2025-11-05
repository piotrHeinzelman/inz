#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <cuda.h>
#include <cuda_runtime.h>

#define N 64000000
#define MAX_ERR 1e-6



__global__ void vector_add11(float *out, float *a, float *b, int n) {
    for(int i = 0; i < n; i ++){
        out[i] = a[i] * b[i];
    }
}


__global__ void vector_addMT(float *out, float *a, float *b, int n) {
    int tid = blockIdx.x * blockDim.x + threadIdx.x;

    // Handling arbitrary vector size
    if (tid < n){
        out[tid] = a[tid] * b[tid];
    }
}

int main(){
    float *a, *b, *out;
    float *d_a, *d_b, *d_out;

    // Allocate host memory
    a   = (float*)malloc(sizeof(float) * N);
    b   = (float*)malloc(sizeof(float) * N);
    out = (float*)malloc(sizeof(float) * N);

    // Initialize host arrays
    for(int i = 0; i < N; i++){
        a[i] = 0.1f*i;
        b[i] = 0.2f*i;
    }

    // Allocate device memory
    cudaMalloc((void**)&d_a, sizeof(float) * N);
    cudaMalloc((void**)&d_b, sizeof(float) * N);
    cudaMalloc((void**)&d_out, sizeof(float) * N);

    // Transfer data from host to device memory
    cudaMemcpy(d_a, a, sizeof(float) * N, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, b, sizeof(float) * N, cudaMemcpyHostToDevice);


    clock_t  step1=clock();


    // Executing kernel
    int block_size = 1000;//1000; //256;
    int grid_size = 64000; //((N + block_size) / block_size);
//    vector_addMT<<<grid_size,block_size>>>(d_out, d_a, d_b, N);
    vector_add11<<<1,1>>>(d_out, d_a, d_b, N);
    clock_t  step2=clock();

    // Transfer data back to host memory
    cudaMemcpy(out, d_out, sizeof(float) * N, cudaMemcpyDeviceToHost);



    // Verification
    for(int i = 0; i < N; i++){
        assert(fabs(out[i] - a[i] * b[i]) < MAX_ERR);
    }

    printf("PASSED\n");

    // Deallocate device memory
    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_out);

    // Deallocate host memory
    free(a);
    free(b);
    free(out);


    double duration=((step2-step1)*1000*1000)/CLOCKS_PER_SEC;
    printf("calculate a[i]*b[i]: %.0f[us] \n", duration );
}

