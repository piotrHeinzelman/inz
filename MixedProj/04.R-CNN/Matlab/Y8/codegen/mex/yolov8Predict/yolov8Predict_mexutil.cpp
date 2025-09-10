//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// yolov8Predict_mexutil.cpp
//
// Code generation for function 'yolov8Predict_mexutil'
//

// Include files
#include "yolov8Predict_mexutil.h"
#include "rt_nonfinite.h"
#include <cstdlib>

// Function Definitions
void checkRunTimeError(const emlrtStack &sp, const char_T *errMsg,
                       const char_T *file, uint32_T b_line)
{
  emlrtRTEInfo rtInfo;
  uint32_T errMsgLen;
  rtInfo = createEmlrtInfoStruct(file, b_line);
  errMsgLen = (uint32_T)strlen(errMsg);
  emlrtErrorWithMessageIdR2018a(
      &sp, &rtInfo, "dnn_core:cnncodegen:RunTimeError",
      "dnn_core:cnncodegen:RunTimeError", 3, mxCHAR_CLASS, errMsgLen, errMsg);
}

emlrtRTEInfo createEmlrtInfoStruct(const char_T *file, uint32_T b_line)
{
  emlrtRTEInfo b_rtInfo;
  uint32_T len;
  char_T *brk;
  char_T *fn;
  char_T *pn;
  len = (uint32_T)strlen(file);
  pn = static_cast<char_T *>(std::calloc(len + 1U, 1U));
  fn = static_cast<char_T *>(std::calloc(len + 1U, 1U));
  memcpy(pn, file, len);
  memcpy(fn, file, len);
  brk = strrchr(fn, '.');
  *brk = '\x00';
  brk = strrchr(fn, '/');
  if (brk == nullptr) {
    brk = strrchr(fn, '\\');
  }
  if (brk == nullptr) {
    brk = fn;
  } else {
    brk++;
  }
  b_rtInfo.lineNo = static_cast<int32_T>(b_line);
  b_rtInfo.colNo = 0;
  b_rtInfo.fName = brk;
  b_rtInfo.pName = pn;
  return b_rtInfo;
}

// End of code generation (yolov8Predict_mexutil.cpp)
