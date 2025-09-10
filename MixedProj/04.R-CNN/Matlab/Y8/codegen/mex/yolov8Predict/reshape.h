//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// reshape.h
//
// Code generation for function 'reshape'
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
void dlarray_reshape(const emlrtStack &sp, const array<real32_T, 3U> &objX_Data,
                     array<real32_T, 2U> &objZ_Data);

void dlarray_reshape(const emlrtStack &sp, const array<real32_T, 2U> &objX_Data,
                     real_T varargin_1, array<real32_T, 3U> &objZ_Data);

} // namespace coder

// End of code generation (reshape.h)
