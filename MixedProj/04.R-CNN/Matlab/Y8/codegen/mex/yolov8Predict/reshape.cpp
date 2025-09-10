//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// reshape.cpp
//
// Code generation for function 'reshape'
//

// Include files
#include "reshape.h"
#include "permute.h"
#include "rt_nonfinite.h"
#include "yolov8Predict_data.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo lb_emlrtRSI{
    34,                // lineNo
    "dlarray/reshape", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\nnet\\deepcoder\\+deep\\+internal\\+"
    "coder\\@dlarray\\reshape.m" // pathName
};

static emlrtRSInfo mb_emlrtRSI{
    35,                // lineNo
    "dlarray/reshape", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\nnet\\deepcoder\\+deep\\+internal\\+"
    "coder\\@dlarray\\reshape.m" // pathName
};

static emlrtRSInfo rb_emlrtRSI{
    114,               // lineNo
    "computeDimsData", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" // pathName
};

static emlrtRTEInfo f_emlrtRTEI{
    58,                   // lineNo
    23,                   // colNo
    "assertValidSizeArg", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\assertValidSizeArg.m" // pName
};

static emlrtRTEInfo x_emlrtRTEI{
    1,         // lineNo
    17,        // colNo
    "reshape", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\nnet\\deepcoder\\+deep\\+internal\\+"
    "coder\\@dlarray\\reshape.m" // pName
};

// Function Definitions
namespace coder {
void dlarray_reshape(const emlrtStack &sp, const array<real32_T, 3U> &objX_Data,
                     array<real32_T, 2U> &objZ_Data)
{
  array<real32_T, 3U> objdata;
  emlrtStack b_st;
  emlrtStack st;
  int32_T emptyDimValue;
  int32_T nx;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  st.site = &lb_emlrtRSI;
  b_st.site = &nb_emlrtRSI;
  permute(b_st, objX_Data, objdata);
  st.site = &mb_emlrtRSI;
  nx = objdata.size(0) * objdata.size(1) * 144;
  b_st.site = &qb_emlrtRSI;
  emptyDimValue = static_cast<int32_T>(static_cast<uint32_T>(nx) / 144U);
  if (emptyDimValue > nx) {
    emlrtErrorWithMessageIdR2018a(&b_st, &d_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  if (emptyDimValue > muIntScalarMax_sint32(nx, 144)) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (emptyDimValue * 144 != nx) {
    emlrtErrorWithMessageIdR2018a(
        &st, &b_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }
  objZ_Data.set_size(&x_emlrtRTEI, &sp, emptyDimValue, 144);
  nx = emptyDimValue * 144;
  for (int32_T i{0}; i < nx; i++) {
    objZ_Data[i] = objdata[i];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

void dlarray_reshape(const emlrtStack &sp, const array<real32_T, 2U> &objX_Data,
                     real_T varargin_1, array<real32_T, 3U> &objZ_Data)
{
  array<real32_T, 2U> objY_Data;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T n;
  int32_T nx;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  st.site = &lb_emlrtRSI;
  b_st.site = &nb_emlrtRSI;
  b_permute(b_st, objX_Data, objY_Data);
  st.site = &mb_emlrtRSI;
  nx = objY_Data.size(0) << 6;
  b_st.site = &qb_emlrtRSI;
  c_st.site = &rb_emlrtRSI;
  if ((varargin_1 != varargin_1) || muDoubleScalarIsInf(varargin_1)) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &f_emlrtRTEI, "Coder:MATLAB:NonIntegerInput",
        "Coder:MATLAB:NonIntegerInput", 4, 12, MIN_int32_T, 12, MAX_int32_T);
  }
  n = objY_Data.size(0);
  if (objY_Data.size(0) < 64) {
    n = 64;
  }
  if (static_cast<int32_T>(varargin_1) > muIntScalarMax_sint32(nx, n)) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  n = static_cast<int32_T>(varargin_1) << 6;
  if (n != nx) {
    emlrtErrorWithMessageIdR2018a(
        &st, &b_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }
  objZ_Data.set_size(&x_emlrtRTEI, &sp, static_cast<int32_T>(varargin_1), 16,
                     4);
  for (int32_T i{0}; i < n; i++) {
    objZ_Data[i] = objY_Data[i];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

} // namespace coder

// End of code generation (reshape.cpp)
