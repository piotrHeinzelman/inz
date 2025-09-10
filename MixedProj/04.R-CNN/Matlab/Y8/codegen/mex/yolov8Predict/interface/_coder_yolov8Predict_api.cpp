//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_yolov8Predict_api.cpp
//
// Code generation for function '_coder_yolov8Predict_api'
//

// Include files
#include "_coder_yolov8Predict_api.h"
#include "rt_nonfinite.h"
#include "yolov8Predict.h"
#include "yolov8Predict_data.h"
#include "yolov8Predict_types.h"
#include "coder_array.h"

// Function Declarations
static uint8_T (*b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId))[623217];

static uint8_T (*emlrt_marshallIn(const emlrtStack &sp,
                                  const mxArray *b_nullptr,
                                  const char_T *identifier))[623217];

static uint8_T (*emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                  const emlrtMsgIdentifier *parentId))[623217];

static const mxArray *emlrt_marshallOut(coder::array<real32_T, 2U> &u);

static const mxArray *emlrt_marshallOut(real32_T u_data[],
                                        const int32_T &u_size);

static const mxArray *emlrt_marshallOut(coder::array<real_T, 1U> &u);

// Function Definitions
static uint8_T (*b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId))[623217]
{
  static const int32_T dims[3]{413, 503, 3};
  int32_T iv[3];
  uint8_T(*ret)[623217];
  boolean_T bv[3]{false, false, false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "uint8", false, 3U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret = (uint8_T(*)[623217])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static uint8_T (*emlrt_marshallIn(const emlrtStack &sp,
                                  const mxArray *b_nullptr,
                                  const char_T *identifier))[623217]
{
  emlrtMsgIdentifier thisId;
  uint8_T(*y)[623217];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId);
  emlrtDestroyArray(&b_nullptr);
  return y;
}

static uint8_T (*emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                  const emlrtMsgIdentifier *parentId))[623217]
{
  uint8_T(*y)[623217];
  y = b_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *emlrt_marshallOut(coder::array<real32_T, 2U> &u)
{
  static const int32_T iv[2]{0, 0};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxSINGLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &u[0]);
  emlrtSetDimensions((mxArray *)m, u.size(), 2);
  u.set_owner(false);
  emlrtAssign(&y, m);
  return y;
}

static const mxArray *emlrt_marshallOut(real32_T u_data[],
                                        const int32_T &u_size)
{
  static const int32_T i{0};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxSINGLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &u_data[0]);
  emlrtSetDimensions((mxArray *)m, &u_size, 1);
  emlrtAssign(&y, m);
  return y;
}

static const mxArray *emlrt_marshallOut(coder::array<real_T, 1U> &u)
{
  static const int32_T i{0};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &u[0]);
  emlrtSetDimensions((mxArray *)m, u.size(), 1);
  u.set_owner(false);
  emlrtAssign(&y, m);
  return y;
}

void yolov8Predict_api(yolov8PredictStackData *SD, const mxArray *const prhs[2],
                       int32_T nlhs, const mxArray *plhs[3])
{
  static const uint32_T uv[4]{4258818705U, 1817939866U, 3590700332U,
                              978749275U};
  static const char_T *s{"numClasses"};
  coder::array<real_T, 1U> labelIds;
  coder::array<real32_T, 2U> bboxes;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  int32_T i;
  int32_T scores_size;
  real32_T(*scores_data)[16320];
  uint8_T(*image)[623217];
  st.tls = emlrtRootTLSGlobal;
  scores_data = (real32_T(*)[16320])mxMalloc(sizeof(real32_T[16320]));
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Check constant function inputs
  i = 4;
  emlrtCheckArrayChecksumR2018b(&st, prhs[1], false, &i, (const char_T **)&s,
                                &uv[0]);
  // Marshall function inputs
  image = emlrt_marshallIn(st, emlrtAlias(prhs[0]), "image");
  // Invoke the target function
  yolov8Predict(SD, &st, *image, bboxes, *scores_data, &scores_size, labelIds);
  // Marshall function outputs
  bboxes.set_owner(false);
  plhs[0] = emlrt_marshallOut(bboxes);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(*scores_data, scores_size);
  }
  if (nlhs > 2) {
    labelIds.set_owner(false);
    plhs[2] = emlrt_marshallOut(labelIds);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

// End of code generation (_coder_yolov8Predict_api.cpp)
