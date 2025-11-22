//https://forums.developer.nvidia.com/t/cublas-evd-function-not-satisfy-av-vd/302461/2

// # cat t246.cu
#include <iostream>
#include <vector>
#include <cuComplex.h>
#include <cusolverDn.h>
#include <cublas_v2.h>
#include <cuda_runtime.h>

// Helper function to print a complex matrix
void printMatrix(const cuDoubleComplex* A, int rows, int cols) {
    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j) {
            std::cout << "(" << cuCreal(A[j * cols + i]) << ", " << cuCimag(A[j * cols + i]) << ") ";
        }
        std::cout << std::endl;
    }
}

// Helper function to check if two complex numbers are approximately equal
bool isApproxEqual(cuDoubleComplex a, cuDoubleComplex b, double tol = 1e-6) {
    return (fabs(cuCreal(a) - cuCreal(b)) < tol) && (fabs(cuCimag(a) - cuCimag(b)) < tol);
}

int main() {
    const int N = 2;
    // Define a 2x2 complex covariance matrix
    cuDoubleComplex A[N * N] = {make_cuDoubleComplex(4.0, 0.0), make_cuDoubleComplex(1.0, 1.0),
                                make_cuDoubleComplex(1.0, -1.0), make_cuDoubleComplex(3.0, 0.0)};

    std::cout << "Original matrix A:" << std::endl;
    printMatrix(A, N, N);

    // cuBLAS and cuSOLVER setup
    cusolverDnHandle_t cusolverH = nullptr;
    cublasHandle_t cublasH = nullptr;
    cudaStream_t stream = nullptr;
    cusolverStatus_t csstat = cusolverDnCreate(&cusolverH);
    if (csstat != CUSOLVER_STATUS_SUCCESS) std::cout << __LINE__ << " cusolver error: " << (int)csstat << std::endl;
    cublasStatus_t cbstat = cublasCreate(&cublasH);
    if (cbstat != CUBLAS_STATUS_SUCCESS) std::cout << __LINE__ << " cublas error: " << (int)cbstat << std::endl;
  //  cudaStreamCreateWithFlags(&stream, cudaStreamNonBlocking);
    cudaStreamCreate(&stream);
    csstat = cusolverDnSetStream(cusolverH, stream);
    if (csstat != CUSOLVER_STATUS_SUCCESS) std::cout << __LINE__ << " cusolver error: " << (int)csstat << std::endl;
    cbstat = cublasSetStream(cublasH, stream);
    if (cbstat != CUBLAS_STATUS_SUCCESS) std::cout << __LINE__ << " cublas error: " << (int)cbstat << std::endl;

    // Device memory for matrix A, eigenvalues, and workspace
    cuDoubleComplex* d_A = nullptr;
    double* d_W = nullptr;
    int* devInfo = nullptr;
    int lwork = 0;
    cuDoubleComplex* d_work = nullptr;

    cudaMalloc((void**)&d_A, sizeof(cuDoubleComplex) * N * N);
    cudaMalloc((void**)&d_W, sizeof(double) * N);
    cudaMalloc((void**)&devInfo, sizeof(int));

    cudaMemcpy(d_A, A, sizeof(cuDoubleComplex) * N * N, cudaMemcpyHostToDevice);

    // Query working space
    csstat = cusolverDnZheevd_bufferSize(cusolverH, CUSOLVER_EIG_MODE_VECTOR, CUBLAS_FILL_MODE_UPPER, N, d_A, N, d_W, &lwork);
    if (csstat != CUSOLVER_STATUS_SUCCESS) std::cout << __LINE__ << " cusolver error: " << (int)csstat << std::endl;
    cudaMalloc((void**)&d_work, sizeof(cuDoubleComplex) * lwork);
    // Compute EVD
    csstat = cusolverDnZheevd(cusolverH, CUSOLVER_EIG_MODE_VECTOR, CUBLAS_FILL_MODE_UPPER, N, d_A, N, d_W, d_work, lwork, devInfo);
    if (csstat != CUSOLVER_STATUS_SUCCESS) std::cout << __LINE__ << " cusolver error: " << (int)csstat << std::endl;

    // Copy results back to host
    cuDoubleComplex V[N * N];
    double W[N];
    cudaMemcpy(V, d_A, sizeof(cuDoubleComplex) * N * N, cudaMemcpyDeviceToHost);
    cudaMemcpy(W, d_W, sizeof(double) * N, cudaMemcpyDeviceToHost);
    int hinfo;
    cudaMemcpy(&hinfo, devInfo, sizeof(int), cudaMemcpyDeviceToHost);
    if (hinfo) std::cout << "devInfo: " << hinfo << std::endl;
    std::cout << "Eigenvalues (diagonal of D):" << std::endl;
    for (int i = 0; i < N; ++i) {
        std::cout << W[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Eigenvectors (columns of V):" << std::endl;
    printMatrix(V, N, N);

    // Verify A * V = V * D using cuBLAS
    cuDoubleComplex* d_V = nullptr;
    cuDoubleComplex* d_D = nullptr;
    cuDoubleComplex* d_DV = nullptr;
    cuDoubleComplex* d_AV = nullptr;

    cudaMalloc((void**)&d_V, sizeof(cuDoubleComplex) * N * N);
    cudaMalloc((void**)&d_D, sizeof(cuDoubleComplex) * N * N);
    cudaMalloc((void**)&d_DV, sizeof(cuDoubleComplex) * N * N);
    cudaMalloc((void**)&d_AV, sizeof(cuDoubleComplex) * N * N);

    cudaMemset(d_D, 0, N*N*sizeof(cuDoubleComplex));
    cuDoubleComplex ev1 = make_cuDoubleComplex(W[0], 0.0);
    cuDoubleComplex ev2 = make_cuDoubleComplex(W[1], 0.0);
    cudaMemcpy(d_D, &ev1, sizeof(cuDoubleComplex), cudaMemcpyHostToDevice);
    cudaMemcpy(d_D+3, &ev2, sizeof(cuDoubleComplex), cudaMemcpyHostToDevice);

    cuDoubleComplex alpha = make_cuDoubleComplex(1.0, 0.0);
    cuDoubleComplex beta = make_cuDoubleComplex(0.0, 0.0);

    // Calculate V * D  d_A now contains the eigenvectors, it is effectively V
    cbstat = cublasZgemm(cublasH, CUBLAS_OP_N, CUBLAS_OP_N, N, N, N, &alpha, d_A, N, d_D, N, &beta, d_DV, N);
    if (cbstat != CUBLAS_STATUS_SUCCESS) std::cout << __LINE__ << " cublas error: " << (int)cbstat << std::endl;

    cuDoubleComplex* d_nA = nullptr;
    cudaMalloc(&d_nA, N*N*sizeof(cuDoubleComplex));
    cudaMemcpy(d_nA, A, N*N*sizeof(cuDoubleComplex), cudaMemcpyHostToDevice);
    // Calculate A * V
    cbstat = cublasZgemm(cublasH, CUBLAS_OP_N, CUBLAS_OP_N, N, N, N, &alpha, d_nA, N, d_A, N, &beta, d_AV, N);
    if (cbstat != CUBLAS_STATUS_SUCCESS) std::cout << __LINE__ << " cublas error: " << (int)cbstat << std::endl;

    // Copy results back to host
    cuDoubleComplex AV[N * N];
    cuDoubleComplex DV[N * N];
    cudaMemcpy(AV, d_AV, sizeof(cuDoubleComplex) * N * N, cudaMemcpyDeviceToHost);
    cudaMemcpy(DV, d_DV, sizeof(cuDoubleComplex) * N * N, cudaMemcpyDeviceToHost);

    std::cout << "A * V:" << std::endl;
    printMatrix(AV, N, N);

    std::cout << "V * D:" << std::endl;
    printMatrix(DV, N, N);

    // Check if A * V is approximately equal to V * D
    bool equal = true;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!isApproxEqual(AV[i * N + j], DV[i * N + j])) {
                equal = false;
                break;
            }
        }
    }

    if (equal) {
        std::cout << "Verification successful: A * V = V * D" << std::endl;
    } else {
        std::cout << "Verification failed: A * V != V * D" << std::endl;
    }

    // Clean up
    cudaFree(d_A);
    cudaFree(d_W);
    cudaFree(devInfo);
    cudaFree(d_work);
    cudaFree(d_V);
    cudaFree(d_DV);
    cudaFree(d_AV);
    cusolverDnDestroy(cusolverH);
    cublasDestroy(cublasH);
    cudaStreamDestroy(stream);

    return 0;
}
/*
# nvcc -o t246 t246.cu -lcublas -lcusolver
# compute-sanitizer ./t246
========= COMPUTE-SANITIZER
Original matrix A:
(4, 0) (1, -1)
(1, 1) (3, 0)
Eigenvalues (diagonal of D):
2 5
Eigenvectors (columns of V):
(-0.408248, 0.408248) (-0.57735, 0.57735)
(0.816497, 0) (-0.57735, 0)
A * V:
(-0.816497, 0.816497) (-2.88675, 2.88675)
(1.63299, 0) (-2.88675, 0)
V * D:
(-0.816497, 0.816497) (-2.88675, 2.88675)
(1.63299, 0) (-2.88675, 0)
Verification successful: A * V = V * D
========= ERROR SUMMARY: 0 errors
#
*/
