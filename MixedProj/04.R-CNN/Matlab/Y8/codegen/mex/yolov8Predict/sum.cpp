//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// sum.cpp
//
// Code generation for function 'sum'
//

// Include files
#include "sum.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <xmmintrin.h>

// Variable Definitions
static emlrtRSInfo mc_emlrtRSI{
    20,    // lineNo
    "sum", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m" // pathName
};

static emlrtRSInfo nc_emlrtRSI{
    99,        // lineNo
    "sumprod", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumpro"
    "d.m" // pathName
};

static emlrtRSInfo oc_emlrtRSI{
    86,                      // lineNo
    "combineVectorElements", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combin"
    "eVectorElements.m" // pathName
};

static emlrtRSInfo pc_emlrtRSI{
    112,                // lineNo
    "blockedSummation", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blocke"
    "dSummation.m" // pathName
};

static emlrtRTEInfo db_emlrtRTEI{
    1,     // lineNo
    14,    // colNo
    "sum", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m" // pName
};

// Function Definitions
namespace coder {
void sum(const emlrtStack &sp, const array<real32_T, 3U> &x,
         array<real32_T, 2U> &y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  st.site = &mc_emlrtRSI;
  b_st.site = &nc_emlrtRSI;
  c_st.site = &oc_emlrtRSI;
  if (x.size(1) == 0) {
    y.set_size(&db_emlrtRTEI, &c_st, 4, 0);
  } else {
    int32_T scalarLB;
    int32_T vectorUB;
    int32_T vstride;
    d_st.site = &pc_emlrtRSI;
    vstride = x.size(1) << 2;
    y.set_size(&db_emlrtRTEI, &d_st, 4, x.size(1));
    for (int32_T xj{0}; xj < vstride; xj++) {
      y[xj] = x[xj];
    }
    scalarLB = (vstride / 4) << 2;
    vectorUB = scalarLB - 4;
    for (int32_T xj{0}; xj < 15; xj++) {
      int32_T xoffset;
      xoffset = (xj + 1) * vstride;
      for (int32_T b_xj{0}; b_xj <= vectorUB; b_xj += 4) {
        __m128 r;
        r = _mm_loadu_ps(&y[b_xj]);
        _mm_storeu_ps(&y[b_xj],
                      _mm_add_ps(r, _mm_loadu_ps(&x[xoffset + b_xj])));
      }
      for (int32_T b_xj{scalarLB}; b_xj < vstride; b_xj++) {
        y[b_xj] = y[b_xj] + x[xoffset + b_xj];
      }
    }
  }
}

} // namespace coder

// End of code generation (sum.cpp)
