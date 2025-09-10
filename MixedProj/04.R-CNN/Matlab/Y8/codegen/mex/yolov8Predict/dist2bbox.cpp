//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// dist2bbox.cpp
//
// Code generation for function 'dist2bbox'
//

// Include files
#include "dist2bbox.h"
#include "div.h"
#include "rt_nonfinite.h"
#include "yolov8Predict_data.h"
#include "coder_array.h"
#include <xmmintrin.h>

// Variable Definitions
static emlrtRSInfo qc_emlrtRSI{
    18,          // lineNo
    "dist2bbox", // fcnName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\dist2bbox.m" // pathName
};

static emlrtRSInfo rc_emlrtRSI{
    41,    // lineNo
    "cat", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m" // pathName
};

static emlrtRSInfo sc_emlrtRSI{
    65,         // lineNo
    "cat_impl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m" // pathName
};

static emlrtRTEInfo g_emlrtRTEI{
    225,                   // lineNo
    27,                    // colNo
    "check_non_axis_size", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m" // pName
};

static emlrtECInfo g_emlrtECI{
    2,           // nDims
    15,          // lineNo
    10,          // colNo
    "dist2bbox", // fName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\dist2bbox.m" // pName
};

static emlrtECInfo h_emlrtECI{
    2,           // nDims
    14,          // lineNo
    12,          // colNo
    "dist2bbox", // fName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\dist2bbox.m" // pName
};

static emlrtECInfo i_emlrtECI{
    2,           // nDims
    10,          // lineNo
    8,           // colNo
    "dist2bbox", // fName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\dist2bbox.m" // pName
};

static emlrtRSInfo ue_emlrtRSI{
    15,          // lineNo
    "dist2bbox", // fcnName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\dist2bbox.m" // pathName
};

static emlrtRSInfo we_emlrtRSI{
    11,          // lineNo
    "dist2bbox", // fcnName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\dist2bbox.m" // pathName
};

static emlrtRSInfo xe_emlrtRSI{
    10,          // lineNo
    "dist2bbox", // fcnName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\dist2bbox.m" // pathName
};

static emlrtRTEInfo eb_emlrtRTEI{
    1,           // lineNo
    22,          // colNo
    "dist2bbox", // fName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\dist2bbox.m" // pName
};

static emlrtRTEInfo mb_emlrtRTEI{
    15,          // lineNo
    5,           // colNo
    "dist2bbox", // fName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\dist2bbox.m" // pName
};

static emlrtRTEInfo ob_emlrtRTEI{
    11,          // lineNo
    1,           // colNo
    "dist2bbox", // fName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\dist2bbox.m" // pName
};

static emlrtRTEInfo pb_emlrtRTEI{
    10,          // lineNo
    1,           // colNo
    "dist2bbox", // fName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\dist2bbox.m" // pName
};

// Function Declarations
static void binary_expand_op_3(const emlrtStack &sp,
                               coder::array<real32_T, 2U> &in1,
                               const coder::array<real_T, 2U> &in2,
                               const coder::array<real32_T, 2U> &in3);

static void binary_expand_op_4(const emlrtStack &sp,
                               coder::array<real32_T, 2U> &in1,
                               const coder::array<real_T, 2U> &in2,
                               const coder::array<real32_T, 2U> &in3);

static void minus(const emlrtStack &sp, coder::array<real32_T, 2U> &in1,
                  const coder::array<real32_T, 2U> &in2);

