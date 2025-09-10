//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// yolov8Transform.cpp
//
// Code generation for function 'yolov8Transform'
//

// Include files
#include "yolov8Transform.h"
#include "cat.h"
#include "dist2bbox.h"
#include "distributionFocalLoss.h"
#include "dlarray.h"
#include "make_anchors.h"
#include "permute.h"
#include "reshape.h"
#include "rt_nonfinite.h"
#include "softmax.h"
#include "sum.h"
#include "yolov8Predict_data.h"
#include "yolov8Predict_internal_types.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <algorithm>
#include <emmintrin.h>
#include <xmmintrin.h>

// Type Definitions
namespace coder {
struct b_dlarray {
  array<real32_T, 2U> Data;
};

struct d_dlarray {
  array<real32_T, 2U> Data;
};

} // namespace coder

// Variable Definitions
static emlrtRSInfo db_emlrtRSI{
    16,                // lineNo
    "yolov8Transform", // fcnName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\yolov8Transform.m" // pathName
};

static emlrtRSInfo eb_emlrtRSI{
    21,                // lineNo
    "yolov8Transform", // fcnName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\yolov8Transform.m" // pathName
};

static emlrtRSInfo fb_emlrtRSI{
    24,                // lineNo
    "yolov8Transform", // fcnName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\yolov8Transform.m" // pathName
};

static emlrtRSInfo gb_emlrtRSI{
    25,                // lineNo
    "yolov8Transform", // fcnName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\yolov8Transform.m" // pathName
};

static emlrtRSInfo hb_emlrtRSI{
    28,                // lineNo
    "yolov8Transform", // fcnName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\yolov8Transform.m" // pathName
};

static emlrtRSInfo ib_emlrtRSI{
    33,                // lineNo
    "yolov8Transform", // fcnName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\yolov8Transform.m" // pathName
};

static emlrtRSInfo jb_emlrtRSI{
    35,                // lineNo
    "yolov8Transform", // fcnName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\yolov8Transform.m" // pathName
};

static emlrtRSInfo kb_emlrtRSI{
    38,                // lineNo
    "yolov8Transform", // fcnName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\yolov8Transform.m" // pathName
};

static emlrtRSInfo sb_emlrtRSI{
    61,            // lineNo
    "dlarray/cat", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\nnet\\deepcoder\\+deep\\+internal\\+"
    "coder\\@dlarray\\cat.m" // pathName
};

static emlrtRSInfo tb_emlrtRSI{
    70,            // lineNo
    "dlarray/cat", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\nnet\\deepcoder\\+deep\\+internal\\+"
    "coder\\@dlarray\\cat.m" // pathName
};

static emlrtRSInfo xb_emlrtRSI{
    18,                      // lineNo
    "distributionFocalLoss", // fcnName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\distributionFocalLoss.m" // pathName
};

static emlrtRSInfo yb_emlrtRSI{
    23,                      // lineNo
    "distributionFocalLoss", // fcnName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\distributionFocalLoss.m" // pathName
};

static emlrtRSInfo ac_emlrtRSI{
    26,                      // lineNo
    "distributionFocalLoss", // fcnName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\distributionFocalLoss.m" // pathName
};

static emlrtRSInfo bc_emlrtRSI{
    34,                      // lineNo
    "distributionFocalLoss", // fcnName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\distributionFocalLoss.m" // pathName
};

static emlrtRSInfo cc_emlrtRSI{
    37,                      // lineNo
    "distributionFocalLoss", // fcnName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\distributionFocalLoss.m" // pathName
};

static emlrtRSInfo dc_emlrtRSI{
    40,                      // lineNo
    "distributionFocalLoss", // fcnName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\distributionFocalLoss.m" // pathName
};

static emlrtRSInfo ec_emlrtRSI{
    41,                      // lineNo
    "distributionFocalLoss", // fcnName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\distributionFocalLoss.m" // pathName
};

