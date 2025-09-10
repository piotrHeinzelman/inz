//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// preprocess.h
//
// Code generation for function 'preprocess'
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
namespace helper {
void b_preprocess(yolov8PredictStackData *SD, const emlrtStack &sp,
                  const uint8_T img[623217], real32_T output[1044480]);

}

// End of code generation (preprocess.h)