// Function Definitions
static void binary_expand_op_3(const emlrtStack &sp,
                               coder::array<real32_T, 2U> &in1,
                               const coder::array<real_T, 2U> &in2,
                               const coder::array<real32_T, 2U> &in3)
{
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  in1.set_size(&ob_emlrtRTEI, &sp, 2, in1.size(1));
  if (in3.size(1) == 1) {
    loop_ub = in2.size(1);
  } else {
    loop_ub = in3.size(1);
  }
  in1.set_size(&ob_emlrtRTEI, &sp, in1.size(0), loop_ub);
  stride_0_1 = (in2.size(1) != 1);
  stride_1_1 = (in3.size(1) != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (int32_T i{0}; i < loop_ub; i++) {
    in1[2 * i] = static_cast<real32_T>(in2[2 * aux_0_1]) + in3[4 * aux_1_1 + 2];
    in1[2 * i + 1] =
        static_cast<real32_T>(in2[2 * aux_0_1 + 1]) + in3[4 * aux_1_1 + 3];
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
}

static void binary_expand_op_4(const emlrtStack &sp,
                               coder::array<real32_T, 2U> &in1,
                               const coder::array<real_T, 2U> &in2,
                               const coder::array<real32_T, 2U> &in3)
{
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  in1.set_size(&pb_emlrtRTEI, &sp, 2, in1.size(1));
  if (in3.size(1) == 1) {
    loop_ub = in2.size(1);
  } else {
    loop_ub = in3.size(1);
  }
  in1.set_size(&pb_emlrtRTEI, &sp, in1.size(0), loop_ub);
  stride_0_1 = (in2.size(1) != 1);
  stride_1_1 = (in3.size(1) != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (int32_T i{0}; i < loop_ub; i++) {
    in1[2 * i] = static_cast<real32_T>(in2[2 * aux_0_1]) - in3[4 * aux_1_1];
    in1[2 * i + 1] =
        static_cast<real32_T>(in2[2 * aux_0_1 + 1]) - in3[4 * aux_1_1 + 1];
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
}

static void minus(const emlrtStack &sp, coder::array<real32_T, 2U> &in1,
                  const coder::array<real32_T, 2U> &in2)
{
  coder::array<real32_T, 2U> b_in1;
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  if (in2.size(1) == 1) {
    loop_ub = in1.size(1);
  } else {
    loop_ub = in2.size(1);
  }
  b_in1.set_size(&mb_emlrtRTEI, &sp, 2, loop_ub);
  stride_0_1 = (in1.size(1) != 1);
  stride_1_1 = (in2.size(1) != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (int32_T i{0}; i < loop_ub; i++) {
    b_in1[2 * i] = in1[2 * aux_0_1] - in2[2 * aux_1_1];
    b_in1[2 * i + 1] = in1[2 * aux_0_1 + 1] - in2[2 * aux_1_1 + 1];
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  in1.set_size(&mb_emlrtRTEI, &sp, 2, loop_ub);
  for (int32_T i{0}; i < loop_ub; i++) {
    in1[2 * i] = b_in1[2 * i];
    stride_0_1 = 2 * i + 1;
    in1[stride_0_1] = b_in1[stride_0_1];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

namespace helper {
void dist2bbox(const emlrtStack &sp, const coder::array<real32_T, 2U> &distance,
               const coder::array<real_T, 2U> &anchorGrid,
               coder::array<real32_T, 2U> &boxesXYWH)
{
  __m128 r;
  __m128 r1;
  coder::array<real32_T, 2U> cxy;
  coder::array<real32_T, 2U> x1y1;
  coder::array<real32_T, 2U> x2y2;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T b_loop_ub;
  int32_T loop_ub;
  int32_T vectorUB;
  int8_T input_sizes_idx_0;
  int8_T sizes_idx_0;
  boolean_T empty_non_axis_sizes;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  //  Transform distance(ltrb) to box(xywh or xyxy)
  //  matrix divided into two along dim 1
  loop_ub = anchorGrid.size(1);
  if ((anchorGrid.size(1) != distance.size(1)) &&
      ((anchorGrid.size(1) != 1) && (distance.size(1) != 1))) {
    emlrtDimSizeImpxCheckR2021b(anchorGrid.size(1), distance.size(1),
                                &i_emlrtECI, (emlrtConstCTX)&sp);
  }
  if (anchorGrid.size(1) == distance.size(1)) {
    x1y1.set_size(&eb_emlrtRTEI, &sp, 2, anchorGrid.size(1));
    for (int32_T i{0}; i < loop_ub; i++) {
      x1y1[2 * i] = static_cast<real32_T>(anchorGrid[2 * i]) - distance[4 * i];
      b_loop_ub = 2 * i + 1;
      x1y1[b_loop_ub] =
          static_cast<real32_T>(anchorGrid[b_loop_ub]) - distance[4 * i + 1];
    }
  } else {
    st.site = &xe_emlrtRSI;
    binary_expand_op_4(st, x1y1, anchorGrid, distance);
  }
  if (anchorGrid.size(1) == distance.size(1)) {
    x2y2.set_size(&eb_emlrtRTEI, &sp, 2, anchorGrid.size(1));
    for (int32_T i{0}; i < loop_ub; i++) {
      x2y2[2 * i] =
          static_cast<real32_T>(anchorGrid[2 * i]) + distance[4 * i + 2];
      b_loop_ub = 2 * i + 1;
      x2y2[b_loop_ub] =
          static_cast<real32_T>(anchorGrid[b_loop_ub]) + distance[4 * i + 3];
    }
  } else {
    st.site = &we_emlrtRSI;
    binary_expand_op_3(st, x2y2, anchorGrid, distance);
  }
  if ((x1y1.size(1) != x2y2.size(1)) &&
      ((x1y1.size(1) != 1) && (x2y2.size(1) != 1))) {
    emlrtDimSizeImpxCheckR2021b(x1y1.size(1), x2y2.size(1), &h_emlrtECI,
                                (emlrtConstCTX)&sp);
  }
  if (x1y1.size(1) == x2y2.size(1)) {
    cxy.set_size(&eb_emlrtRTEI, &sp, 2, x1y1.size(1));
    b_loop_ub = x1y1.size(1) << 1;
    loop_ub = (b_loop_ub / 4) << 2;
    vectorUB = loop_ub - 4;
    for (int32_T i{0}; i <= vectorUB; i += 4) {
      r = _mm_loadu_ps(&x1y1[i]);
      r1 = _mm_loadu_ps(&x2y2[i]);
      _mm_storeu_ps(&cxy[i], _mm_div_ps(_mm_add_ps(r, r1), _mm_set1_ps(2.0F)));
    }
    for (int32_T i{loop_ub}; i < b_loop_ub; i++) {
      cxy[i] = (x1y1[i] + x2y2[i]) / 2.0F;
    }
  } else {
    st.site = &ve_emlrtRSI;
    binary_expand_op_2(st, cxy, x1y1, x2y2);
  }
  if ((x2y2.size(1) != x1y1.size(1)) &&
      ((x2y2.size(1) != 1) && (x1y1.size(1) != 1))) {
    emlrtDimSizeImpxCheckR2021b(x2y2.size(1), x1y1.size(1), &g_emlrtECI,
                                (emlrtConstCTX)&sp);
  }
  if (x2y2.size(1) == x1y1.size(1)) {
    b_loop_ub = x2y2.size(1) << 1;
    x2y2.set_size(&eb_emlrtRTEI, &sp, 2, x2y2.size(1));
    loop_ub = (b_loop_ub / 4) << 2;
    vectorUB = loop_ub - 4;
    for (int32_T i{0}; i <= vectorUB; i += 4) {
      r = _mm_loadu_ps(&x2y2[i]);
      r1 = _mm_loadu_ps(&x1y1[i]);
      _mm_storeu_ps(&x2y2[i], _mm_sub_ps(r, r1));
    }
    for (int32_T i{loop_ub}; i < b_loop_ub; i++) {
      x2y2[i] = x2y2[i] - x1y1[i];
    }
  } else {
    st.site = &ue_emlrtRSI;
    minus(st, x2y2, x1y1);
  }
  st.site = &qc_emlrtRSI;
  b_st.site = &rc_emlrtRSI;
  if (cxy.size(1) != 0) {
    b_loop_ub = cxy.size(1);
  } else if (x2y2.size(1) != 0) {
    b_loop_ub = x2y2.size(1);
  } else {
    b_loop_ub = 0;
  }
  c_st.site = &sc_emlrtRSI;
  if ((cxy.size(1) != b_loop_ub) && (cxy.size(1) != 0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &g_emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  if ((x2y2.size(1) != b_loop_ub) && (x2y2.size(1) != 0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &g_emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  empty_non_axis_sizes = (b_loop_ub == 0);
  if (empty_non_axis_sizes || (cxy.size(1) != 0)) {
    input_sizes_idx_0 = 2;
  } else {
    input_sizes_idx_0 = 0;
  }
  if (empty_non_axis_sizes || (x2y2.size(1) != 0)) {
    sizes_idx_0 = 2;
  } else {
    sizes_idx_0 = 0;
  }
  vectorUB = input_sizes_idx_0;
  loop_ub = sizes_idx_0;
  boxesXYWH.set_size(&eb_emlrtRTEI, &b_st, input_sizes_idx_0 + sizes_idx_0,
                     b_loop_ub);
  for (int32_T i1{0}; i1 < b_loop_ub; i1++) {
    for (int32_T i{0}; i < vectorUB; i++) {
      boxesXYWH[i + boxesXYWH.size(0) * i1] = cxy[i + input_sizes_idx_0 * i1];
    }
    for (int32_T i{0}; i < loop_ub; i++) {
      boxesXYWH[(i + input_sizes_idx_0) + boxesXYWH.size(0) * i1] =
          x2y2[i + sizes_idx_0 * i1];
    }
  }
  //  xywh bbox
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

} // namespace helper

// End of code generation (dist2bbox.cpp)
