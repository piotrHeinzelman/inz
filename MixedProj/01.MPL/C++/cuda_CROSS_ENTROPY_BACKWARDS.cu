// https://www.youtube.com/watch?v=Iyfuu64A0MM&list=PL5XwKDZZlwaY7t0M5OLprpkJUIrF8Lc9j&index=4

__global__ void cross_entropy_backwarsa(int w, int h, float* preds, float* real, float* output)
{
  int col = blockIdx.x*blockDim.x + threadIdx.x;
  int row = blockIdx.y*blockDim.y + threadIdx.y; 
  if (row<h && col < w )
  {
	output[row*w+col]=preds[row*w+col]-real[row*w+col];
  }
}