//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// softmax.cpp
//
// Code generation for function 'softmax'
//

// Include files
#include "softmax.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"
#include "yolov8Predict_internal_types.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo ic_emlrtRSI{
    42,                // lineNo
    "dlarray/softmax", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\nnet\\deepcoder\\+deep\\+internal\\+"
    "coder\\@dlarray\\softmax.m" // pathName
};

static emlrtRSInfo jc_emlrtRSI{
    66,                 // lineNo
    "internal_softmax", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\nnet\\deepcoder\\+deep\\+internal\\+"
    "coder\\+dlarray\\internal_softmax.m" // pathName
};

static emlrtRSInfo kc_emlrtRSI{
    107,                     // lineNo
    "iComputeSoftmaxForCpu", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\nnet\\deepcoder\\+deep\\+internal\\+"
    "coder\\+dlarray\\internal_softmax.m" // pathName
};

static emlrtRSInfo lc_emlrtRSI{
    30,        // lineNo
    "ind2sub", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m" // pathName
};

static emlrtBCInfo db_emlrtBCI{
    1,                       // iFirst
    4,                       // iLast
    111,                     // lineNo
    23,                      // colNo
    "",                      // aName
    "iComputeSoftmaxForCpu", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\nnet\\deepcoder\\+deep\\+internal\\+"
    "coder\\+dlarray\\internal_softmax.m", // pName
    0                                      // checkKind
};

static emlrtBCInfo eb_emlrtBCI{
    -1,                      // iFirst
    -1,                      // iLast
    111,                     // lineNo
    23,                      // colNo
    "",                      // aName
    "iComputeSoftmaxForCpu", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\nnet\\deepcoder\\+deep\\+internal\\+"
    "coder\\+dlarray\\internal_softmax.m", // pName
    0                                      // checkKind
};

static emlrtRTEInfo q_emlrtRTEI{
    21,        // lineNo
    15,        // colNo
    "ind2sub", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\ind2sub.m" // pName
};

static emlrtBCInfo fb_emlrtBCI{
    -1,                      // iFirst
    -1,                      // iLast
    130,                     // lineNo
    19,                      // colNo
    "",                      // aName
    "iComputeSoftmaxForCpu", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\nnet\\deepcoder\\+deep\\+internal\\+"
    "coder\\+dlarray\\internal_softmax.m", // pName
    0                                      // checkKind
};

static emlrtRTEInfo jb_emlrtRTEI{
    1,         // lineNo
    14,        // colNo
    "softmax", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\nnet\\deepcoder\\+deep\\+internal\\+"
    "coder\\@dlarray\\softmax.m" // pName
};

// Function Definitions
namespace coder {
void dlarray_softmax(const emlrtStack &sp, c_dlarray &X)
{
  array<real32_T, 3U> xdata;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T i;
  int32_T i1;
  int32_T v1;
  int16_T nonChannelDims_idx_1;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  st.site = &ic_emlrtRSI;
  b_st.site = &jc_emlrtRSI;
  i = X.Data.size(1);
  xdata.set_size(&jb_emlrtRTEI, &b_st, 4, i, 16);
  nonChannelDims_idx_1 = static_cast<int16_T>(X.Data.size(1));
  i1 = X.Data.size(1) << 2;
  for (int32_T nonChannelDimsProductIdx{0}; nonChannelDimsProductIdx < i1;
       nonChannelDimsProductIdx++) {
    int32_T i2;
    int32_T vk;
    real32_T dataExp[16];
    real32_T maxVal;
    c_st.site = &kc_emlrtRSI;
    d_st.site = &lc_emlrtRSI;
    if (nonChannelDimsProductIdx + 1 > (nonChannelDims_idx_1 << 2)) {
      emlrtErrorWithMessageIdR2018a(&d_st, &q_emlrtRTEI,
                                    "Coder:MATLAB:ind2sub_IndexOutOfRange",
                                    "Coder:MATLAB:ind2sub_IndexOutOfRange", 0);
    }
    vk = static_cast<uint16_T>(nonChannelDimsProductIdx) >> 2;
    v1 = nonChannelDimsProductIdx - (vk << 2);
    if ((v1 + 1 < 1) || (v1 + 1 > 4)) {
      emlrtDynamicBoundsCheckR2012b(v1 + 1, 1, 4, &db_emlrtBCI, &b_st);
    }
    if (vk + 1 > i) {
      emlrtDynamicBoundsCheckR2012b(vk + 1, 1, i, &eb_emlrtBCI, &b_st);
    }
    i2 = v1 + 4 * vk;
    if (!muSingleScalarIsNaN(X.Data[i2])) {
      v1 = 1;
    } else {
      int32_T k;
      boolean_T exitg1;
      v1 = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 17)) {
        if (!muSingleScalarIsNaN(X.Data[i2 + 4 * X.Data.size(1) * (k - 1)])) {
          v1 = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (v1 == 0) {
      maxVal = X.Data[i2];
    } else {
      maxVal = X.Data[i2 + 4 * X.Data.size(1) * (v1 - 1)];
      v1++;
      for (int32_T dim3{v1}; dim3 < 17; dim3++) {
        real32_T f;
        f = X.Data[i2 + 4 * X.Data.size(1) * (dim3 - 1)];
        if (maxVal < f) {
          maxVal = f;
        }
      }
    }
    for (int32_T dim3{0}; dim3 < 16; dim3++) {
      dataExp[dim3] =
          muSingleScalarExp(X.Data[i2 + 4 * X.Data.size(1) * dim3] - maxVal);
    }
    maxVal = sumColumnB(dataExp);
    if (vk + 1 > i) {
      emlrtDynamicBoundsCheckR2012b(vk + 1, 1, i, &fb_emlrtBCI, &b_st);
    }
    for (int32_T dim3{0}; dim3 < 16; dim3++) {
      xdata[i2 + 4 * xdata.size(1) * dim3] = dataExp[dim3] / maxVal;
    }
  }
  X.Data.set_size(&jb_emlrtRTEI, &sp, 4, X.Data.size(1), 16);
  v1 = xdata.size(1) << 6;
  for (int32_T dim3{0}; dim3 < v1; dim3++) {
    X.Data[dim3] = xdata[dim3];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

} // namespace coder

// End of code generation (softmax.cpp)
