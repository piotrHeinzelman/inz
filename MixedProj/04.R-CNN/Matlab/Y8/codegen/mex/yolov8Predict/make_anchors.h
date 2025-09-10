//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// make_anchors.h
//
// Code generation for function 'make_anchors'
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
void make_anchors(const emlrtStack &sp, const coder::dlarray feats[3],
                  coder::array<real_T, 2U> &anchorGrid,
                  coder::array<real_T, 2U> &stride);

}

// End of code generation (make_anchors.h)
