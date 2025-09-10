//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// make_anchors.cpp
//
// Code generation for function 'make_anchors'
//

// Include files
#include "make_anchors.h"
#include "cat.h"
#include "rt_nonfinite.h"
#include "yolov8Predict_data.h"
#include "yolov8Predict_internal_types.h"
#include "coder_array.h"
#include <emmintrin.h>

// Variable Definitions
static emlrtRSInfo ub_emlrtRSI{
    23,             // lineNo
    "make_anchors", // fcnName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\make_anchors.m" // pathName
};

static emlrtRSInfo vb_emlrtRSI{
    26,             // lineNo
    "make_anchors", // fcnName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\make_anchors.m" // pathName
};

static emlrtRSInfo wb_emlrtRSI{
    27,             // lineNo
    "make_anchors", // fcnName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\make_anchors.m" // pathName
};

static emlrtRTEInfo bb_emlrtRTEI{
    1,              // lineNo
    33,             // colNo
    "make_anchors", // fName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\make_anchors.m" // pName
};

// Function Definitions
namespace helper {
void make_anchors(const emlrtStack &sp, const coder::dlarray feats[3],
                  coder::array<real_T, 2U> &anchorGrid,
                  coder::array<real_T, 2U> &stride)
{
  static const int8_T iv[3]{8, 16, 32};
  cell_wrap_48 anchorGridTmp[3];
  cell_wrap_49 strideTmp[3];
  emlrtStack st;
  real_T sx_data[80];
  st.prev = &sp;
  st.tls = sp.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  //  feats - cell array containing output features
  //  gridCellOffset = 0.5 - value to shift the z,y values by
  for (int32_T i{0}; i < 3; i++) {
    real_T b_sx_data[5440];
    real_T b_sy_data[5440];
    real_T sy_data[68];
    int32_T iy;
    int32_T scalarLB;
    int32_T sx_size_idx_1;
    int32_T vectorUB;
    int8_T y_data[80];
    uint8_T sz_init_idx_0;
    uint8_T sz_init_idx_1;
    boolean_T exitg1;
    sz_init_idx_0 = static_cast<uint8_T>(feats[i].Data.size(0));
    sz_init_idx_1 = static_cast<uint8_T>(feats[i].Data.size(1));
    if (sz_init_idx_1 - 1 < 0) {
      sx_size_idx_1 = 0;
    } else {
      sx_size_idx_1 = sz_init_idx_1;
      iy = sz_init_idx_1 - 1;
      for (int32_T j{0}; j <= iy; j++) {
        sx_data[j] = j;
      }
    }
    iy = sx_size_idx_1 - 1;
    scalarLB = (sx_size_idx_1 / 2) << 1;
    vectorUB = scalarLB - 2;
    for (int32_T j{0}; j <= vectorUB; j += 2) {
      __m128d r;
      r = _mm_loadu_pd(&sx_data[j]);
      _mm_storeu_pd(&sx_data[j], _mm_add_pd(r, _mm_set1_pd(0.5)));
    }
    for (int32_T j{scalarLB}; j <= iy; j++) {
      sx_data[j] += 0.5;
    }
    if (sz_init_idx_0 - 1 < 0) {
      scalarLB = 0;
    } else {
      scalarLB = sz_init_idx_0;
      iy = sz_init_idx_0 - 1;
      for (int32_T j{0}; j <= iy; j++) {
        y_data[j] = static_cast<int8_T>(j);
      }
    }
    for (int32_T j{0}; j < scalarLB; j++) {
      sy_data[j] = static_cast<real_T>(y_data[j]) + 0.5;
    }
    if ((scalarLB != 0) && (sx_size_idx_1 != 0)) {
      for (int32_T j{0}; j < scalarLB; j++) {
        for (int32_T b_i{0}; b_i < sx_size_idx_1; b_i++) {
          iy = b_i + sx_size_idx_1 * j;
          b_sy_data[iy] = sy_data[j];
          b_sx_data[iy] = sx_data[b_i];
        }
      }
    }
    st.site = &ub_emlrtRSI;
    scalarLB *= sx_size_idx_1;
    iy = 0;
    exitg1 = false;
    while ((!exitg1) && (iy < 2)) {
      if ((iy + 1 != 2) && (static_cast<int16_T>(scalarLB) != scalarLB)) {
        emlrtErrorWithMessageIdR2018a(
            &st, &e_emlrtRTEI, "Coder:MATLAB:catenate_dimensionMismatch",
            "Coder:MATLAB:catenate_dimensionMismatch", 0);
      } else {
        iy++;
      }
    }
    iy = 0;
    exitg1 = false;
    while ((!exitg1) && (iy < 2)) {
      if ((iy + 1 != 2) && (static_cast<int16_T>(scalarLB) != scalarLB)) {
        emlrtErrorWithMessageIdR2018a(
            &st, &e_emlrtRTEI, "Coder:MATLAB:catenate_dimensionMismatch",
            "Coder:MATLAB:catenate_dimensionMismatch", 0);
      } else {
        iy++;
      }
    }
    anchorGridTmp[i].f1.set_size(
        &bb_emlrtRTEI, &st,
        static_cast<int32_T>(static_cast<int16_T>(scalarLB)), 2);
    for (int32_T j{0}; j < scalarLB; j++) {
      anchorGridTmp[i].f1[j] = b_sx_data[j];
    }
    if (scalarLB - 1 < 0) {
      iy = -1;
    } else {
      iy = scalarLB + -1;
    }
    for (int32_T j{0}; j < scalarLB; j++) {
      anchorGridTmp[i].f1[(iy + j) + 1] = b_sy_data[j];
    }
    iy = sz_init_idx_0 * sz_init_idx_1;
    strideTmp[i].f1.set_size(&bb_emlrtRTEI, &sp, iy, 1);
    for (int32_T j{0}; j < iy; j++) {
      strideTmp[i].f1[j] = iv[i];
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)&sp);
    }
  }
  st.site = &vb_emlrtRSI;
  coder::cat(st, anchorGridTmp[0].f1, anchorGridTmp[1].f1, anchorGridTmp[2].f1,
             anchorGrid);
  st.site = &wb_emlrtRSI;
  coder::cat(st, (const real_T *)strideTmp[0].f1.data(), strideTmp[0].f1.size(),
             (const real_T *)strideTmp[1].f1.data(), strideTmp[1].f1.size(),
             (const real_T *)strideTmp[2].f1.data(), strideTmp[2].f1.size(),
             stride);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

} // namespace helper

// End of code generation (make_anchors.cpp)
