//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// Resize2DLayer.cpp
//
// Code generation for function 'Resize2DLayer'
//

// Include files
#include "Resize2DLayer.h"
#include "rt_nonfinite.h"

// Function Definitions
namespace coder {
namespace nnet {
namespace cnn {
namespace layer {
void Resize2DLayer::b_interp1CustomImpl(const real32_T v[348160],
                                        real32_T out[696320])
{
  static const int8_T iv[80]{
      1,  1,  2,  2,  3,  3,  4,  4,  5,  5,  6,  6,  7,  7,  8,  8,
      9,  9,  10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 15, 15, 16, 16,
      17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 23, 24, 24,
      25, 25, 26, 26, 27, 27, 28, 28, 29, 29, 30, 30, 31, 31, 32, 32,
      33, 33, 34, 34, 35, 35, 36, 36, 37, 37, 38, 38, 39, 39, 40, 40};
  for (int32_T i{0}; i < 80; i++) {
    int8_T b_i;
    b_i = iv[i];
    for (int32_T j{0}; j < 8704; j++) {
      out[i + 80 * j] = v[(b_i + 40 * j) - 1];
    }
  }
}

void Resize2DLayer::interp1CustomImpl(const real32_T v[174080],
                                      real32_T out[348160])
{
  static const int8_T iv[40]{1,  1,  2,  2,  3,  3,  4,  4,  5,  5,
                             6,  6,  7,  7,  8,  8,  9,  9,  10, 10,
                             11, 11, 12, 12, 13, 13, 14, 14, 15, 15,
                             16, 16, 17, 17, 18, 18, 19, 19, 20, 20};
  for (int32_T i{0}; i < 40; i++) {
    int8_T b_i;
    b_i = iv[i];
    for (int32_T j{0}; j < 8704; j++) {
      out[i + 40 * j] = v[(b_i + 20 * j) - 1];
    }
  }
}

void Resize2DLayer::interpAlongSpatialDim(const real32_T inTmp[174080],
                                          real32_T out[348160])
{
  static const int8_T xq[68]{
      1,  1,  2,  2,  3,  3,  4,  4,  5,  5,  6,  6,  7,  7,  8,  8,  9,
      9,  10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 15, 15, 16, 16, 17, 17,
      18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 23, 24, 24, 25, 25, 26,
      26, 27, 27, 28, 28, 29, 29, 30, 30, 31, 31, 32, 32, 33, 33, 34, 34};
  for (int32_T i{0}; i < 68; i++) {
    int8_T b_i;
    b_i = xq[i];
    for (int32_T j{0}; j < 5120; j++) {
      out[i + 68 * j] = inTmp[(b_i + 34 * j) - 1];
    }
  }
}

} // namespace layer
} // namespace cnn
} // namespace nnet
} // namespace coder

// End of code generation (Resize2DLayer.cpp)
