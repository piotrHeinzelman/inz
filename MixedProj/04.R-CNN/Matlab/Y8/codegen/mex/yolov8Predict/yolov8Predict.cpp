//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// yolov8Predict.cpp
//
// Code generation for function 'yolov8Predict'
//

// Include files
#include "yolov8Predict.h"
#include "dlnetwork.h"
#include "postprocess.h"
#include "predict.h"
#include "preprocess.h"
#include "rt_nonfinite.h"
#include "yolov8Predict_data.h"
#include "yolov8Predict_internal_types.h"
#include "yolov8Predict_types.h"
#include "MWOnednnCustomLayerBase.hpp"
#include "MWOnednnTargetNetworkImpl.hpp"
#include "MWTensor.hpp"
#include "MWTensorBase.hpp"
#include "coder_array.h"
#include <algorithm>

// Variable Definitions
static yolov8n0_0 net;

static boolean_T net_not_empty;

static emlrtRSInfo emlrtRSI{
    17,              // lineNo
    "yolov8Predict", // fcnName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\yolov8Predict.m" // pathName
};

static emlrtRSInfo b_emlrtRSI{
    26,              // lineNo
    "yolov8Predict", // fcnName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\yolov8Predict.m" // pathName
};

static emlrtRSInfo c_emlrtRSI{
    29,              // lineNo
    "yolov8Predict", // fcnName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\yolov8Predict.m" // pathName
};

static emlrtRSInfo d_emlrtRSI{
    8,               // lineNo
    "yolov8Predict", // fcnName
    "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
    "Add-Ons\\Collections\\Object Detection And Instance Segmentation Using YO"
    "LO v8\\yolov8Predict.m" // pathName
};

static emlrtRSInfo e_emlrtRSI{
    70,                        // lineNo
    "loadDeepLearningNetwork", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\shared\\coder\\coder\\lib\\+"
    "coder\\loadDeepLearningNetwork.m" // pathName
};

static emlrtRSInfo f_emlrtRSI{
    1,                         // lineNo
    "loadDeepLearningNetwork", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\shared\\dlcoder_base\\dlcoder_base\\+"
    "coder\\+internal\\loadDeepLearningNetwork.p" // pathName
};

// Function Definitions
void MWSplitLayer_yolov8n0_07::cleanupLayer()
{
}

void ib_MWMultiplicationLayer_yolov8::cleanupLayer()
{
}

void sb_MWMultiplicationLayer_yolov8::cleanupLayer()
{
}

void tb_MWMultiplicationLayer_yolov8::cleanupLayer()
{
}

void ub_MWMultiplicationLayer_yolov8::cleanupLayer()
{
}

void vb_MWMultiplicationLayer_yolov8::cleanupLayer()
{
}

void wb_MWMultiplicationLayer_yolov8::cleanupLayer()
{
}

void xb_MWMultiplicationLayer_yolov8::cleanupLayer()
{
}

void yb_MWMultiplicationLayer_yolov8::cleanupLayer()
{
}

void ac_MWMultiplicationLayer_yolov8::cleanupLayer()
{
}

void bc_MWMultiplicationLayer_yolov8::cleanupLayer()
{
}

void MWSplitLayer_yolov8n0_08::cleanupLayer()
{
}

void cc_MWMultiplicationLayer_yolov8::cleanupLayer()
{
}

void dc_MWMultiplicationLayer_yolov8::cleanupLayer()
{
}

void ec_MWMultiplicationLayer_yolov8::cleanupLayer()
{
}

void fc_MWMultiplicationLayer_yolov8::cleanupLayer()
{
}

void gc_MWMultiplicationLayer_yolov8::cleanupLayer()
{
}

void hc_MWMultiplicationLayer_yolov8::cleanupLayer()
{
}

void ic_MWMultiplicationLayer_yolov8::cleanupLayer()
{
}

void MWResize2DLayer_yolov8n0_02::cleanupLayer()
{
}

void hb_MWMultiplicationLayer_yolov8::cleanupLayer()
{
}

void r_MWMultiplicationLayer_yolov8n::cleanupLayer()
{
}

void d_MWMultiplicationLayer_yolov8n::cleanupLayer()
{
}

void gb_MWMultiplicationLayer_yolov8::cleanupLayer()
{
}

