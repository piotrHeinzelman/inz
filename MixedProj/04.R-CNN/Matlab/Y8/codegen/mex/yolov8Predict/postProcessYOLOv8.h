//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// postProcessYOLOv8.h
//
// Code generation for function 'postProcessYOLOv8'
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
namespace helper {
void postProcessYOLOv8(const emlrtStack &sp,
                       const coder::array<real32_T, 2U> &coords,
                       coder::array<real32_T, 2U> &newCoords);

}

// End of code generation (postProcessYOLOv8.h)
