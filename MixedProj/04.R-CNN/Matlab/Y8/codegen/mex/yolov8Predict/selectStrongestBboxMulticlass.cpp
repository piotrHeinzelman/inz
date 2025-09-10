//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// selectStrongestBboxMulticlass.cpp
//
// Code generation for function 'selectStrongestBboxMulticlass'
//

// Include files
#include "selectStrongestBboxMulticlass.h"
#include "any1.h"
#include "indexShapeCheck.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "yolov8Predict_types.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <algorithm>
#include <cstring>
#include <xmmintrin.h>

// Variable Definitions
static emlrtRSInfo xc_emlrtRSI{
    12,                              // lineNo
    "selectStrongestBboxMulticlass", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\vision\\vision\\selectStrongestBboxMulticl"
    "ass.m" // pathName
};

static emlrtRSInfo yc_emlrtRSI{
    41,                              // lineNo
    "selectStrongestBboxMulticlass", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\vision\\vision\\selectStrongestBboxMulticl"
    "ass.m" // pathName
};

static emlrtRSInfo ad_emlrtRSI{
    52,                              // lineNo
    "selectStrongestBboxMulticlass", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\vision\\vision\\selectStrongestBboxMulticl"
    "ass.m" // pathName
};

static emlrtRSInfo bd_emlrtRSI{
    75,                              // lineNo
    "selectStrongestBboxMulticlass", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\vision\\vision\\selectStrongestBboxMulticl"
    "ass.m" // pathName
};

static emlrtRSInfo cd_emlrtRSI{
    158,            // lineNo
    "iParseInputs", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\vision\\vision\\selectStrongestBboxMulticl"
    "ass.m" // pathName
};

static emlrtRSInfo dd_emlrtRSI{
    129,                            // lineNo
    "iCheckInputBboxScoreAndLabel", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\vision\\vision\\selectStrongestBboxMulticl"
    "ass.m" // pathName
};

static emlrtRSInfo ed_emlrtRSI{
    130,                            // lineNo
    "iCheckInputBboxScoreAndLabel", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\vision\\vision\\selectStrongestBboxMulticl"
    "ass.m" // pathName
};

static emlrtRSInfo fd_emlrtRSI{
    82,                                                 // lineNo
    "selectStrongestValidation/checkInputBboxAndScore", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "detector\\selectStrongestValidation.m" // pathName
};

static emlrtRSInfo gd_emlrtRSI{
    86,                                                 // lineNo
    "selectStrongestValidation/checkInputBboxAndScore", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "detector\\selectStrongestValidation.m" // pathName
};

static emlrtRSInfo hd_emlrtRSI{
    96,                                                 // lineNo
    "selectStrongestValidation/checkInputBboxAndScore", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "detector\\selectStrongestValidation.m" // pathName
};

static emlrtRSInfo id_emlrtRSI{
    93,                   // lineNo
    "validateattributes", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\lang\\validateattributes"
    ".m" // pathName
};

static emlrtRSInfo jd_emlrtRSI{
    143,           // lineNo
    "iCheckLabel", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\vision\\vision\\selectStrongestBboxMulticl"
    "ass.m" // pathName
};

static emlrtRSInfo kd_emlrtRSI{
    37,     // lineNo
    "sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m" // pathName
};

static emlrtRSInfo me_emlrtRSI{
    89,                               // lineNo
    "iOverlapSuppressionAxisAligned", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\vision\\vision\\selectStrongestBboxMulticl"
    "ass.m" // pathName
};

static emlrtRSInfo ne_emlrtRSI{
    39,     // lineNo
    "find", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" // pathName
};

static emlrtRSInfo oe_emlrtRSI{
    138,        // lineNo
    "eml_find", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" // pathName
};

static emlrtRSInfo pe_emlrtRSI{
    376,                  // lineNo
    "find_first_indices", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" // pathName
};

static emlrtRSInfo qe_emlrtRSI{
    396,                  // lineNo
    "find_first_indices", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" // pathName
};

