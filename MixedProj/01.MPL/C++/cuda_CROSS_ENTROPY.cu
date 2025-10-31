// https://www.youtube.com/watch?v=Iyfuu64A0MM&list=PL5XwKDZZlwaY7t0M5OLprpkJUIrF8Lc9j&index=4

__global__ void cross_entropy(int w, int h, float* preds, float* real, float* output)
{
  int idx = blockIdx.x*blockDim.x + threadIdx.x;
  if (idx<h)
  {
  float loss = 0.f;
  for (int i=0;i<w;i++)
     { 
	 loss -= real[idx*w+i] * log( max(1e-6, preds[idx*w+1]));
     }
	 output[idx] = loss;
  }
}