void e_MWMultiplicationLayer_yolov8n::cleanupLayer()
{
}

void fb_MWMultiplicationLayer_yolov8::cleanupLayer()
{
}

void MWSplitLayer_yolov8n0_01::cleanupLayer()
{
}

void f_MWMultiplicationLayer_yolov8n::cleanupLayer()
{
}

void y_MWMultiplicationLayer_yolov8n::cleanupLayer()
{
}

void MWSplitLayer_yolov8n0_05::cleanupLayer()
{
}

void g_MWMultiplicationLayer_yolov8n::cleanupLayer()
{
}

void s_MWMultiplicationLayer_yolov8n::cleanupLayer()
{
}

void h_MWMultiplicationLayer_yolov8n::cleanupLayer()
{
}

void kb_MWMultiplicationLayer_yolov8::cleanupLayer()
{
}

void eb_MWMultiplicationLayer_yolov8::cleanupLayer()
{
}

void i_MWMultiplicationLayer_yolov8n::cleanupLayer()
{
}

void j_MWMultiplicationLayer_yolov8n::cleanupLayer()
{
}

void MWResize2DLayer_yolov8n0_01::cleanupLayer()
{
}

void MWSplitLayer_yolov8n0_02::cleanupLayer()
{
}

void t_MWMultiplicationLayer_yolov8n::cleanupLayer()
{
}

void k_MWMultiplicationLayer_yolov8n::cleanupLayer()
{
}

void x_MWMultiplicationLayer_yolov8n::cleanupLayer()
{
}

void db_MWMultiplicationLayer_yolov8::cleanupLayer()
{
}

void l_MWMultiplicationLayer_yolov8n::cleanupLayer()
{
}

void m_MWMultiplicationLayer_yolov8n::cleanupLayer()
{
}

void MWSplitLayer_yolov8n0_04::cleanupLayer()
{
}

void c_MWMultiplicationLayer_yolov8n::cleanupLayer()
{
}

void cb_MWMultiplicationLayer_yolov8::cleanupLayer()
{
}

void n_MWMultiplicationLayer_yolov8n::cleanupLayer()
{
}

void u_MWMultiplicationLayer_yolov8n::cleanupLayer()
{
}

void o_MWMultiplicationLayer_yolov8n::cleanupLayer()
{
}

void w_MWMultiplicationLayer_yolov8n::cleanupLayer()
{
}

void bb_MWMultiplicationLayer_yolov8::cleanupLayer()
{
}

void p_MWMultiplicationLayer_yolov8n::cleanupLayer()
{
}

void q_MWMultiplicationLayer_yolov8n::cleanupLayer()
{
}

void ab_MWMultiplicationLayer_yolov8::cleanupLayer()
{
}

void MWSplitLayer_yolov8n0_03::cleanupLayer()
{
}

void v_MWMultiplicationLayer_yolov8n::cleanupLayer()
{
}

void MWSplitLayer_yolov8n0_06::cleanupLayer()
{
}

void jb_MWMultiplicationLayer_yolov8::cleanupLayer()
{
}

void lb_MWMultiplicationLayer_yolov8::cleanupLayer()
{
}

void mb_MWMultiplicationLayer_yolov8::cleanupLayer()
{
}

void nb_MWMultiplicationLayer_yolov8::cleanupLayer()
{
}

void ob_MWMultiplicationLayer_yolov8::cleanupLayer()
{
}

void pb_MWMultiplicationLayer_yolov8::cleanupLayer()
{
}

void qb_MWMultiplicationLayer_yolov8::cleanupLayer()
{
}

void rb_MWMultiplicationLayer_yolov8::cleanupLayer()
{
}

void ib_MWMultiplicationLayer_yolov8::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void c_MWMultiplicationLayer_yolov8n::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void d_MWMultiplicationLayer_yolov8n::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void e_MWMultiplicationLayer_yolov8n::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void MWSplitLayer_yolov8n0_01::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    const char_T *c, const char_T *d, int32_T e, int32_T f)
{
  setupTensors(1, 2, b, c, d, e, f);
  setupLayer(targetImpl);
}

