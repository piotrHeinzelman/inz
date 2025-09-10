//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// sortIdx.cpp
//
// Code generation for function 'sortIdx'
//

// Include files
#include "sortIdx.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "yolov8Predict_data.h"
#include "yolov8Predict_types.h"
#include "mwmathutil.h"
#include <algorithm>
#include <cstring>

// Variable Definitions
static emlrtRSInfo rd_emlrtRSI{
    105,       // lineNo
    "sortIdx", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo sd_emlrtRSI{
    301,                // lineNo
    "block_merge_sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo td_emlrtRSI{
    309,                // lineNo
    "block_merge_sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo ud_emlrtRSI{
    310,                // lineNo
    "block_merge_sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo vd_emlrtRSI{
    318,                // lineNo
    "block_merge_sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo wd_emlrtRSI{
    326,                // lineNo
    "block_merge_sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo xd_emlrtRSI{
    333,                // lineNo
    "block_merge_sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo yd_emlrtRSI{
    381,                      // lineNo
    "initialize_vector_sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo ae_emlrtRSI{
    409,                      // lineNo
    "initialize_vector_sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo be_emlrtRSI{
    416,                      // lineNo
    "initialize_vector_sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo ce_emlrtRSI{
    576,                // lineNo
    "merge_pow2_block", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo de_emlrtRSI{
    578,                // lineNo
    "merge_pow2_block", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo ee_emlrtRSI{
    606,                // lineNo
    "merge_pow2_block", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo fe_emlrtRSI{
    488,           // lineNo
    "merge_block", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo ge_emlrtRSI{
    496,           // lineNo
    "merge_block", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo he_emlrtRSI{
    503,           // lineNo
    "merge_block", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo ie_emlrtRSI{
    550,     // lineNo
    "merge", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo je_emlrtRSI{
    519,     // lineNo
    "merge", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo ke_emlrtRSI{
    347,          // lineNo
    "shift_NaNs", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

static emlrtRSInfo le_emlrtRSI{
    356,          // lineNo
    "shift_NaNs", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m" // pathName
};

// Function Declarations
namespace coder {
namespace internal {
static void merge(const emlrtStack &sp, int32_T idx_data[], real32_T x_data[],
                  int32_T offset, int32_T np, int32_T nq, int32_T iwork_data[],
                  real32_T xwork_data[]);

static void merge_block(const emlrtStack &sp, int32_T idx_data[],
                        real32_T x_data[], int32_T offset, int32_T n,
                        int32_T preSortLevel, int32_T iwork_data[],
                        real32_T xwork_data[]);

} // namespace internal
} // namespace coder

// Function Definitions
namespace coder {
namespace internal {
static void merge(const emlrtStack &sp, int32_T idx_data[], real32_T x_data[],
                  int32_T offset, int32_T np, int32_T nq, int32_T iwork_data[],
                  real32_T xwork_data[])
{
  emlrtStack b_st;
  emlrtStack st;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (nq != 0) {
    int32_T iout;
    int32_T n;
    int32_T p;
    int32_T q;
    n = np + nq;
    st.site = &je_emlrtRSI;
    if (n > 2147483646) {
      b_st.site = &p_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T j{0}; j < n; j++) {
      q = offset + j;
      iwork_data[j] = idx_data[q];
      xwork_data[j] = x_data[q];
    }
    p = 0;
    q = np;
    iout = offset - 1;
    int32_T exitg1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork_data[p] >= xwork_data[q]) {
        idx_data[iout] = iwork_data[p];
        x_data[iout] = xwork_data[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx_data[iout] = iwork_data[q];
        x_data[iout] = xwork_data[q];
        if (q + 1 < n) {
          q++;
        } else {
          q = iout - p;
          st.site = &ie_emlrtRSI;
          if ((p + 1 <= np) && (np > 2147483646)) {
            b_st.site = &p_emlrtRSI;
            check_forloop_overflow_error(b_st);
          }
          for (int32_T j{p + 1}; j <= np; j++) {
            iout = q + j;
            idx_data[iout] = iwork_data[j - 1];
            x_data[iout] = xwork_data[j - 1];
          }
          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

static void merge_block(const emlrtStack &sp, int32_T idx_data[],
                        real32_T x_data[], int32_T offset, int32_T n,
                        int32_T preSortLevel, int32_T iwork_data[],
                        real32_T xwork_data[])
{
  emlrtStack st;
  int32_T bLen;
  int32_T nPairs;
  st.prev = &sp;
  st.tls = sp.tls;
  nPairs = n >> preSortLevel;
  bLen = 1 << preSortLevel;
  while (nPairs > 1) {
    int32_T tailOffset;
    if ((static_cast<uint32_T>(nPairs) & 1U) != 0U) {
      int32_T nTail;
      nPairs--;
      tailOffset = bLen * nPairs;
      nTail = n - tailOffset;
      if (nTail > bLen) {
        st.site = &fe_emlrtRSI;
        merge(st, idx_data, x_data, offset + tailOffset, bLen, nTail - bLen,
              iwork_data, xwork_data);
      }
    }
    tailOffset = bLen << 1;
    nPairs >>= 1;
    for (int32_T k{0}; k < nPairs; k++) {
      st.site = &ge_emlrtRSI;
      merge(st, idx_data, x_data, offset + k * tailOffset, bLen, bLen,
            iwork_data, xwork_data);
    }
    bLen = tailOffset;
  }
  if (n > bLen) {
    st.site = &he_emlrtRSI;
    merge(st, idx_data, x_data, offset, bLen, n - bLen, iwork_data, xwork_data);
  }
}

int32_T b_sortIdx(yolov8PredictStackData *SD, const emlrtStack &sp,
                  real32_T x_data[], const int32_T &x_size, int32_T idx_data[])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T idx_size;
  real32_T xwork_data[16320];
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  idx_size = static_cast<int16_T>(x_size);
  if (idx_size - 1 >= 0) {
    std::memset(&idx_data[0], 0,
                static_cast<uint32_T>(idx_size) * sizeof(int32_T));
  }
  if (x_size != 0) {
    int32_T bLen;
    int32_T bLen2;
    int32_T i1;
    int32_T i2;
    int32_T i4;
    int32_T ib;
    int32_T n;
    int32_T nNaNs;
    int32_T quartetOffset;
    int32_T wOffset;
    real32_T x4[4];
    int16_T idx4[4];
    st.site = &rd_emlrtRSI;
    if (idx_size - 1 >= 0) {
      std::memset(&SD->f0.iwork_data[0], 0,
                  static_cast<uint32_T>(idx_size) * sizeof(int32_T));
    }
    b_st.site = &sd_emlrtRSI;
    n = x_size;
    x4[0] = 0.0F;
    idx4[0] = 0;
    x4[1] = 0.0F;
    idx4[1] = 0;
    x4[2] = 0.0F;
    idx4[2] = 0;
    x4[3] = 0.0F;
    idx4[3] = 0;
    nNaNs = 0;
    ib = 0;
    c_st.site = &yd_emlrtRSI;
    for (int32_T k{0}; k < n; k++) {
      if (muSingleScalarIsNaN(x_data[k])) {
        i1 = (n - nNaNs) - 1;
        idx_data[i1] = k + 1;
        xwork_data[i1] = x_data[k];
        nNaNs++;
      } else {
        ib++;
        idx4[ib - 1] = static_cast<int16_T>(k + 1);
        x4[ib - 1] = x_data[k];
        if (ib == 4) {
          real32_T f;
          real32_T f1;
          quartetOffset = k - nNaNs;
          if (x4[0] >= x4[1]) {
            i1 = 1;
            i2 = 2;
          } else {
            i1 = 2;
            i2 = 1;
          }
          if (x4[2] >= x4[3]) {
            ib = 3;
            i4 = 4;
          } else {
            ib = 4;
            i4 = 3;
          }
          f = x4[i1 - 1];
          f1 = x4[ib - 1];
          if (f >= f1) {
            real32_T f2;
            f2 = x4[i2 - 1];
            if (f2 >= f1) {
              bLen = i1;
              bLen2 = i2;
              i1 = ib;
              i2 = i4;
            } else if (f2 >= x4[i4 - 1]) {
              bLen = i1;
              bLen2 = ib;
              i1 = i2;
              i2 = i4;
            } else {
              bLen = i1;
              bLen2 = ib;
              i1 = i4;
            }
          } else {
            real32_T f2;
            f2 = x4[i4 - 1];
            if (f >= f2) {
              if (x4[i2 - 1] >= f2) {
                bLen = ib;
                bLen2 = i1;
                i1 = i2;
                i2 = i4;
              } else {
                bLen = ib;
                bLen2 = i1;
                i1 = i4;
              }
            } else {
              bLen = ib;
              bLen2 = i4;
            }
          }
          idx_data[quartetOffset - 3] = idx4[bLen - 1];
          idx_data[quartetOffset - 2] = idx4[bLen2 - 1];
          idx_data[quartetOffset - 1] = idx4[i1 - 1];
          idx_data[quartetOffset] = idx4[i2 - 1];
          x_data[quartetOffset - 3] = x4[bLen - 1];
          x_data[quartetOffset - 2] = x4[bLen2 - 1];
          x_data[quartetOffset - 1] = x4[i1 - 1];
          x_data[quartetOffset] = x4[i2 - 1];
          ib = 0;
        }
      }
    }
    wOffset = x_size - nNaNs;
    if (ib > 0) {
      int8_T perm[4];
      perm[1] = 0;
      perm[2] = 0;
      perm[3] = 0;
      if (ib == 1) {
        perm[0] = 1;
      } else if (ib == 2) {
        if (x4[0] >= x4[1]) {
          perm[0] = 1;
          perm[1] = 2;
        } else {
          perm[0] = 2;
          perm[1] = 1;
        }
      } else if (x4[0] >= x4[1]) {
        if (x4[1] >= x4[2]) {
          perm[0] = 1;
          perm[1] = 2;
          perm[2] = 3;
        } else if (x4[0] >= x4[2]) {
          perm[0] = 1;
          perm[1] = 3;
          perm[2] = 2;
        } else {
          perm[0] = 3;
          perm[1] = 1;
          perm[2] = 2;
        }
      } else if (x4[0] >= x4[2]) {
        perm[0] = 2;
        perm[1] = 1;
        perm[2] = 3;
      } else if (x4[1] >= x4[2]) {
        perm[0] = 2;
        perm[1] = 3;
        perm[2] = 1;
      } else {
        perm[0] = 3;
        perm[1] = 2;
        perm[2] = 1;
      }
      c_st.site = &ae_emlrtRSI;
      if (ib > 2147483646) {
        d_st.site = &p_emlrtRSI;
        check_forloop_overflow_error(d_st);
      }
      i1 = static_cast<uint8_T>(ib);
      for (int32_T k{0}; k < i1; k++) {
        quartetOffset = (wOffset - ib) + k;
        i2 = perm[k];
        idx_data[quartetOffset] = idx4[i2 - 1];
        x_data[quartetOffset] = x4[i2 - 1];
      }
    }
    i1 = nNaNs >> 1;
    c_st.site = &be_emlrtRSI;
    for (int32_T k{0}; k < i1; k++) {
      quartetOffset = wOffset + k;
      i2 = idx_data[quartetOffset];
      ib = (n - k) - 1;
      idx_data[quartetOffset] = idx_data[ib];
      idx_data[ib] = i2;
      x_data[quartetOffset] = xwork_data[ib];
      x_data[ib] = xwork_data[quartetOffset];
    }
    if ((static_cast<uint32_T>(nNaNs) & 1U) != 0U) {
      i1 += wOffset;
      x_data[i1] = xwork_data[i1];
    }
    i1 = 2;
    if (wOffset > 1) {
      if (x_size >= 256) {
        int32_T nBlocks;
        nBlocks = wOffset >> 8;
        if (nBlocks > 0) {
          b_st.site = &td_emlrtRSI;
          for (int32_T b{0}; b < nBlocks; b++) {
            real32_T xwork[256];
            int16_T iwork[256];
            b_st.site = &ud_emlrtRSI;
            i4 = (b << 8) - 1;
            for (int32_T b_b{0}; b_b < 6; b_b++) {
              bLen = 1 << (b_b + 2);
              bLen2 = bLen << 1;
              n = 256 >> (b_b + 3);
              c_st.site = &ce_emlrtRSI;
              for (int32_T b_k{0}; b_k < n; b_k++) {
                i1 = (i4 + b_k * bLen2) + 1;
                c_st.site = &de_emlrtRSI;
                for (int32_T k{0}; k < bLen2; k++) {
                  ib = i1 + k;
                  iwork[k] = static_cast<int16_T>(idx_data[ib]);
                  xwork[k] = x_data[ib];
                }
                i2 = 0;
                quartetOffset = bLen;
                ib = i1 - 1;
                int32_T exitg1;
                do {
                  exitg1 = 0;
                  ib++;
                  if (xwork[i2] >= xwork[quartetOffset]) {
                    idx_data[ib] = iwork[i2];
                    x_data[ib] = xwork[i2];
                    if (i2 + 1 < bLen) {
                      i2++;
                    } else {
                      exitg1 = 1;
                    }
                  } else {
                    idx_data[ib] = iwork[quartetOffset];
                    x_data[ib] = xwork[quartetOffset];
                    if (quartetOffset + 1 < bLen2) {
                      quartetOffset++;
                    } else {
                      ib -= i2;
                      c_st.site = &ee_emlrtRSI;
                      for (int32_T k{i2 + 1}; k <= bLen; k++) {
                        quartetOffset = ib + k;
                        idx_data[quartetOffset] = iwork[k - 1];
                        x_data[quartetOffset] = xwork[k - 1];
                      }
                      exitg1 = 1;
                    }
                  }
                } while (exitg1 == 0);
              }
            }
          }
          i1 = nBlocks << 8;
          quartetOffset = wOffset - i1;
          if (quartetOffset > 0) {
            b_st.site = &vd_emlrtRSI;
            merge_block(b_st, idx_data, x_data, i1, quartetOffset, 2,
                        SD->f0.iwork_data, xwork_data);
          }
          i1 = 8;
        }
      }
      b_st.site = &wd_emlrtRSI;
      merge_block(b_st, idx_data, x_data, 0, wOffset, i1, SD->f0.iwork_data,
                  xwork_data);
    }
    if ((nNaNs > 0) && (wOffset > 0)) {
      b_st.site = &xd_emlrtRSI;
      c_st.site = &ke_emlrtRSI;
      for (int32_T k{0}; k < nNaNs; k++) {
        i1 = wOffset + k;
        xwork_data[k] = x_data[i1];
        SD->f0.iwork_data[k] = idx_data[i1];
      }
      for (int32_T k{wOffset}; k >= 1; k--) {
        i1 = (nNaNs + k) - 1;
        x_data[i1] = x_data[k - 1];
        idx_data[i1] = idx_data[k - 1];
      }
      c_st.site = &le_emlrtRSI;
      std::copy(&xwork_data[0], &xwork_data[nNaNs], &x_data[0]);
      std::copy(&SD->f0.iwork_data[0], &SD->f0.iwork_data[nNaNs], &idx_data[0]);
    }
  }
  return idx_size;
}

} // namespace internal
} // namespace coder

// End of code generation (sortIdx.cpp)
