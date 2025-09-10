//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// preprocess.cpp
//
// Code generation for function 'preprocess'
//

// Include files
#include "preprocess.h"
#include "imresize.h"
#include "rt_nonfinite.h"
#include "yolov8Predict_types.h"
#include <algorithm>

// Variable Definitions
static emlrtRSInfo h_emlrtRSI{
    22,           // lineNo
    "preprocess", // fcnName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\preprocess.m" // pathName
};

// Function Definitions
namespace helper {
void b_preprocess(yolov8PredictStackData *SD, const emlrtStack &sp,
                  const uint8_T img[623217], real32_T output[1044480])
{
  emlrtStack st;
  st.prev = &sp;
  st.tls = sp.tls;
  //  This function preprocesses the input image.
  //  Copyright 2024 The MathWorks, Inc.
  //  Compute scaling ratio
  //  Compute padding values
  //  w padding
  //  divide padding into 2 sides
  //  h padding
  //  divide padding into 2 sides
  //  Resize input image
  st.site = &h_emlrtRSI;
  coder::b_imresize(SD, st, img, SD->f6.c_I);
  //  Pad values to the image
  for (int32_T k{0}; k < 3; k++) {
    for (int32_T j{0}; j < 640; j++) {
      for (int32_T i{0}; i < 9; i++) {
        SD->f6.b_b_I[(i + 534 * j) + 341760 * k] = 114U;
      }
      std::copy(&SD->f6.c_I[k * 336000 + j * 525],
                &SD->f6.c_I[static_cast<int32_T>(
                    static_cast<uint32_T>(k * 336000 + j * 525) + 525U)],
                &SD->f6.b_b_I[(k * 341760 + j * 534) + 9]);
      for (int32_T i{0}; i < 10; i++) {
        SD->f6.b_I[((i + 544 * j) + 348160 * k) + 534] = 114U;
      }
      std::copy(&SD->f6.b_b_I[k * 341760 + j * 534],
                &SD->f6.b_b_I[static_cast<int32_T>(
                    static_cast<uint32_T>(k * 341760 + j * 534) + 534U)],
                &SD->f6.b_I[k * 348160 + j * 544]);
    }
  }
  //  Convert uint8 to single
  //  Rescale image pixes to [0,1]
  for (int32_T i{0}; i < 1044480; i++) {
    output[i] = static_cast<real32_T>(SD->f6.b_I[i]) / 255.0F;
  }
}

} // namespace helper

// End of code generation (preprocess.cpp)
