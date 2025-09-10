//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// permute.h
//
// Code generation for function 'permute'
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
void b_permute(const emlrtStack &sp, const array<real32_T, 2U> &a,
               array<real32_T, 2U> &b);

void c_permute(const emlrtStack &sp, const array<real32_T, 2U> &a,
               array<real32_T, 2U> &b);

void d_permute(const emlrtStack &sp, const array<real32_T, 2U> &a,
               array<real32_T, 2U> &b);

void permute(const emlrtStack &sp, const array<real32_T, 3U> &a,
             array<real32_T, 3U> &b);

void permute(const emlrtStack &sp, const array<real32_T, 2U> &a,
             array<real32_T, 2U> &b);

} // namespace coder

// End of code generation (permute.h)
