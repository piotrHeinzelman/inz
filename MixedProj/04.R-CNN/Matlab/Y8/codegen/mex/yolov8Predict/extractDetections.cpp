//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// extractDetections.cpp
//
// Code generation for function 'extractDetections'
//

// Include files
#include "extractDetections.h"
#include "rt_nonfinite.h"
#include "selectStrongestBboxMulticlass.h"
#include "yolov8Predict_types.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <algorithm>
#include <cstring>
#include <emmintrin.h>
#include <xmmintrin.h>

// Variable Definitions
static emlrtRSInfo vc_emlrtRSI{
    22,                  // lineNo
    "extractDetections", // fcnName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\extractDetections.m" // pathName
};

static emlrtRSInfo wc_emlrtRSI{
    16,                  // lineNo
    "extractDetections", // fcnName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\extractDetections.m" // pathName
};

static emlrtBCInfo ab_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    4,                   // lineNo
    24,                  // colNo
    "predictions",       // aName
    "extractDetections", // fName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\extractDetections.m", // pName
    0                                      // checkKind
};

static emlrtBCInfo bb_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    9,                   // lineNo
    13,                  // colNo
    "pred",              // aName
    "extractDetections", // fName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\extractDetections.m", // pName
    0                                      // checkKind
};

static emlrtBCInfo cb_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    13,                  // lineNo
    14,                  // colNo
    "pred",              // aName
    "extractDetections", // fName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\extractDetections.m", // pName
    0                                      // checkKind
};

static emlrtECInfo o_emlrtECI{
    -1,                        // nDims
    29,                        // lineNo
    1,                         // colNo
    "iConvertCenterToTopLeft", // fName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\extractDetections.m" // pName
};

static emlrtECInfo p_emlrtECI{
    -1,                        // nDims
    28,                        // lineNo
    1,                         // colNo
    "iConvertCenterToTopLeft", // fName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\extractDetections.m" // pName
};

static emlrtBCInfo gb_emlrtBCI{
    -1,                        // iFirst
    -1,                        // iLast
    31,                        // lineNo
    8,                         // colNo
    "bboxes",                  // aName
    "iConvertCenterToTopLeft", // fName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\extractDetections.m", // pName
    0                                      // checkKind
};

static emlrtRTEInfo ib_emlrtRTEI{
    1,                   // lineNo
    37,                  // colNo
    "extractDetections", // fName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\extractDetections.m" // pName
};

