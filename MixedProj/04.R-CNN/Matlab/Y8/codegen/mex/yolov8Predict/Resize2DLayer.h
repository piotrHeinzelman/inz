//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// Resize2DLayer.h
//
// Code generation for function 'Resize2DLayer'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Type Definitions
namespace coder {
namespace nnet {
namespace cnn {
namespace layer {
class Resize2DLayer {
public:
  static void interpAlongSpatialDim(const real32_T inTmp[174080],
                                    real32_T out[348160]);
  static void interp1CustomImpl(const real32_T v[174080], real32_T out[348160]);
  static void b_interp1CustomImpl(const real32_T v[348160],
                                  real32_T out[696320]);
};

} // namespace layer
} // namespace cnn
} // namespace nnet
} // namespace coder

// End of code generation (Resize2DLayer.h)
