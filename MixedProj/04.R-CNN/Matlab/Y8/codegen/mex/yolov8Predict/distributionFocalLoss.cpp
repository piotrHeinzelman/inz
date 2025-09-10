//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// distributionFocalLoss.cpp
//
// Code generation for function 'distributionFocalLoss'
//

// Include files
#include "distributionFocalLoss.h"
#include "rt_nonfinite.h"
#include "sum.h"
#include "yolov8Predict_internal_types.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRTEInfo lb_emlrtRTEI{
    37,                      // lineNo
    1,                       // colNo
    "distributionFocalLoss", // fName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\distributionFocalLoss.m" // pName
};

// Function Definitions
void binary_expand_op_1(const emlrtStack &sp, coder::array<real32_T, 2U> &in1,
                        const emlrtRSInfo in2, const coder::c_dlarray &in3,
                        const coder::array<real_T, 2U> &in4, int32_T in5)
{
  coder::array<real32_T, 3U> b_in3;
  emlrtStack st;
  int32_T aux_1_2;
  int32_T stride_0_1;
  int32_T stride_1_2;
  int32_T unnamed_idx_1;
  st.prev = &sp;
  st.tls = sp.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  unnamed_idx_1 = in3.Data.size(1);
  b_in3.set_size(&lb_emlrtRTEI, &sp, 4, unnamed_idx_1, 16);
  stride_0_1 = (in3.Data.size(1) != 1);
  stride_1_2 = (in5 != 1);
  aux_1_2 = 0;
  for (int32_T i{0}; i < 16; i++) {
    int32_T aux_0_1;
    int32_T aux_1_1;
    aux_0_1 = 0;
    aux_1_1 = 0;
    for (int32_T i1{0}; i1 < unnamed_idx_1; i1++) {
      int32_T i2;
      int32_T i3;
      aux_0_1 = 4 * aux_0_1 + 4 * in3.Data.size(1) * i;
      i2 = 4 * aux_1_1 + 4 * unnamed_idx_1 * aux_1_2;
      i3 = 4 * i1 + 4 * b_in3.size(1) * i;
      b_in3[i3] = in3.Data[aux_0_1] * static_cast<real32_T>(in4[i2]);
      b_in3[i3 + 1] =
          in3.Data[aux_0_1 + 1] * static_cast<real32_T>(in4[i2 + 1]);
      b_in3[i3 + 2] =
          in3.Data[aux_0_1 + 2] * static_cast<real32_T>(in4[i2 + 2]);
      b_in3[i3 + 3] =
          in3.Data[aux_0_1 + 3] * static_cast<real32_T>(in4[i2 + 3]);
      aux_1_1 += stride_0_1;
      aux_0_1 = aux_1_1;
    }
    aux_1_2 += stride_1_2;
  }
  st.site = const_cast<emlrtRSInfo *>(&in2);
  coder::sum(st, b_in3, in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

// End of code generation (distributionFocalLoss.cpp)
