//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// permute.cpp
//
// Code generation for function 'permute'
//

// Include files
#include "permute.h"
#include "rt_nonfinite.h"
#include "yolov8Predict_data.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRTEInfo y_emlrtRTEI{
    1,         // lineNo
    14,        // colNo
    "permute", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\elmat\\permute.m" // pName
};

// Function Definitions
namespace coder {
void b_permute(const emlrtStack &sp, const array<real32_T, 2U> &a,
               array<real32_T, 2U> &b)
{
  static const int8_T iv[4]{2, 1, 3, 4};
  emlrtStack st;
  int32_T nx;
  int32_T plast;
  boolean_T b_b;
  st.prev = &sp;
  st.tls = sp.tls;
  b_b = true;
  if (a.size(1) != 0) {
    boolean_T exitg1;
    plast = 0;
    nx = 0;
    exitg1 = false;
    while ((!exitg1) && (nx < 4)) {
      int32_T i;
      if (iv[nx] <= 2) {
        i = a.size(iv[nx] - 1);
      } else {
        i = 1;
      }
      if (i != 1) {
        if (plast > iv[nx]) {
          b_b = false;
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
  if (b_b) {
    st.site = &ob_emlrtRSI;
    nx = a.size(1) << 6;
    plast = 64;
    if (a.size(1) > 64) {
      plast = a.size(1);
    }
    if (a.size(1) > muIntScalarMax_sint32(nx, plast)) {
      emlrtErrorWithMessageIdR2018a(
          &st, &c_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    b.set_size(&y_emlrtRTEI, &sp, a.size(1), 64);
    for (int32_T k{0}; k < nx; k++) {
      b[k] = a[k];
    }
  } else {
    st.site = &pb_emlrtRSI;
    plast = a.size(1) << 6;
    nx = 64;
    if (a.size(1) > 64) {
      nx = a.size(1);
    }
    if (a.size(1) > muIntScalarMax_sint32(plast, nx)) {
      emlrtErrorWithMessageIdR2018a(
          &st, &c_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    plast = a.size(1);
    b.set_size(&y_emlrtRTEI, &sp, a.size(1), 64);
    for (int32_T k{0}; k < plast; k++) {
      for (int32_T b_k{0}; b_k < 64; b_k++) {
        b[k + b.size(0) * b_k] = a[b_k + 64 * k];
      }
    }
  }
}

void c_permute(const emlrtStack &sp, const array<real32_T, 2U> &a,
               array<real32_T, 2U> &b)
{
  static const int8_T iv[4]{2, 1, 3, 4};
  emlrtStack st;
  int32_T nx;
  int32_T plast;
  boolean_T b_b;
  st.prev = &sp;
  st.tls = sp.tls;
  b_b = true;
  if (a.size(1) != 0) {
    boolean_T exitg1;
    plast = 0;
    nx = 0;
    exitg1 = false;
    while ((!exitg1) && (nx < 4)) {
      int32_T i;
      if (iv[nx] <= 2) {
        i = a.size(iv[nx] - 1);
      } else {
        i = 1;
      }
      if (i != 1) {
        if (plast > iv[nx]) {
          b_b = false;
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
  if (b_b) {
    st.site = &ob_emlrtRSI;
    nx = a.size(1) << 2;
    plast = 4;
    if (a.size(1) > 4) {
      plast = a.size(1);
    }
    if (a.size(1) > muIntScalarMax_sint32(nx, plast)) {
      emlrtErrorWithMessageIdR2018a(
          &st, &c_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    b.set_size(&y_emlrtRTEI, &sp, a.size(1), 4);
    for (int32_T k{0}; k < nx; k++) {
      b[k] = a[k];
    }
  } else {
    st.site = &pb_emlrtRSI;
    plast = a.size(1) << 2;
    nx = 4;
    if (a.size(1) > 4) {
      nx = a.size(1);
    }
    if (a.size(1) > muIntScalarMax_sint32(plast, nx)) {
      emlrtErrorWithMessageIdR2018a(
          &st, &c_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    plast = a.size(1);
    b.set_size(&y_emlrtRTEI, &sp, a.size(1), 4);
    for (int32_T k{0}; k < plast; k++) {
      b[k] = a[4 * k];
      b[k + b.size(0)] = a[4 * k + 1];
      b[k + b.size(0) * 2] = a[4 * k + 2];
      b[k + b.size(0) * 3] = a[4 * k + 3];
    }
  }
}

void d_permute(const emlrtStack &sp, const array<real32_T, 2U> &a,
               array<real32_T, 2U> &b)
{
  static const int8_T iv[4]{2, 1, 3, 4};
  emlrtStack st;
  int32_T n;
  int32_T nx;
  int32_T plast;
  int16_T subsa_idx_1;
  boolean_T b_b;
  st.prev = &sp;
  st.tls = sp.tls;
  b_b = true;
  if (a.size(0) != 0) {
    boolean_T exitg1;
    plast = 0;
    nx = 0;
    exitg1 = false;
    while ((!exitg1) && (nx < 4)) {
      if (iv[nx] <= 2) {
        n = a.size(iv[nx] - 1);
      } else {
        n = 1;
      }
      if (n != 1) {
        if (plast > iv[nx]) {
          b_b = false;
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
  if (b_b) {
    st.site = &ob_emlrtRSI;
    nx = a.size(0) << 2;
    plast = a.size(0);
    if (a.size(0) < 4) {
      plast = 4;
    }
    if (a.size(0) > muIntScalarMax_sint32(nx, plast)) {
      emlrtErrorWithMessageIdR2018a(
          &st, &c_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    b.set_size(&y_emlrtRTEI, &sp, 4, a.size(0));
    for (int32_T k{0}; k < nx; k++) {
      b[k] = a[k];
    }
  } else {
    st.site = &pb_emlrtRSI;
    plast = a.size(0) << 2;
    nx = a.size(0);
    n = a.size(0);
    if (a.size(0) < 4) {
      n = 4;
    }
    if (a.size(0) > muIntScalarMax_sint32(plast, n)) {
      emlrtErrorWithMessageIdR2018a(
          &st, &c_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    b.set_size(&y_emlrtRTEI, &sp, 4, a.size(0));
    for (int32_T k{0}; k < 4; k++) {
      if (nx - 1 >= 0) {
        subsa_idx_1 = static_cast<int16_T>(k + 1);
      }
      for (int32_T b_k{0}; b_k < nx; b_k++) {
        b[(subsa_idx_1 + 4 * b_k) - 1] = a[b_k + a.size(0) * (subsa_idx_1 - 1)];
      }
    }
  }
}

void permute(const emlrtStack &sp, const array<real32_T, 3U> &a,
             array<real32_T, 3U> &b)
{
  static const int8_T iv[4]{2, 1, 3, 4};
  int32_T k;
  int32_T plast;
  uint8_T subsa_idx_1;
  uint8_T subsa_idx_2;
  boolean_T b_b;
  b_b = true;
  if ((a.size(0) != 0) && (a.size(1) != 0)) {
    boolean_T exitg1;
    plast = 0;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 4)) {
      int32_T i;
      if (iv[k] <= 3) {
        i = a.size(iv[k] - 1);
      } else {
        i = 1;
      }
      if (i != 1) {
        if (plast > iv[k]) {
          b_b = false;
          exitg1 = true;
        } else {
          plast = iv[k];
          k++;
        }
      } else {
        k++;
      }
    }
  }
  if (b_b) {
    b.set_size(&y_emlrtRTEI, &sp, a.size(1), a.size(0), 144);
    plast = a.size(0) * a.size(1) * 144;
    for (int32_T b_k{0}; b_k < plast; b_k++) {
      b[b_k] = a[b_k];
    }
  } else {
    plast = a.size(1);
    k = a.size(0);
    b.set_size(&y_emlrtRTEI, &sp, a.size(1), a.size(0), 144);
    for (int32_T b_k{0}; b_k < 144; b_k++) {
      for (int32_T c_k{0}; c_k < plast; c_k++) {
        if (a.size(0) - 1 >= 0) {
          subsa_idx_1 = static_cast<uint8_T>(c_k + 1);
          subsa_idx_2 = static_cast<uint8_T>(b_k + 1);
        }
        for (int32_T d_k{0}; d_k < k; d_k++) {
          b[((subsa_idx_1 + b.size(0) * d_k) +
             b.size(0) * b.size(1) * (subsa_idx_2 - 1)) -
            1] = a[(d_k + a.size(0) * (subsa_idx_1 - 1)) +
                   a.size(0) * a.size(1) * (subsa_idx_2 - 1)];
        }
      }
    }
  }
}

void permute(const emlrtStack &sp, const array<real32_T, 2U> &a,
             array<real32_T, 2U> &b)
{
  static const int8_T iv[4]{2, 1, 3, 4};
  emlrtStack st;
  int32_T n;
  int32_T nx;
  int32_T plast;
  int16_T subsa_idx_1;
  boolean_T b_b;
  st.prev = &sp;
  st.tls = sp.tls;
  b_b = true;
  if (a.size(0) != 0) {
    boolean_T exitg1;
    plast = 0;
    nx = 0;
    exitg1 = false;
    while ((!exitg1) && (nx < 4)) {
      if (iv[nx] <= 2) {
        n = a.size(iv[nx] - 1);
      } else {
        n = 1;
      }
      if (n != 1) {
        if (plast > iv[nx]) {
          b_b = false;
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
  if (b_b) {
    st.site = &ob_emlrtRSI;
    nx = a.size(0) * 144;
    plast = a.size(0);
    if (a.size(0) < 144) {
      plast = 144;
    }
    if (a.size(0) > muIntScalarMax_sint32(nx, plast)) {
      emlrtErrorWithMessageIdR2018a(
          &st, &c_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    b.set_size(&y_emlrtRTEI, &sp, 144, a.size(0));
    for (int32_T k{0}; k < nx; k++) {
      b[k] = a[k];
    }
  } else {
    st.site = &pb_emlrtRSI;
    plast = a.size(0) * 144;
    nx = a.size(0);
    n = a.size(0);
    if (a.size(0) < 144) {
      n = 144;
    }
    if (a.size(0) > muIntScalarMax_sint32(plast, n)) {
      emlrtErrorWithMessageIdR2018a(
          &st, &c_emlrtRTEI, "Coder:toolbox:reshape_emptyReshapeLimit",
          "Coder:toolbox:reshape_emptyReshapeLimit", 0);
    }
    b.set_size(&y_emlrtRTEI, &sp, 144, a.size(0));
    for (int32_T k{0}; k < 144; k++) {
      if (nx - 1 >= 0) {
        subsa_idx_1 = static_cast<int16_T>(k + 1);
      }
      for (int32_T b_k{0}; b_k < nx; b_k++) {
        b[(subsa_idx_1 + 144 * b_k) - 1] =
            a[b_k + a.size(0) * (subsa_idx_1 - 1)];
      }
    }
  }
}

} // namespace coder

// End of code generation (permute.cpp)