void f_MWMultiplicationLayer_yolov8n::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void g_MWMultiplicationLayer_yolov8n::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void h_MWMultiplicationLayer_yolov8n::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void i_MWMultiplicationLayer_yolov8n::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void j_MWMultiplicationLayer_yolov8n::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void MWSplitLayer_yolov8n0_02::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    const char_T *c, const char_T *d, int32_T e, int32_T f)
{
  setupTensors(1, 2, b, c, d, e, f);
  setupLayer(targetImpl);
}

void k_MWMultiplicationLayer_yolov8n::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void l_MWMultiplicationLayer_yolov8n::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void m_MWMultiplicationLayer_yolov8n::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void n_MWMultiplicationLayer_yolov8n::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void o_MWMultiplicationLayer_yolov8n::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void p_MWMultiplicationLayer_yolov8n::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void q_MWMultiplicationLayer_yolov8n::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void ic_MWMultiplicationLayer_yolov8::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void kb_MWMultiplicationLayer_yolov8::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void ec_MWMultiplicationLayer_yolov8::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void jb_MWMultiplicationLayer_yolov8::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void wb_MWMultiplicationLayer_yolov8::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void MWSplitLayer_yolov8n0_06::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    const char_T *c, const char_T *d, int32_T e, int32_T f)
{
  setupTensors(1, 2, b, c, d, e, f);
  setupLayer(targetImpl);
}

void vb_MWMultiplicationLayer_yolov8::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void MWResize2DLayer_yolov8n0_02::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    const char_T *c, int32_T d)
{
  setupTensors(1, 1, b, c, d);
  setupLayer(targetImpl);
}

void bc_MWMultiplicationLayer_yolov8::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void hb_MWMultiplicationLayer_yolov8::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void dc_MWMultiplicationLayer_yolov8::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void gb_MWMultiplicationLayer_yolov8::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void ub_MWMultiplicationLayer_yolov8::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void fb_MWMultiplicationLayer_yolov8::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void hc_MWMultiplicationLayer_yolov8::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void MWSplitLayer_yolov8n0_05::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    const char_T *c, const char_T *d, int32_T e, int32_T f)
{
  setupTensors(1, 2, b, c, d, e, f);
  setupLayer(targetImpl);
}

void ac_MWMultiplicationLayer_yolov8::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void eb_MWMultiplicationLayer_yolov8::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void tb_MWMultiplicationLayer_yolov8::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void MWResize2DLayer_yolov8n0_01::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    const char_T *c, int32_T d)
{
  setupTensors(1, 1, b, c, d);
  setupLayer(targetImpl);
}

void sb_MWMultiplicationLayer_yolov8::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void db_MWMultiplicationLayer_yolov8::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void MWSplitLayer_yolov8n0_07::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    const char_T *c, const char_T *d, int32_T e, int32_T f)
{
  setupTensors(1, 2, b, c, d, e, f);
  setupLayer(targetImpl);
}

void u_MWMultiplicationLayer_yolov8n::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void yb_MWMultiplicationLayer_yolov8::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void cb_MWMultiplicationLayer_yolov8::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void rb_MWMultiplicationLayer_yolov8::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void bb_MWMultiplicationLayer_yolov8::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void qb_MWMultiplicationLayer_yolov8::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void ab_MWMultiplicationLayer_yolov8::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void xb_MWMultiplicationLayer_yolov8::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void y_MWMultiplicationLayer_yolov8n::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void gc_MWMultiplicationLayer_yolov8::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void MWSplitLayer_yolov8n0_04::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    const char_T *c, const char_T *d, int32_T e, int32_T f)
{
  setupTensors(1, 2, b, c, d, e, f);
  setupLayer(targetImpl);
}

void fc_MWMultiplicationLayer_yolov8::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void x_MWMultiplicationLayer_yolov8n::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void pb_MWMultiplicationLayer_yolov8::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void w_MWMultiplicationLayer_yolov8n::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void cc_MWMultiplicationLayer_yolov8::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void v_MWMultiplicationLayer_yolov8n::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void ob_MWMultiplicationLayer_yolov8::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void t_MWMultiplicationLayer_yolov8n::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void MWSplitLayer_yolov8n0_08::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    const char_T *c, const char_T *d, int32_T e, int32_T f)
{
  setupTensors(1, 2, b, c, d, e, f);
  setupLayer(targetImpl);
}

