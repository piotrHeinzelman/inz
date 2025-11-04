// https://www.youtube.com/watch?v=Iyfuu64A0MM&list=PL5XwKDZZlwaY7t0M5OLprpkJUIrF8Lc9j&index=4

__global__ void relu_backwards(int w, int h, int ns, float* a, float* d_l, float* b)
{
  int col = blockIdx.x*blockDim.x + threadIdx.x;
  int row = blockIdx.y*blockDim.y + threadIdx.y; 
  if (row < w && col < h )
  {
	float activation = a[row*w+col];
	b[row*w+col] = activation > 0.f ? d_l[row*w+col] : 0.f;
  }
}