static emlrtRSInfo fc_emlrtRSI{
    42,                      // lineNo
    "distributionFocalLoss", // fcnName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\distributionFocalLoss.m" // pathName
};

static emlrtRSInfo tc_emlrtRSI{
    31,                // lineNo
    "dlarray/sigmoid", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\nnet\\deepcoder\\+deep\\+internal\\+"
    "coder\\@dlarray\\sigmoid.m" // pathName
};

static emlrtRSInfo uc_emlrtRSI{
    7,         // lineNo
    "sigmoid", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\nnet\\deepcoder\\+deep\\+internal\\+"
    "coder\\+dlarray\\+elementwiseUtils\\sigmoid.m" // pathName
};

static emlrtECInfo e_emlrtECI{
    2,                 // nDims
    36,                // lineNo
    7,                 // colNo
    "yolov8Transform", // fName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\yolov8Transform.m" // pName
};

static emlrtBCInfo emlrtBCI{
    -1,                       // iFirst
    -1,                       // iLast
    36,                       // lineNo
    25,                       // colNo
    "",                       // aName
    "dlarray/parenReference", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\nnet\\deepcoder\\+deep\\+internal\\+"
    "coder\\@dlarray\\parenReference.m", // pName
    0                                    // checkKind
};

static emlrtECInfo f_emlrtECI{
    3,                       // nDims
    36,                      // lineNo
    13,                      // colNo
    "distributionFocalLoss", // fName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\distributionFocalLoss.m" // pName
};

static emlrtRSInfo te_emlrtRSI{
    36,                // lineNo
    "yolov8Transform", // fcnName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\yolov8Transform.m" // pathName
};

static emlrtRTEInfo t_emlrtRTEI{
    1,                 // lineNo
    23,                // colNo
    "yolov8Transform", // fName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\yolov8Transform.m" // pName
};

static emlrtRTEInfo u_emlrtRTEI{
    34,                      // lineNo
    19,                      // colNo
    "distributionFocalLoss", // fName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\distributionFocalLoss.m" // pName
};

static emlrtRTEInfo v_emlrtRTEI{
    33,                // lineNo
    7,                 // colNo
    "yolov8Transform", // fName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\yolov8Transform.m" // pName
};

static emlrtRTEInfo w_emlrtRTEI{
    38,                // lineNo
    7,                 // colNo
    "yolov8Transform", // fName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\yolov8Transform.m" // pName
};

static emlrtRTEInfo kb_emlrtRTEI{
    36,                // lineNo
    1,                 // colNo
    "yolov8Transform", // fName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\+helper\\yolov8Transform.m" // pName
};

// Function Declarations
static void binary_expand_op(const emlrtStack &sp,
                             coder::array<real32_T, 2U> &in1,
                             const coder::array<real_T, 2U> &in2);