void s_MWMultiplicationLayer_yolov8n::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void nb_MWMultiplicationLayer_yolov8::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void r_MWMultiplicationLayer_yolov8n::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void mb_MWMultiplicationLayer_yolov8::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void MWSplitLayer_yolov8n0_03::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    const char_T *c, const char_T *d, int32_T e, int32_T f)
{
  setupTensors(1, 2, b, c, d, e, f);
  setupLayer(targetImpl);
}

void lb_MWMultiplicationLayer_yolov8::createCustomLayer(
    MWOnednnTarget::MWTargetNetworkImpl *targetImpl, MWTensorBase *b,
    MWTensorBase *c, const char_T *d, int32_T e)
{
  setupTensors(2, 1, b, c, d, e);
  setupLayer(targetImpl);
}

void nb_MWMultiplicationLayer_yolov8::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::v_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void l_MWMultiplicationLayer_yolov8n::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::k_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void m_MWMultiplicationLayer_yolov8n::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::k_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void ob_MWMultiplicationLayer_yolov8::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::i_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void n_MWMultiplicationLayer_yolov8n::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::k_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void o_MWMultiplicationLayer_yolov8n::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::i_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void pb_MWMultiplicationLayer_yolov8::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::v_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void p_MWMultiplicationLayer_yolov8n::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::l_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void q_MWMultiplicationLayer_yolov8n::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::l_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void qb_MWMultiplicationLayer_yolov8::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::n_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void MWSplitLayer_yolov8n0_03::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  coder::internal::m_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData(),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(1)))->getData());
}

void r_MWMultiplicationLayer_yolov8n::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::n_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void rb_MWMultiplicationLayer_yolov8::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::l_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void s_MWMultiplicationLayer_yolov8n::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::n_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void t_MWMultiplicationLayer_yolov8n::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::n_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void MWSplitLayer_yolov8n0_07::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  coder::internal::t_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData(),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(1)))->getData());
}

void u_MWMultiplicationLayer_yolov8n::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::n_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void v_MWMultiplicationLayer_yolov8n::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::l_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void sb_MWMultiplicationLayer_yolov8::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::n_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void w_MWMultiplicationLayer_yolov8n::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::o_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void fb_MWMultiplicationLayer_yolov8::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::n_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void tb_MWMultiplicationLayer_yolov8::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::n_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void x_MWMultiplicationLayer_yolov8n::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::o_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void MWSplitLayer_yolov8n0_04::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  coder::internal::p_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData(),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(1)))->getData());
}

void ub_MWMultiplicationLayer_yolov8::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::l_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void y_MWMultiplicationLayer_yolov8n::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::q_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void ab_MWMultiplicationLayer_yolov8::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::q_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void vb_MWMultiplicationLayer_yolov8::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::n_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void bb_MWMultiplicationLayer_yolov8::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::o_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void cb_MWMultiplicationLayer_yolov8::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::q_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void wb_MWMultiplicationLayer_yolov8::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::w_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void db_MWMultiplicationLayer_yolov8::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::o_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void MWResize2DLayer_yolov8n0_01::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  coder::internal::e_dlnetwork_layerPredictWithCol(
      m_SD, m_ntwkImpl->getPermuteBuffer(0),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void xb_MWMultiplicationLayer_yolov8::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::n_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void eb_MWMultiplicationLayer_yolov8::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::l_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void ic_MWMultiplicationLayer_yolov8::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::y_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void MWSplitLayer_yolov8n0_05::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  coder::internal::r_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData(),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(1)))->getData());
}

void yb_MWMultiplicationLayer_yolov8::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::w_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void gb_MWMultiplicationLayer_yolov8::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::n_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void hb_MWMultiplicationLayer_yolov8::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::l_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void ac_MWMultiplicationLayer_yolov8::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::q_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void MWResize2DLayer_yolov8n0_02::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  coder::internal::f_dlnetwork_layerPredictWithCol(
      m_SD, m_ntwkImpl->getPermuteBuffer(0),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void ib_MWMultiplicationLayer_yolov8::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::i_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void bc_MWMultiplicationLayer_yolov8::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::o_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void e_MWMultiplicationLayer_yolov8n::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::f_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void MWSplitLayer_yolov8n0_06::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  coder::internal::s_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData(),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(1)))->getData());
}

