//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// yolov8Predict.h
//
// Code generation for function 'yolov8Predict'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "yolov8Predict_types.h"
#include "coder_array.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
void yolov8Predict(yolov8PredictStackData *SD, const emlrtStack *sp,
                   const uint8_T image[623217],
                   coder::array<real32_T, 2U> &bboxes, real32_T scores_data[],
                   int32_T scores_size[1], coder::array<real_T, 1U> &labelIds);

void yolov8Predict_delete();

void yolov8Predict_init();

void yolov8Predict_new();

// End of code generation (yolov8Predict.h)
