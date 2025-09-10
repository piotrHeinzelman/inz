//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// postProcessYOLOv8.cpp
//
// Code generation for function 'postProcessYOLOv8'
//

// Include files
#include "postProcessYOLOv8.h"
#include "div.h"
#include "rt_nonfinite.h"
#include "yolov8Predict_data.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo se_emlrtRSI{
    10,                  // lineNo
    "postProcessYOLOv8", // fcnName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\postProcessYOLOv8.m" // pathName
};

static emlrtECInfo j_emlrtECI{
    1,                   // nDims
    10,                  // lineNo
    13,                  // colNo
    "postProcessYOLOv8", // fName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\postProcessYOLOv8.m" // pName
};

static emlrtECInfo k_emlrtECI{
    -1,                  // nDims
    14,                  // lineNo
    1,                   // colNo
    "postProcessYOLOv8", // fName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\postProcessYOLOv8.m" // pName
};

static emlrtECInfo l_emlrtECI{
    -1,                  // nDims
    15,                  // lineNo
    1,                   // colNo
    "postProcessYOLOv8", // fName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\postProcessYOLOv8.m" // pName
};

static emlrtECInfo m_emlrtECI{
    -1,                  // nDims
    16,                  // lineNo
    1,                   // colNo
    "postProcessYOLOv8", // fName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\postProcessYOLOv8.m" // pName
};

static emlrtECInfo n_emlrtECI{
    -1,                  // nDims
    17,                  // lineNo
    1,                   // colNo
    "postProcessYOLOv8", // fName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\postProcessYOLOv8.m" // pName
};

static emlrtBCInfo y_emlrtBCI{
    -1,                  // iFirst
    -1,                  // iLast
    12,                  // lineNo
    11,                  // colNo
    "newCoords",         // aName
    "postProcessYOLOv8", // fName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\postProcessYOLOv8.m", // pName
    0                                      // checkKind
};

static emlrtRTEInfo gb_emlrtRTEI{
    10,                  // lineNo
    22,                  // colNo
    "postProcessYOLOv8", // fName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\postProcessYOLOv8.m" // pName
};

static emlrtRTEInfo hb_emlrtRTEI{
    2,                   // lineNo
    22,                  // colNo
    "postProcessYOLOv8", // fName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\postProcessYOLOv8.m" // pName
};

// Function Definitions
namespace helper {
void postProcessYOLOv8(const emlrtStack &sp,
                       const coder::array<real32_T, 2U> &coords,
                       coder::array<real32_T, 2U> &newCoords)
{
  coder::array<real_T, 2U> r;
  emlrtStack st;
  int32_T varargin_1;
  real32_T tmp_data[16320];
  real32_T b_varargin_1;
  st.prev = &sp;
  st.tls = sp.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  //  Rescale coords (xyxy) from img1_shape to img0_shape
  st.site = &se_emlrtRSI;
  varargin_1 = coords.size(0);
  r.set_size(&gb_emlrtRTEI, &st, varargin_1, 4);
  for (int32_T jtilecol{0}; jtilecol < 2; jtilecol++) {
    int32_T ibtile;
    ibtile = jtilecol * (varargin_1 << 1);
    for (int32_T jcol{0}; jcol < 2; jcol++) {
      int32_T ibmat;
      ibmat = ibtile + jcol * varargin_1;
      for (int32_T itilerow{0}; itilerow < varargin_1; itilerow++) {
        r[ibmat + itilerow] = 9.2564612326043516 * static_cast<real_T>(jcol);
      }
    }
  }
  if ((coords.size(0) != r.size(0)) &&
      ((coords.size(0) != 1) && (r.size(0) != 1))) {
    emlrtDimSizeImpxCheckR2021b(coords.size(0), r.size(0), &j_emlrtECI,
                                (emlrtConstCTX)&sp);
  }
  if (coords.size(0) == r.size(0)) {
    newCoords.set_size(&hb_emlrtRTEI, &sp, coords.size(0), 4);
    varargin_1 = coords.size(0) << 2;
    for (int32_T jtilecol{0}; jtilecol < varargin_1; jtilecol++) {
      newCoords[jtilecol] =
          (coords[jtilecol] - static_cast<real32_T>(r[jtilecol])) / 1.27236581F;
    }
  } else {
    st.site = &ve_emlrtRSI;
    binary_expand_op_5(st, newCoords, coords, r);
  }
  varargin_1 = newCoords.size(0) << 2;
  for (int32_T jtilecol{0}; jtilecol < varargin_1; jtilecol++) {
    if (newCoords[jtilecol] < 0.0F) {
      if (jtilecol > varargin_1 - 1) {
        emlrtDynamicBoundsCheckR2012b(jtilecol, 0, varargin_1 - 1, &y_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      newCoords[jtilecol] = 0.1F;
    }
  }
  varargin_1 = newCoords.size(0);
  for (int32_T jtilecol{0}; jtilecol < varargin_1; jtilecol++) {
    b_varargin_1 = newCoords[jtilecol];
    tmp_data[jtilecol] = muSingleScalarMin(b_varargin_1, 503.0F);
  }
  emlrtSubAssignSizeCheckR2012b(newCoords.size(), 1, newCoords.size(), 1,
                                &k_emlrtECI, (emlrtCTX)&sp);
  for (int32_T jtilecol{0}; jtilecol < varargin_1; jtilecol++) {
    newCoords[jtilecol] = tmp_data[jtilecol];
  }
  for (int32_T jtilecol{0}; jtilecol < varargin_1; jtilecol++) {
    b_varargin_1 = newCoords[jtilecol + newCoords.size(0)];
    tmp_data[jtilecol] = muSingleScalarMin(b_varargin_1, 413.0F);
  }
  emlrtSubAssignSizeCheckR2012b(newCoords.size(), 1, newCoords.size(), 1,
                                &l_emlrtECI, (emlrtCTX)&sp);
  for (int32_T jtilecol{0}; jtilecol < varargin_1; jtilecol++) {
    newCoords[jtilecol + newCoords.size(0)] = tmp_data[jtilecol];
  }
  for (int32_T jtilecol{0}; jtilecol < varargin_1; jtilecol++) {
    b_varargin_1 = newCoords[jtilecol + newCoords.size(0) * 2];
    tmp_data[jtilecol] = muSingleScalarMin(b_varargin_1, 503.0F);
  }
  emlrtSubAssignSizeCheckR2012b(newCoords.size(), 1, newCoords.size(), 1,
                                &m_emlrtECI, (emlrtCTX)&sp);
  for (int32_T jtilecol{0}; jtilecol < varargin_1; jtilecol++) {
    newCoords[jtilecol + newCoords.size(0) * 2] = tmp_data[jtilecol];
  }
  for (int32_T jtilecol{0}; jtilecol < varargin_1; jtilecol++) {
    b_varargin_1 = newCoords[jtilecol + newCoords.size(0) * 3];
    tmp_data[jtilecol] = muSingleScalarMin(b_varargin_1, 413.0F);
  }
  emlrtSubAssignSizeCheckR2012b(newCoords.size(), 1, newCoords.size(), 1,
                                &n_emlrtECI, (emlrtCTX)&sp);
  for (int32_T jtilecol{0}; jtilecol < varargin_1; jtilecol++) {
    newCoords[jtilecol + newCoords.size(0) * 3] = tmp_data[jtilecol];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

} // namespace helper

// End of code generation (postProcessYOLOv8.cpp)
