//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// postprocess.h
//
// Code generation for function 'postprocess'
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

namespace coder {
struct dlarray;

}

// Function Declarations
namespace helper {
int32_T b_postprocess(yolov8PredictStackData *SD, const emlrtStack &sp,
                      const coder::dlarray outFeatureMaps[3],
                      coder::array<real32_T, 2U> &bboxes,
                      real32_T scores_data[],
                      coder::array<real_T, 1U> &labelIds);

}

// End of code generation (postprocess.h)
