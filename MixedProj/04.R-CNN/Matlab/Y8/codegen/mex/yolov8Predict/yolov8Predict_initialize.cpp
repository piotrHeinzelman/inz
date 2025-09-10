//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// yolov8Predict_initialize.cpp
//
// Code generation for function 'yolov8Predict_initialize'
//

// Include files
#include "yolov8Predict_initialize.h"
#include "_coder_yolov8Predict_mex.h"
#include "rt_nonfinite.h"
#include "yolov8Predict.h"
#include "yolov8Predict_data.h"

// Function Declarations
static void yolov8Predict_once();

// Function Definitions
static void yolov8Predict_once()
{
  mex_InitInfAndNan();
  yolov8Predict_new();
  yolov8Predict_init();
}

void yolov8Predict_initialize()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2022b(&st);
  emlrtClearAllocCountR2012b(&st, false, 0U, nullptr);
  emlrtEnterRtStackR2012b(&st);
  emlrtLicenseCheckR2022a(&st, "EMLRT:runTime:MexFunctionNeedsLicense",
                          "neural_network_toolbox", 2);
  emlrtLicenseCheckR2022a(&st, "EMLRT:runTime:MexFunctionNeedsLicense",
                          "image_toolbox", 2);
  emlrtLicenseCheckR2022a(&st, "EMLRT:runTime:MexFunctionNeedsLicense",
                          "video_and_image_blockset", 2);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    yolov8Predict_once();
  }
}

// End of code generation (yolov8Predict_initialize.cpp)
