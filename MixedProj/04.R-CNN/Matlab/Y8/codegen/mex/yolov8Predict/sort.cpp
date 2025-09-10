//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// sort.cpp
//
// Code generation for function 'sort'
//

// Include files
#include "sort.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "sortIdx.h"
#include "yolov8Predict_data.h"
#include "yolov8Predict_types.h"

// Variable Definitions
static emlrtRSInfo ld_emlrtRSI{
    76,     // lineNo
    "sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" // pathName
};

static emlrtRSInfo md_emlrtRSI{
    79,     // lineNo
    "sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" // pathName
};

static emlrtRSInfo nd_emlrtRSI{
    81,     // lineNo
    "sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" // pathName
};

static emlrtRSInfo od_emlrtRSI{
    84,     // lineNo
    "sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" // pathName
};

static emlrtRSInfo pd_emlrtRSI{
    87,     // lineNo
    "sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" // pathName
};

static emlrtRSInfo qd_emlrtRSI{
    90,     // lineNo
    "sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" // pathName
};

// Function Definitions
namespace coder {
namespace internal {
int32_T b_sort(yolov8PredictStackData *SD, const emlrtStack &sp,
               real32_T x_data[], const int32_T &x_size, int32_T idx_data[])
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T dim;
  int32_T idx_size;
  int32_T vstride;
  int32_T vwork_size;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  dim = 2;
  if (x_size != 1) {
    dim = 1;
  }
  if (dim <= 1) {
    vwork_size = x_size;
  } else {
    vwork_size = 1;
  }
  idx_size = x_size;
  st.site = &ld_emlrtRSI;
  vstride = 1;
  dim -= 2;
  for (int32_T k{0}; k <= dim; k++) {
    vstride *= x_size;
  }
  st.site = &md_emlrtRSI;
  st.site = &nd_emlrtRSI;
  if (vstride > 2147483646) {
    b_st.site = &p_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T j{0}; j < vstride; j++) {
    st.site = &od_emlrtRSI;
    for (int32_T k{0}; k < vwork_size; k++) {
      SD->f5.vwork_data[k] = x_data[j + k * vstride];
    }
    st.site = &pd_emlrtRSI;
    b_sortIdx(SD, st, SD->f5.vwork_data, vwork_size, SD->f5.iidx_data);
    st.site = &qd_emlrtRSI;
    for (int32_T k{0}; k < vwork_size; k++) {
      dim = j + k * vstride;
      x_data[dim] = SD->f5.vwork_data[k];
      idx_data[dim] = SD->f5.iidx_data[k];
    }
  }
  return idx_size;
}

} // namespace internal
} // namespace coder

// End of code generation (sort.cpp)
