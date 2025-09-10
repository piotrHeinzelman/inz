//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// cat.h
//
// Code generation for function 'cat'
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
namespace coder {
void cat(const emlrtStack &sp, const array<real32_T, 2U> &varargin_1,
         const array<real32_T, 2U> &varargin_2,
         const array<real32_T, 2U> &varargin_3, array<real32_T, 2U> &y);

void cat(const emlrtStack &sp, const array<real_T, 2U> &varargin_1,
         const array<real_T, 2U> &varargin_2,
         const array<real_T, 2U> &varargin_3, array<real_T, 2U> &y);

void cat(const emlrtStack &sp, const real_T varargin_1_data[],
         const int32_T varargin_1_size[2], const real_T varargin_2_data[],
         const int32_T varargin_2_size[2], const real_T varargin_3_data[],
         const int32_T varargin_3_size[2], array<real_T, 2U> &y);

} // namespace coder

// End of code generation (cat.h)
