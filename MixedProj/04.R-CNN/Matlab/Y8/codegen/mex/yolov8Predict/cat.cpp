//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// cat.cpp
//
// Code generation for function 'cat'
//

// Include files
#include "cat.h"
#include "rt_nonfinite.h"
#include "yolov8Predict_internal_types.h"
#include "coder_array.h"
#include <algorithm>

// Variable Definitions
static emlrtRTEInfo
    ab_emlrtRTEI{
        1,     // lineNo
        14,    // colNo
        "cat", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\elmat\\cat.m" // pName
    };

// Function Definitions
namespace coder {
void cat(const emlrtStack &sp, const array<real32_T, 2U> &varargin_1,
         const array<real32_T, 2U> &varargin_2,
         const array<real32_T, 2U> &varargin_3, array<real32_T, 2U> &y)
{
  int32_T iy;
  int32_T loop_ub;
  y.set_size(&ab_emlrtRTEI, &sp, 144, varargin_1.size(1));
  loop_ub = 144 * varargin_1.size(1);
  for (int32_T j{0}; j < loop_ub; j++) {
    y[j] = varargin_1[j];
  }
  y.set_size(&ab_emlrtRTEI, &sp, 144,
             (varargin_1.size(1) + varargin_2.size(1)) + varargin_3.size(1));
  iy = 144 * varargin_2.size(1);
  for (int32_T j{0}; j < iy; j++) {
    y[loop_ub + j] = varargin_2[j];
  }
  if (iy - 1 < 0) {
    iy = loop_ub - 1;
  } else {
    iy = (loop_ub + iy) - 1;
  }
  loop_ub = 144 * varargin_3.size(1);
  for (int32_T j{0}; j < loop_ub; j++) {
    y[(iy + j) + 1] = varargin_3[j];
  }
}

void cat(const emlrtStack &sp, const array<real_T, 2U> &varargin_1,
         const array<real_T, 2U> &varargin_2,
         const array<real_T, 2U> &varargin_3, array<real_T, 2U> &y)
{
  cell_wrap_48 r;
  cell_wrap_48 r1;
  cell_wrap_48 r2;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T k;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  y.set_size(&ab_emlrtRTEI, &sp,
             (varargin_1.size(0) + varargin_2.size(0)) + varargin_3.size(0), 2);
  i = varargin_1.size(0);
  r.f1.set_size(&ab_emlrtRTEI, &sp, varargin_1.size(0), 2);
  k = varargin_1.size(0) << 1;
  for (int32_T j{0}; j < k; j++) {
    r.f1[j] = varargin_1[j];
  }
  i1 = varargin_2.size(0);
  r1.f1.set_size(&ab_emlrtRTEI, &sp, varargin_2.size(0), 2);
  k = varargin_2.size(0) << 1;
  for (int32_T j{0}; j < k; j++) {
    r1.f1[j] = varargin_2[j];
  }
  i2 = varargin_3.size(0);
  r2.f1.set_size(&ab_emlrtRTEI, &sp, varargin_3.size(0), 2);
  k = varargin_3.size(0) << 1;
  for (int32_T j{0}; j < k; j++) {
    r2.f1[j] = varargin_3[j];
  }
  for (int32_T b_k{0}; b_k < 2; b_k++) {
    for (int32_T j{0}; j < i; j++) {
      y[j + y.size(0) * b_k] = r.f1[j + r.f1.size(0) * b_k];
    }
    if (i - 1 < 0) {
      k = -1;
    } else {
      k = i + -1;
    }
    for (int32_T j{0}; j < i1; j++) {
      y[((k + j) + y.size(0) * b_k) + 1] = r1.f1[j + r1.f1.size(0) * b_k];
    }
    if (i1 - 1 >= 0) {
      k += i1;
    }
    for (int32_T j{0}; j < i2; j++) {
      y[((k + j) + y.size(0) * b_k) + 1] = r2.f1[j + r2.f1.size(0) * b_k];
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

void cat(const emlrtStack &sp, const real_T varargin_1_data[],
         const int32_T varargin_1_size[2], const real_T varargin_2_data[],
         const int32_T varargin_2_size[2], const real_T varargin_3_data[],
         const int32_T varargin_3_size[2], array<real_T, 2U> &y)
{
  cell_wrap_49 r;
  cell_wrap_49 r1;
  cell_wrap_49 r2;
  int32_T b_loop_ub;
  int32_T k;
  int32_T loop_ub;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  y.set_size(&ab_emlrtRTEI, &sp,
             (varargin_1_size[0] + varargin_2_size[0]) + varargin_3_size[0], 1);
  k = varargin_1_size[0];
  r.f1.set_size(&ab_emlrtRTEI, &sp, varargin_1_size[0], 1);
  if (k - 1 >= 0) {
    std::copy(&varargin_1_data[0], &varargin_1_data[k], &r.f1[0]);
  }
  loop_ub = varargin_2_size[0];
  r1.f1.set_size(&ab_emlrtRTEI, &sp, varargin_2_size[0], 1);
  if (loop_ub - 1 >= 0) {
    std::copy(&varargin_2_data[0], &varargin_2_data[loop_ub], &r1.f1[0]);
  }
  b_loop_ub = varargin_3_size[0];
  r2.f1.set_size(&ab_emlrtRTEI, &sp, varargin_3_size[0], 1);
  if (b_loop_ub - 1 >= 0) {
    std::copy(&varargin_3_data[0], &varargin_3_data[b_loop_ub], &r2.f1[0]);
  }
  for (int32_T j{0}; j < k; j++) {
    y[j] = r.f1[j];
  }
  if (r.f1.size(0) - 1 < 0) {
    k = -1;
  } else {
    k = r.f1.size(0) + -1;
  }
  for (int32_T j{0}; j < loop_ub; j++) {
    y[(k + j) + 1] = r1.f1[j];
  }
  if (r1.f1.size(0) - 1 >= 0) {
    k += r1.f1.size(0);
  }
  for (int32_T j{0}; j < b_loop_ub; j++) {
    y[(k + j) + 1] = r2.f1[j];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

} // namespace coder

// End of code generation (cat.cpp)
