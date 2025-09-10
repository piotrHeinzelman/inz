//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_yolov8Predict_api.h
//
// Code generation for function '_coder_yolov8Predict_api'
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
void yolov8Predict_api(yolov8PredictStackData *SD, const mxArray *const prhs[2],
                       int32_T nlhs, const mxArray *plhs[3]);

// End of code generation (_coder_yolov8Predict_api.h)
