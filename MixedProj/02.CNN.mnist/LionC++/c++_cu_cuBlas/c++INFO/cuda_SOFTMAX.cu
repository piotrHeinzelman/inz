// https://www.youtube.com/watch?v=Iyfuu64A0MM&list=PL5XwKDZZlwaY7t0M5OLprpkJUIrF8Lc9j&index=4

__global__ void softmax(int w, int h, float* input, float* output)
{
  int column = blockIdx.x*blockDim.x + threadIdx.x;
  int    row = blockIdx.y*blockDim.y + threadIdx.y;
  if (row<h && column < w)
  {
  for (int i=1;i<w;i++)
     {
	 maxval = max(maxval, input[row*w+i]);
     }
	 float divisor = 0.f;
	 for (int i=0;i<w;i++)
	 {
	    divisor +=exp(input[row*w+1]-maxval);
	 }
	 output[row*w+column] = exp( input[row*w+col]-maxval)/(divisor);
  }
}