static emlrtRTEInfo h_emlrtRTEI{
    386,                  // lineNo
    1,                    // colNo
    "find_first_indices", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" // pName
};

static emlrtRTEInfo i_emlrtRTEI{
    132,                            // lineNo
    1,                              // colNo
    "iCheckInputBboxScoreAndLabel", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\vision\\vision\\selectStrongestBboxMulticl"
    "ass.m" // pName
};

static emlrtRTEInfo j_emlrtRTEI{
    93,                                                 // lineNo
    13,                                                 // colNo
    "selectStrongestValidation/checkInputBboxAndScore", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "detector\\selectStrongestValidation.m" // pName
};

static emlrtRTEInfo k_emlrtRTEI{
    96,                                                 // lineNo
    13,                                                 // colNo
    "selectStrongestValidation/checkInputBboxAndScore", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "detector\\selectStrongestValidation.m" // pName
};

static emlrtRTEInfo l_emlrtRTEI{
    14,               // lineNo
    37,               // colNo
    "validatefinite", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatefinite.m" // pName
};

static emlrtRTEInfo m_emlrtRTEI{
    15,             // lineNo
    19,             // colNo
    "validatesize", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatesize.m" // pName
};

static emlrtRTEInfo n_emlrtRTEI{
    13,                // lineNo
    37,                // colNo
    "validateinteger", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validateinteger.m" // pName
};

static emlrtBCInfo b_emlrtBCI{
    -1,                           // iFirst
    -1,                           // iLast
    148,                          // lineNo
    8,                            // colNo
    "",                           // aName
    "selectStrongestBboxCodegen", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "detector\\selectStrongestBboxCodegen.m", // pName
    0                                         // checkKind
};

static emlrtBCInfo c_emlrtBCI{
    -1,                           // iFirst
    -1,                           // iLast
    133,                          // lineNo
    62,                           // colNo
    "",                           // aName
    "selectStrongestBboxCodegen", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "detector\\selectStrongestBboxCodegen.m", // pName
    0                                         // checkKind
};

static emlrtBCInfo d_emlrtBCI{
    -1,                           // iFirst
    -1,                           // iLast
    133,                          // lineNo
    54,                           // colNo
    "",                           // aName
    "selectStrongestBboxCodegen", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "detector\\selectStrongestBboxCodegen.m", // pName
    0                                         // checkKind
};

static emlrtBCInfo e_emlrtBCI{
    -1,                           // iFirst
    -1,                           // iLast
    101,                          // lineNo
    60,                           // colNo
    "",                           // aName
    "selectStrongestBboxCodegen", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "detector\\selectStrongestBboxCodegen.m", // pName
    0                                         // checkKind
};

static emlrtBCInfo f_emlrtBCI{
    -1,                           // iFirst
    -1,                           // iLast
    101,                          // lineNo
    53,                           // colNo
    "",                           // aName
    "selectStrongestBboxCodegen", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "detector\\selectStrongestBboxCodegen.m", // pName
    0                                         // checkKind
};

static emlrtBCInfo g_emlrtBCI{
    -1,                           // iFirst
    -1,                           // iLast
    101,                          // lineNo
    40,                           // colNo
    "",                           // aName
    "selectStrongestBboxCodegen", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "detector\\selectStrongestBboxCodegen.m", // pName
    0                                         // checkKind
};

static emlrtBCInfo h_emlrtBCI{
    -1,                           // iFirst
    -1,                           // iLast
    101,                          // lineNo
    33,                           // colNo
    "",                           // aName
    "selectStrongestBboxCodegen", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "detector\\selectStrongestBboxCodegen.m", // pName
    0                                         // checkKind
};

static emlrtBCInfo i_emlrtBCI{
    -1,                           // iFirst
    -1,                           // iLast
    96,                           // lineNo
    59,                           // colNo
    "",                           // aName
    "selectStrongestBboxCodegen", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "detector\\selectStrongestBboxCodegen.m", // pName
    0                                         // checkKind
};

