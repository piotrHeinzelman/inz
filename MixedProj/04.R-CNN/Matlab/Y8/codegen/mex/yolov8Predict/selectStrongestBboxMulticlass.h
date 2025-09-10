//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// selectStrongestBboxMulticlass.h
//
// Code generation for function 'selectStrongestBboxMulticlass'
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
namespace coder {
int32_T b_selectStrongestBboxMulticlass(
    yolov8PredictStackData *SD, const emlrtStack &sp,
    const array<real32_T, 2U> &bbox, const real32_T score_data[],
    int32_T score_size, const array<real_T, 1U> &label,
    array<real32_T, 2U> &selectedBbox, real32_T selectedScore_data[],
    array<real_T, 1U> &selectedLabel);

}

// End of code generation (selectStrongestBboxMulticlass.h)
