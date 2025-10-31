// https://www.youtube.com/watch?v=Iyfuu64A0MM&list=PL5XwKDZZlwaY7t0M5OLprpkJUIrF8Lc9j&index=4

__global__ void update_layer(int w, int h, int batch_size, float lr, float* weights, float* biases, float* activations, float* d_l)
{
  int col = blockIdx.x*blockDim.x + threadIdx.x;
  int row = blockIdx.y*blockDim.y + threadIdx.y; 
  if (row < w && col < h )
  {
     float dw=0.f;
	 float db=0.f;
	 for (int i=0; i<batch_size; i++)
	 {
		float act = activations[i*h + row];
		float dl=d_l[i*w + col];
		dw += act*dl;
		db += dl;
	 }
	weights[row*w+col] -= lr * dw / batch_size;
 	biases[column]     -= lr * dw / batch_size;
  }
}