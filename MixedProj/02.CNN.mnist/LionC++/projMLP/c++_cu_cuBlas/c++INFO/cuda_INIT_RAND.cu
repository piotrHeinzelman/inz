// https://www.youtube.com/watch?v=Iyfuu64A0MM&list=PL5XwKDZZlwaY7t0M5OLprpkJUIrF8Lc9j&index=4

__global__ void init_rand(int w, int h, float* mat)
{
  int column = blockIdx.x*blockDim.x + threadIdx.x;
  int row    = blockIdx.y*blockDim.y + threadIdx.y; 
  if (row<h && column < w )
  {
	  curandState state;
	  curand_int(42,row*w+column, 0, &state);
	  mat[row*w + column]=curant_normal(&state)*sqrtf(2.f/h);
  }
}