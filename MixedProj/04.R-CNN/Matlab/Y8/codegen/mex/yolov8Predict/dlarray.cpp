//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// dlarray.cpp
//
// Code generation for function 'dlarray'
//

// Include files
#include "dlarray.h"
#include "rt_nonfinite.h"
#include "yolov8Predict_data.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo gc_emlrtRSI{
    426,                   // lineNo
    "dlarray/extractdata", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\nnet\\deepcoder\\+deep\\+internal\\+"
    "coder\\@dlarray\\dlarray.m" // pathName
};

static emlrtRSInfo hc_emlrtRSI{
    15,                          // lineNo
    "dlarray/permuteToViewData", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\nnet\\deepcoder\\+deep\\+internal\\+"
    "coder\\@dlarray\\permuteToViewData.m" // pathName
};

static emlrtRTEInfo cb_emlrtRTEI{
    417,       // lineNo
    29,        // colNo
    "dlarray", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\nnet\\deepcoder\\+deep\\+internal\\+"
    "coder\\@dlarray\\dlarray.m" // pName
};

// Function Definitions
namespace coder {
void dlarray_extractdata(const emlrtStack &sp,
                         const array<real32_T, 3U> &obj_Data,
                         array<real32_T, 3U> &viewData)
{
  static const int8_T iv[4]{3, 1, 2, 4};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T n;
  int32_T nx;
  int32_T plast;
  int16_T subsa_idx_1;
  int16_T subsa_idx_2;
  boolean_T b;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  st.site = &gc_emlrtRSI;
  b_st.site = &hc_emlrtRSI;
  b = true;
  if (obj_Data.size(0) != 0) {
    boolean_T exitg1;
    plast = 0;
    nx = 0;
    exitg1 = false;
    while ((!exitg1) && (nx < 4)) {
      if (iv[nx] <= 3) {
        n = obj_Data.size(iv[nx] - 1);
      } else {
        n = 1;
      }
      if (n != 1) {
        if (plast > iv[nx]) {
          b = false;
          exitg1 = true;
        } else {
          plast = iv[nx];
          nx++;
        }
      } else {
        nx++;
      }
    }
  }
  if (b) {
    c_st.site = &ob_emlrtRSI;
    nx = obj_Data.size(0) << 6;
    plast = obj_Data.size(0);
    if (obj_Data.size(0) < 16) {
      plast = 16;
    }
    if (obj_Data.size(0) > muIntScalarMax_sint32(nx, plast)) {
      emlrtErrorWithMessageIdR2018a(
          &c_st, &c_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    viewData.set_size(&cb_emlrtRTEI, &b_st, 4, obj_Data.size(0), 16);
    for (int32_T k{0}; k < nx; k++) {
      viewData[k] = obj_Data[k];
    }
  } else {
    c_st.site = &pb_emlrtRSI;
    plast = obj_Data.size(0) << 6;
    nx = obj_Data.size(0);
    n = obj_Data.size(0);
    if (obj_Data.size(0) < 16) {
      n = 16;
    }
    if (obj_Data.size(0) > muIntScalarMax_sint32(plast, n)) {
      emlrtErrorWithMessageIdR2018a(
          &c_st, &c_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    viewData.set_size(&cb_emlrtRTEI, &b_st, 4, obj_Data.size(0), 16);
    for (int32_T k{0}; k < 4; k++) {
      for (int32_T b_k{0}; b_k < 16; b_k++) {
        if (nx - 1 >= 0) {
          subsa_idx_1 = static_cast<int16_T>(b_k + 1);
          subsa_idx_2 = static_cast<int16_T>(k + 1);
        }
        for (int32_T c_k{0}; c_k < nx; c_k++) {
          viewData[((subsa_idx_2 + 4 * c_k) +
                    4 * viewData.size(1) * (subsa_idx_1 - 1)) -
                   1] = obj_Data[(c_k + obj_Data.size(0) * (subsa_idx_1 - 1)) +
                                 obj_Data.size(0) * 16 * (subsa_idx_2 - 1)];
        }
      }
    }
  }
}

} // namespace coder

// End of code generation (dlarray.cpp)
