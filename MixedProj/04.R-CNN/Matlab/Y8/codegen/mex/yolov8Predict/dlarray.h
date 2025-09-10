//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// dlarray.h
//
// Code generation for function 'dlarray'
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
void dlarray_extractdata(const emlrtStack &sp,
                         const array<real32_T, 3U> &obj_Data,
                         array<real32_T, 3U> &viewData);

}

// End of code generation (dlarray.h)
