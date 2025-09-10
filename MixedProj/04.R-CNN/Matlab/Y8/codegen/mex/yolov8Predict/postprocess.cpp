//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// postprocess.cpp
//
// Code generation for function 'postprocess'
//

// Include files
#include "postprocess.h"
#include "extractDetections.h"
#include "postProcessYOLOv8.h"
#include "rt_nonfinite.h"
#include "yolov8Predict_data.h"
#include "yolov8Predict_internal_types.h"
#include "yolov8Predict_types.h"
#include "yolov8Transform.h"
#include "coder_array.h"
#include <xmmintrin.h>

// Variable Definitions
static emlrtRSInfo w_emlrtRSI{
    8,             // lineNo
    "postprocess", // fcnName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\postprocess.m" // pathName
};

static emlrtRSInfo x_emlrtRSI{
    11,            // lineNo
    "postprocess", // fcnName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\postprocess.m" // pathName
};

static emlrtRSInfo y_emlrtRSI{
    15,            // lineNo
    "postprocess", // fcnName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\postprocess.m" // pathName
};

static emlrtRSInfo ab_emlrtRSI{
    16,            // lineNo
    "postprocess", // fcnName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\postprocess.m" // pathName
};

static emlrtRSInfo bb_emlrtRSI{
    19,            // lineNo
    "postprocess", // fcnName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\postprocess.m" // pathName
};

static emlrtRSInfo cb_emlrtRSI{
    20,            // lineNo
    "postprocess", // fcnName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\postprocess.m" // pathName
};

static emlrtECInfo emlrtECI{
    -1,               // nDims
    28,               // lineNo
    1,                // colNo
    "xywhToX1Y1X2Y2", // fName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\postprocess.m" // pName
};

static emlrtECInfo b_emlrtECI{
    -1,               // nDims
    29,               // lineNo
    1,                // colNo
    "xywhToX1Y1X2Y2", // fName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\postprocess.m" // pName
};

static emlrtECInfo c_emlrtECI{
    -1,               // nDims
    36,               // lineNo
    1,                // colNo
    "x1y1x2y2ToXYWH", // fName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\postprocess.m" // pName
};

static emlrtECInfo d_emlrtECI{
    -1,               // nDims
    37,               // lineNo
    1,                // colNo
    "x1y1x2y2ToXYWH", // fName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\postprocess.m" // pName
};

static emlrtRTEInfo s_emlrtRTEI{
    11,            // lineNo
    15,            // colNo
    "postprocess", // fName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\postprocess.m" // pName
};

