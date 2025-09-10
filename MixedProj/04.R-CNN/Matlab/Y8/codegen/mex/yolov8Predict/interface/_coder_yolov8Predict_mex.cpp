//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_yolov8Predict_mex.cpp
//
// Code generation for function '_coder_yolov8Predict_mex'
//

// Include files
#include "_coder_yolov8Predict_mex.h"
#include "_coder_yolov8Predict_api.h"
#include "rt_nonfinite.h"
#include "yolov8Predict_data.h"
#include "yolov8Predict_initialize.h"
#include "yolov8Predict_terminate.h"
#include "yolov8Predict_types.h"
#include <cstdlib>
#include <stdexcept>

void emlrtExceptionBridge();
void emlrtExceptionBridge()
{
  throw std::runtime_error("");
}
// Function Definitions
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  yolov8PredictStackData *yolov8PredictStackDataGlobal{nullptr};
  yolov8PredictStackDataGlobal =
      static_cast<yolov8PredictStackData *>(new yolov8PredictStackData);
  mexAtExit(&yolov8Predict_atexit);
  yolov8Predict_initialize();
  try {
    yolov8Predict_mexFunction(yolov8PredictStackDataGlobal, nlhs, plhs, nrhs,
                              prhs);
    yolov8Predict_terminate();
  } catch (...) {
    emlrtCleanupOnException((emlrtCTX *)emlrtRootTLSGlobal);
    throw;
  }
  delete yolov8PredictStackDataGlobal;
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, nullptr, 1,
                           (void *)&emlrtExceptionBridge, "windows-1250", true);
  return emlrtRootTLSGlobal;
}

void yolov8Predict_mexFunction(yolov8PredictStackData *SD, int32_T nlhs,
                               mxArray *plhs[3], int32_T nrhs,
                               const mxArray *prhs[2])
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  const mxArray *outputs[3];
  int32_T i;
  st.tls = emlrtRootTLSGlobal;
  // Check for proper number of arguments.
  if (nrhs < 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooFewInputsConstants", 9, 4, 13,
                        "yolov8Predict", 4, 13, "yolov8Predict", 4, 13,
                        "yolov8Predict");
  }
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4,
                        13, "yolov8Predict");
  }
  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 13,
                        "yolov8Predict");
  }
  // Call the function.
  yolov8Predict_api(SD, prhs, nlhs, outputs);
  // Copy over outputs to the caller.
  if (nlhs < 1) {
    i = 1;
  } else {
    i = nlhs;
  }
  emlrtReturnArrays(i, &plhs[0], &outputs[0]);
}

// End of code generation (_coder_yolov8Predict_mex.cpp)