static emlrtBCInfo j_emlrtBCI{
    -1,                           // iFirst
    -1,                           // iLast
    96,                           // lineNo
    52,                           // colNo
    "",                           // aName
    "selectStrongestBboxCodegen", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "detector\\selectStrongestBboxCodegen.m", // pName
    0                                         // checkKind
};

static emlrtBCInfo k_emlrtBCI{
    -1,                           // iFirst
    -1,                           // iLast
    96,                           // lineNo
    39,                           // colNo
    "",                           // aName
    "selectStrongestBboxCodegen", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "detector\\selectStrongestBboxCodegen.m", // pName
    0                                         // checkKind
};

static emlrtBCInfo l_emlrtBCI{
    -1,                           // iFirst
    -1,                           // iLast
    96,                           // lineNo
    32,                           // colNo
    "",                           // aName
    "selectStrongestBboxCodegen", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "detector\\selectStrongestBboxCodegen.m", // pName
    0                                         // checkKind
};

static emlrtBCInfo m_emlrtBCI{
    -1,                           // iFirst
    -1,                           // iLast
    65,                           // lineNo
    53,                           // colNo
    "",                           // aName
    "selectStrongestBboxCodegen", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "detector\\selectStrongestBboxCodegen.m", // pName
    0                                         // checkKind
};

static emlrtBCInfo n_emlrtBCI{
    -1,                           // iFirst
    -1,                           // iLast
    54,                           // lineNo
    28,                           // colNo
    "",                           // aName
    "selectStrongestBboxCodegen", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "detector\\selectStrongestBboxCodegen.m", // pName
    0                                         // checkKind
};

static emlrtBCInfo o_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    45,                              // lineNo
    24,                              // colNo
    "",                              // aName
    "selectStrongestBboxMulticlass", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\vision\\vision\\selectStrongestBboxMulticl"
    "ass.m", // pName
    0        // checkKind
};

static emlrtBCInfo p_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    46,                              // lineNo
    25,                              // colNo
    "",                              // aName
    "selectStrongestBboxMulticlass", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\vision\\vision\\selectStrongestBboxMulticl"
    "ass.m", // pName
    0        // checkKind
};

static emlrtBCInfo q_emlrtBCI{
    -1,                           // iFirst
    -1,                           // iLast
    58,                           // lineNo
    20,                           // colNo
    "",                           // aName
    "selectStrongestBboxCodegen", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "detector\\selectStrongestBboxCodegen.m", // pName
    0                                         // checkKind
};

static emlrtBCInfo r_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    68,                              // lineNo
    7,                               // colNo
    "",                              // aName
    "selectStrongestBboxMulticlass", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\vision\\vision\\selectStrongestBboxMulticl"
    "ass.m", // pName
    0        // checkKind
};

static emlrtBCInfo s_emlrtBCI{
    -1,                           // iFirst
    -1,                           // iLast
    86,                           // lineNo
    24,                           // colNo
    "",                           // aName
    "selectStrongestBboxCodegen", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "detector\\selectStrongestBboxCodegen.m", // pName
    0                                         // checkKind
};

static emlrtBCInfo t_emlrtBCI{
    -1,                           // iFirst
    -1,                           // iLast
    90,                           // lineNo
    39,                           // colNo
    "",                           // aName
    "selectStrongestBboxCodegen", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "detector\\selectStrongestBboxCodegen.m", // pName
    0                                         // checkKind
};

static emlrtBCInfo u_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    70,                              // lineNo
    21,                              // colNo
    "",                              // aName
    "selectStrongestBboxMulticlass", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\vision\\vision\\selectStrongestBboxMulticl"
    "ass.m", // pName
    0        // checkKind
};

static emlrtBCInfo v_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    71,                              // lineNo
    23,                              // colNo
    "",                              // aName
    "selectStrongestBboxMulticlass", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\vision\\vision\\selectStrongestBboxMulticl"
    "ass.m", // pName
    0        // checkKind
};

