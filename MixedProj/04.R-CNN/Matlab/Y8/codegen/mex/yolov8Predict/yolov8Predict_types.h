//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// yolov8Predict_types.h
//
// Code generation for function 'yolov8Predict'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "emlrt.h"

// Type Definitions
struct sortIdx {
  int32_T iwork_data[16320];
};

struct dlnetwork_predict {
  real32_T inputDataT_0_f1[1044480];
  real32_T outputData_f1[783360];
  real32_T outputDataAfterTranspose_f1[783360];
  real32_T outputData_f2[195840];
  real32_T outputDataAfterTranspose_f2[195840];
  real32_T outputData_f3[48960];
};

struct imresize {
  uint8_T APartialResize[792225];
};

struct c_dlnetwork_layerPredictWithCol {
  real32_T b[348160];
  real32_T out[174080];
  real32_T b_b[174080];
};

struct d_dlnetwork_layerPredictWithCol {
  real32_T b[696320];
  real32_T a[348160];
  real32_T b_b[348160];
};

struct sort {
  real32_T vwork_data[16320];
  int32_T iidx_data[16320];
};

struct selectStrongestBboxMulticlass {
  real32_T inputLabel_data[16320];
  real32_T area_data[16320];
  int32_T ii_data[16320];
  real32_T x2_data[16320];
  real32_T y2_data[16320];
};

struct extractDetections {
  real32_T maxval_data[16320];
};

struct postprocess {
  real32_T bboxesTmp_data[16320];
};

struct b_yolov8Predict {
  real32_T img[1044480];
  real32_T b_img[1044480];
  uint8_T image[623217];
};

struct preprocess {
  uint8_T b_I[1044480];
  uint8_T b_b_I[1025280];
  uint8_T c_I[1008000];
};

struct yolov8PredictStackData {
  sortIdx f0;
  dlnetwork_predict f1;
  imresize f2;
  c_dlnetwork_layerPredictWithCol f3;
  d_dlnetwork_layerPredictWithCol f4;
  sort f5;
  preprocess f6;
  selectStrongestBboxMulticlass f7;
  extractDetections f8;
  postprocess f9;
  b_yolov8Predict f10;
};

// End of code generation (yolov8Predict_types.h)
