//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// softmax.h
//
// Code generation for function 'softmax'
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
namespace coder {
struct c_dlarray;

}

// Function Declarations
namespace coder {
void dlarray_softmax(const emlrtStack &sp, c_dlarray &X);

}

// End of code generation (softmax.h)