// Function Definitions
namespace helper {
int32_T b_extractDetections(yolov8PredictStackData *SD, const emlrtStack &sp,
                            const coder::array<real32_T, 2U> &predictions,
                            coder::array<real32_T, 2U> &bboxes,
                            real32_T scores_data[],
                            coder::array<real_T, 1U> &labelIds)
{
  __m128 r1;
  __m128 r2;
  coder::array<real_T, 1U> idx;
  coder::array<real32_T, 2U> b_pred;
  coder::array<real32_T, 2U> bboxesTopLeft;
  coder::array<real32_T, 2U> pred;
  emlrtStack st;
  real_T dv[2];
  real_T dv1[2];
  int32_T b_loop_ub;
  int32_T loop_ub;
  int32_T maxval_data_tmp;
  int32_T n;
  int32_T scores_size;
  real32_T a;
  real32_T b;
  int16_T tmp_data[16320];
  int8_T idx_data[16320];
  boolean_T xc_data[16320];
  boolean_T p;
  st.prev = &sp;
  st.tls = sp.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  //  Filter predictions by confidence threshold
  loop_ub = predictions.size(0);
  if (predictions.size(0) < 1) {
    emlrtDynamicBoundsCheckR2012b(predictions.size(0), 1, predictions.size(0),
                                  &ab_emlrtBCI, (emlrtConstCTX)&sp);
  }
  scores_size = predictions.size(0) - 4;
  n = predictions.size(1);
  if (predictions.size(1) >= 1) {
    for (int32_T j{0}; j < n; j++) {
      maxval_data_tmp = predictions.size(0) * j;
      SD->f8.maxval_data[j] = predictions[maxval_data_tmp + 4];
      for (int32_T i{2}; i <= scores_size; i++) {
        a = SD->f8.maxval_data[j];
        b = predictions[(i + maxval_data_tmp) + 3];
        if (muSingleScalarIsNaN(b)) {
          p = false;
        } else if (muSingleScalarIsNaN(a)) {
          p = true;
        } else {
          p = (a < b);
        }
        if (p) {
          SD->f8.maxval_data[j] = b;
        }
      }
    }
  }
  for (int32_T i{0}; i < n; i++) {
    xc_data[i] = (SD->f8.maxval_data[i] > 0.5F);
  }
  //  candidates for each image
  //  TODO: Hardcoding now only one image
  //  INDEXING REQUIRED if multiple images
  pred.set_size(&ib_emlrtRTEI, &sp, predictions.size(1), predictions.size(0));
  for (int32_T i{0}; i < loop_ub; i++) {
    for (int32_T j{0}; j < n; j++) {
      pred[j + pred.size(0) * i] = predictions[i + predictions.size(0) * j];
    }
  }
  maxval_data_tmp = 0;
  scores_size = 0;
  for (int32_T i{0}; i < n; i++) {
    if (xc_data[i]) {
      maxval_data_tmp++;
      tmp_data[scores_size] = static_cast<int16_T>(i);
      scores_size++;
    }
  }
  b_pred.set_size(&ib_emlrtRTEI, &sp, maxval_data_tmp, predictions.size(0));
  for (int32_T i{0}; i < loop_ub; i++) {
    for (int32_T j{0}; j < maxval_data_tmp; j++) {
      int16_T b_i;
      b_i = tmp_data[j];
      if (b_i > pred.size(0) - 1) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_i), 0,
                                      pred.size(0) - 1, &bb_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      b_pred[j + b_pred.size(0) * i] = pred[b_i + pred.size(0) * i];
    }
  }
  b_loop_ub = b_pred.size(0);
  maxval_data_tmp = b_pred.size(1);
  pred.set_size(&ib_emlrtRTEI, &sp, b_pred.size(0), b_pred.size(1));
  scores_size = b_pred.size(0) * b_pred.size(1);
  if (scores_size - 1 >= 0) {
    std::copy(&b_pred[0], &b_pred[scores_size], &pred[0]);
  }
  //  box, class
  for (int32_T i{0}; i <= 78; i += 2) {
    __m128d r;
    dv[0] = i;
    dv[1] = static_cast<real_T>(i) + 1.0;
    r = _mm_loadu_pd(&dv[0]);
    _mm_storeu_pd(&dv1[0], _mm_add_pd(_mm_set1_pd(5.0), r));
    if ((static_cast<int32_T>(dv1[0]) < 1) ||
        (static_cast<int32_T>(dv1[0]) > maxval_data_tmp)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(dv1[0]), 1,
                                    maxval_data_tmp, &cb_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    if ((static_cast<int32_T>(dv1[1]) < 1) ||
        (static_cast<int32_T>(dv1[1]) > maxval_data_tmp)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(dv1[1]), 1,
                                    maxval_data_tmp, &cb_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
  }
  //  convert [x_c y_c w h] to [xTopLeft yTopLeft w h]
  bboxesTopLeft.set_size(&ib_emlrtRTEI, &sp, b_pred.size(0), 4);
  for (int32_T i{0}; i < 4; i++) {
    for (int32_T j{0}; j < b_loop_ub; j++) {
      bboxesTopLeft[j + bboxesTopLeft.size(0) * i] = pred[j + pred.size(0) * i];
    }
  }
  st.site = &wc_emlrtRSI;
  maxval_data_tmp = bboxesTopLeft.size(0);
  n = (bboxesTopLeft.size(0) / 4) << 2;
  scores_size = n - 4;
  for (int32_T j{0}; j <= scores_size; j += 4) {
    r1 = _mm_loadu_ps(&bboxesTopLeft[j + bboxesTopLeft.size(0) * 2]);
    _mm_storeu_ps(&SD->f8.maxval_data[j], _mm_div_ps(r1, _mm_set1_ps(2.0F)));
  }
  for (int32_T j{n}; j < maxval_data_tmp; j++) {
    SD->f8.maxval_data[j] = bboxesTopLeft[j + bboxesTopLeft.size(0) * 2] / 2.0F;
  }
  emlrtSubAssignSizeCheckR2012b(bboxesTopLeft.size(), 1, bboxesTopLeft.size(),
                                1, &p_emlrtECI, &st);
  scores_size = n - 4;
  for (int32_T j{0}; j <= scores_size; j += 4) {
    r1 = _mm_loadu_ps(&bboxesTopLeft[j]);
    r2 = _mm_loadu_ps(&SD->f8.maxval_data[j]);
    _mm_storeu_ps(&bboxesTopLeft[j],
                  _mm_add_ps(_mm_sub_ps(r1, r2), _mm_set1_ps(0.5F)));
  }
  for (int32_T j{n}; j < maxval_data_tmp; j++) {
    bboxesTopLeft[j] = (bboxesTopLeft[j] - SD->f8.maxval_data[j]) + 0.5F;
  }
  n = bboxesTopLeft.size(0);
  loop_ub = (bboxesTopLeft.size(0) / 4) << 2;
  scores_size = loop_ub - 4;
  for (int32_T j{0}; j <= scores_size; j += 4) {
    r1 = _mm_loadu_ps(&bboxesTopLeft[j + bboxesTopLeft.size(0) * 3]);
    _mm_storeu_ps(&SD->f8.maxval_data[j], _mm_div_ps(r1, _mm_set1_ps(2.0F)));
  }
  for (int32_T j{loop_ub}; j < n; j++) {
    SD->f8.maxval_data[j] = bboxesTopLeft[j + bboxesTopLeft.size(0) * 3] / 2.0F;
  }
  emlrtSubAssignSizeCheckR2012b(bboxesTopLeft.size(), 1, bboxesTopLeft.size(),
                                1, &o_emlrtECI, &st);
  scores_size = loop_ub - 4;
  for (int32_T j{0}; j <= scores_size; j += 4) {
    maxval_data_tmp = j + bboxesTopLeft.size(0);
    r1 = _mm_loadu_ps(&bboxesTopLeft[maxval_data_tmp]);
    r2 = _mm_loadu_ps(&SD->f8.maxval_data[j]);
    _mm_storeu_ps(&bboxesTopLeft[maxval_data_tmp],
                  _mm_add_ps(_mm_sub_ps(r1, r2), _mm_set1_ps(0.5F)));
  }
  for (int32_T j{loop_ub}; j < n; j++) {
    scores_size = j + bboxesTopLeft.size(0);
    bboxesTopLeft[scores_size] =
        (bboxesTopLeft[scores_size] - SD->f8.maxval_data[j]) + 0.5F;
  }
  scores_size = bboxesTopLeft.size(0) << 2;
  for (int32_T i{0}; i < scores_size; i++) {
    bboxesTopLeft[i] = muSingleScalarFloor(bboxesTopLeft[i]);
  }
  for (int32_T j{0}; j < scores_size; j++) {
    if (bboxesTopLeft[j] < 1.0F) {
      if (j > scores_size - 1) {
        emlrtDynamicBoundsCheckR2012b(j, 0, scores_size - 1, &gb_emlrtBCI, &st);
      }
      bboxesTopLeft[j] = 1.0F;
    }
  }
  scores_size = b_pred.size(0);
  if (b_loop_ub - 1 >= 0) {
    std::memset(&idx_data[0], 1,
                static_cast<uint32_T>(b_loop_ub) * sizeof(int8_T));
  }
  if (pred.size(0) >= 1) {
    for (int32_T i{0}; i < b_loop_ub; i++) {
      SD->f8.maxval_data[i] = pred[i + pred.size(0) * 4];
    }
    for (int32_T i{0}; i < 79; i++) {
      for (int32_T j{0}; j < b_loop_ub; j++) {
        a = pred[j + pred.size(0) * (i + 5)];
        if (muSingleScalarIsNaN(a)) {
          p = false;
        } else {
          b = SD->f8.maxval_data[j];
          if (muSingleScalarIsNaN(b)) {
            p = true;
          } else {
            p = (b < a);
          }
        }
        if (p) {
          SD->f8.maxval_data[j] = a;
          idx_data[j] = static_cast<int8_T>(i + 2);
        }
      }
    }
  }
  //  NMS
  idx.set_size(&ib_emlrtRTEI, &sp, b_pred.size(0));
  for (int32_T i{0}; i < b_loop_ub; i++) {
    idx[i] = idx_data[i];
  }
  st.site = &vc_emlrtRSI;
  scores_size = coder::b_selectStrongestBboxMulticlass(
      SD, st, bboxesTopLeft, SD->f8.maxval_data, scores_size, idx, bboxes,
      scores_data, labelIds);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
  return scores_size;
}

} // namespace helper

// End of code generation (extractDetections.cpp)