// Function Definitions
static void binary_expand_op(const emlrtStack &sp,
                             coder::array<real32_T, 2U> &in1,
                             const coder::array<real_T, 2U> &in2)
{
  coder::array<real32_T, 2U> b_in1;
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T b_loop_ub;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  loop_ub = in1.size(0);
  if (in2.size(1) == 1) {
    b_loop_ub = in1.size(1);
  } else {
    b_loop_ub = in2.size(1);
  }
  b_in1.set_size(&kb_emlrtRTEI, &sp, loop_ub, b_loop_ub);
  stride_0_1 = (in1.size(1) != 1);
  stride_1_1 = (in2.size(1) != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (int32_T i{0}; i < b_loop_ub; i++) {
    int32_T scalarLB;
    int32_T vectorUB;
    scalarLB = (loop_ub / 4) << 2;
    vectorUB = scalarLB - 4;
    for (int32_T i1{0}; i1 <= vectorUB; i1 += 4) {
      __m128 r;
      r = _mm_loadu_ps(&in1[in1.size(0) * aux_0_1]);
      _mm_storeu_ps(&b_in1[b_in1.size(0) * i],
                    _mm_mul_ps(r, _mm_set1_ps(static_cast<real32_T>(
                                      in2[in2.size(0) * aux_1_1]))));
    }
    for (int32_T i1{scalarLB}; i1 < loop_ub; i1++) {
      b_in1[i1 + b_in1.size(0) * i] =
          in1[i1 + in1.size(0) * aux_0_1] *
          static_cast<real32_T>(in2[in2.size(0) * aux_1_1]);
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  loop_ub = b_in1.size(0);
  in1.set_size(&kb_emlrtRTEI, &sp, b_in1.size(0), in1.size(1));
  b_loop_ub = b_in1.size(1);
  in1.set_size(&kb_emlrtRTEI, &sp, in1.size(0), b_in1.size(1));
  for (int32_T i{0}; i < b_loop_ub; i++) {
    for (int32_T i1{0}; i1 < loop_ub; i1++) {
      in1[i1 + in1.size(0) * i] = b_in1[i1 + b_in1.size(0) * i];
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

namespace helper {
void yolov8Transform(const emlrtStack &sp, const coder::dlarray predictions[3],
                     coder::array<real32_T, 2U> &box,
                     coder::array<real32_T, 2U> &cls)
{
  static const int32_T offsets[4]{0, 1, 2, 3};
  __m128 r1;
  coder::array<real_T, 2U> anchorGrid;
  coder::array<real_T, 2U> b_anchorGrid;
  coder::array<real_T, 2U> b_stride;
  coder::array<real_T, 2U> c_stride;
  coder::array<real_T, 2U> r;
  coder::array<real_T, 2U> stride;
  coder::array<real32_T, 3U> b_boxesMax;
  coder::array<real32_T, 3U> boxesReshaped_Data;
  coder::array<real32_T, 2U> b_box;
  coder::array<real32_T, 2U> b_objdata;
  coder::array<real32_T, 2U> box_Data;
  coder::array<real32_T, 2U> boxesTmp;
  coder::array<real32_T, 2U> boxesTotal;
  coder::array<real32_T, 2U> c_box;
  coder::array<real32_T, 2U> c_objdata;
  coder::array<real32_T, 2U> objdata;
  coder::array<real32_T, 2U> predCat_Data;
  coder::array<real32_T, 2U> x;
  coder::b_dlarray predPermute[3];
  coder::c_dlarray boxesMax;
  coder::d_dlarray b_cls;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T varargin_1;
  int32_T iv[4];
  int32_T emptyDimValue;
  int32_T ibmat;
  int32_T loop_ub;
  int32_T maxdimlen;
  int32_T n;
  int32_T prodsz;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  //  Transforms predictions from dlnetwork to
  //  box [x_center y_center w h] and cls scores
  st.site = &db_emlrtRSI;
  coder::dlarray_reshape(st, predictions[0].Data, predPermute[0].Data);
  st.site = &db_emlrtRSI;
  coder::dlarray_reshape(st, predictions[1].Data, predPermute[1].Data);
  st.site = &db_emlrtRSI;
  coder::dlarray_reshape(st, predictions[2].Data, predPermute[2].Data);
  //  Concat all Predictions
  st.site = &eb_emlrtRSI;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  b_st.site = &sb_emlrtRSI;
  c_st.site = &nb_emlrtRSI;
  coder::permute(c_st, predPermute[0].Data, objdata);
  b_st.site = &sb_emlrtRSI;
  c_st.site = &nb_emlrtRSI;
  coder::permute(c_st, predPermute[1].Data, b_objdata);
  b_st.site = &sb_emlrtRSI;
  c_st.site = &nb_emlrtRSI;
  coder::permute(c_st, predPermute[2].Data, c_objdata);
  b_st.site = &tb_emlrtRSI;
  coder::cat(b_st, objdata, b_objdata, c_objdata, predCat_Data);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
  //  Split classes and boxes
  st.site = &fb_emlrtRSI;
  loop_ub = predCat_Data.size(1);
  box_Data.set_size(&t_emlrtRTEI, &st, 64, predCat_Data.size(1));
  for (int32_T jcol{0}; jcol < loop_ub; jcol++) {
    for (int32_T itilerow{0}; itilerow < 64; itilerow++) {
      if (jcol + 1 > loop_ub) {
        emlrtDynamicBoundsCheckR2012b(jcol + 1, 1, loop_ub, &emlrtBCI, &st);
      }
      box_Data[itilerow + 64 * jcol] = predCat_Data[itilerow + 144 * jcol];
    }
  }
  st.site = &gb_emlrtRSI;
  n = (predCat_Data.size(1) / 4) << 2;
  ibmat = n - 4;
  for (int32_T jcol{0}; jcol <= ibmat; jcol += 4) {
    _mm_storeu_si128(
        (__m128i *)&iv[0],
        _mm_add_epi32(
            _mm_set1_epi32(1),
            _mm_add_epi32(_mm_set1_epi32(jcol),
                          _mm_loadu_si128((const __m128i *)&offsets[0]))));
    if ((iv[0] < 1) || (iv[0] > loop_ub)) {
      emlrtDynamicBoundsCheckR2012b(iv[0], 1, loop_ub, &emlrtBCI, &st);
    }
    if ((iv[1] < 1) || (iv[1] > loop_ub)) {
      emlrtDynamicBoundsCheckR2012b(iv[1], 1, loop_ub, &emlrtBCI, &st);
    }
    if ((iv[2] < 1) || (iv[2] > loop_ub)) {
      emlrtDynamicBoundsCheckR2012b(iv[2], 1, loop_ub, &emlrtBCI, &st);
    }
    if ((iv[3] < 1) || (iv[3] > loop_ub)) {
      emlrtDynamicBoundsCheckR2012b(iv[3], 1, loop_ub, &emlrtBCI, &st);
    }
  }
  for (int32_T jcol{n}; jcol < loop_ub; jcol++) {
    if (jcol + 1 > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(jcol + 1, 1, loop_ub, &emlrtBCI, &st);
    }
  }
  //  Compute anchor grid and stride
  st.site = &hb_emlrtRSI;
  make_anchors(st, predictions, anchorGrid, stride);
  //  anchor grid and stride transposed
  n = stride.size(0);
  b_stride.set_size(&t_emlrtRTEI, &sp, 1, stride.size(0));
  for (int32_T jcol{0}; jcol < n; jcol++) {
    b_stride[b_stride.size(0) * jcol] = stride[jcol];
  }
  c_stride.set_size(&t_emlrtRTEI, &sp, 1, stride.size(0));
  if (n - 1 >= 0) {
    std::copy(&b_stride[0], &b_stride[n], &c_stride[0]);
  }
  st.site = &ib_emlrtRSI;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  //  Distribution Focal Loss Module
  //  pre-specified
  //  compute batch. channel and anchors
  //  Reshape Operation
  b_st.site = &xb_emlrtRSI;
  coder::dlarray_reshape(b_st, box_Data, static_cast<real_T>(box_Data.size(1)),
                         boxesReshaped_Data);
  //  Transpose Operation
  b_st.site = &yb_emlrtRSI;
  coder::dlarray_extractdata(b_st, boxesReshaped_Data, boxesMax.Data);
  //  softmax along the channel dimension
  b_st.site = &ac_emlrtRSI;
  coder::dlarray_softmax(b_st, boxesMax);
  //  1-d conv operation
  //  Define weights
  b_st.site = &bc_emlrtRSI;
  varargin_1 = 4.0 * static_cast<real_T>(boxesMax.Data.size(1));
  n = static_cast<int32_T>(varargin_1);
  r.set_size(&u_emlrtRTEI, &b_st, static_cast<int32_T>(varargin_1), 16);
  for (int32_T jcol{0}; jcol < 16; jcol++) {
    ibmat = jcol * static_cast<int32_T>(varargin_1);
    for (int32_T itilerow{0}; itilerow < n; itilerow++) {
      r[ibmat + itilerow] = (static_cast<real_T>(jcol) + 1.0) - 1.0;
    }
  }
  b_st.site = &bc_emlrtRSI;
  ibmat = r.size(0) << 4;
  c_st.site = &qb_emlrtRSI;
  prodsz = boxesMax.Data.size(1) << 2;
  if (prodsz > 0) {
    emptyDimValue = static_cast<int32_T>(static_cast<uint32_T>(ibmat) /
                                         static_cast<uint32_T>(prodsz));
    if (emptyDimValue > ibmat) {
      emlrtErrorWithMessageIdR2018a(&c_st, &d_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
  } else {
    emptyDimValue = 0;
  }
  n = r.size(0);
  if (r.size(0) < 16) {
    n = 16;
  }
  maxdimlen = muIntScalarMax_sint32(ibmat, n);
  if (boxesMax.Data.size(1) > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (emptyDimValue > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (prodsz * emptyDimValue != ibmat) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &b_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }
  //  Conv operation
  if ((emptyDimValue != 16) && (emptyDimValue != 1)) {
    emlrtDimSizeImpxCheckR2021b(16, emptyDimValue, &f_emlrtECI, &st);
  }
  if (emptyDimValue == 16) {
    b_boxesMax.set_size(&v_emlrtRTEI, &st, 4, boxesMax.Data.size(1), 16);
    n = boxesMax.Data.size(1) << 6;
    for (int32_T jcol{0}; jcol < n; jcol++) {
      b_boxesMax[jcol] = boxesMax.Data[jcol] * static_cast<real32_T>(r[jcol]);
    }
    b_st.site = &cc_emlrtRSI;
    coder::sum(b_st, b_boxesMax, boxesTotal);
  } else {
    b_st.site = &cc_emlrtRSI;
    binary_expand_op_1(b_st, boxesTotal, cc_emlrtRSI, boxesMax, r,
                       emptyDimValue);
  }
  //  Reshape Operation
  b_st.site = &dc_emlrtRSI;
  coder::c_permute(b_st, boxesTotal, boxesTmp);
  b_st.site = &ec_emlrtRSI;
  n = boxesTmp.size(0) << 2;
  ibmat = boxesTmp.size(0);
  if (boxesTmp.size(0) < 4) {
    ibmat = 4;
  }
  if (box_Data.size(1) > muIntScalarMax_sint32(n, ibmat)) {
    emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (box_Data.size(1) << 2 != n) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &b_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }
  objdata = boxesTmp.reshape(box_Data.size(1), 4);
  b_st.site = &fc_emlrtRSI;
  coder::d_permute(b_st, objdata, b_box);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
  //  Converting boxes to xywh format here
  n = anchorGrid.size(0);
  b_anchorGrid.set_size(&t_emlrtRTEI, &sp, 2, anchorGrid.size(0));
  for (int32_T jcol{0}; jcol < n; jcol++) {
    b_anchorGrid[2 * jcol] = anchorGrid[jcol];
    b_anchorGrid[2 * jcol + 1] = anchorGrid[jcol + anchorGrid.size(0)];
  }
  st.site = &jb_emlrtRSI;
  dist2bbox(st, b_box, b_anchorGrid, box);
  ibmat = box.size(1);
  if ((stride.size(0) != box.size(1)) &&
      ((box.size(1) != 1) && (stride.size(0) != 1))) {
    emlrtDimSizeImpxCheckR2021b(box.size(1), stride.size(0), &e_emlrtECI,
                                (emlrtConstCTX)&sp);
  }
  if (box.size(1) == c_stride.size(1)) {
    n = box.size(0);
    c_box.set_size(&t_emlrtRTEI, &sp, box.size(0), box.size(1));
    for (int32_T jcol{0}; jcol < ibmat; jcol++) {
      maxdimlen = (box.size(0) / 4) << 2;
      prodsz = maxdimlen - 4;
      for (int32_T itilerow{0}; itilerow <= prodsz; itilerow += 4) {
        r1 = _mm_loadu_ps(&box[box.size(0) * jcol]);
        _mm_storeu_ps(&c_box[c_box.size(0) * jcol],
                      _mm_mul_ps(r1, _mm_set1_ps(static_cast<real32_T>(
                                         c_stride[c_stride.size(0) * jcol]))));
      }
      for (int32_T itilerow{maxdimlen}; itilerow < n; itilerow++) {
        c_box[itilerow + c_box.size(0) * jcol] =
            box[itilerow + box.size(0) * jcol] *
            static_cast<real32_T>(c_stride[c_stride.size(0) * jcol]);
      }
    }
    box.set_size(&t_emlrtRTEI, &sp, c_box.size(0), c_box.size(1));
    n = c_box.size(0) * c_box.size(1);
    for (int32_T jcol{0}; jcol < n; jcol++) {
      box[jcol] = c_box[jcol];
    }
  } else {
    st.site = &te_emlrtRSI;
    binary_expand_op(st, box, c_stride);
  }
  //  Sigmoid of classes
  b_cls.Data.set_size(&t_emlrtRTEI, &sp, 80, predCat_Data.size(1));
  for (int32_T jcol{0}; jcol < loop_ub; jcol++) {
    std::copy(&predCat_Data[jcol * 144 + 64], &predCat_Data[jcol * 144 + 144],
              &b_cls.Data[jcol * 80]);
  }
  st.site = &kb_emlrtRSI;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  b_st.site = &tc_emlrtRSI;
  c_st.site = &uc_emlrtRSI;
  x.set_size(&w_emlrtRTEI, &c_st, 80, b_cls.Data.size(1));
  n = 80 * b_cls.Data.size(1);
  ibmat = (n / 4) << 2;
  maxdimlen = ibmat - 4;
  for (int32_T jcol{0}; jcol <= maxdimlen; jcol += 4) {
    r1 = _mm_loadu_ps(&b_cls.Data[jcol]);
    _mm_storeu_ps(&x[jcol], _mm_mul_ps(r1, _mm_set1_ps(-1.0F)));
  }
  for (int32_T jcol{ibmat}; jcol < n; jcol++) {
    x[jcol] = -b_cls.Data[jcol];
  }
  maxdimlen = 80 * x.size(1);
  for (int32_T jcol{0}; jcol < maxdimlen; jcol++) {
    x[jcol] = muSingleScalarExp(x[jcol]);
  }
  b_cls.Data.set_size(&w_emlrtRTEI, &b_st, 80, b_cls.Data.size(1));
  b_cls.Data.set_size(&w_emlrtRTEI, &b_st, b_cls.Data.size(0), x.size(1));
  n = (maxdimlen / 4) << 2;
  ibmat = n - 4;
  for (int32_T jcol{0}; jcol <= ibmat; jcol += 4) {
    __m128 r2;
    r1 = _mm_loadu_ps(&x[jcol]);
    r2 = _mm_set1_ps(1.0F);
    _mm_storeu_ps(&b_cls.Data[jcol], _mm_div_ps(r2, _mm_add_ps(r1, r2)));
  }
  for (int32_T jcol{n}; jcol < maxdimlen; jcol++) {
    b_cls.Data[jcol] = 1.0F / (x[jcol] + 1.0F);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
  cls.set_size(&t_emlrtRTEI, &sp, 80, b_cls.Data.size(1));
  n = 80 * b_cls.Data.size(1);
  for (int32_T jcol{0}; jcol < n; jcol++) {
    cls[jcol] = b_cls.Data[jcol];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

} // namespace helper

// End of code generation (yolov8Transform.cpp)
