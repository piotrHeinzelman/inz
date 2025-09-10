//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// sort.h
//
// Code generation for function 'sort'
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

// Type Declarations
struct yolov8PredictStackData;

// Function Declarations
namespace coder {
namespace internal {
int32_T b_sort(yolov8PredictStackData *SD, const emlrtStack &sp,
               real32_T x_data[], const int32_T &x_size, int32_T idx_data[]);

}
} // namespace coder

// End of code generation (sort.h)
