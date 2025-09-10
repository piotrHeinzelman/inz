//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// predict.h
//
// Code generation for function 'predict'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Type Declarations
struct yolov8PredictStackData;

class yolov8n0_0;

// Function Declarations
namespace coder {
namespace internal {
void b_dlnetwork_predict(yolov8PredictStackData *SD, const emlrtStack &sp,
                         yolov8n0_0 &obj,
                         const real32_T varargin_1_Data[1044480],
                         array<real32_T, 3U> &varargout_1_Data,
                         array<real32_T, 3U> &varargout_2_Data,
                         array<real32_T, 3U> &varargout_3_Data);

}
} // namespace coder

// End of code generation (predict.h)