void MWSplitLayer_yolov8n0_08::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  coder::internal::u_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData(),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(1)))->getData());
}

void c_MWMultiplicationLayer_yolov8n::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::e_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void d_MWMultiplicationLayer_yolov8n::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::f_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void cc_MWMultiplicationLayer_yolov8::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::q_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void jb_MWMultiplicationLayer_yolov8::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::k_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void MWSplitLayer_yolov8n0_01::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  coder::internal::g_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData(),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(1)))->getData());
}

void dc_MWMultiplicationLayer_yolov8::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::q_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void f_MWMultiplicationLayer_yolov8n::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::h_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void kb_MWMultiplicationLayer_yolov8::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::k_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void ec_MWMultiplicationLayer_yolov8::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::o_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void g_MWMultiplicationLayer_yolov8n::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::h_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void h_MWMultiplicationLayer_yolov8n::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::f_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void fc_MWMultiplicationLayer_yolov8::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::x_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void lb_MWMultiplicationLayer_yolov8::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::i_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void i_MWMultiplicationLayer_yolov8n::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::i_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void gc_MWMultiplicationLayer_yolov8::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::y_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void j_MWMultiplicationLayer_yolov8n::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::i_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void mb_MWMultiplicationLayer_yolov8::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::i_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void hc_MWMultiplicationLayer_yolov8::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::x_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void MWSplitLayer_yolov8n0_02::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  coder::internal::j_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData(),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(1)))->getData());
}

void k_MWMultiplicationLayer_yolov8n::predict()
{
  layerMemoryReorder(getInputTensor(0), 0);
  layerMemoryReorder(getInputTensor(1), 1);
  coder::internal::k_dlnetwork_layerPredictWithCol(
      m_ntwkImpl->getPermuteBuffer(0), m_ntwkImpl->getPermuteBuffer(1),
      (static_cast<MWTensor<real32_T> *>(getOutputTensor(0)))->getData());
}

void ab_MWMultiplicationLayer_yolov8::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(17, 20, 128, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void gb_MWMultiplicationLayer_yolov8::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(34, 40, 64, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void MWSplitLayer_yolov8n0_07::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::W, MWTensorBase::H};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(34, 40, 64, batchSize, 1, 0);
  resizeOutputTensor(34, 40, 64, batchSize, 1, 1);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getOutputTensor(0), layout);
  createLayerMemory(getOutputTensor(1), layout);
}

