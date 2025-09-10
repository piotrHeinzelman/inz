//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// distributionFocalLoss.h
//
// Code generation for function 'distributionFocalLoss'
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
namespace coder {
struct c_dlarray;

}

// Function Declarations
void binary_expand_op_1(const emlrtStack &sp, coder::array<real32_T, 2U> &in1,
                        const emlrtRSInfo in2, const coder::c_dlarray &in3,
                        const coder::array<real_T, 2U> &in4, int32_T in5);

// End of code generation (distributionFocalLoss.h)
