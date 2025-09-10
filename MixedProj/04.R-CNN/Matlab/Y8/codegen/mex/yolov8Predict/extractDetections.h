//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// extractDetections.h
//
// Code generation for function 'extractDetections'
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
struct yolov8PredictStackData;

// Function Declarations
namespace helper {
int32_T b_extractDetections(yolov8PredictStackData *SD, const emlrtStack &sp,
                            const coder::array<real32_T, 2U> &predictions,
                            coder::array<real32_T, 2U> &bboxes,
                            real32_T scores_data[],
                            coder::array<real_T, 1U> &labelIds);

}

// End of code generation (extractDetections.h)
