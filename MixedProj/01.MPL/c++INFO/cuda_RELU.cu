// https://www.youtube.com/watch?v=Iyfuu64A0MM&list=PL5XwKDZZlwaY7t0M5OLprpkJUIrF8Lc9j&index=4

__global__ void relu(int w, int h, float* input, float* output)
{
  int column = blockIdx.x*blockDim.x + threadIdx.x;
  int    row = blockIdx.y*blockDim.y + threadIdx.y;
  if (row<h && column < w)
  {
     float activation = input[row*w+column];
	 output[row*w+column] = activation > 0.f ? activation : 0.f;
  }
}