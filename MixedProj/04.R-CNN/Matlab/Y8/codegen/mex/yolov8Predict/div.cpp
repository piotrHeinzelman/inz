//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// div.cpp
//
// Code generation for function 'div'
//

// Include files
#include "div.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRTEInfo nb_emlrtRTEI{
    54,    // lineNo
    5,     // colNo
    "div", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\div.m" // pName
};

// Function Definitions
void binary_expand_op_2(const emlrtStack &sp, coder::array<real32_T, 2U> &in1,
                        const coder::array<real32_T, 2U> &in2,
                        const coder::array<real32_T, 2U> &in3)
{
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  in1.set_size(&nb_emlrtRTEI, &sp, 2, in1.size(1));
  if (in3.size(1) == 1) {
    loop_ub = in2.size(1);
  } else {
    loop_ub = in3.size(1);
  }
  in1.set_size(&nb_emlrtRTEI, &sp, in1.size(0), loop_ub);
  stride_0_1 = (in2.size(1) != 1);
  stride_1_1 = (in3.size(1) != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (int32_T i{0}; i < loop_ub; i++) {
    in1[2 * i] = (in2[2 * aux_0_1] + in3[2 * aux_1_1]) / 2.0F;
    in1[2 * i + 1] = (in2[2 * aux_0_1 + 1] + in3[2 * aux_1_1 + 1]) / 2.0F;
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
}

void binary_expand_op_5(const emlrtStack &sp, coder::array<real32_T, 2U> &in1,
                        const coder::array<real32_T, 2U> &in2,
                        const coder::array<real_T, 2U> &in3)
{
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  if (in3.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in3.size(0);
  }
  in1.set_size(&nb_emlrtRTEI, &sp, loop_ub, 4);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  for (int32_T i{0}; i < 4; i++) {
    for (int32_T i1{0}; i1 < loop_ub; i1++) {
      in1[i1 + in1.size(0) * i] =
          (in2[i1 * stride_0_0 + in2.size(0) * i] -
           static_cast<real32_T>(in3[i1 * stride_1_0 + in3.size(0) * i])) /
          1.27236581F;
    }
  }
}

// End of code generation (div.cpp)
