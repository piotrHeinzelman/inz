// https://www.youtube.com/watch?v=Iyfuu64A0MM&list=PL5XwKDZZlwaY7t0M5OLprpkJUIrF8Lc9j&index=4

__global__ void backwar(int batch_size, int n, int out_w, float* weights, float* biases, float* d_l, float* out_d_l)
{
  int col = blockIdx.x*blockDim.x + threadIdx.x;
  int row = blockIdx.y*blockDim.y + threadIdx.y; 
  if (row < batch_size && col < out_w )
  {
	float dl=0.f;
	for (int i=0; i<n; i++){
	   float w=weights[i*out_w+col];
	   dl += w*d_l[row*n + i];
	}
	out_d_l[row*out_w+col]=dl;
  }
}