//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// imresize.h
//
// Code generation for function 'imresize'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Type Declarations
struct yolov8PredictStackData;

// Function Declarations
namespace coder {
void b_imresize(yolov8PredictStackData *SD, const emlrtStack &sp,
                const uint8_T Ain[623217], uint8_T Bout[1008000]);

}

// End of code generation (imresize.h)