void e_MWMultiplicationLayer_yolov8n::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(136, 160, 32, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void r_MWMultiplicationLayer_yolov8n::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(34, 40, 64, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void d_MWMultiplicationLayer_yolov8n::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(136, 160, 32, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void sb_MWMultiplicationLayer_yolov8::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(34, 40, 64, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void hb_MWMultiplicationLayer_yolov8::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(34, 40, 128, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void c_MWMultiplicationLayer_yolov8n::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(272, 320, 16, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void vb_MWMultiplicationLayer_yolov8::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(34, 40, 64, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void tb_MWMultiplicationLayer_yolov8::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(34, 40, 64, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void fb_MWMultiplicationLayer_yolov8::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(34, 40, 64, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void MWResize2DLayer_yolov8n0_02::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::W, MWTensorBase::H};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(68, 80, 128, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void MWSplitLayer_yolov8n0_01::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::W, MWTensorBase::H};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(136, 160, 16, batchSize, 1, 0);
  resizeOutputTensor(136, 160, 16, batchSize, 1, 1);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getOutputTensor(0), layout);
  createLayerMemory(getOutputTensor(1), layout);
}

void ub_MWMultiplicationLayer_yolov8::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(34, 40, 128, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void MWSplitLayer_yolov8n0_03::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::W, MWTensorBase::H};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(34, 40, 64, batchSize, 1, 0);
  resizeOutputTensor(34, 40, 64, batchSize, 1, 1);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getOutputTensor(0), layout);
  createLayerMemory(getOutputTensor(1), layout);
}

void rb_MWMultiplicationLayer_yolov8::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(34, 40, 128, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void ib_MWMultiplicationLayer_yolov8::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(68, 80, 64, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void ic_MWMultiplicationLayer_yolov8::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(17, 20, 80, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void x_MWMultiplicationLayer_yolov8n::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(17, 20, 256, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void MWSplitLayer_yolov8n0_04::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::W, MWTensorBase::H};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(17, 20, 128, batchSize, 1, 0);
  resizeOutputTensor(17, 20, 128, batchSize, 1, 1);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getOutputTensor(0), layout);
  createLayerMemory(getOutputTensor(1), layout);
}

void yb_MWMultiplicationLayer_yolov8::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(34, 40, 80, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void wb_MWMultiplicationLayer_yolov8::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(34, 40, 80, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void MWSplitLayer_yolov8n0_06::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::W, MWTensorBase::H};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(68, 80, 32, batchSize, 1, 0);
  resizeOutputTensor(68, 80, 32, batchSize, 1, 1);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getOutputTensor(0), layout);
  createLayerMemory(getOutputTensor(1), layout);
}

void q_MWMultiplicationLayer_yolov8n::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(34, 40, 128, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void bb_MWMultiplicationLayer_yolov8::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(17, 20, 256, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void xb_MWMultiplicationLayer_yolov8::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(34, 40, 64, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void p_MWMultiplicationLayer_yolov8n::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(34, 40, 128, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void jb_MWMultiplicationLayer_yolov8::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(68, 80, 32, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void u_MWMultiplicationLayer_yolov8n::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(34, 40, 64, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void o_MWMultiplicationLayer_yolov8n::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(68, 80, 64, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void cb_MWMultiplicationLayer_yolov8::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(17, 20, 128, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void kb_MWMultiplicationLayer_yolov8::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(68, 80, 32, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void n_MWMultiplicationLayer_yolov8n::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(68, 80, 32, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void ac_MWMultiplicationLayer_yolov8::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(17, 20, 128, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void w_MWMultiplicationLayer_yolov8n::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(17, 20, 256, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void m_MWMultiplicationLayer_yolov8n::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(68, 80, 32, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void lb_MWMultiplicationLayer_yolov8::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(68, 80, 64, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void bc_MWMultiplicationLayer_yolov8::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(17, 20, 256, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void db_MWMultiplicationLayer_yolov8::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(17, 20, 256, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void l_MWMultiplicationLayer_yolov8n::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(68, 80, 32, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void t_MWMultiplicationLayer_yolov8n::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(34, 40, 64, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void MWSplitLayer_yolov8n0_08::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::W, MWTensorBase::H};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(17, 20, 128, batchSize, 1, 0);
  resizeOutputTensor(17, 20, 128, batchSize, 1, 1);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getOutputTensor(0), layout);
  createLayerMemory(getOutputTensor(1), layout);
}

void mb_MWMultiplicationLayer_yolov8::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(68, 80, 64, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void k_MWMultiplicationLayer_yolov8n::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(68, 80, 32, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void MWResize2DLayer_yolov8n0_01::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::W, MWTensorBase::H};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(34, 40, 256, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void cc_MWMultiplicationLayer_yolov8::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(17, 20, 128, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void MWSplitLayer_yolov8n0_02::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::W, MWTensorBase::H};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(68, 80, 32, batchSize, 1, 0);
  resizeOutputTensor(68, 80, 32, batchSize, 1, 1);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getOutputTensor(0), layout);
  createLayerMemory(getOutputTensor(1), layout);
}

void nb_MWMultiplicationLayer_yolov8::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(68, 80, 80, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void y_MWMultiplicationLayer_yolov8n::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(17, 20, 128, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void dc_MWMultiplicationLayer_yolov8::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(17, 20, 128, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void j_MWMultiplicationLayer_yolov8n::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(68, 80, 64, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void eb_MWMultiplicationLayer_yolov8::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(34, 40, 128, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void ob_MWMultiplicationLayer_yolov8::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(68, 80, 64, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void ec_MWMultiplicationLayer_yolov8::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(17, 20, 256, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void i_MWMultiplicationLayer_yolov8n::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(68, 80, 64, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void s_MWMultiplicationLayer_yolov8n::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(34, 40, 64, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void h_MWMultiplicationLayer_yolov8n::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(136, 160, 32, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void fc_MWMultiplicationLayer_yolov8::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(17, 20, 64, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void pb_MWMultiplicationLayer_yolov8::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(68, 80, 80, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void MWSplitLayer_yolov8n0_05::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::W, MWTensorBase::H};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(34, 40, 64, batchSize, 1, 0);
  resizeOutputTensor(34, 40, 64, batchSize, 1, 1);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getOutputTensor(0), layout);
  createLayerMemory(getOutputTensor(1), layout);
}

void g_MWMultiplicationLayer_yolov8n::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(136, 160, 16, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void gc_MWMultiplicationLayer_yolov8::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(17, 20, 80, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void v_MWMultiplicationLayer_yolov8n::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(34, 40, 128, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void qb_MWMultiplicationLayer_yolov8::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(34, 40, 64, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void f_MWMultiplicationLayer_yolov8n::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(136, 160, 16, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void hc_MWMultiplicationLayer_yolov8::propagateSize()
{
  int32_T batchSize;
  MWTensorBase::DIMSLABEL layout[4]{MWTensorBase::N, MWTensorBase::C,
                                    MWTensorBase::H, MWTensorBase::W};
  batchSize = getInputTensor(0)->getBatchSize();
  resizeOutputTensor(17, 20, 64, batchSize, 1, 0);
  createLayerMemory(getInputTensor(0), layout);
  createLayerMemory(getInputTensor(1), layout);
  createLayerMemory(getOutputTensor(0), layout);
}

void MWResize2DLayer_yolov8n0_01::setStackDataPtr(yolov8PredictStackData *SD)
{
  m_SD = SD;
}

void MWResize2DLayer_yolov8n0_02::setStackDataPtr(yolov8PredictStackData *SD)
{
  m_SD = SD;
}

void yolov8Predict(yolov8PredictStackData *SD, const emlrtStack *sp,
                   const uint8_T image[623217],
                   coder::array<real32_T, 2U> &bboxes, real32_T scores_data[],
                   int32_T scores_size[1], coder::array<real_T, 1U> &labelIds)
{
  coder::dlarray outFeatureMaps[3];
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  //  Copyright 2024 The MathWorks, Inc.
  //  Load pretrained network.
  if (!net_not_empty) {
    st.site = &d_emlrtRSI;
    b_st.site = &e_emlrtRSI;
    c_st.site = &f_emlrtRSI;
    d_st.site = &g_emlrtRSI;
    coder::internal::dlnetwork_setup(d_st, net);
    net.matlabCodegenIsDeleted = false;
    net_not_empty = true;
  }
  //  Get the input size of the network.
  //  Apply Preprocessing on the input image.
  for (int32_T i{0}; i < 3; i++) {
    for (int32_T i1{0}; i1 < 503; i1++) {
      std::copy(&image[(i * -207739 + i1 * 413) + 415478],
                &image[(i * -207739 + i1 * 413) + 415891],
                &SD->f10.image[i * 207739 + i1 * 413]);
    }
  }
  st.site = &emlrtRSI;
  helper::b_preprocess(SD, st, SD->f10.image, SD->f10.img);
  for (int32_T i{0}; i < 3; i++) {
    for (int32_T i1{0}; i1 < 640; i1++) {
      std::copy(&SD->f10.img[(i * -348160 + i1 * 544) + 696320],
                &SD->f10.img[(i * -348160 + i1 * 544) + 696864],
                &SD->f10.b_img[i * 348160 + i1 * 544]);
    }
  }
  //  Convert to dlarray.
  //  Perform prediction on the input image.
  st.site = &b_emlrtRSI;
  coder::internal::b_dlnetwork_predict(
      SD, st, net, SD->f10.b_img, outFeatureMaps[0].Data,
      outFeatureMaps[1].Data, outFeatureMaps[2].Data);
  //  Apply postprocessing on the output feature maps.
  st.site = &c_emlrtRSI;
  scores_size[0] = helper::b_postprocess(SD, st, outFeatureMaps, bboxes,
                                         scores_data, labelIds);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void yolov8Predict_delete()
{
  if (!net.matlabCodegenIsDeleted) {
    net.matlabCodegenIsDeleted = true;
    coder::internal::dlnetwork_delete(net);
  }
}

void yolov8Predict_init()
{
  net_not_empty = false;
}

void yolov8Predict_new()
{
  net.matlabCodegenIsDeleted = true;
}

// End of code generation (yolov8Predict.cpp)
