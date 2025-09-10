//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// sum.h
//
// Code generation for function 'sum'
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
void sum(const emlrtStack &sp, const array<real32_T, 3U> &x,
         array<real32_T, 2U> &y);

}

// End of code generation (sum.h)