static emlrtBCInfo w_emlrtBCI{
    -1,                              // iFirst
    -1,                              // iLast
    72,                              // lineNo
    23,                              // colNo
    "",                              // aName
    "selectStrongestBboxMulticlass", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\vision\\vision\\selectStrongestBboxMulticl"
    "ass.m", // pName
    0        // checkKind
};

static emlrtBCInfo x_emlrtBCI{
    -1,                           // iFirst
    -1,                           // iLast
    139,                          // lineNo
    24,                           // colNo
    "",                           // aName
    "selectStrongestBboxCodegen", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\vision\\vision\\+vision\\+internal\\+"
    "detector\\selectStrongestBboxCodegen.m", // pName
    0                                         // checkKind
};

static emlrtRTEInfo fb_emlrtRTEI{
    2,                               // lineNo
    5,                               // colNo
    "selectStrongestBboxMulticlass", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\vision\\vision\\selectStrongestBboxMulticl"
    "ass.m" // pName
};

// Function Definitions
namespace coder {
int32_T b_selectStrongestBboxMulticlass(
    yolov8PredictStackData *SD, const emlrtStack &sp,
    const array<real32_T, 2U> &bbox, const real32_T score_data[],
    int32_T score_size, const array<real_T, 1U> &label,
    array<real32_T, 2U> &selectedBbox, real32_T selectedScore_data[],
    array<real_T, 1U> &selectedLabel)
{
  static real_T dv[2]{0.0, 1.0};
  array<real32_T, 2U> b_bbox;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T d;
  int32_T idx;
  int32_T k;
  int32_T selectedScore_size;
  int16_T tmp_data[16320];
  boolean_T b_selectedIndex_data[16320];
  boolean_T selectedIndex_data[16320];
  boolean_T exitg1;
  boolean_T p;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  dv[0] = rtNaN;
  st.site = &xc_emlrtRSI;
  b_st.site = &cd_emlrtRSI;
  c_st.site = &dd_emlrtRSI;
  d_st.site = &fd_emlrtRSI;
  e_st.site = &id_emlrtRSI;
  p = true;
  idx = bbox.size(0) << 2;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= idx - 1)) {
    if ((!muSingleScalarIsInf(bbox[k])) && (!muSingleScalarIsNaN(bbox[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &e_st, &l_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:selectStrongestBboxMulticlass:expectedFinite", 3, 4, 21,
        "input number 1, bbox,");
  }
  d_st.site = &gd_emlrtRSI;
  e_st.site = &id_emlrtRSI;
  p = true;
  idx = 0;
  exitg1 = false;
  while ((!exitg1) && (idx <= score_size - 1)) {
    if ((!muSingleScalarIsInf(score_data[idx])) &&
        (!muSingleScalarIsNaN(score_data[idx]))) {
      idx++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &e_st, &l_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:selectStrongestBboxMulticlass:expectedFinite", 3, 4, 22,
        "input number 2, score,");
  }
  e_st.site = &id_emlrtRSI;
  p = true;
  for (int32_T b_k{0}; b_k < 2; b_k++) {
    if (p) {
      d = dv[b_k];
      if (!(d != d)) {
        if (b_k <= 0) {
          idx = score_size;
        } else {
          idx = 1;
        }
        if (!(d == idx)) {
          p = false;
        }
      }
    } else {
      p = false;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &e_st, &m_emlrtRTEI, "Coder:toolbox:ValidateattributesincorrectSize",
        "MATLAB:selectStrongestBboxMulticlass:incorrectSize", 3, 4, 22,
        "Input number 2, score,");
  }
  if (bbox.size(0) != score_size) {
    emlrtErrorWithMessageIdR2018a(&c_st, &j_emlrtRTEI,
                                  "vision:visionlib:unmatchedBboxAndScore",
                                  "vision:visionlib:unmatchedBboxAndScore", 0);
  }
  selectedScore_size = bbox.size(0);
  for (int32_T b_k{0}; b_k < selectedScore_size; b_k++) {
    selectedIndex_data[b_k] = (bbox[b_k + bbox.size(0) * 2] <= 0.0F);
  }
  d_st.site = &hd_emlrtRSI;
  if (any(selectedIndex_data, bbox.size(0))) {
    emlrtErrorWithMessageIdR2018a(&c_st, &k_emlrtRTEI,
                                  "vision:visionlib:invalidBboxHeightWidth",
                                  "vision:visionlib:invalidBboxHeightWidth", 0);
  } else {
    for (int32_T b_k{0}; b_k < selectedScore_size; b_k++) {
      selectedIndex_data[b_k] = (bbox[b_k + bbox.size(0) * 3] <= 0.0F);
    }
    d_st.site = &hd_emlrtRSI;
    if (any(selectedIndex_data, bbox.size(0))) {
      emlrtErrorWithMessageIdR2018a(
          &c_st, &k_emlrtRTEI, "vision:visionlib:invalidBboxHeightWidth",
          "vision:visionlib:invalidBboxHeightWidth", 0);
    }
  }
  c_st.site = &ed_emlrtRSI;
  d_st.site = &jd_emlrtRSI;
  e_st.site = &id_emlrtRSI;
  p = true;
  idx = 0;
  exitg1 = false;
  while ((!exitg1) && (idx <= label.size(0) - 1)) {
    if ((!muDoubleScalarIsInf(label[idx])) &&
        (!muDoubleScalarIsNaN(label[idx]))) {
      idx++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &e_st, &l_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:selectStrongestBboxMulticlass:expectedFinite", 3, 4, 22,
        "input number 3, label,");
  }
  e_st.site = &id_emlrtRSI;
  p = true;
  idx = 0;
  exitg1 = false;
  while ((!exitg1) && (idx <= label.size(0) - 1)) {
    if ((!muDoubleScalarIsInf(label[idx])) &&
        (!muDoubleScalarIsNaN(label[idx])) && (label[idx] == label[idx])) {
      idx++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &e_st, &n_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedInteger",
        "MATLAB:selectStrongestBboxMulticlass:expectedInteger", 3, 4, 22,
        "input number 3, label,");
  }
  e_st.site = &id_emlrtRSI;
  p = true;
  for (int32_T b_k{0}; b_k < 2; b_k++) {
    if (p) {
      d = dv[b_k];
      if (!(d != d)) {
        if (b_k <= 0) {
          idx = label.size(0);
        } else {
          idx = 1;
        }
        if (!(d == idx)) {
          p = false;
        }
      }
    } else {
      p = false;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &e_st, &m_emlrtRTEI, "Coder:toolbox:ValidateattributesincorrectSize",
        "MATLAB:selectStrongestBboxMulticlass:incorrectSize", 3, 4, 22,
        "Input number 3, label,");
  }
  if ((label.size(0) != 0) && (label.size(0) != bbox.size(0))) {
    emlrtErrorWithMessageIdR2018a(&b_st, &i_emlrtRTEI,
                                  "vision:visionlib:unmatchedBboxAndLabel",
                                  "vision:visionlib:unmatchedBboxAndLabel", 0);
  }
  if (bbox.size(0) == 0) {
    selectedBbox.set_size(&fb_emlrtRTEI, &sp, 0, 4);
    selectedScore_size = score_size;
    if (score_size - 1 >= 0) {
      std::copy(&score_data[0], &score_data[score_size],
                &selectedScore_data[0]);
    }
    idx = label.size(0);
    selectedLabel.set_size(&fb_emlrtRTEI, &sp, label.size(0));
    for (int32_T b_k{0}; b_k < idx; b_k++) {
      selectedLabel[b_k] = label[b_k];
    }
  } else {
    __m128 r;
    __m128 r1;
    int32_T ii_size;
    int16_T b_i;
    k = label.size(0);
    for (int32_T b_k{0}; b_k < k; b_k++) {
      SD->f7.inputLabel_data[b_k] = static_cast<real32_T>(label[b_k]);
    }
    st.site = &yc_emlrtRSI;
    if (score_size - 1 >= 0) {
      std::copy(&score_data[0], &score_data[score_size], &SD->f7.area_data[0]);
    }
    b_st.site = &kd_emlrtRSI;
    ii_size = internal::b_sort(SD, b_st, SD->f7.area_data, score_size,
                               SD->f7.ii_data);
    for (int32_T b_k{0}; b_k < ii_size; b_k++) {
      idx = SD->f7.ii_data[b_k];
      if ((idx < 1) || (idx > selectedScore_size)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, selectedScore_size, &o_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
    }
    for (int32_T b_k{0}; b_k < ii_size; b_k++) {
      idx = SD->f7.ii_data[b_k];
      if ((idx < 1) || (idx > k)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, k, &p_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      SD->f7.area_data[b_k] = SD->f7.inputLabel_data[idx - 1];
    }
    if (ii_size - 1 >= 0) {
      std::copy(&SD->f7.area_data[0], &SD->f7.area_data[ii_size],
                &SD->f7.inputLabel_data[0]);
    }
    st.site = &ad_emlrtRSI;
    b_bbox.set_size(&fb_emlrtRTEI, &st, ii_size, 4);
    for (int32_T b_k{0}; b_k < 4; b_k++) {
      for (int32_T i{0}; i < ii_size; i++) {
        b_bbox[i + b_bbox.size(0) * b_k] =
            bbox[(SD->f7.ii_data[i] + bbox.size(0) * b_k) - 1];
      }
    }
    b_st.site = &me_emlrtRSI;
    for (int32_T b_k{0}; b_k < ii_size; b_k++) {
      selectedIndex_data[b_k] = true;
    }
    k = (ii_size / 4) << 2;
    idx = k - 4;
    for (int32_T b_k{0}; b_k <= idx; b_k += 4) {
      r = _mm_loadu_ps(&b_bbox[b_k + b_bbox.size(0) * 2]);
      r1 = _mm_loadu_ps(&b_bbox[b_k + b_bbox.size(0) * 3]);
      _mm_storeu_ps(&SD->f7.area_data[b_k], _mm_mul_ps(r, r1));
    }
    for (int32_T b_k{k}; b_k < ii_size; b_k++) {
      SD->f7.area_data[b_k] =
          b_bbox[b_k + b_bbox.size(0) * 2] * b_bbox[b_k + b_bbox.size(0) * 3];
    }
    idx = k - 4;
    for (int32_T b_k{0}; b_k <= idx; b_k += 4) {
      r = _mm_loadu_ps(&b_bbox[b_k]);
      r1 = _mm_loadu_ps(&b_bbox[b_k + b_bbox.size(0) * 2]);
      _mm_storeu_ps(&SD->f7.x2_data[b_k], _mm_add_ps(r, r1));
    }
    for (int32_T b_k{k}; b_k < ii_size; b_k++) {
      SD->f7.x2_data[b_k] = b_bbox[b_k] + b_bbox[b_k + b_bbox.size(0) * 2];
    }
    idx = k - 4;
    for (int32_T b_k{0}; b_k <= idx; b_k += 4) {
      r = _mm_loadu_ps(&b_bbox[b_k + b_bbox.size(0)]);
      r1 = _mm_loadu_ps(&b_bbox[b_k + b_bbox.size(0) * 3]);
      _mm_storeu_ps(&SD->f7.y2_data[b_k], _mm_add_ps(r, r1));
    }
    for (int32_T b_k{k}; b_k < ii_size; b_k++) {
      SD->f7.y2_data[b_k] =
          b_bbox[b_k + b_bbox.size(0)] + b_bbox[b_k + b_bbox.size(0) * 3];
    }
    selectedScore_size = 1;
    for (int32_T i{0}; i < ii_size; i++) {
      selectedScore_size = i + 2;
      if (i + 1 > ii_size) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, ii_size, &n_emlrtBCI, &b_st);
      }
      if (muSingleScalarIsNaN(SD->f7.inputLabel_data[i])) {
        if (i + 1 > ii_size) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, ii_size, &q_emlrtBCI, &b_st);
        }
        selectedIndex_data[i] = false;
      } else {
        if (i + 1 > ii_size) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, ii_size, &m_emlrtBCI, &b_st);
        }
        if (selectedIndex_data[i]) {
          idx = 2;
        } else {
          idx = 1;
        }
        if (idx != 1) {
          k = ii_size - i;
          for (int32_T b_k{0}; b_k <= k - 2; b_k++) {
            idx = (i + b_k) + 2;
            if (idx > ii_size) {
              emlrtDynamicBoundsCheckR2012b(idx, 1, ii_size, &s_emlrtBCI,
                                            &b_st);
            }
            if (selectedIndex_data[idx - 1]) {
              if (idx > ii_size) {
                emlrtDynamicBoundsCheckR2012b(idx, 1, ii_size, &t_emlrtBCI,
                                              &b_st);
              }
              if (!(SD->f7.inputLabel_data[idx - 1] !=
                    SD->f7.inputLabel_data[i])) {
                real32_T width;
                if (i + 1 > ii_size) {
                  emlrtDynamicBoundsCheckR2012b(i + 1, 1, ii_size, &l_emlrtBCI,
                                                &b_st);
                }
                if (idx > ii_size) {
                  emlrtDynamicBoundsCheckR2012b(idx, 1, ii_size, &k_emlrtBCI,
                                                &b_st);
                }
                if (i + 1 > ii_size) {
                  emlrtDynamicBoundsCheckR2012b(i + 1, 1, ii_size, &j_emlrtBCI,
                                                &b_st);
                }
                if (idx > ii_size) {
                  emlrtDynamicBoundsCheckR2012b(idx, 1, ii_size, &i_emlrtBCI,
                                                &b_st);
                }
                width = muSingleScalarMin(SD->f7.x2_data[i],
                                          SD->f7.x2_data[idx - 1]) -
                        muSingleScalarMax(b_bbox[i], b_bbox[idx - 1]);
                if (!(width <= 0.0F)) {
                  real32_T height;
                  if (i + 1 > ii_size) {
                    emlrtDynamicBoundsCheckR2012b(i + 1, 1, ii_size,
                                                  &h_emlrtBCI, &b_st);
                  }
                  if (idx > ii_size) {
                    emlrtDynamicBoundsCheckR2012b(idx, 1, ii_size, &g_emlrtBCI,
                                                  &b_st);
                  }
                  if (i + 1 > ii_size) {
                    emlrtDynamicBoundsCheckR2012b(i + 1, 1, ii_size,
                                                  &f_emlrtBCI, &b_st);
                  }
                  if (idx > ii_size) {
                    emlrtDynamicBoundsCheckR2012b(idx, 1, ii_size, &e_emlrtBCI,
                                                  &b_st);
                  }
                  height =
                      muSingleScalarMin(SD->f7.y2_data[i],
                                        SD->f7.y2_data[idx - 1]) -
                      muSingleScalarMax(b_bbox[i + b_bbox.size(0)],
                                        b_bbox[(idx + b_bbox.size(0)) - 1]);
                  if (!(height <= 0.0F)) {
                    width *= height;
                    if (i + 1 > ii_size) {
                      emlrtDynamicBoundsCheckR2012b(i + 1, 1, ii_size,
                                                    &d_emlrtBCI, &b_st);
                    }
                    if (idx > ii_size) {
                      emlrtDynamicBoundsCheckR2012b(idx, 1, ii_size,
                                                    &c_emlrtBCI, &b_st);
                    }
                    if (width /
                            ((SD->f7.area_data[i] + SD->f7.area_data[idx - 1]) -
                             width) >
                        0.45) {
                      if (idx > ii_size) {
                        emlrtDynamicBoundsCheckR2012b(idx, 1, ii_size,
                                                      &x_emlrtBCI, &b_st);
                      }
                      selectedIndex_data[idx - 1] = false;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    if (selectedScore_size > ii_size) {
      k = 0;
      idx = 0;
    } else {
      if (selectedScore_size > ii_size) {
        emlrtDynamicBoundsCheckR2012b(selectedScore_size, 1, ii_size,
                                      &b_emlrtBCI, &b_st);
      }
      k = selectedScore_size - 1;
      idx = ii_size;
    }
    idx -= k;
    if (idx - 1 >= 0) {
      std::memset(&selectedIndex_data[k], 0,
                  static_cast<uint32_T>(idx) * sizeof(boolean_T));
    }
    for (int32_T b_k{0}; b_k < ii_size; b_k++) {
      idx = SD->f7.ii_data[b_k];
      if ((idx < 1) || (idx > ii_size)) {
        emlrtDynamicBoundsCheckR2012b(idx, 1, ii_size, &r_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
    }
    if (ii_size - 1 >= 0) {
      std::copy(&selectedIndex_data[0], &selectedIndex_data[ii_size],
                &b_selectedIndex_data[0]);
    }
    for (int32_T b_k{0}; b_k < ii_size; b_k++) {
      selectedIndex_data[SD->f7.ii_data[b_k] - 1] = b_selectedIndex_data[b_k];
    }
    selectedScore_size = 0;
    idx = 0;
    for (int32_T b_k{0}; b_k < ii_size; b_k++) {
      if (selectedIndex_data[b_k]) {
        selectedScore_size++;
        tmp_data[idx] = static_cast<int16_T>(b_k);
        idx++;
      }
    }
    selectedBbox.set_size(&fb_emlrtRTEI, &sp, selectedScore_size, 4);
    for (int32_T b_k{0}; b_k < 4; b_k++) {
      for (int32_T i{0}; i < selectedScore_size; i++) {
        b_i = tmp_data[i];
        if (b_i > bbox.size(0) - 1) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_i), 0,
                                        bbox.size(0) - 1, &u_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        selectedBbox[i + selectedBbox.size(0) * b_k] =
            bbox[b_i + bbox.size(0) * b_k];
      }
    }
    for (int32_T b_k{0}; b_k < selectedScore_size; b_k++) {
      b_i = tmp_data[b_k];
      if (b_i > score_size - 1) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_i), 0,
                                      score_size - 1, &v_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      selectedScore_data[b_k] = score_data[b_i];
    }
    selectedLabel.set_size(&fb_emlrtRTEI, &sp, selectedScore_size);
    for (int32_T b_k{0}; b_k < selectedScore_size; b_k++) {
      b_i = tmp_data[b_k];
      if (b_i > label.size(0) - 1) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_i), 0,
                                      label.size(0) - 1, &w_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      selectedLabel[b_k] = label[static_cast<int32_T>(b_i)];
    }
    st.site = &bd_emlrtRSI;
    b_st.site = &ne_emlrtRSI;
    c_st.site = &oe_emlrtRSI;
    idx = 0;
    d_st.site = &pe_emlrtRSI;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= ii_size - 1)) {
      if (selectedIndex_data[k]) {
        idx++;
        if (idx >= ii_size) {
          exitg1 = true;
        } else {
          k++;
        }
      } else {
        k++;
      }
    }
    if (idx > ii_size) {
      emlrtErrorWithMessageIdR2018a(&c_st, &h_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    if (ii_size != 1) {
      int32_T iv[2];
      iv[0] = 1;
      if (idx < 1) {
        iv[1] = 0;
      } else {
        iv[1] = idx;
      }
      d_st.site = &qe_emlrtRSI;
      internal::indexShapeCheck(d_st, ii_size, iv);
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
  return selectedScore_size;
}

} // namespace coder

// End of code generation (selectStrongestBboxMulticlass.cpp)