// Function Definitions
namespace helper {
int32_T b_postprocess(yolov8PredictStackData *SD, const emlrtStack &sp,
                      const coder::dlarray outFeatureMaps[3],
                      coder::array<real32_T, 2U> &bboxes,
                      real32_T scores_data[],
                      coder::array<real_T, 1U> &labelIds)
{
  __m128 r;
  __m128 r1;
  coder::array<real32_T, 2U> bboxesTmp;
  coder::array<real32_T, 2U> box;
  coder::array<real32_T, 2U> cls;
  coder::array<real32_T, 2U> predictions;
  emlrtStack st;
  int32_T bboxesTmp_size;
  int32_T k;
  int32_T loop_ub;
  int32_T scalarLB;
  int32_T scores_size;
  int16_T ysize_idx_1;
  boolean_T exitg1;
  st.prev = &sp;
  st.tls = sp.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  //  The postprocess function applies postprocessing on the generated feature
  //  maps and returns bounding boxes, detection scores and labels.
  //  Copyright 2024 The MathWorks, Inc.
  //  Transform outFeatureMaps to box [x_center y_center w h] and class scores
  st.site = &w_emlrtRSI;
  yolov8Transform(st, outFeatureMaps, box, cls);
  //  Map network predictions to anchor girds.
  st.site = &x_emlrtRSI;
  ysize_idx_1 = static_cast<int16_T>(box.size(1));
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((k != 0) && (ysize_idx_1 != box.size(1))) {
      emlrtErrorWithMessageIdR2018a(
          &st, &e_emlrtRTEI, "Coder:MATLAB:catenate_dimensionMismatch",
          "Coder:MATLAB:catenate_dimensionMismatch", 0);
    } else {
      k++;
    }
  }
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((k != 0) && (ysize_idx_1 != cls.size(1))) {
      emlrtErrorWithMessageIdR2018a(
          &st, &e_emlrtRTEI, "Coder:MATLAB:catenate_dimensionMismatch",
          "Coder:MATLAB:catenate_dimensionMismatch", 0);
    } else {
      k++;
    }
  }
  loop_ub = box.size(1);
  predictions.set_size(&s_emlrtRTEI, &st, box.size(0) + 80, box.size(1));
  for (int32_T b_k{0}; b_k < loop_ub; b_k++) {
    k = box.size(0);
    for (int32_T j{0}; j < k; j++) {
      predictions[j + predictions.size(0) * b_k] = box[j + box.size(0) * b_k];
    }
    if (box.size(0) - 1 < 0) {
      k = -1;
    } else {
      k = box.size(0) + -1;
    }
    for (int32_T j{0}; j < 80; j++) {
      predictions[((k + j) + predictions.size(0) * b_k) + 1] =
          cls[j + 80 * b_k];
    }
  }
  //  Extract detections from predictions.
  st.site = &y_emlrtRSI;
  scores_size = b_extractDetections(SD, st, predictions, bboxesTmp, scores_data,
                                    labelIds);
  st.site = &ab_emlrtRSI;
  //  Convert [x y w h] box to [x1 y1 x2 y2]. Input and output
  //  boxes are in pixel coordinates. boxes is an M-by-4
  //  matrix.
  loop_ub = bboxesTmp.size(0);
  emlrtSubAssignSizeCheckR2012b(bboxesTmp.size(), 1, bboxesTmp.size(), 1,
                                &emlrtECI, &st);
  bboxesTmp_size = bboxesTmp.size(0);
  scalarLB = (bboxesTmp.size(0) / 4) << 2;
  k = scalarLB - 4;
  for (int32_T j{0}; j <= k; j += 4) {
    r = _mm_loadu_ps(&bboxesTmp[j]);
    r1 = _mm_loadu_ps(&bboxesTmp[j + bboxesTmp.size(0) * 2]);
    _mm_storeu_ps(&SD->f9.bboxesTmp_data[j],
                  _mm_sub_ps(_mm_add_ps(r, r1), _mm_set1_ps(1.0F)));
  }
  for (int32_T j{scalarLB}; j < loop_ub; j++) {
    SD->f9.bboxesTmp_data[j] =
        (bboxesTmp[j] + bboxesTmp[j + bboxesTmp.size(0) * 2]) - 1.0F;
  }
  for (int32_T j{0}; j < bboxesTmp_size; j++) {
    bboxesTmp[j + bboxesTmp.size(0) * 2] = SD->f9.bboxesTmp_data[j];
  }
  emlrtSubAssignSizeCheckR2012b(bboxesTmp.size(), 1, bboxesTmp.size(), 1,
                                &b_emlrtECI, &st);
  bboxesTmp_size = bboxesTmp.size(0);
  k = scalarLB - 4;
  for (int32_T j{0}; j <= k; j += 4) {
    r = _mm_loadu_ps(&bboxesTmp[j + bboxesTmp.size(0)]);
    r1 = _mm_loadu_ps(&bboxesTmp[j + bboxesTmp.size(0) * 3]);
    _mm_storeu_ps(&SD->f9.bboxesTmp_data[j],
                  _mm_sub_ps(_mm_add_ps(r, r1), _mm_set1_ps(1.0F)));
  }
  for (int32_T j{scalarLB}; j < loop_ub; j++) {
    SD->f9.bboxesTmp_data[j] = (bboxesTmp[j + bboxesTmp.size(0)] +
                                bboxesTmp[j + bboxesTmp.size(0) * 3]) -
                               1.0F;
  }
  for (int32_T j{0}; j < bboxesTmp_size; j++) {
    bboxesTmp[j + bboxesTmp.size(0) * 3] = SD->f9.bboxesTmp_data[j];
  }
  //  Map predictions back to original dimension.
  st.site = &bb_emlrtRSI;
  postProcessYOLOv8(st, bboxesTmp, bboxes);
  st.site = &cb_emlrtRSI;
  //  Convert [x1 y1 x2 y2] boxes into [x y w h] format. Input and
  //  output boxes are in pixel coordinates. boxes is an M-by-4
  //  matrix.
  loop_ub = bboxes.size(0);
  emlrtSubAssignSizeCheckR2012b(bboxes.size(), 1, bboxes.size(), 1, &c_emlrtECI,
                                &st);
  bboxesTmp_size = bboxes.size(0);
  scalarLB = (bboxes.size(0) / 4) << 2;
  k = scalarLB - 4;
  for (int32_T j{0}; j <= k; j += 4) {
    r = _mm_loadu_ps(&bboxes[j + bboxes.size(0) * 2]);
    r1 = _mm_loadu_ps(&bboxes[j]);
    _mm_storeu_ps(&SD->f9.bboxesTmp_data[j],
                  _mm_add_ps(_mm_sub_ps(r, r1), _mm_set1_ps(1.0F)));
  }
  for (int32_T j{scalarLB}; j < loop_ub; j++) {
    SD->f9.bboxesTmp_data[j] =
        (bboxes[j + bboxes.size(0) * 2] - bboxes[j]) + 1.0F;
  }
  for (int32_T j{0}; j < bboxesTmp_size; j++) {
    bboxes[j + bboxes.size(0) * 2] = SD->f9.bboxesTmp_data[j];
  }
  emlrtSubAssignSizeCheckR2012b(bboxes.size(), 1, bboxes.size(), 1, &d_emlrtECI,
                                &st);
  bboxesTmp_size = bboxes.size(0);
  k = scalarLB - 4;
  for (int32_T j{0}; j <= k; j += 4) {
    r = _mm_loadu_ps(&bboxes[j + bboxes.size(0) * 3]);
    r1 = _mm_loadu_ps(&bboxes[j + bboxes.size(0)]);
    _mm_storeu_ps(&SD->f9.bboxesTmp_data[j],
                  _mm_add_ps(_mm_sub_ps(r, r1), _mm_set1_ps(1.0F)));
  }
  for (int32_T j{scalarLB}; j < loop_ub; j++) {
    SD->f9.bboxesTmp_data[j] =
        (bboxes[j + bboxes.size(0) * 3] - bboxes[j + bboxes.size(0)]) + 1.0F;
  }
  for (int32_T j{0}; j < bboxesTmp_size; j++) {
    bboxes[j + bboxes.size(0) * 3] = SD->f9.bboxesTmp_data[j];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
  return scores_size;
}

} // namespace helper

// End of code generation (postprocess.cpp)
