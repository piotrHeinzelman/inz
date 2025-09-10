//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// div.h
//
// Code generation for function 'div'
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

// Function Declarations
void binary_expand_op_2(const emlrtStack &sp, coder::array<real32_T, 2U> &in1,
                        const coder::array<real32_T, 2U> &in2,
                        const coder::array<real32_T, 2U> &in3);

void binary_expand_op_5(const emlrtStack &sp, coder::array<real32_T, 2U> &in1,
                        const coder::array<real32_T, 2U> &in2,
                        const coder::array<real_T, 2U> &in3);

// End of code generation (div.h)
