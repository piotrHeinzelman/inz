#include <iostream>
#include <cuda_runtime.h>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Dense>

using Vector = Eigen::Matrix<float, Eigen::Dynamic, 1, Eigen::ColMajor>;

int main(){
Vector vector;
uint64_t size = 6;

vector.resize(size);
for (uint64_t i = 0; i < size; ++i)
    vector[i] = i;

uint64_t sizeInBytes = size * sizeof (float);

float *raw_vector = vector.data();
float *vectorCuda;
cudaMalloc((void**)&vectorCuda, sizeInBytes);
cudaMemcpy(vectorCuda, raw_vector, sizeInBytes, cudaMemcpyKind::cudaMemcpyHostToDevice);

Vector result;
result.resize(size);
cudaMemcpy(result.data(), vectorCuda, sizeInBytes, cudaMemcpyKind::cudaMemcpyDeviceToHost);

cudaFree(vectorCuda);
std::cout << "result: " << std::endl << result << std::endl;
return 0;

 }#include <iostream>
#include <Eigen/Dense>

using Eigen::MatrixXd;

int main() {
  MatrixXd m(2, 2);
  m(0, 0) = 3;
  m(1, 0) = 2.5;
  m(0, 1) = -1;
  m(1, 1) = m(1, 0) + m(0, 1);
  std::cout << m << std::endl;
}
