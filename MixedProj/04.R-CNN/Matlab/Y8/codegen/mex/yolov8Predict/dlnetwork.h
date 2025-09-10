//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// dlnetwork.h
//
// Code generation for function 'dlnetwork'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Type Declarations
class yolov8n0_0;

struct yolov8PredictStackData;

// Function Declarations
namespace coder {
namespace internal {
void dlnetwork_delete(yolov8n0_0 &obj);

void dlnetwork_setup(const emlrtStack &sp, yolov8n0_0 &obj);

void e_dlnetwork_layerPredictWithCol(const real32_T varargin_1[1392640],
                                     const real32_T varargin_2[1392640],
                                     real32_T varargout_1[1392640]);

void e_dlnetwork_layerPredictWithCol(yolov8PredictStackData *SD,
                                     const real32_T varargin_1[87040],
                                     real32_T varargout_1[348160]);

void f_dlnetwork_layerPredictWithCol(const real32_T varargin_1[696320],
                                     const real32_T varargin_2[696320],
                                     real32_T varargout_1[696320]);

void f_dlnetwork_layerPredictWithCol(yolov8PredictStackData *SD,
                                     const real32_T varargin_1[174080],
                                     real32_T varargout_1[696320]);

void g_dlnetwork_layerPredictWithCol(const real32_T varargin_1[696320],
                                     real32_T varargout_1[348160],
                                     real32_T varargout_2[348160]);

void h_dlnetwork_layerPredictWithCol(const real32_T varargin_1[348160],
                                     const real32_T varargin_2[348160],
                                     real32_T varargout_1[348160]);

void i_dlnetwork_layerPredictWithCol(const real32_T varargin_1[348160],
                                     const real32_T varargin_2[348160],
                                     real32_T varargout_1[348160]);

void j_dlnetwork_layerPredictWithCol(const real32_T varargin_1[348160],
                                     real32_T varargout_1[174080],
                                     real32_T varargout_2[174080]);

void k_dlnetwork_layerPredictWithCol(const real32_T varargin_1[174080],
                                     const real32_T varargin_2[174080],
                                     real32_T varargout_1[174080]);

void l_dlnetwork_layerPredictWithCol(const real32_T varargin_1[174080],
                                     const real32_T varargin_2[174080],
                                     real32_T varargout_1[174080]);

void m_dlnetwork_layerPredictWithCol(const real32_T varargin_1[174080],
                                     real32_T varargout_1[87040],
                                     real32_T varargout_2[87040]);

void n_dlnetwork_layerPredictWithCol(const real32_T varargin_1[87040],
                                     const real32_T varargin_2[87040],
                                     real32_T varargout_1[87040]);

void o_dlnetwork_layerPredictWithCol(const real32_T varargin_1[87040],
                                     const real32_T varargin_2[87040],
                                     real32_T varargout_1[87040]);

void p_dlnetwork_layerPredictWithCol(const real32_T varargin_1[87040],
                                     real32_T varargout_1[43520],
                                     real32_T varargout_2[43520]);

void q_dlnetwork_layerPredictWithCol(const real32_T varargin_1[43520],
                                     const real32_T varargin_2[43520],
                                     real32_T varargout_1[43520]);

void r_dlnetwork_layerPredictWithCol(const real32_T varargin_1[174080],
                                     real32_T varargout_1[87040],
                                     real32_T varargout_2[87040]);

void s_dlnetwork_layerPredictWithCol(const real32_T varargin_1[348160],
                                     real32_T varargout_1[174080],
                                     real32_T varargout_2[174080]);

void t_dlnetwork_layerPredictWithCol(const real32_T varargin_1[174080],
                                     real32_T varargout_1[87040],
                                     real32_T varargout_2[87040]);

void u_dlnetwork_layerPredictWithCol(const real32_T varargin_1[87040],
                                     real32_T varargout_1[43520],
                                     real32_T varargout_2[43520]);

void v_dlnetwork_layerPredictWithCol(const real32_T varargin_1[435200],
                                     const real32_T varargin_2[435200],
                                     real32_T varargout_1[435200]);

void w_dlnetwork_layerPredictWithCol(const real32_T varargin_1[108800],
                                     const real32_T varargin_2[108800],
                                     real32_T varargout_1[108800]);

void x_dlnetwork_layerPredictWithCol(const real32_T varargin_1[21760],
                                     const real32_T varargin_2[21760],
                                     real32_T varargout_1[21760]);

void y_dlnetwork_layerPredictWithCol(const real32_T varargin_1[27200],
                                     const real32_T varargin_2[27200],
                                     real32_T varargout_1[27200]);

} // namespace internal
} // namespace coder

// End of code generation (dlnetwork.h)
