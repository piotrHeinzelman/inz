//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// predict.cpp
//
// Code generation for function 'predict'
//

// Include files
#include "predict.h"
#include "dlnetwork.h"
#include "rt_nonfinite.h"
#include "yolov8Predict_data.h"
#include "yolov8Predict_internal_types.h"
#include "yolov8Predict_mexutil.h"
#include "yolov8Predict_types.h"
#include "coder_array.h"
#include <cstring>

// Variable Definitions
static emlrtRSInfo v_emlrtRSI{
    1,                   // lineNo
    "dlnetwork/predict", // fcnName
    "C:"
    "\\ProgramData\\MATLAB\\SupportPackages\\R2025a\\toolbox\\shared\\dlcoder_"
    "base\\supportpackages\\shared_dl_targets\\+coder\\+in"
    "ternal\\@dlnetwork\\predict.p" // pathName
};

static emlrtRTEInfo r_emlrtRTEI{
    1,         // lineNo
    1,         // colNo
    "predict", // fName
    "C:"
    "\\ProgramData\\MATLAB\\SupportPackages\\R2025a\\toolbox\\shared\\dlcoder_"
    "base\\supportpackages\\shared_dl_targets\\+coder\\+in"
    "ternal\\@dlnetwork\\predict.p" // pName
};

// Function Definitions
namespace coder {
namespace internal {
void b_dlnetwork_predict(yolov8PredictStackData *SD, const emlrtStack &sp,
                         yolov8n0_0 &obj,
                         const real32_T varargin_1_Data[1044480],
                         array<real32_T, 3U> &varargout_1_Data,
                         array<real32_T, 3U> &varargout_2_Data,
                         array<real32_T, 3U> &varargout_3_Data)
{
  emlrtStack st;
  real32_T outputDataAfterTranspose_f3[48960];
  st.prev = &sp;
  st.tls = sp.tls;
  for (int32_T p{0}; p < 3; p++) {
    for (int32_T i{0}; i < 544; i++) {
      for (int32_T b_p{0}; b_p < 640; b_p++) {
        SD->f1.inputDataT_0_f1[(b_p + 640 * i) + 348160 * p] =
            varargin_1_Data[(i + 544 * b_p) + 348160 * p];
      }
    }
  }
  st.site = &v_emlrtRSI;
  std::memcpy(obj.getInputDataPointer(0), &SD->f1.inputDataT_0_f1[0],
              static_cast<uint32_T>(obj.getLayerOutputSize(0, 0)));
  try {
    obj.activations(SD, 215);
  } catch (std::runtime_error const &err) {
    checkRunTimeError(st, err.what(), __FILE__, __LINE__);
  } catch (...) {
    checkRunTimeError(st, "", __FILE__, __LINE__);
  }
  std::memcpy(&SD->f1.outputData_f1[0], obj.getLayerOutput(147, 0),
              static_cast<uint32_T>(obj.getLayerOutputSize(147, 0)));
  std::memcpy(&SD->f1.outputData_f2[0], obj.getLayerOutput(181, 0),
              static_cast<uint32_T>(obj.getLayerOutputSize(181, 0)));
  std::memcpy(&SD->f1.outputData_f3[0], obj.getLayerOutput(215, 0),
              static_cast<uint32_T>(obj.getLayerOutputSize(215, 0)));
  for (int32_T b_p{0}; b_p < 144; b_p++) {
    for (int32_T p{0}; p < 80; p++) {
      for (int32_T i{0}; i < 68; i++) {
        SD->f1.outputDataAfterTranspose_f1[(i + 68 * p) + 5440 * b_p] =
            SD->f1.outputData_f1[(p + 80 * i) + 5440 * b_p];
      }
    }
    for (int32_T p{0}; p < 40; p++) {
      for (int32_T i{0}; i < 34; i++) {
        SD->f1.outputDataAfterTranspose_f2[(i + 34 * p) + 1360 * b_p] =
            SD->f1.outputData_f2[(p + 40 * i) + 1360 * b_p];
      }
    }
    for (int32_T p{0}; p < 20; p++) {
      for (int32_T i{0}; i < 17; i++) {
        outputDataAfterTranspose_f3[(i + 17 * p) + 340 * b_p] =
            SD->f1.outputData_f3[(p + 20 * i) + 340 * b_p];
      }
    }
  }
  varargout_1_Data.set_size(&r_emlrtRTEI, &sp, 68, 80, 144);
  for (int32_T p{0}; p < 783360; p++) {
    varargout_1_Data[p] = SD->f1.outputDataAfterTranspose_f1[p];
  }
  varargout_2_Data.set_size(&r_emlrtRTEI, &sp, 34, 40, 144);
  for (int32_T p{0}; p < 195840; p++) {
    varargout_2_Data[p] = SD->f1.outputDataAfterTranspose_f2[p];
  }
  varargout_3_Data.set_size(&r_emlrtRTEI, &sp, 17, 20, 144);
  for (int32_T p{0}; p < 48960; p++) {
    varargout_3_Data[p] = outputDataAfterTranspose_f3[p];
  }
}

} // namespace internal
} // namespace coder

// End of code generation (predict.cpp)
