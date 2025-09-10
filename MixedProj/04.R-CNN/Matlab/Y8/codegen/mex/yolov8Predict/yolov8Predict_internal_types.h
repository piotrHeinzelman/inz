//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// yolov8Predict_internal_types.h
//
// Code generation for function 'yolov8Predict'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "yolov8Predict_types.h"
#include "MWCNNLayer.hpp"
#include "MWOnednnCustomLayerBase.hpp"
#include "MWOnednnTargetNetworkImpl.hpp"
#include "MWTensorBase.hpp"
#include "coder_array.h"
#include "emlrt.h"

// Type Definitions
class c_MWMultiplicationLayer_yolov8n : public MWOnednnCustomLayerBase {
public:
  c_MWMultiplicationLayer_yolov8n() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class d_MWMultiplicationLayer_yolov8n : public MWOnednnCustomLayerBase {
public:
  d_MWMultiplicationLayer_yolov8n() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class e_MWMultiplicationLayer_yolov8n : public MWOnednnCustomLayerBase {
public:
  e_MWMultiplicationLayer_yolov8n() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class MWSplitLayer_yolov8n0_01 : public MWOnednnCustomLayerBase {
public:
  MWSplitLayer_yolov8n0_01() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, const char_T *c, const char_T *d,
                         int32_T e, int32_T f);
  void propagateSize();
  void cleanupLayer();
  void predict();
};

class f_MWMultiplicationLayer_yolov8n : public MWOnednnCustomLayerBase {
public:
  f_MWMultiplicationLayer_yolov8n() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class g_MWMultiplicationLayer_yolov8n : public MWOnednnCustomLayerBase {
public:
  g_MWMultiplicationLayer_yolov8n() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class h_MWMultiplicationLayer_yolov8n : public MWOnednnCustomLayerBase {
public:
  h_MWMultiplicationLayer_yolov8n() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class i_MWMultiplicationLayer_yolov8n : public MWOnednnCustomLayerBase {
public:
  i_MWMultiplicationLayer_yolov8n() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class j_MWMultiplicationLayer_yolov8n : public MWOnednnCustomLayerBase {
public:
  j_MWMultiplicationLayer_yolov8n() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class MWSplitLayer_yolov8n0_02 : public MWOnednnCustomLayerBase {
public:
  MWSplitLayer_yolov8n0_02() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, const char_T *c, const char_T *d,
                         int32_T e, int32_T f);
  void propagateSize();
  void cleanupLayer();
  void predict();
};

class k_MWMultiplicationLayer_yolov8n : public MWOnednnCustomLayerBase {
public:
  k_MWMultiplicationLayer_yolov8n() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class l_MWMultiplicationLayer_yolov8n : public MWOnednnCustomLayerBase {
public:
  l_MWMultiplicationLayer_yolov8n() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class m_MWMultiplicationLayer_yolov8n : public MWOnednnCustomLayerBase {
public:
  m_MWMultiplicationLayer_yolov8n() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class n_MWMultiplicationLayer_yolov8n : public MWOnednnCustomLayerBase {
public:
  n_MWMultiplicationLayer_yolov8n() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class o_MWMultiplicationLayer_yolov8n : public MWOnednnCustomLayerBase {
public:
  o_MWMultiplicationLayer_yolov8n() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class p_MWMultiplicationLayer_yolov8n : public MWOnednnCustomLayerBase {
public:
  p_MWMultiplicationLayer_yolov8n() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class q_MWMultiplicationLayer_yolov8n : public MWOnednnCustomLayerBase {
public:
  q_MWMultiplicationLayer_yolov8n() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class MWSplitLayer_yolov8n0_03 : public MWOnednnCustomLayerBase {
public:
  MWSplitLayer_yolov8n0_03() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, const char_T *c, const char_T *d,
                         int32_T e, int32_T f);
  void propagateSize();
  void cleanupLayer();
  void predict();
};

class r_MWMultiplicationLayer_yolov8n : public MWOnednnCustomLayerBase {
public:
  r_MWMultiplicationLayer_yolov8n() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class s_MWMultiplicationLayer_yolov8n : public MWOnednnCustomLayerBase {
public:
  s_MWMultiplicationLayer_yolov8n() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class t_MWMultiplicationLayer_yolov8n : public MWOnednnCustomLayerBase {
public:
  t_MWMultiplicationLayer_yolov8n() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class u_MWMultiplicationLayer_yolov8n : public MWOnednnCustomLayerBase {
public:
  u_MWMultiplicationLayer_yolov8n() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class v_MWMultiplicationLayer_yolov8n : public MWOnednnCustomLayerBase {
public:
  v_MWMultiplicationLayer_yolov8n() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class w_MWMultiplicationLayer_yolov8n : public MWOnednnCustomLayerBase {
public:
  w_MWMultiplicationLayer_yolov8n() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class x_MWMultiplicationLayer_yolov8n : public MWOnednnCustomLayerBase {
public:
  x_MWMultiplicationLayer_yolov8n() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class MWSplitLayer_yolov8n0_04 : public MWOnednnCustomLayerBase {
public:
  MWSplitLayer_yolov8n0_04() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, const char_T *c, const char_T *d,
                         int32_T e, int32_T f);
  void propagateSize();
  void cleanupLayer();
  void predict();
};

class y_MWMultiplicationLayer_yolov8n : public MWOnednnCustomLayerBase {
public:
  y_MWMultiplicationLayer_yolov8n() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class ab_MWMultiplicationLayer_yolov8 : public MWOnednnCustomLayerBase {
public:
  ab_MWMultiplicationLayer_yolov8() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class bb_MWMultiplicationLayer_yolov8 : public MWOnednnCustomLayerBase {
public:
  bb_MWMultiplicationLayer_yolov8() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class cb_MWMultiplicationLayer_yolov8 : public MWOnednnCustomLayerBase {
public:
  cb_MWMultiplicationLayer_yolov8() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class db_MWMultiplicationLayer_yolov8 : public MWOnednnCustomLayerBase {
public:
  db_MWMultiplicationLayer_yolov8() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class eb_MWMultiplicationLayer_yolov8 : public MWOnednnCustomLayerBase {
public:
  eb_MWMultiplicationLayer_yolov8() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class MWSplitLayer_yolov8n0_05 : public MWOnednnCustomLayerBase {
public:
  MWSplitLayer_yolov8n0_05() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, const char_T *c, const char_T *d,
                         int32_T e, int32_T f);
  void propagateSize();
  void cleanupLayer();
  void predict();
};

class fb_MWMultiplicationLayer_yolov8 : public MWOnednnCustomLayerBase {
public:
  fb_MWMultiplicationLayer_yolov8() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class gb_MWMultiplicationLayer_yolov8 : public MWOnednnCustomLayerBase {
public:
  gb_MWMultiplicationLayer_yolov8() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class hb_MWMultiplicationLayer_yolov8 : public MWOnednnCustomLayerBase {
public:
  hb_MWMultiplicationLayer_yolov8() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class ib_MWMultiplicationLayer_yolov8 : public MWOnednnCustomLayerBase {
public:
  ib_MWMultiplicationLayer_yolov8() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class MWSplitLayer_yolov8n0_06 : public MWOnednnCustomLayerBase {
public:
  MWSplitLayer_yolov8n0_06() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, const char_T *c, const char_T *d,
                         int32_T e, int32_T f);
  void propagateSize();
  void cleanupLayer();
  void predict();
};

class jb_MWMultiplicationLayer_yolov8 : public MWOnednnCustomLayerBase {
public:
  jb_MWMultiplicationLayer_yolov8() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class kb_MWMultiplicationLayer_yolov8 : public MWOnednnCustomLayerBase {
public:
  kb_MWMultiplicationLayer_yolov8() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class lb_MWMultiplicationLayer_yolov8 : public MWOnednnCustomLayerBase {
public:
  lb_MWMultiplicationLayer_yolov8() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class mb_MWMultiplicationLayer_yolov8 : public MWOnednnCustomLayerBase {
public:
  mb_MWMultiplicationLayer_yolov8() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class nb_MWMultiplicationLayer_yolov8 : public MWOnednnCustomLayerBase {
public:
  nb_MWMultiplicationLayer_yolov8() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class ob_MWMultiplicationLayer_yolov8 : public MWOnednnCustomLayerBase {
public:
  ob_MWMultiplicationLayer_yolov8() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class pb_MWMultiplicationLayer_yolov8 : public MWOnednnCustomLayerBase {
public:
  pb_MWMultiplicationLayer_yolov8() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class qb_MWMultiplicationLayer_yolov8 : public MWOnednnCustomLayerBase {
public:
  qb_MWMultiplicationLayer_yolov8() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class rb_MWMultiplicationLayer_yolov8 : public MWOnednnCustomLayerBase {
public:
  rb_MWMultiplicationLayer_yolov8() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class MWSplitLayer_yolov8n0_07 : public MWOnednnCustomLayerBase {
public:
  MWSplitLayer_yolov8n0_07() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, const char_T *c, const char_T *d,
                         int32_T e, int32_T f);
  void propagateSize();
  void cleanupLayer();
  void predict();
};

class sb_MWMultiplicationLayer_yolov8 : public MWOnednnCustomLayerBase {
public:
  sb_MWMultiplicationLayer_yolov8() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class tb_MWMultiplicationLayer_yolov8 : public MWOnednnCustomLayerBase {
public:
  tb_MWMultiplicationLayer_yolov8() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class ub_MWMultiplicationLayer_yolov8 : public MWOnednnCustomLayerBase {
public:
  ub_MWMultiplicationLayer_yolov8() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class vb_MWMultiplicationLayer_yolov8 : public MWOnednnCustomLayerBase {
public:
  vb_MWMultiplicationLayer_yolov8() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class wb_MWMultiplicationLayer_yolov8 : public MWOnednnCustomLayerBase {
public:
  wb_MWMultiplicationLayer_yolov8() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class xb_MWMultiplicationLayer_yolov8 : public MWOnednnCustomLayerBase {
public:
  xb_MWMultiplicationLayer_yolov8() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class yb_MWMultiplicationLayer_yolov8 : public MWOnednnCustomLayerBase {
public:
  yb_MWMultiplicationLayer_yolov8() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class ac_MWMultiplicationLayer_yolov8 : public MWOnednnCustomLayerBase {
public:
  ac_MWMultiplicationLayer_yolov8() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class bc_MWMultiplicationLayer_yolov8 : public MWOnednnCustomLayerBase {
public:
  bc_MWMultiplicationLayer_yolov8() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class MWSplitLayer_yolov8n0_08 : public MWOnednnCustomLayerBase {
public:
  MWSplitLayer_yolov8n0_08() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, const char_T *c, const char_T *d,
                         int32_T e, int32_T f);
  void propagateSize();
  void cleanupLayer();
  void predict();
};

class cc_MWMultiplicationLayer_yolov8 : public MWOnednnCustomLayerBase {
public:
  cc_MWMultiplicationLayer_yolov8() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class dc_MWMultiplicationLayer_yolov8 : public MWOnednnCustomLayerBase {
public:
  dc_MWMultiplicationLayer_yolov8() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class ec_MWMultiplicationLayer_yolov8 : public MWOnednnCustomLayerBase {
public:
  ec_MWMultiplicationLayer_yolov8() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class fc_MWMultiplicationLayer_yolov8 : public MWOnednnCustomLayerBase {
public:
  fc_MWMultiplicationLayer_yolov8() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class gc_MWMultiplicationLayer_yolov8 : public MWOnednnCustomLayerBase {
public:
  gc_MWMultiplicationLayer_yolov8() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class hc_MWMultiplicationLayer_yolov8 : public MWOnednnCustomLayerBase {
public:
  hc_MWMultiplicationLayer_yolov8() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class ic_MWMultiplicationLayer_yolov8 : public MWOnednnCustomLayerBase {
public:
  ic_MWMultiplicationLayer_yolov8() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, MWTensorBase *c, const char_T *d,
                         int32_T e);
  void propagateSize();
  void cleanupLayer();
  void predict();

private:
  emlrtStack *m_emlrtStack;
};

class yolov8n0_0 {
public:
  yolov8n0_0();
  void setSize();
  void resetState();
  void setup();
  void activations(yolov8PredictStackData *SD, int32_T layerIdx);
  void cleanup();
  real32_T *getLayerOutput(int32_T layerIndex, int32_T portIndex);
  int32_T getLayerOutputSize(int32_T layerIndex, int32_T portIndex);
  real32_T *getInputDataPointer(int32_T b_index);
  real32_T *getInputDataPointer();
  real32_T *getOutputDataPointer(int32_T b_index);
  real32_T *getOutputDataPointer();
  int32_T getBatchSize();
  int32_T getOutputSequenceLength(int32_T layerIndex, int32_T portIndex);
  ~yolov8n0_0();

private:
  void allocate();
  void postsetup();
  void deallocate();

public:
  boolean_T isInitialized;
  boolean_T matlabCodegenIsDeleted;

private:
  int32_T numLayers;
  MWTensorBase *inputTensors[1];
  MWTensorBase *outputTensors[3];
  MWCNNLayer *layers[216];
  MWOnednnTarget::MWTargetNetworkImpl *targetImpl;
};

namespace coder {
struct dlarray {
  array<real32_T, 3U> Data;
};

struct c_dlarray {
  array<real32_T, 3U> Data;
};

} // namespace coder
struct cell_wrap_48 {
  coder::array<real_T, 2U> f1;
};

struct cell_wrap_49 {
  coder::array<real_T, 2U> f1;
};

struct rtDesignRangeCheckInfo {
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
};

struct rtDoubleCheckInfo {
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
  int32_T checkKind;
};

struct rtRunTimeErrorInfo {
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
};

class MWResize2DLayer_yolov8n0_01 : public MWOnednnCustomLayerBase {
public:
  MWResize2DLayer_yolov8n0_01() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, const char_T *c, int32_T d);
  void propagateSize();
  void cleanupLayer();
  void predict();
  void setStackDataPtr(yolov8PredictStackData *SD);

private:
  yolov8PredictStackData *m_SD;
};

class MWResize2DLayer_yolov8n0_02 : public MWOnednnCustomLayerBase {
public:
  MWResize2DLayer_yolov8n0_02() = default;
  void createCustomLayer(MWOnednnTarget::MWTargetNetworkImpl *targetImpl,
                         MWTensorBase *b, const char_T *c, int32_T d);
  void propagateSize();
  void cleanupLayer();
  void predict();
  void setStackDataPtr(yolov8PredictStackData *SD);

private:
  yolov8PredictStackData *m_SD;
};

// End of code generation (yolov8Predict_internal_types.h)
