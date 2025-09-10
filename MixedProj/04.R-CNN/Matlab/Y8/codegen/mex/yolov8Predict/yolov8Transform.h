//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// yolov8Transform.h
//
// Code generation for function 'yolov8Transform'
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
struct dlarray;

}

// Function Declarations
namespace helper {
void yolov8Transform(const emlrtStack &sp, const coder::dlarray predictions[3],
                     coder::array<real32_T, 2U> &box,
                     coder::array<real32_T, 2U> &cls);

}

// End of code generation (yolov8Transform.h)
