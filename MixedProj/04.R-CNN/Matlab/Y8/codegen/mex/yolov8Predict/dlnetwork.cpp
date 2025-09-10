//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// dlnetwork.cpp
//
// Code generation for function 'dlnetwork'
//

// Include files
#include "dlnetwork.h"
#include "Resize2DLayer.h"
#include "rt_nonfinite.h"
#include "yolov8Predict.h"
#include "yolov8Predict_data.h"
#include "yolov8Predict_internal_types.h"
#include "yolov8Predict_mexutil.h"
#include "yolov8Predict_types.h"
#include "MWAdditionLayer.hpp"
#include "MWCNNLayer.hpp"
#include "MWConcatenationLayer.hpp"
#include "MWConvLayer.hpp"
#include "MWInputLayer.hpp"
#include "MWMaxPoolingLayer.hpp"
#include "MWOnednnCustomLayerBase.hpp"
#include "MWOnednnTargetNetworkImpl.hpp"
#include "MWOutputLayer.hpp"
#include "MWSigmoidLayer.hpp"
#include "MWSplittingLayer.hpp"
#include "MWTensor.hpp"
#include "MWTensorBase.hpp"
#include <algorithm>
#include <xmmintrin.h>

// Function Declarations
static void checkCleanupRunTimeError(const char_T *errMsg, const char_T *file,
                                     uint32_T b_line);

// Function Definitions
void yolov8n0_0::allocate()
{
  MWCNNLayer *b_this[216];
  for (int32_T b{0}; b < 216; b++) {
    b_this[b] = layers[b];
  }
  targetImpl->allocate(8, b_this, numLayers, 2);
  for (int32_T idx{0}; idx < 216; idx++) {
    layers[idx]->allocate();
  }
  (static_cast<MWTensor<real32_T> *>(inputTensors[0]))
      ->setData(layers[0]->getLayerOutput(0));
}

void yolov8n0_0::cleanup()
{
  try {
    isInitialized = false;
    deallocate();
    for (int32_T idx{0}; idx < 216; idx++) {
      layers[idx]->cleanup();
    }
    if (targetImpl) {
      targetImpl->cleanup();
    }
  } catch (std::runtime_error const &err) {
    checkCleanupRunTimeError(err.what(), __FILE__, __LINE__);
  } catch (...) {
    checkCleanupRunTimeError("", __FILE__, __LINE__);
  }
}

void yolov8n0_0::deallocate()
{
  targetImpl->deallocate();
  for (int32_T idx{0}; idx < 216; idx++) {
    layers[idx]->deallocate();
  }
}

void yolov8n0_0::postsetup()
{
  targetImpl->postSetup();
}

void yolov8n0_0::resetState()
{
}

void yolov8n0_0::setSize()
{
  for (int32_T idx{0}; idx < 216; idx++) {
    layers[idx]->propagateSize();
  }
  allocate();
  postsetup();
}

void yolov8n0_0::setup()
{
  if (isInitialized) {
    resetState();
  } else {
    targetImpl->preSetup();
    (static_cast<MWInputLayer *>(layers[0]))
        ->createInputLayer(targetImpl, inputTensors[0], "SSCB", 0);
    (static_cast<MWConvLayer *>(layers[1]))
        ->createConvLayer(
            targetImpl, layers[0]->getOutputTensor(0), 3, 3, 3, 16, 2, 2, 1, 1,
            1, 1, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_0_conv_"
            "Conv_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_0_conv_"
            "Conv_b.bin",
            "SSCB", 1);
    (static_cast<MWSigmoidLayer *>(layers[2]))
        ->createSigmoidLayer(targetImpl, layers[1]->getOutputTensor(0), "SSCB",
                             0);
    (static_cast<c_MWMultiplicationLayer_yolov8n *>(layers[3]))
        ->createCustomLayer(targetImpl, layers[1]->getOutputTensor(0),
                            layers[2]->getOutputTensor(0), "SSCB", 2);
    (static_cast<MWConvLayer *>(layers[4]))
        ->createConvLayer(
            targetImpl, layers[3]->getOutputTensor(0), 3, 3, 16, 32, 2, 2, 1, 1,
            1, 1, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_1_conv_"
            "Conv_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_1_conv_"
            "Conv_b.bin",
            "SSCB", 0);
    (static_cast<MWSigmoidLayer *>(layers[5]))
        ->createSigmoidLayer(targetImpl, layers[4]->getOutputTensor(0), "SSCB",
                             1);
    (static_cast<d_MWMultiplicationLayer_yolov8n *>(layers[6]))
        ->createCustomLayer(targetImpl, layers[4]->getOutputTensor(0),
                            layers[5]->getOutputTensor(0), "SSCB", 2);
    (static_cast<MWConvLayer *>(layers[7]))
        ->createConvLayer(
            targetImpl, layers[6]->getOutputTensor(0), 1, 1, 32, 32, 1, 1, 0, 0,
            0, 0, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_2_cv1_"
            "conv_1_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_2_cv1_"
            "conv_1_b.bin",
            "SSCB", 0);
    (static_cast<MWSigmoidLayer *>(layers[8]))
        ->createSigmoidLayer(targetImpl, layers[7]->getOutputTensor(0), "SSCB",
                             1);
    (static_cast<e_MWMultiplicationLayer_yolov8n *>(layers[9]))
        ->createCustomLayer(targetImpl, layers[7]->getOutputTensor(0),
                            layers[8]->getOutputTensor(0), "SSCB", 2);
    (static_cast<MWSplitLayer_yolov8n0_01 *>(layers[10]))
        ->createCustomLayer(targetImpl, layers[9]->getOutputTensor(0), "SSCB",
                            "SSCB", 0, 1);
    (static_cast<MWConvLayer *>(layers[11]))
        ->createConvLayer(
            targetImpl, layers[10]->getOutputTensor(0), 3, 3, 16, 16, 1, 1, 1,
            1, 1, 1, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_2_m_0_cv1_"
            "_4_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_2_m_0_cv1_"
            "_4_b.bin",
            "SSCB", 2);
    (static_cast<MWSigmoidLayer *>(layers[12]))
        ->createSigmoidLayer(targetImpl, layers[11]->getOutputTensor(0), "SSCB",
                             3);
    (static_cast<f_MWMultiplicationLayer_yolov8n *>(layers[13]))
        ->createCustomLayer(targetImpl, layers[11]->getOutputTensor(0),
                            layers[12]->getOutputTensor(0), "SSCB", 4);
    (static_cast<MWConvLayer *>(layers[14]))
        ->createConvLayer(
            targetImpl, layers[13]->getOutputTensor(0), 3, 3, 16, 16, 1, 1, 1,
            1, 1, 1, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_2_m_0_cv2_"
            "_4_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_2_m_0_cv2_"
            "_4_b.bin",
            "SSCB", 2);
    (static_cast<MWSigmoidLayer *>(layers[15]))
        ->createSigmoidLayer(targetImpl, layers[14]->getOutputTensor(0), "SSCB",
                             3);
    (static_cast<g_MWMultiplicationLayer_yolov8n *>(layers[16]))
        ->createCustomLayer(targetImpl, layers[14]->getOutputTensor(0),
                            layers[15]->getOutputTensor(0), "SSCB", 4);
    (static_cast<MWAdditionLayer *>(layers[17]))
        ->createAdditionLayer<real32_T, real32_T>(
            targetImpl, 2, layers[10]->getOutputTensor(0),
            layers[16]->getOutputTensor(0), 0, "FLOAT", "SSCB", 2);
    (static_cast<MWConcatenationLayer *>(layers[18]))
        ->createConcatenationLayer(
            targetImpl, 3, layers[10]->getOutputTensor(1),
            layers[10]->getOutputTensor(0), layers[17]->getOutputTensor(0), 3,
            "C", "SSCB", 3);
    (static_cast<MWConvLayer *>(layers[19]))
        ->createConvLayer(
            targetImpl, layers[18]->getOutputTensor(0), 1, 1, 48, 32, 1, 1, 0,
            0, 0, 0, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_2_cv2_"
            "conv_1_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_2_cv2_"
            "conv_1_b.bin",
            "SSCB", 0);
    (static_cast<MWSigmoidLayer *>(layers[20]))
        ->createSigmoidLayer(targetImpl, layers[19]->getOutputTensor(0), "SSCB",
                             1);
    (static_cast<h_MWMultiplicationLayer_yolov8n *>(layers[21]))
        ->createCustomLayer(targetImpl, layers[19]->getOutputTensor(0),
                            layers[20]->getOutputTensor(0), "SSCB", 2);
    (static_cast<MWConvLayer *>(layers[22]))
        ->createConvLayer(
            targetImpl, layers[21]->getOutputTensor(0), 3, 3, 32, 64, 2, 2, 1,
            1, 1, 1, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_3_conv_"
            "Conv_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_3_conv_"
            "Conv_b.bin",
            "SSCB", 0);
    (static_cast<MWSigmoidLayer *>(layers[23]))
        ->createSigmoidLayer(targetImpl, layers[22]->getOutputTensor(0), "SSCB",
                             1);
    (static_cast<i_MWMultiplicationLayer_yolov8n *>(layers[24]))
        ->createCustomLayer(targetImpl, layers[22]->getOutputTensor(0),
                            layers[23]->getOutputTensor(0), "SSCB", 2);
    (static_cast<MWConvLayer *>(layers[25]))
        ->createConvLayer(
            targetImpl, layers[24]->getOutputTensor(0), 1, 1, 64, 64, 1, 1, 0,
            0, 0, 0, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_4_cv1_"
            "conv_1_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_4_cv1_"
            "conv_1_b.bin",
            "SSCB", 0);
    (static_cast<MWSigmoidLayer *>(layers[26]))
        ->createSigmoidLayer(targetImpl, layers[25]->getOutputTensor(0), "SSCB",
                             1);
    (static_cast<j_MWMultiplicationLayer_yolov8n *>(layers[27]))
        ->createCustomLayer(targetImpl, layers[25]->getOutputTensor(0),
                            layers[26]->getOutputTensor(0), "SSCB", 2);
    (static_cast<MWSplitLayer_yolov8n0_02 *>(layers[28]))
        ->createCustomLayer(targetImpl, layers[27]->getOutputTensor(0), "SSCB",
                            "SSCB", 0, 1);
    (static_cast<MWConvLayer *>(layers[29]))
        ->createConvLayer(
            targetImpl, layers[28]->getOutputTensor(0), 3, 3, 32, 32, 1, 1, 1,
            1, 1, 1, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_4_m_0_cv1_"
            "_4_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_4_m_0_cv1_"
            "_4_b.bin",
            "SSCB", 2);
    (static_cast<MWSigmoidLayer *>(layers[30]))
        ->createSigmoidLayer(targetImpl, layers[29]->getOutputTensor(0), "SSCB",
                             3);
    (static_cast<k_MWMultiplicationLayer_yolov8n *>(layers[31]))
        ->createCustomLayer(targetImpl, layers[29]->getOutputTensor(0),
                            layers[30]->getOutputTensor(0), "SSCB", 4);
    (static_cast<MWConvLayer *>(layers[32]))
        ->createConvLayer(
            targetImpl, layers[31]->getOutputTensor(0), 3, 3, 32, 32, 1, 1, 1,
            1, 1, 1, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_4_m_0_cv2_"
            "_4_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_4_m_0_cv2_"
            "_4_b.bin",
            "SSCB", 2);
    (static_cast<MWSigmoidLayer *>(layers[33]))
        ->createSigmoidLayer(targetImpl, layers[32]->getOutputTensor(0), "SSCB",
                             3);
    (static_cast<l_MWMultiplicationLayer_yolov8n *>(layers[34]))
        ->createCustomLayer(targetImpl, layers[32]->getOutputTensor(0),
                            layers[33]->getOutputTensor(0), "SSCB", 4);
    (static_cast<MWAdditionLayer *>(layers[35]))
        ->createAdditionLayer<real32_T, real32_T>(
            targetImpl, 2, layers[28]->getOutputTensor(0),
            layers[34]->getOutputTensor(0), 0, "FLOAT", "SSCB", 2);
    (static_cast<MWConvLayer *>(layers[36]))
        ->createConvLayer(
            targetImpl, layers[35]->getOutputTensor(0), 3, 3, 32, 32, 1, 1, 1,
            1, 1, 1, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_4_m_1_cv1_"
            "_4_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_4_m_1_cv1_"
            "_4_b.bin",
            "SSCB", 3);
    (static_cast<MWSigmoidLayer *>(layers[37]))
        ->createSigmoidLayer(targetImpl, layers[36]->getOutputTensor(0), "SSCB",
                             4);
    (static_cast<m_MWMultiplicationLayer_yolov8n *>(layers[38]))
        ->createCustomLayer(targetImpl, layers[36]->getOutputTensor(0),
                            layers[37]->getOutputTensor(0), "SSCB", 5);
    (static_cast<MWConvLayer *>(layers[39]))
        ->createConvLayer(
            targetImpl, layers[38]->getOutputTensor(0), 3, 3, 32, 32, 1, 1, 1,
            1, 1, 1, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_4_m_1_cv2_"
            "_4_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_4_m_1_cv2_"
            "_4_b.bin",
            "SSCB", 3);
    (static_cast<MWSigmoidLayer *>(layers[40]))
        ->createSigmoidLayer(targetImpl, layers[39]->getOutputTensor(0), "SSCB",
                             4);
    (static_cast<n_MWMultiplicationLayer_yolov8n *>(layers[41]))
        ->createCustomLayer(targetImpl, layers[39]->getOutputTensor(0),
                            layers[40]->getOutputTensor(0), "SSCB", 5);
    (static_cast<MWAdditionLayer *>(layers[42]))
        ->createAdditionLayer<real32_T, real32_T>(
            targetImpl, 2, layers[35]->getOutputTensor(0),
            layers[41]->getOutputTensor(0), 0, "FLOAT", "SSCB", 3);
    (static_cast<MWConcatenationLayer *>(layers[43]))
        ->createConcatenationLayer(
            targetImpl, 4, layers[28]->getOutputTensor(1),
            layers[28]->getOutputTensor(0), layers[35]->getOutputTensor(0),
            layers[42]->getOutputTensor(0), 3, "C", "SSCB", 4);
    (static_cast<MWConvLayer *>(layers[44]))
        ->createConvLayer(
            targetImpl, layers[43]->getOutputTensor(0), 1, 1, 128, 64, 1, 1, 0,
            0, 0, 0, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_4_cv2_"
            "conv_1_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_4_cv2_"
            "conv_1_b.bin",
            "SSCB", 0);
    (static_cast<MWSigmoidLayer *>(layers[45]))
        ->createSigmoidLayer(targetImpl, layers[44]->getOutputTensor(0), "SSCB",
                             1);
    (static_cast<o_MWMultiplicationLayer_yolov8n *>(layers[46]))
        ->createCustomLayer(targetImpl, layers[44]->getOutputTensor(0),
                            layers[45]->getOutputTensor(0), "SSCB", 2);
    (static_cast<MWConvLayer *>(layers[47]))
        ->createConvLayer(
            targetImpl, layers[46]->getOutputTensor(0), 3, 3, 64, 128, 2, 2, 1,
            1, 1, 1, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_5_conv_"
            "Conv_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_5_conv_"
            "Conv_b.bin",
            "SSCB", 0);
    (static_cast<MWSigmoidLayer *>(layers[48]))
        ->createSigmoidLayer(targetImpl, layers[47]->getOutputTensor(0), "SSCB",
                             1);
    (static_cast<p_MWMultiplicationLayer_yolov8n *>(layers[49]))
        ->createCustomLayer(targetImpl, layers[47]->getOutputTensor(0),
                            layers[48]->getOutputTensor(0), "SSCB", 3);
    (static_cast<MWConvLayer *>(layers[50]))
        ->createConvLayer(
            targetImpl, layers[49]->getOutputTensor(0), 1, 1, 128, 128, 1, 1, 0,
            0, 0, 0, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_6_cv1_"
            "conv_1_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_6_cv1_"
            "conv_1_b.bin",
            "SSCB", 0);
    (static_cast<MWSigmoidLayer *>(layers[51]))
        ->createSigmoidLayer(targetImpl, layers[50]->getOutputTensor(0), "SSCB",
                             1);
    (static_cast<q_MWMultiplicationLayer_yolov8n *>(layers[52]))
        ->createCustomLayer(targetImpl, layers[50]->getOutputTensor(0),
                            layers[51]->getOutputTensor(0), "SSCB", 3);
    (static_cast<MWSplitLayer_yolov8n0_03 *>(layers[53]))
        ->createCustomLayer(targetImpl, layers[52]->getOutputTensor(0), "SSCB",
                            "SSCB", 0, 1);
    (static_cast<MWConvLayer *>(layers[54]))
        ->createConvLayer(
            targetImpl, layers[53]->getOutputTensor(0), 3, 3, 64, 64, 1, 1, 1,
            1, 1, 1, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_6_m_0_cv1_"
            "_4_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_6_m_0_cv1_"
            "_4_b.bin",
            "SSCB", 3);
    (static_cast<MWSigmoidLayer *>(layers[55]))
        ->createSigmoidLayer(targetImpl, layers[54]->getOutputTensor(0), "SSCB",
                             4);
    (static_cast<r_MWMultiplicationLayer_yolov8n *>(layers[56]))
        ->createCustomLayer(targetImpl, layers[54]->getOutputTensor(0),
                            layers[55]->getOutputTensor(0), "SSCB", 5);
    (static_cast<MWConvLayer *>(layers[57]))
        ->createConvLayer(
            targetImpl, layers[56]->getOutputTensor(0), 3, 3, 64, 64, 1, 1, 1,
            1, 1, 1, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_6_m_0_cv2_"
            "_4_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_6_m_0_cv2_"
            "_4_b.bin",
            "SSCB", 3);
    (static_cast<MWSigmoidLayer *>(layers[58]))
        ->createSigmoidLayer(targetImpl, layers[57]->getOutputTensor(0), "SSCB",
                             4);
    (static_cast<s_MWMultiplicationLayer_yolov8n *>(layers[59]))
        ->createCustomLayer(targetImpl, layers[57]->getOutputTensor(0),
                            layers[58]->getOutputTensor(0), "SSCB", 5);
    (static_cast<MWAdditionLayer *>(layers[60]))
        ->createAdditionLayer<real32_T, real32_T>(
            targetImpl, 2, layers[53]->getOutputTensor(0),
            layers[59]->getOutputTensor(0), 0, "FLOAT", "SSCB", 3);
    (static_cast<MWConvLayer *>(layers[61]))
        ->createConvLayer(
            targetImpl, layers[60]->getOutputTensor(0), 3, 3, 64, 64, 1, 1, 1,
            1, 1, 1, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_6_m_1_cv1_"
            "_4_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_6_m_1_cv1_"
            "_4_b.bin",
            "SSCB", 4);
    (static_cast<MWSigmoidLayer *>(layers[62]))
        ->createSigmoidLayer(targetImpl, layers[61]->getOutputTensor(0), "SSCB",
                             5);
    (static_cast<t_MWMultiplicationLayer_yolov8n *>(layers[63]))
        ->createCustomLayer(targetImpl, layers[61]->getOutputTensor(0),
                            layers[62]->getOutputTensor(0), "SSCB", 6);
    (static_cast<MWConvLayer *>(layers[64]))
        ->createConvLayer(
            targetImpl, layers[63]->getOutputTensor(0), 3, 3, 64, 64, 1, 1, 1,
            1, 1, 1, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_6_m_1_cv2_"
            "_4_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_6_m_1_cv2_"
            "_4_b.bin",
            "SSCB", 4);
    (static_cast<MWSigmoidLayer *>(layers[65]))
        ->createSigmoidLayer(targetImpl, layers[64]->getOutputTensor(0), "SSCB",
                             5);
    (static_cast<u_MWMultiplicationLayer_yolov8n *>(layers[66]))
        ->createCustomLayer(targetImpl, layers[64]->getOutputTensor(0),
                            layers[65]->getOutputTensor(0), "SSCB", 6);
    (static_cast<MWAdditionLayer *>(layers[67]))
        ->createAdditionLayer<real32_T, real32_T>(
            targetImpl, 2, layers[60]->getOutputTensor(0),
            layers[66]->getOutputTensor(0), 0, "FLOAT", "SSCB", 4);
    (static_cast<MWConcatenationLayer *>(layers[68]))
        ->createConcatenationLayer(
            targetImpl, 4, layers[53]->getOutputTensor(1),
            layers[53]->getOutputTensor(0), layers[60]->getOutputTensor(0),
            layers[67]->getOutputTensor(0), 3, "C", "SSCB", 5);
    (static_cast<MWConvLayer *>(layers[69]))
        ->createConvLayer(
            targetImpl, layers[68]->getOutputTensor(0), 1, 1, 256, 128, 1, 1, 0,
            0, 0, 0, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_6_cv2_"
            "conv_1_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_6_cv2_"
            "conv_1_b.bin",
            "SSCB", 0);
    (static_cast<MWSigmoidLayer *>(layers[70]))
        ->createSigmoidLayer(targetImpl, layers[69]->getOutputTensor(0), "SSCB",
                             1);
    (static_cast<v_MWMultiplicationLayer_yolov8n *>(layers[71]))
        ->createCustomLayer(targetImpl, layers[69]->getOutputTensor(0),
                            layers[70]->getOutputTensor(0), "SSCB", 3);
    (static_cast<MWConvLayer *>(layers[72]))
        ->createConvLayer(
            targetImpl, layers[71]->getOutputTensor(0), 3, 3, 128, 256, 2, 2, 1,
            1, 1, 1, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_7_conv_"
            "Conv_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_7_conv_"
            "Conv_b.bin",
            "SSCB", 0);
    (static_cast<MWSigmoidLayer *>(layers[73]))
        ->createSigmoidLayer(targetImpl, layers[72]->getOutputTensor(0), "SSCB",
                             1);
    (static_cast<w_MWMultiplicationLayer_yolov8n *>(layers[74]))
        ->createCustomLayer(targetImpl, layers[72]->getOutputTensor(0),
                            layers[73]->getOutputTensor(0), "SSCB", 4);
    (static_cast<MWConvLayer *>(layers[75]))
        ->createConvLayer(
            targetImpl, layers[74]->getOutputTensor(0), 1, 1, 256, 256, 1, 1, 0,
            0, 0, 0, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_8_cv1_"
            "conv_1_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_8_cv1_"
            "conv_1_b.bin",
            "SSCB", 0);
    (static_cast<MWSigmoidLayer *>(layers[76]))
        ->createSigmoidLayer(targetImpl, layers[75]->getOutputTensor(0), "SSCB",
                             1);
    (static_cast<x_MWMultiplicationLayer_yolov8n *>(layers[77]))
        ->createCustomLayer(targetImpl, layers[75]->getOutputTensor(0),
                            layers[76]->getOutputTensor(0), "SSCB", 4);
    (static_cast<MWSplitLayer_yolov8n0_04 *>(layers[78]))
        ->createCustomLayer(targetImpl, layers[77]->getOutputTensor(0), "SSCB",
                            "SSCB", 0, 1);
    (static_cast<MWConvLayer *>(layers[79]))
        ->createConvLayer(
            targetImpl, layers[78]->getOutputTensor(0), 3, 3, 128, 128, 1, 1, 1,
            1, 1, 1, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_8_m_0_cv1_"
            "_4_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_8_m_0_cv1_"
            "_4_b.bin",
            "SSCB", 4);
    (static_cast<MWSigmoidLayer *>(layers[80]))
        ->createSigmoidLayer(targetImpl, layers[79]->getOutputTensor(0), "SSCB",
                             5);
    (static_cast<y_MWMultiplicationLayer_yolov8n *>(layers[81]))
        ->createCustomLayer(targetImpl, layers[79]->getOutputTensor(0),
                            layers[80]->getOutputTensor(0), "SSCB", 6);
    (static_cast<MWConvLayer *>(layers[82]))
        ->createConvLayer(
            targetImpl, layers[81]->getOutputTensor(0), 3, 3, 128, 128, 1, 1, 1,
            1, 1, 1, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_8_m_0_cv2_"
            "_4_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_8_m_0_cv2_"
            "_4_b.bin",
            "SSCB", 4);
    (static_cast<MWSigmoidLayer *>(layers[83]))
        ->createSigmoidLayer(targetImpl, layers[82]->getOutputTensor(0), "SSCB",
                             5);
    (static_cast<ab_MWMultiplicationLayer_yolov8 *>(layers[84]))
        ->createCustomLayer(targetImpl, layers[82]->getOutputTensor(0),
                            layers[83]->getOutputTensor(0), "SSCB", 6);
    (static_cast<MWAdditionLayer *>(layers[85]))
        ->createAdditionLayer<real32_T, real32_T>(
            targetImpl, 2, layers[78]->getOutputTensor(0),
            layers[84]->getOutputTensor(0), 0, "FLOAT", "SSCB", 4);
    (static_cast<MWConcatenationLayer *>(layers[86]))
        ->createConcatenationLayer(
            targetImpl, 3, layers[78]->getOutputTensor(1),
            layers[78]->getOutputTensor(0), layers[85]->getOutputTensor(0), 3,
            "C", "SSCB", 5);
    (static_cast<MWConvLayer *>(layers[87]))
        ->createConvLayer(
            targetImpl, layers[86]->getOutputTensor(0), 1, 1, 384, 256, 1, 1, 0,
            0, 0, 0, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_8_cv2_"
            "conv_1_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_8_cv2_"
            "conv_1_b.bin",
            "SSCB", 0);
    (static_cast<MWSigmoidLayer *>(layers[88]))
        ->createSigmoidLayer(targetImpl, layers[87]->getOutputTensor(0), "SSCB",
                             1);
    (static_cast<bb_MWMultiplicationLayer_yolov8 *>(layers[89]))
        ->createCustomLayer(targetImpl, layers[87]->getOutputTensor(0),
                            layers[88]->getOutputTensor(0), "SSCB", 4);
    (static_cast<MWConvLayer *>(layers[90]))
        ->createConvLayer(
            targetImpl, layers[89]->getOutputTensor(0), 1, 1, 256, 128, 1, 1, 0,
            0, 0, 0, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_9_cv1_"
            "conv_1_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_9_cv1_"
            "conv_1_b.bin",
            "SSCB", 0);
    (static_cast<MWSigmoidLayer *>(layers[91]))
        ->createSigmoidLayer(targetImpl, layers[90]->getOutputTensor(0), "SSCB",
                             1);
    (static_cast<cb_MWMultiplicationLayer_yolov8 *>(layers[92]))
        ->createCustomLayer(targetImpl, layers[90]->getOutputTensor(0),
                            layers[91]->getOutputTensor(0), "SSCB", 4);
    (static_cast<MWMaxPoolingLayer *>(layers[93]))
        ->createMaxPoolingLayer<real32_T, real32_T>(
            targetImpl, layers[92]->getOutputTensor(0), 5, 5, 1, 1, 2, 2, 2, 2,
            0, 0, "FLOAT", 1, "SSCB", 0);
    (static_cast<MWMaxPoolingLayer *>(layers[94]))
        ->createMaxPoolingLayer<real32_T, real32_T>(
            targetImpl, layers[93]->getOutputTensor(0), 5, 5, 1, 1, 2, 2, 2, 2,
            0, 0, "FLOAT", 1, "SSCB", 1);
    (static_cast<MWMaxPoolingLayer *>(layers[95]))
        ->createMaxPoolingLayer<real32_T, real32_T>(
            targetImpl, layers[94]->getOutputTensor(0), 5, 5, 1, 1, 2, 2, 2, 2,
            0, 0, "FLOAT", 1, "SSCB", 5);
    (static_cast<MWConcatenationLayer *>(layers[96]))
        ->createConcatenationLayer(
            targetImpl, 4, layers[92]->getOutputTensor(0),
            layers[93]->getOutputTensor(0), layers[94]->getOutputTensor(0),
            layers[95]->getOutputTensor(0), 3, "C", "SSCB", 6);
    (static_cast<MWConvLayer *>(layers[97]))
        ->createConvLayer(
            targetImpl, layers[96]->getOutputTensor(0), 1, 1, 512, 256, 1, 1, 0,
            0, 0, 0, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_9_cv2_"
            "conv_1_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_9_cv2_"
            "conv_1_b.bin",
            "SSCB", 0);
    (static_cast<MWSigmoidLayer *>(layers[98]))
        ->createSigmoidLayer(targetImpl, layers[97]->getOutputTensor(0), "SSCB",
                             1);
    (static_cast<db_MWMultiplicationLayer_yolov8 *>(layers[99]))
        ->createCustomLayer(targetImpl, layers[97]->getOutputTensor(0),
                            layers[98]->getOutputTensor(0), "SSCB", 4);
    (static_cast<MWResize2DLayer_yolov8n0_01 *>(layers[100]))
        ->createCustomLayer(targetImpl, layers[99]->getOutputTensor(0), "SSCB",
                            0);
    (static_cast<MWConcatenationLayer *>(layers[101]))
        ->createConcatenationLayer(
            targetImpl, 2, layers[100]->getOutputTensor(0),
            layers[71]->getOutputTensor(0), 3, "C", "SSCB", 1);
    (static_cast<MWConvLayer *>(layers[102]))
        ->createConvLayer(
            targetImpl, layers[101]->getOutputTensor(0), 1, 1, 384, 128, 1, 1,
            0, 0, 0, 0, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_12_cv1_"
            "con_1_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_12_cv1_"
            "con_1_b.bin",
            "SSCB", 0);
    (static_cast<MWSigmoidLayer *>(layers[103]))
        ->createSigmoidLayer(targetImpl, layers[102]->getOutputTensor(0),
                             "SSCB", 1);
    (static_cast<eb_MWMultiplicationLayer_yolov8 *>(layers[104]))
        ->createCustomLayer(targetImpl, layers[102]->getOutputTensor(0),
                            layers[103]->getOutputTensor(0), "SSCB", 3);
    (static_cast<MWSplitLayer_yolov8n0_05 *>(layers[105]))
        ->createCustomLayer(targetImpl, layers[104]->getOutputTensor(0), "SSCB",
                            "SSCB", 0, 1);
    (static_cast<MWConvLayer *>(layers[106]))
        ->createConvLayer(
            targetImpl, layers[105]->getOutputTensor(0), 3, 3, 64, 64, 1, 1, 1,
            1, 1, 1, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_12_m_0_"
            "cv1_4_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_12_m_0_"
            "cv1_4_b.bin",
            "SSCB", 3);
    (static_cast<MWSigmoidLayer *>(layers[107]))
        ->createSigmoidLayer(targetImpl, layers[106]->getOutputTensor(0),
                             "SSCB", 5);
    (static_cast<fb_MWMultiplicationLayer_yolov8 *>(layers[108]))
        ->createCustomLayer(targetImpl, layers[106]->getOutputTensor(0),
                            layers[107]->getOutputTensor(0), "SSCB", 6);
    (static_cast<MWConvLayer *>(layers[109]))
        ->createConvLayer(
            targetImpl, layers[108]->getOutputTensor(0), 3, 3, 64, 64, 1, 1, 1,
            1, 1, 1, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_12_m_0_"
            "cv2_4_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_12_m_0_"
            "cv2_4_b.bin",
            "SSCB", 3);
    (static_cast<MWSigmoidLayer *>(layers[110]))
        ->createSigmoidLayer(targetImpl, layers[109]->getOutputTensor(0),
                             "SSCB", 5);
    (static_cast<gb_MWMultiplicationLayer_yolov8 *>(layers[111]))
        ->createCustomLayer(targetImpl, layers[109]->getOutputTensor(0),
                            layers[110]->getOutputTensor(0), "SSCB", 6);
    (static_cast<MWConcatenationLayer *>(layers[112]))
        ->createConcatenationLayer(
            targetImpl, 3, layers[105]->getOutputTensor(1),
            layers[105]->getOutputTensor(0), layers[111]->getOutputTensor(0), 3,
            "C", "SSCB", 3);
    (static_cast<MWConvLayer *>(layers[113]))
        ->createConvLayer(
            targetImpl, layers[112]->getOutputTensor(0), 1, 1, 192, 128, 1, 1,
            0, 0, 0, 0, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_12_cv2_"
            "con_1_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_12_cv2_"
            "con_1_b.bin",
            "SSCB", 0);
    (static_cast<MWSigmoidLayer *>(layers[114]))
        ->createSigmoidLayer(targetImpl, layers[113]->getOutputTensor(0),
                             "SSCB", 1);
    (static_cast<hb_MWMultiplicationLayer_yolov8 *>(layers[115]))
        ->createCustomLayer(targetImpl, layers[113]->getOutputTensor(0),
                            layers[114]->getOutputTensor(0), "SSCB", 3);
    (static_cast<MWResize2DLayer_yolov8n0_02 *>(layers[116]))
        ->createCustomLayer(targetImpl, layers[115]->getOutputTensor(0), "SSCB",
                            0);
    (static_cast<MWConcatenationLayer *>(layers[117]))
        ->createConcatenationLayer(
            targetImpl, 2, layers[116]->getOutputTensor(0),
            layers[46]->getOutputTensor(0), 3, "C", "SSCB", 1);
    (static_cast<MWConvLayer *>(layers[118]))
        ->createConvLayer(
            targetImpl, layers[117]->getOutputTensor(0), 1, 1, 192, 64, 1, 1, 0,
            0, 0, 0, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_15_cv1_"
            "con_1_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_15_cv1_"
            "con_1_b.bin",
            "SSCB", 0);
    (static_cast<MWSigmoidLayer *>(layers[119]))
        ->createSigmoidLayer(targetImpl, layers[118]->getOutputTensor(0),
                             "SSCB", 1);
    (static_cast<ib_MWMultiplicationLayer_yolov8 *>(layers[120]))
        ->createCustomLayer(targetImpl, layers[118]->getOutputTensor(0),
                            layers[119]->getOutputTensor(0), "SSCB", 2);
    (static_cast<MWSplitLayer_yolov8n0_06 *>(layers[121]))
        ->createCustomLayer(targetImpl, layers[120]->getOutputTensor(0), "SSCB",
                            "SSCB", 0, 1);
    (static_cast<MWConvLayer *>(layers[122]))
        ->createConvLayer(
            targetImpl, layers[121]->getOutputTensor(0), 3, 3, 32, 32, 1, 1, 1,
            1, 1, 1, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_15_m_0_"
            "cv1_4_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_15_m_0_"
            "cv1_4_b.bin",
            "SSCB", 2);
    (static_cast<MWSigmoidLayer *>(layers[123]))
        ->createSigmoidLayer(targetImpl, layers[122]->getOutputTensor(0),
                             "SSCB", 5);
    (static_cast<jb_MWMultiplicationLayer_yolov8 *>(layers[124]))
        ->createCustomLayer(targetImpl, layers[122]->getOutputTensor(0),
                            layers[123]->getOutputTensor(0), "SSCB", 6);
    (static_cast<MWConvLayer *>(layers[125]))
        ->createConvLayer(
            targetImpl, layers[124]->getOutputTensor(0), 3, 3, 32, 32, 1, 1, 1,
            1, 1, 1, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_15_m_0_"
            "cv2_4_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_15_m_0_"
            "cv2_4_b.bin",
            "SSCB", 2);
    (static_cast<MWSigmoidLayer *>(layers[126]))
        ->createSigmoidLayer(targetImpl, layers[125]->getOutputTensor(0),
                             "SSCB", 5);
    (static_cast<kb_MWMultiplicationLayer_yolov8 *>(layers[127]))
        ->createCustomLayer(targetImpl, layers[125]->getOutputTensor(0),
                            layers[126]->getOutputTensor(0), "SSCB", 6);
    (static_cast<MWConcatenationLayer *>(layers[128]))
        ->createConcatenationLayer(
            targetImpl, 3, layers[121]->getOutputTensor(1),
            layers[121]->getOutputTensor(0), layers[127]->getOutputTensor(0), 3,
            "C", "SSCB", 2);
    (static_cast<MWConvLayer *>(layers[129]))
        ->createConvLayer(
            targetImpl, layers[128]->getOutputTensor(0), 1, 1, 96, 64, 1, 1, 0,
            0, 0, 0, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_15_cv2_"
            "con_1_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_15_cv2_"
            "con_1_b.bin",
            "SSCB", 0);
    (static_cast<MWSigmoidLayer *>(layers[130]))
        ->createSigmoidLayer(targetImpl, layers[129]->getOutputTensor(0),
                             "SSCB", 1);
    (static_cast<lb_MWMultiplicationLayer_yolov8 *>(layers[131]))
        ->createCustomLayer(targetImpl, layers[129]->getOutputTensor(0),
                            layers[130]->getOutputTensor(0), "SSCB", 2);
    (static_cast<MWConvLayer *>(layers[132]))
        ->createConvLayer(
            targetImpl, layers[131]->getOutputTensor(0), 3, 3, 64, 144, 1, 1, 1,
            1, 1, 1, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_22_cv3_0__"
            "9_w_fused.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_22_cv3_0__"
            "9_b_fused.bin",
            "SSCB", 0);
    (static_cast<MWSplittingLayer *>(layers[133]))
        ->createSplittingLayer(targetImpl, layers[132]->getOutputTensor(0), 2,
                               80, 64, 2, "SSCB", "SSCB", 1, 5);
    (static_cast<MWSigmoidLayer *>(layers[134]))
        ->createSigmoidLayer(targetImpl, layers[133]->getOutputTensor(1),
                             "SSCB", 0);
    (static_cast<mb_MWMultiplicationLayer_yolov8 *>(layers[135]))
        ->createCustomLayer(targetImpl, layers[133]->getOutputTensor(1),
                            layers[134]->getOutputTensor(0), "SSCB", 6);
    (static_cast<MWConvLayer *>(layers[136]))
        ->createConvLayer(
            targetImpl, layers[135]->getOutputTensor(0), 3, 3, 64, 64, 1, 1, 1,
            1, 1, 1, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_22_cv2_0__"
            "12_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_22_cv2_0__"
            "12_b.bin",
            "SSCB", 0);
    (static_cast<MWSigmoidLayer *>(layers[137]))
        ->createSigmoidLayer(targetImpl, layers[136]->getOutputTensor(0),
                             "SSCB", 5);
    (static_cast<MWSigmoidLayer *>(layers[138]))
        ->createSigmoidLayer(targetImpl, layers[133]->getOutputTensor(0),
                             "SSCB", 6);
    (static_cast<nb_MWMultiplicationLayer_yolov8 *>(layers[139]))
        ->createCustomLayer(targetImpl, layers[133]->getOutputTensor(0),
                            layers[138]->getOutputTensor(0), "SSCB", 7);
    (static_cast<MWConvLayer *>(layers[140]))
        ->createConvLayer(
            targetImpl, layers[139]->getOutputTensor(0), 3, 3, 80, 80, 1, 1, 1,
            1, 1, 1, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_22_cv3_0__"
            "12_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_22_cv3_0__"
            "12_b.bin",
            "SSCB", 1);
    (static_cast<MWSigmoidLayer *>(layers[141]))
        ->createSigmoidLayer(targetImpl, layers[140]->getOutputTensor(0),
                             "SSCB", 6);
    (static_cast<ob_MWMultiplicationLayer_yolov8 *>(layers[142]))
        ->createCustomLayer(targetImpl, layers[136]->getOutputTensor(0),
                            layers[137]->getOutputTensor(0), "SSCB", 7);
    (static_cast<MWConvLayer *>(layers[143]))
        ->createConvLayer(
            targetImpl, layers[142]->getOutputTensor(0), 1, 1, 64, 64, 1, 1, 0,
            0, 0, 0, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_22_cv2_0__"
            "13_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_22_cv2_0__"
            "13_b.bin",
            "SSCB", 0);
    (static_cast<pb_MWMultiplicationLayer_yolov8 *>(layers[144]))
        ->createCustomLayer(targetImpl, layers[140]->getOutputTensor(0),
                            layers[141]->getOutputTensor(0), "SSCB", 5);
    (static_cast<MWConvLayer *>(layers[145]))
        ->createConvLayer(
            targetImpl, layers[144]->getOutputTensor(0), 1, 1, 80, 80, 1, 1, 0,
            0, 0, 0, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_22_cv3_0__"
            "13_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_22_cv3_0__"
            "13_b.bin",
            "SSCB", 1);
    (static_cast<MWConcatenationLayer *>(layers[146]))
        ->createConcatenationLayer(
            targetImpl, 2, layers[143]->getOutputTensor(0),
            layers[145]->getOutputTensor(0), 3, "C", "SSCB", 5);
    (static_cast<MWOutputLayer *>(layers[147]))
        ->createOutputLayer(targetImpl, layers[146]->getOutputTensor(0), "SSCB",
                            -1);
    (static_cast<MWConvLayer *>(layers[148]))
        ->createConvLayer(
            targetImpl, layers[131]->getOutputTensor(0), 3, 3, 64, 64, 2, 2, 1,
            1, 1, 1, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_16_conv_"
            "Co_1_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_16_conv_"
            "Co_1_b.bin",
            "SSCB", 0);
    (static_cast<MWSigmoidLayer *>(layers[149]))
        ->createSigmoidLayer(targetImpl, layers[148]->getOutputTensor(0),
                             "SSCB", 1);
    (static_cast<qb_MWMultiplicationLayer_yolov8 *>(layers[150]))
        ->createCustomLayer(targetImpl, layers[148]->getOutputTensor(0),
                            layers[149]->getOutputTensor(0), "SSCB", 2);
    (static_cast<MWConcatenationLayer *>(layers[151]))
        ->createConcatenationLayer(
            targetImpl, 2, layers[150]->getOutputTensor(0),
            layers[115]->getOutputTensor(0), 3, "C", "SSCB", 0);
    (static_cast<MWConvLayer *>(layers[152]))
        ->createConvLayer(
            targetImpl, layers[151]->getOutputTensor(0), 1, 1, 192, 128, 1, 1,
            0, 0, 0, 0, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_18_cv1_"
            "con_1_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_18_cv1_"
            "con_1_b.bin",
            "SSCB", 1);
    (static_cast<MWSigmoidLayer *>(layers[153]))
        ->createSigmoidLayer(targetImpl, layers[152]->getOutputTensor(0),
                             "SSCB", 0);
    (static_cast<rb_MWMultiplicationLayer_yolov8 *>(layers[154]))
        ->createCustomLayer(targetImpl, layers[152]->getOutputTensor(0),
                            layers[153]->getOutputTensor(0), "SSCB", 2);
    (static_cast<MWSplitLayer_yolov8n0_07 *>(layers[155]))
        ->createCustomLayer(targetImpl, layers[154]->getOutputTensor(0), "SSCB",
                            "SSCB", 0, 1);
    (static_cast<MWConvLayer *>(layers[156]))
        ->createConvLayer(
            targetImpl, layers[155]->getOutputTensor(0), 3, 3, 64, 64, 1, 1, 1,
            1, 1, 1, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_18_m_0_"
            "cv1_4_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_18_m_0_"
            "cv1_4_b.bin",
            "SSCB", 2);
    (static_cast<MWSigmoidLayer *>(layers[157]))
        ->createSigmoidLayer(targetImpl, layers[156]->getOutputTensor(0),
                             "SSCB", 3);
    (static_cast<sb_MWMultiplicationLayer_yolov8 *>(layers[158]))
        ->createCustomLayer(targetImpl, layers[156]->getOutputTensor(0),
                            layers[157]->getOutputTensor(0), "SSCB", 6);
    (static_cast<MWConvLayer *>(layers[159]))
        ->createConvLayer(
            targetImpl, layers[158]->getOutputTensor(0), 3, 3, 64, 64, 1, 1, 1,
            1, 1, 1, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_18_m_0_"
            "cv2_4_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_18_m_0_"
            "cv2_4_b.bin",
            "SSCB", 2);
    (static_cast<MWSigmoidLayer *>(layers[160]))
        ->createSigmoidLayer(targetImpl, layers[159]->getOutputTensor(0),
                             "SSCB", 3);
    (static_cast<tb_MWMultiplicationLayer_yolov8 *>(layers[161]))
        ->createCustomLayer(targetImpl, layers[159]->getOutputTensor(0),
                            layers[160]->getOutputTensor(0), "SSCB", 6);
    (static_cast<MWConcatenationLayer *>(layers[162]))
        ->createConcatenationLayer(
            targetImpl, 3, layers[155]->getOutputTensor(1),
            layers[155]->getOutputTensor(0), layers[161]->getOutputTensor(0), 3,
            "C", "SSCB", 2);
    (static_cast<MWConvLayer *>(layers[163]))
        ->createConvLayer(
            targetImpl, layers[162]->getOutputTensor(0), 1, 1, 192, 128, 1, 1,
            0, 0, 0, 0, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_18_cv2_"
            "con_1_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_18_cv2_"
            "con_1_b.bin",
            "SSCB", 0);
    (static_cast<MWSigmoidLayer *>(layers[164]))
        ->createSigmoidLayer(targetImpl, layers[163]->getOutputTensor(0),
                             "SSCB", 1);
    (static_cast<ub_MWMultiplicationLayer_yolov8 *>(layers[165]))
        ->createCustomLayer(targetImpl, layers[163]->getOutputTensor(0),
                            layers[164]->getOutputTensor(0), "SSCB", 2);
    (static_cast<MWConvLayer *>(layers[166]))
        ->createConvLayer(
            targetImpl, layers[165]->getOutputTensor(0), 3, 3, 128, 144, 1, 1,
            1, 1, 1, 1, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_22_cv3_1__"
            "9_w_fused.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_22_cv3_1__"
            "9_b_fused.bin",
            "SSCB", 0);
    (static_cast<MWSplittingLayer *>(layers[167]))
        ->createSplittingLayer(targetImpl, layers[166]->getOutputTensor(0), 2,
                               80, 64, 2, "SSCB", "SSCB", 1, 3);
    (static_cast<MWSigmoidLayer *>(layers[168]))
        ->createSigmoidLayer(targetImpl, layers[167]->getOutputTensor(1),
                             "SSCB", 0);
    (static_cast<vb_MWMultiplicationLayer_yolov8 *>(layers[169]))
        ->createCustomLayer(targetImpl, layers[167]->getOutputTensor(1),
                            layers[168]->getOutputTensor(0), "SSCB", 6);
    (static_cast<MWConvLayer *>(layers[170]))
        ->createConvLayer(
            targetImpl, layers[169]->getOutputTensor(0), 3, 3, 64, 64, 1, 1, 1,
            1, 1, 1, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_22_cv2_1__"
            "12_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_22_cv2_1__"
            "12_b.bin",
            "SSCB", 0);
    (static_cast<MWSigmoidLayer *>(layers[171]))
        ->createSigmoidLayer(targetImpl, layers[170]->getOutputTensor(0),
                             "SSCB", 3);
    (static_cast<MWSigmoidLayer *>(layers[172]))
        ->createSigmoidLayer(targetImpl, layers[167]->getOutputTensor(0),
                             "SSCB", 6);
    (static_cast<wb_MWMultiplicationLayer_yolov8 *>(layers[173]))
        ->createCustomLayer(targetImpl, layers[167]->getOutputTensor(0),
                            layers[172]->getOutputTensor(0), "SSCB", 7);
    (static_cast<MWConvLayer *>(layers[174]))
        ->createConvLayer(
            targetImpl, layers[173]->getOutputTensor(0), 3, 3, 80, 80, 1, 1, 1,
            1, 1, 1, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_22_cv3_1__"
            "12_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_22_cv3_1__"
            "12_b.bin",
            "SSCB", 1);
    (static_cast<MWSigmoidLayer *>(layers[175]))
        ->createSigmoidLayer(targetImpl, layers[174]->getOutputTensor(0),
                             "SSCB", 6);
    (static_cast<xb_MWMultiplicationLayer_yolov8 *>(layers[176]))
        ->createCustomLayer(targetImpl, layers[170]->getOutputTensor(0),
                            layers[171]->getOutputTensor(0), "SSCB", 7);
    (static_cast<MWConvLayer *>(layers[177]))
        ->createConvLayer(
            targetImpl, layers[176]->getOutputTensor(0), 1, 1, 64, 64, 1, 1, 0,
            0, 0, 0, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_22_cv2_1__"
            "13_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_22_cv2_1__"
            "13_b.bin",
            "SSCB", 0);
    (static_cast<yb_MWMultiplicationLayer_yolov8 *>(layers[178]))
        ->createCustomLayer(targetImpl, layers[174]->getOutputTensor(0),
                            layers[175]->getOutputTensor(0), "SSCB", 3);
    (static_cast<MWConvLayer *>(layers[179]))
        ->createConvLayer(
            targetImpl, layers[178]->getOutputTensor(0), 1, 1, 80, 80, 1, 1, 0,
            0, 0, 0, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_22_cv3_1__"
            "13_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_22_cv3_1__"
            "13_b.bin",
            "SSCB", 1);
    (static_cast<MWConcatenationLayer *>(layers[180]))
        ->createConcatenationLayer(
            targetImpl, 2, layers[177]->getOutputTensor(0),
            layers[179]->getOutputTensor(0), 3, "C", "SSCB", 3);
    (static_cast<MWOutputLayer *>(layers[181]))
        ->createOutputLayer(targetImpl, layers[180]->getOutputTensor(0), "SSCB",
                            -1);
    (static_cast<MWConvLayer *>(layers[182]))
        ->createConvLayer(
            targetImpl, layers[165]->getOutputTensor(0), 3, 3, 128, 128, 2, 2,
            1, 1, 1, 1, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_19_conv_"
            "Co_1_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_19_conv_"
            "Co_1_b.bin",
            "SSCB", 0);
    (static_cast<MWSigmoidLayer *>(layers[183]))
        ->createSigmoidLayer(targetImpl, layers[182]->getOutputTensor(0),
                             "SSCB", 1);
    (static_cast<ac_MWMultiplicationLayer_yolov8 *>(layers[184]))
        ->createCustomLayer(targetImpl, layers[182]->getOutputTensor(0),
                            layers[183]->getOutputTensor(0), "SSCB", 2);
    (static_cast<MWConcatenationLayer *>(layers[185]))
        ->createConcatenationLayer(
            targetImpl, 2, layers[184]->getOutputTensor(0),
            layers[99]->getOutputTensor(0), 3, "C", "SSCB", 0);
    (static_cast<MWConvLayer *>(layers[186]))
        ->createConvLayer(
            targetImpl, layers[185]->getOutputTensor(0), 1, 1, 384, 256, 1, 1,
            0, 0, 0, 0, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_21_cv1_"
            "con_1_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_21_cv1_"
            "con_1_b.bin",
            "SSCB", 1);
    (static_cast<MWSigmoidLayer *>(layers[187]))
        ->createSigmoidLayer(targetImpl, layers[186]->getOutputTensor(0),
                             "SSCB", 0);
    (static_cast<bc_MWMultiplicationLayer_yolov8 *>(layers[188]))
        ->createCustomLayer(targetImpl, layers[186]->getOutputTensor(0),
                            layers[187]->getOutputTensor(0), "SSCB", 2);
    (static_cast<MWSplitLayer_yolov8n0_08 *>(layers[189]))
        ->createCustomLayer(targetImpl, layers[188]->getOutputTensor(0), "SSCB",
                            "SSCB", 0, 1);
    (static_cast<MWConvLayer *>(layers[190]))
        ->createConvLayer(
            targetImpl, layers[189]->getOutputTensor(0), 3, 3, 128, 128, 1, 1,
            1, 1, 1, 1, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_21_m_0_"
            "cv1_4_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_21_m_0_"
            "cv1_4_b.bin",
            "SSCB", 2);
    (static_cast<MWSigmoidLayer *>(layers[191]))
        ->createSigmoidLayer(targetImpl, layers[190]->getOutputTensor(0),
                             "SSCB", 4);
    (static_cast<cc_MWMultiplicationLayer_yolov8 *>(layers[192]))
        ->createCustomLayer(targetImpl, layers[190]->getOutputTensor(0),
                            layers[191]->getOutputTensor(0), "SSCB", 6);
    (static_cast<MWConvLayer *>(layers[193]))
        ->createConvLayer(
            targetImpl, layers[192]->getOutputTensor(0), 3, 3, 128, 128, 1, 1,
            1, 1, 1, 1, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_21_m_0_"
            "cv2_4_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_21_m_0_"
            "cv2_4_b.bin",
            "SSCB", 2);
    (static_cast<MWSigmoidLayer *>(layers[194]))
        ->createSigmoidLayer(targetImpl, layers[193]->getOutputTensor(0),
                             "SSCB", 4);
    (static_cast<dc_MWMultiplicationLayer_yolov8 *>(layers[195]))
        ->createCustomLayer(targetImpl, layers[193]->getOutputTensor(0),
                            layers[194]->getOutputTensor(0), "SSCB", 6);
    (static_cast<MWConcatenationLayer *>(layers[196]))
        ->createConcatenationLayer(
            targetImpl, 3, layers[189]->getOutputTensor(1),
            layers[189]->getOutputTensor(0), layers[195]->getOutputTensor(0), 3,
            "C", "SSCB", 2);
    (static_cast<MWConvLayer *>(layers[197]))
        ->createConvLayer(
            targetImpl, layers[196]->getOutputTensor(0), 1, 1, 384, 256, 1, 1,
            0, 0, 0, 0, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_21_cv2_"
            "con_1_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_21_cv2_"
            "con_1_b.bin",
            "SSCB", 0);
    (static_cast<MWSigmoidLayer *>(layers[198]))
        ->createSigmoidLayer(targetImpl, layers[197]->getOutputTensor(0),
                             "SSCB", 1);
    (static_cast<ec_MWMultiplicationLayer_yolov8 *>(layers[199]))
        ->createCustomLayer(targetImpl, layers[197]->getOutputTensor(0),
                            layers[198]->getOutputTensor(0), "SSCB", 2);
    (static_cast<MWConvLayer *>(layers[200]))
        ->createConvLayer(
            targetImpl, layers[199]->getOutputTensor(0), 3, 3, 256, 144, 1, 1,
            1, 1, 1, 1, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_22_cv3_2__"
            "9_w_fused.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_22_cv3_2__"
            "9_b_fused.bin",
            "SSCB", 0);
    (static_cast<MWSplittingLayer *>(layers[201]))
        ->createSplittingLayer(targetImpl, layers[200]->getOutputTensor(0), 2,
                               80, 64, 2, "SSCB", "SSCB", 1, 2);
    (static_cast<MWSigmoidLayer *>(layers[202]))
        ->createSigmoidLayer(targetImpl, layers[201]->getOutputTensor(1),
                             "SSCB", 0);
    (static_cast<fc_MWMultiplicationLayer_yolov8 *>(layers[203]))
        ->createCustomLayer(targetImpl, layers[201]->getOutputTensor(1),
                            layers[202]->getOutputTensor(0), "SSCB", 4);
    (static_cast<MWConvLayer *>(layers[204]))
        ->createConvLayer(
            targetImpl, layers[203]->getOutputTensor(0), 3, 3, 64, 64, 1, 1, 1,
            1, 1, 1, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_22_cv2_2__"
            "12_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_22_cv2_2__"
            "12_b.bin",
            "SSCB", 0);
    (static_cast<MWSigmoidLayer *>(layers[205]))
        ->createSigmoidLayer(targetImpl, layers[204]->getOutputTensor(0),
                             "SSCB", 2);
    (static_cast<MWSigmoidLayer *>(layers[206]))
        ->createSigmoidLayer(targetImpl, layers[201]->getOutputTensor(0),
                             "SSCB", 4);
    (static_cast<gc_MWMultiplicationLayer_yolov8 *>(layers[207]))
        ->createCustomLayer(targetImpl, layers[201]->getOutputTensor(0),
                            layers[206]->getOutputTensor(0), "SSCB", 6);
    (static_cast<MWConvLayer *>(layers[208]))
        ->createConvLayer(
            targetImpl, layers[207]->getOutputTensor(0), 3, 3, 80, 80, 1, 1, 1,
            1, 1, 1, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_22_cv3_2__"
            "12_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_22_cv3_2__"
            "12_b.bin",
            "SSCB", 1);
    (static_cast<MWSigmoidLayer *>(layers[209]))
        ->createSigmoidLayer(targetImpl, layers[208]->getOutputTensor(0),
                             "SSCB", 4);
    (static_cast<hc_MWMultiplicationLayer_yolov8 *>(layers[210]))
        ->createCustomLayer(targetImpl, layers[204]->getOutputTensor(0),
                            layers[205]->getOutputTensor(0), "SSCB", 6);
    (static_cast<MWConvLayer *>(layers[211]))
        ->createConvLayer(
            targetImpl, layers[210]->getOutputTensor(0), 1, 1, 64, 64, 1, 1, 0,
            0, 0, 0, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_22_cv2_2__"
            "13_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_22_cv2_2__"
            "13_b.bin",
            "SSCB", 0);
    (static_cast<ic_MWMultiplicationLayer_yolov8 *>(layers[212]))
        ->createCustomLayer(targetImpl, layers[208]->getOutputTensor(0),
                            layers[209]->getOutputTensor(0), "SSCB", 2);
    (static_cast<MWConvLayer *>(layers[213]))
        ->createConvLayer(
            targetImpl, layers[212]->getOutputTensor(0), 1, 1, 80, 80, 1, 1, 0,
            0, 0, 0, 1, 1, 1,
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_22_cv3_2__"
            "13_w.bin",
            "C:\\Users\\PiotrH\\AppData\\Roaming\\MathWorks\\MATLAB "
            "Add-Ons\\Collections\\Object Detection And Instance Segmentation "
            "Using YO"
            "LO "
            "v8\\codegen\\mex\\yolov8Predict\\cnn_yolov8n0_0_x_model_22_cv3_2__"
            "13_b.bin",
            "SSCB", 1);
    (static_cast<MWConcatenationLayer *>(layers[214]))
        ->createConcatenationLayer(
            targetImpl, 2, layers[211]->getOutputTensor(0),
            layers[213]->getOutputTensor(0), 3, "C", "SSCB", 2);
    (static_cast<MWOutputLayer *>(layers[215]))
        ->createOutputLayer(targetImpl, layers[214]->getOutputTensor(0), "SSCB",
                            -1);
    outputTensors[0] = layers[147]->getOutputTensor(0);
    outputTensors[1] = layers[181]->getOutputTensor(0);
    outputTensors[2] = layers[215]->getOutputTensor(0);
    setSize();
  }
  isInitialized = true;
}

static void checkCleanupRunTimeError(const char_T *errMsg, const char_T *file,
                                     uint32_T b_line)
{
  emlrtRTEInfo rtInfo;
  uint32_T errMsgLen;
  rtInfo = createEmlrtInfoStruct(file, b_line);
  errMsgLen = (uint32_T)strlen(errMsg);
  emlrtErrorWithMessageIdR2018a(emlrtRootTLSGlobal, &rtInfo,
                                "dnn_core:cnncodegen:CleanupRunTimeError",
                                "dnn_core:cnncodegen:CleanupRunTimeError", 3,
                                mxCHAR_CLASS, errMsgLen, errMsg);
}

void yolov8n0_0::activations(yolov8PredictStackData *SD, int32_T layerIdx)
{
  (static_cast<MWResize2DLayer_yolov8n0_02 *>(layers[116]))
      ->setStackDataPtr(SD);
  (static_cast<MWResize2DLayer_yolov8n0_01 *>(layers[100]))
      ->setStackDataPtr(SD);
  for (int32_T idx{0}; idx <= layerIdx; idx++) {
    layers[idx]->predict();
  }
}

int32_T yolov8n0_0::getBatchSize()
{
  return inputTensors[0]->getBatchSize();
}

real32_T *yolov8n0_0::getInputDataPointer(int32_T b_index)
{
  return (static_cast<MWTensor<real32_T> *>(inputTensors[b_index]))->getData();
}

real32_T *yolov8n0_0::getInputDataPointer()
{
  return (static_cast<MWTensor<real32_T> *>(inputTensors[0]))->getData();
}

real32_T *yolov8n0_0::getLayerOutput(int32_T layerIndex, int32_T portIndex)
{
  MWCNNLayer *b_this[216];
  for (int32_T b{0}; b < 216; b++) {
    b_this[b] = layers[b];
  }
  return targetImpl->getLayerOutput(b_this, layerIndex, portIndex);
}

int32_T yolov8n0_0::getLayerOutputSize(int32_T layerIndex, int32_T portIndex)
{
  return static_cast<uint32_T>(
             layers[layerIndex]->getOutputTensor(portIndex)->getNumElements()) *
         sizeof(real32_T);
}

real32_T *yolov8n0_0::getOutputDataPointer(int32_T b_index)
{
  return (static_cast<MWTensor<real32_T> *>(outputTensors[b_index]))->getData();
}

real32_T *yolov8n0_0::getOutputDataPointer()
{
  return (static_cast<MWTensor<real32_T> *>(outputTensors[0]))->getData();
}

int32_T yolov8n0_0::getOutputSequenceLength(int32_T layerIndex,
                                            int32_T portIndex)
{
  return layers[layerIndex]->getOutputTensor(portIndex)->getSequenceLength();
}

yolov8n0_0::yolov8n0_0()
{
  numLayers = 216;
  isInitialized = false;
  targetImpl = 0;
  layers[0] = new MWInputLayer;
  layers[0]->setName("images");
  layers[1] = new MWConvLayer;
  layers[1]->setName("x_model_0_conv_Conv");
  layers[2] = new MWSigmoidLayer;
  layers[2]->setName("x_model_0_act_Sigm_1");
  layers[3] = new c_MWMultiplicationLayer_yolov8n;
  layers[3]->setName("x_model_0_act_Mul");
  layers[4] = new MWConvLayer;
  layers[4]->setName("x_model_1_conv_Conv");
  layers[5] = new MWSigmoidLayer;
  layers[5]->setName("x_model_1_act_Sigm_1");
  layers[6] = new d_MWMultiplicationLayer_yolov8n;
  layers[6]->setName("x_model_1_act_Mul");
  layers[7] = new MWConvLayer;
  layers[7]->setName("x_model_2_cv1_conv_1");
  layers[8] = new MWSigmoidLayer;
  layers[8]->setName("x_model_2_cv1_act__2");
  layers[9] = new e_MWMultiplicationLayer_yolov8n;
  layers[9]->setName("x_model_2_cv1_act__1");
  layers[10] = new MWSplitLayer_yolov8n0_01;
  layers[10]->setName("splitLayer1");
  layers[11] = new MWConvLayer;
  layers[11]->setName("x_model_2_m_0_cv1__4");
  layers[12] = new MWSigmoidLayer;
  layers[12]->setName("x_model_2_m_0_cv1__3");
  layers[13] = new f_MWMultiplicationLayer_yolov8n;
  layers[13]->setName("x_model_2_m_0_cv1__2");
  layers[14] = new MWConvLayer;
  layers[14]->setName("x_model_2_m_0_cv2__4");
  layers[15] = new MWSigmoidLayer;
  layers[15]->setName("x_model_2_m_0_cv2__3");
  layers[16] = new g_MWMultiplicationLayer_yolov8n;
  layers[16]->setName("x_model_2_m_0_cv2__2");
  layers[17] = new MWAdditionLayer;
  layers[17]->setName("x_model_2_m_0_Add");
  layers[18] = new MWConcatenationLayer;
  layers[18]->setName("x_model_2_Concat");
  layers[19] = new MWConvLayer;
  layers[19]->setName("x_model_2_cv2_conv_1");
  layers[20] = new MWSigmoidLayer;
  layers[20]->setName("x_model_2_cv2_act__2");
  layers[21] = new h_MWMultiplicationLayer_yolov8n;
  layers[21]->setName("x_model_2_cv2_act__1");
  layers[22] = new MWConvLayer;
  layers[22]->setName("x_model_3_conv_Conv");
  layers[23] = new MWSigmoidLayer;
  layers[23]->setName("x_model_3_act_Sigm_1");
  layers[24] = new i_MWMultiplicationLayer_yolov8n;
  layers[24]->setName("x_model_3_act_Mul");
  layers[25] = new MWConvLayer;
  layers[25]->setName("x_model_4_cv1_conv_1");
  layers[26] = new MWSigmoidLayer;
  layers[26]->setName("x_model_4_cv1_act__2");
  layers[27] = new j_MWMultiplicationLayer_yolov8n;
  layers[27]->setName("x_model_4_cv1_act__1");
  layers[28] = new MWSplitLayer_yolov8n0_02;
  layers[28]->setName("splitLayer2");
  layers[29] = new MWConvLayer;
  layers[29]->setName("x_model_4_m_0_cv1__4");
  layers[30] = new MWSigmoidLayer;
  layers[30]->setName("x_model_4_m_0_cv1__3");
  layers[31] = new k_MWMultiplicationLayer_yolov8n;
  layers[31]->setName("x_model_4_m_0_cv1__2");
  layers[32] = new MWConvLayer;
  layers[32]->setName("x_model_4_m_0_cv2__4");
  layers[33] = new MWSigmoidLayer;
  layers[33]->setName("x_model_4_m_0_cv2__3");
  layers[34] = new l_MWMultiplicationLayer_yolov8n;
  layers[34]->setName("x_model_4_m_0_cv2__2");
  layers[35] = new MWAdditionLayer;
  layers[35]->setName("x_model_4_m_0_Add");
  layers[36] = new MWConvLayer;
  layers[36]->setName("x_model_4_m_1_cv1__4");
  layers[37] = new MWSigmoidLayer;
  layers[37]->setName("x_model_4_m_1_cv1__3");
  layers[38] = new m_MWMultiplicationLayer_yolov8n;
  layers[38]->setName("x_model_4_m_1_cv1__2");
  layers[39] = new MWConvLayer;
  layers[39]->setName("x_model_4_m_1_cv2__4");
  layers[40] = new MWSigmoidLayer;
  layers[40]->setName("x_model_4_m_1_cv2__3");
  layers[41] = new n_MWMultiplicationLayer_yolov8n;
  layers[41]->setName("x_model_4_m_1_cv2__2");
  layers[42] = new MWAdditionLayer;
  layers[42]->setName("x_model_4_m_1_Add");
  layers[43] = new MWConcatenationLayer;
  layers[43]->setName("x_model_4_Concat");
  layers[44] = new MWConvLayer;
  layers[44]->setName("x_model_4_cv2_conv_1");
  layers[45] = new MWSigmoidLayer;
  layers[45]->setName("x_model_4_cv2_act__2");
  layers[46] = new o_MWMultiplicationLayer_yolov8n;
  layers[46]->setName("x_model_4_cv2_act__1");
  layers[47] = new MWConvLayer;
  layers[47]->setName("x_model_5_conv_Conv");
  layers[48] = new MWSigmoidLayer;
  layers[48]->setName("x_model_5_act_Sigm_1");
  layers[49] = new p_MWMultiplicationLayer_yolov8n;
  layers[49]->setName("x_model_5_act_Mul");
  layers[50] = new MWConvLayer;
  layers[50]->setName("x_model_6_cv1_conv_1");
  layers[51] = new MWSigmoidLayer;
  layers[51]->setName("x_model_6_cv1_act__2");
  layers[52] = new q_MWMultiplicationLayer_yolov8n;
  layers[52]->setName("x_model_6_cv1_act__1");
  layers[53] = new MWSplitLayer_yolov8n0_03;
  layers[53]->setName("splitLayer3");
  layers[54] = new MWConvLayer;
  layers[54]->setName("x_model_6_m_0_cv1__4");
  layers[55] = new MWSigmoidLayer;
  layers[55]->setName("x_model_6_m_0_cv1__3");
  layers[56] = new r_MWMultiplicationLayer_yolov8n;
  layers[56]->setName("x_model_6_m_0_cv1__2");
  layers[57] = new MWConvLayer;
  layers[57]->setName("x_model_6_m_0_cv2__4");
  layers[58] = new MWSigmoidLayer;
  layers[58]->setName("x_model_6_m_0_cv2__3");
  layers[59] = new s_MWMultiplicationLayer_yolov8n;
  layers[59]->setName("x_model_6_m_0_cv2__2");
  layers[60] = new MWAdditionLayer;
  layers[60]->setName("x_model_6_m_0_Add");
  layers[61] = new MWConvLayer;
  layers[61]->setName("x_model_6_m_1_cv1__4");
  layers[62] = new MWSigmoidLayer;
  layers[62]->setName("x_model_6_m_1_cv1__3");
  layers[63] = new t_MWMultiplicationLayer_yolov8n;
  layers[63]->setName("x_model_6_m_1_cv1__2");
  layers[64] = new MWConvLayer;
  layers[64]->setName("x_model_6_m_1_cv2__4");
  layers[65] = new MWSigmoidLayer;
  layers[65]->setName("x_model_6_m_1_cv2__3");
  layers[66] = new u_MWMultiplicationLayer_yolov8n;
  layers[66]->setName("x_model_6_m_1_cv2__2");
  layers[67] = new MWAdditionLayer;
  layers[67]->setName("x_model_6_m_1_Add");
  layers[68] = new MWConcatenationLayer;
  layers[68]->setName("x_model_6_Concat");
  layers[69] = new MWConvLayer;
  layers[69]->setName("x_model_6_cv2_conv_1");
  layers[70] = new MWSigmoidLayer;
  layers[70]->setName("x_model_6_cv2_act__2");
  layers[71] = new v_MWMultiplicationLayer_yolov8n;
  layers[71]->setName("x_model_6_cv2_act__1");
  layers[72] = new MWConvLayer;
  layers[72]->setName("x_model_7_conv_Conv");
  layers[73] = new MWSigmoidLayer;
  layers[73]->setName("x_model_7_act_Sigm_1");
  layers[74] = new w_MWMultiplicationLayer_yolov8n;
  layers[74]->setName("x_model_7_act_Mul");
  layers[75] = new MWConvLayer;
  layers[75]->setName("x_model_8_cv1_conv_1");
  layers[76] = new MWSigmoidLayer;
  layers[76]->setName("x_model_8_cv1_act__2");
  layers[77] = new x_MWMultiplicationLayer_yolov8n;
  layers[77]->setName("x_model_8_cv1_act__1");
  layers[78] = new MWSplitLayer_yolov8n0_04;
  layers[78]->setName("splitLayer4");
  layers[79] = new MWConvLayer;
  layers[79]->setName("x_model_8_m_0_cv1__4");
  layers[80] = new MWSigmoidLayer;
  layers[80]->setName("x_model_8_m_0_cv1__3");
  layers[81] = new y_MWMultiplicationLayer_yolov8n;
  layers[81]->setName("x_model_8_m_0_cv1__2");
  layers[82] = new MWConvLayer;
  layers[82]->setName("x_model_8_m_0_cv2__4");
  layers[83] = new MWSigmoidLayer;
  layers[83]->setName("x_model_8_m_0_cv2__3");
  layers[84] = new ab_MWMultiplicationLayer_yolov8;
  layers[84]->setName("x_model_8_m_0_cv2__2");
  layers[85] = new MWAdditionLayer;
  layers[85]->setName("x_model_8_m_0_Add");
  layers[86] = new MWConcatenationLayer;
  layers[86]->setName("x_model_8_Concat");
  layers[87] = new MWConvLayer;
  layers[87]->setName("x_model_8_cv2_conv_1");
  layers[88] = new MWSigmoidLayer;
  layers[88]->setName("x_model_8_cv2_act__2");
  layers[89] = new bb_MWMultiplicationLayer_yolov8;
  layers[89]->setName("x_model_8_cv2_act__1");
  layers[90] = new MWConvLayer;
  layers[90]->setName("x_model_9_cv1_conv_1");
  layers[91] = new MWSigmoidLayer;
  layers[91]->setName("x_model_9_cv1_act__2");
  layers[92] = new cb_MWMultiplicationLayer_yolov8;
  layers[92]->setName("x_model_9_cv1_act__1");
  layers[93] = new MWMaxPoolingLayer;
  layers[93]->setName("x_model_9_m_MaxPool");
  layers[94] = new MWMaxPoolingLayer;
  layers[94]->setName("x_model_9_m_1_MaxP_1");
  layers[95] = new MWMaxPoolingLayer;
  layers[95]->setName("x_model_9_m_2_MaxP_1");
  layers[96] = new MWConcatenationLayer;
  layers[96]->setName("x_model_9_Concat");
  layers[97] = new MWConvLayer;
  layers[97]->setName("x_model_9_cv2_conv_1");
  layers[98] = new MWSigmoidLayer;
  layers[98]->setName("x_model_9_cv2_act__2");
  layers[99] = new db_MWMultiplicationLayer_yolov8;
  layers[99]->setName("x_model_9_cv2_act__1");
  layers[100] = new MWResize2DLayer_yolov8n0_01;
  layers[100]->setName("resize1");
  layers[101] = new MWConcatenationLayer;
  layers[101]->setName("x_model_11_Concat");
  layers[102] = new MWConvLayer;
  layers[102]->setName("x_model_12_cv1_con_1");
  layers[103] = new MWSigmoidLayer;
  layers[103]->setName("x_model_12_cv1_act_2");
  layers[104] = new eb_MWMultiplicationLayer_yolov8;
  layers[104]->setName("x_model_12_cv1_act_1");
  layers[105] = new MWSplitLayer_yolov8n0_05;
  layers[105]->setName("splitLayer5");
  layers[106] = new MWConvLayer;
  layers[106]->setName("x_model_12_m_0_cv1_4");
  layers[107] = new MWSigmoidLayer;
  layers[107]->setName("x_model_12_m_0_cv1_3");
  layers[108] = new fb_MWMultiplicationLayer_yolov8;
  layers[108]->setName("x_model_12_m_0_cv1_2");
  layers[109] = new MWConvLayer;
  layers[109]->setName("x_model_12_m_0_cv2_4");
  layers[110] = new MWSigmoidLayer;
  layers[110]->setName("x_model_12_m_0_cv2_3");
  layers[111] = new gb_MWMultiplicationLayer_yolov8;
  layers[111]->setName("x_model_12_m_0_cv2_2");
  layers[112] = new MWConcatenationLayer;
  layers[112]->setName("x_model_12_Concat");
  layers[113] = new MWConvLayer;
  layers[113]->setName("x_model_12_cv2_con_1");
  layers[114] = new MWSigmoidLayer;
  layers[114]->setName("x_model_12_cv2_act_2");
  layers[115] = new hb_MWMultiplicationLayer_yolov8;
  layers[115]->setName("x_model_12_cv2_act_1");
  layers[116] = new MWResize2DLayer_yolov8n0_02;
  layers[116]->setName("resize2");
  layers[117] = new MWConcatenationLayer;
  layers[117]->setName("x_model_14_Concat");
  layers[118] = new MWConvLayer;
  layers[118]->setName("x_model_15_cv1_con_1");
  layers[119] = new MWSigmoidLayer;
  layers[119]->setName("x_model_15_cv1_act_2");
  layers[120] = new ib_MWMultiplicationLayer_yolov8;
  layers[120]->setName("x_model_15_cv1_act_1");
  layers[121] = new MWSplitLayer_yolov8n0_06;
  layers[121]->setName("splitLayer6");
  layers[122] = new MWConvLayer;
  layers[122]->setName("x_model_15_m_0_cv1_4");
  layers[123] = new MWSigmoidLayer;
  layers[123]->setName("x_model_15_m_0_cv1_3");
  layers[124] = new jb_MWMultiplicationLayer_yolov8;
  layers[124]->setName("x_model_15_m_0_cv1_2");
  layers[125] = new MWConvLayer;
  layers[125]->setName("x_model_15_m_0_cv2_4");
  layers[126] = new MWSigmoidLayer;
  layers[126]->setName("x_model_15_m_0_cv2_3");
  layers[127] = new kb_MWMultiplicationLayer_yolov8;
  layers[127]->setName("x_model_15_m_0_cv2_2");
  layers[128] = new MWConcatenationLayer;
  layers[128]->setName("x_model_15_Concat");
  layers[129] = new MWConvLayer;
  layers[129]->setName("x_model_15_cv2_con_1");
  layers[130] = new MWSigmoidLayer;
  layers[130]->setName("x_model_15_cv2_act_2");
  layers[131] = new lb_MWMultiplicationLayer_yolov8;
  layers[131]->setName("x_model_15_cv2_act_1");
  layers[132] = new MWConvLayer;
  layers[132]->setName("x_model_22_cv3_0__9_fused");
  layers[133] = new MWSplittingLayer;
  layers[133]->setName("x_model_22_cv3_0__9_fused_channelSplit");
  layers[134] = new MWSigmoidLayer;
  layers[134]->setName("x_model_22_cv2_0__8");
  layers[135] = new mb_MWMultiplicationLayer_yolov8;
  layers[135]->setName("x_model_22_cv2_0__7");
  layers[136] = new MWConvLayer;
  layers[136]->setName("x_model_22_cv2_0__12");
  layers[137] = new MWSigmoidLayer;
  layers[137]->setName("x_model_22_cv2_0__11");
  layers[138] = new MWSigmoidLayer;
  layers[138]->setName("x_model_22_cv3_0__8");
  layers[139] = new nb_MWMultiplicationLayer_yolov8;
  layers[139]->setName("x_model_22_cv3_0__7");
  layers[140] = new MWConvLayer;
  layers[140]->setName("x_model_22_cv3_0__12");
  layers[141] = new MWSigmoidLayer;
  layers[141]->setName("x_model_22_cv3_0__11");
  layers[142] = new ob_MWMultiplicationLayer_yolov8;
  layers[142]->setName("x_model_22_cv2_0__10");
  layers[143] = new MWConvLayer;
  layers[143]->setName("x_model_22_cv2_0__13");
  layers[144] = new pb_MWMultiplicationLayer_yolov8;
  layers[144]->setName("x_model_22_cv3_0__10");
  layers[145] = new MWConvLayer;
  layers[145]->setName("x_model_22_cv3_0__13");
  layers[146] = new MWConcatenationLayer;
  layers[146]->setName("x_model_22_Concat");
  layers[147] = new MWOutputLayer;
  layers[147]->setName("output_x_model_22_Concat");
  layers[147]->setInPlaceIndex(0, 0);
  layers[148] = new MWConvLayer;
  layers[148]->setName("x_model_16_conv_Co_1");
  layers[149] = new MWSigmoidLayer;
  layers[149]->setName("x_model_16_act_Sig_1");
  layers[150] = new qb_MWMultiplicationLayer_yolov8;
  layers[150]->setName("x_model_16_act_Mul");
  layers[151] = new MWConcatenationLayer;
  layers[151]->setName("x_model_17_Concat");
  layers[152] = new MWConvLayer;
  layers[152]->setName("x_model_18_cv1_con_1");
  layers[153] = new MWSigmoidLayer;
  layers[153]->setName("x_model_18_cv1_act_2");
  layers[154] = new rb_MWMultiplicationLayer_yolov8;
  layers[154]->setName("x_model_18_cv1_act_1");
  layers[155] = new MWSplitLayer_yolov8n0_07;
  layers[155]->setName("splitLayer7");
  layers[156] = new MWConvLayer;
  layers[156]->setName("x_model_18_m_0_cv1_4");
  layers[157] = new MWSigmoidLayer;
  layers[157]->setName("x_model_18_m_0_cv1_3");
  layers[158] = new sb_MWMultiplicationLayer_yolov8;
  layers[158]->setName("x_model_18_m_0_cv1_2");
  layers[159] = new MWConvLayer;
  layers[159]->setName("x_model_18_m_0_cv2_4");
  layers[160] = new MWSigmoidLayer;
  layers[160]->setName("x_model_18_m_0_cv2_3");
  layers[161] = new tb_MWMultiplicationLayer_yolov8;
  layers[161]->setName("x_model_18_m_0_cv2_2");
  layers[162] = new MWConcatenationLayer;
  layers[162]->setName("x_model_18_Concat");
  layers[163] = new MWConvLayer;
  layers[163]->setName("x_model_18_cv2_con_1");
  layers[164] = new MWSigmoidLayer;
  layers[164]->setName("x_model_18_cv2_act_2");
  layers[165] = new ub_MWMultiplicationLayer_yolov8;
  layers[165]->setName("x_model_18_cv2_act_1");
  layers[166] = new MWConvLayer;
  layers[166]->setName("x_model_22_cv3_1__9_fused");
  layers[167] = new MWSplittingLayer;
  layers[167]->setName("x_model_22_cv3_1__9_fused_channelSplit");
  layers[168] = new MWSigmoidLayer;
  layers[168]->setName("x_model_22_cv2_1__8");
  layers[169] = new vb_MWMultiplicationLayer_yolov8;
  layers[169]->setName("x_model_22_cv2_1__7");
  layers[170] = new MWConvLayer;
  layers[170]->setName("x_model_22_cv2_1__12");
  layers[171] = new MWSigmoidLayer;
  layers[171]->setName("x_model_22_cv2_1__11");
  layers[172] = new MWSigmoidLayer;
  layers[172]->setName("x_model_22_cv3_1__8");
  layers[173] = new wb_MWMultiplicationLayer_yolov8;
  layers[173]->setName("x_model_22_cv3_1__7");
  layers[174] = new MWConvLayer;
  layers[174]->setName("x_model_22_cv3_1__12");
  layers[175] = new MWSigmoidLayer;
  layers[175]->setName("x_model_22_cv3_1__11");
  layers[176] = new xb_MWMultiplicationLayer_yolov8;
  layers[176]->setName("x_model_22_cv2_1__10");
  layers[177] = new MWConvLayer;
  layers[177]->setName("x_model_22_cv2_1__13");
  layers[178] = new yb_MWMultiplicationLayer_yolov8;
  layers[178]->setName("x_model_22_cv3_1__10");
  layers[179] = new MWConvLayer;
  layers[179]->setName("x_model_22_cv3_1__13");
  layers[180] = new MWConcatenationLayer;
  layers[180]->setName("x_model_22_Concat_1");
  layers[181] = new MWOutputLayer;
  layers[181]->setName("output_x_model_22_Concat_1");
  layers[181]->setInPlaceIndex(0, 0);
  layers[182] = new MWConvLayer;
  layers[182]->setName("x_model_19_conv_Co_1");
  layers[183] = new MWSigmoidLayer;
  layers[183]->setName("x_model_19_act_Sig_1");
  layers[184] = new ac_MWMultiplicationLayer_yolov8;
  layers[184]->setName("x_model_19_act_Mul");
  layers[185] = new MWConcatenationLayer;
  layers[185]->setName("x_model_20_Concat");
  layers[186] = new MWConvLayer;
  layers[186]->setName("x_model_21_cv1_con_1");
  layers[187] = new MWSigmoidLayer;
  layers[187]->setName("x_model_21_cv1_act_2");
  layers[188] = new bc_MWMultiplicationLayer_yolov8;
  layers[188]->setName("x_model_21_cv1_act_1");
  layers[189] = new MWSplitLayer_yolov8n0_08;
  layers[189]->setName("splitLayer8");
  layers[190] = new MWConvLayer;
  layers[190]->setName("x_model_21_m_0_cv1_4");
  layers[191] = new MWSigmoidLayer;
  layers[191]->setName("x_model_21_m_0_cv1_3");
  layers[192] = new cc_MWMultiplicationLayer_yolov8;
  layers[192]->setName("x_model_21_m_0_cv1_2");
  layers[193] = new MWConvLayer;
  layers[193]->setName("x_model_21_m_0_cv2_4");
  layers[194] = new MWSigmoidLayer;
  layers[194]->setName("x_model_21_m_0_cv2_3");
  layers[195] = new dc_MWMultiplicationLayer_yolov8;
  layers[195]->setName("x_model_21_m_0_cv2_2");
  layers[196] = new MWConcatenationLayer;
  layers[196]->setName("x_model_21_Concat");
  layers[197] = new MWConvLayer;
  layers[197]->setName("x_model_21_cv2_con_1");
  layers[198] = new MWSigmoidLayer;
  layers[198]->setName("x_model_21_cv2_act_2");
  layers[199] = new ec_MWMultiplicationLayer_yolov8;
  layers[199]->setName("x_model_21_cv2_act_1");
  layers[200] = new MWConvLayer;
  layers[200]->setName("x_model_22_cv3_2__9_fused");
  layers[201] = new MWSplittingLayer;
  layers[201]->setName("x_model_22_cv3_2__9_fused_channelSplit");
  layers[202] = new MWSigmoidLayer;
  layers[202]->setName("x_model_22_cv2_2__8");
  layers[203] = new fc_MWMultiplicationLayer_yolov8;
  layers[203]->setName("x_model_22_cv2_2__7");
  layers[204] = new MWConvLayer;
  layers[204]->setName("x_model_22_cv2_2__12");
  layers[205] = new MWSigmoidLayer;
  layers[205]->setName("x_model_22_cv2_2__11");
  layers[206] = new MWSigmoidLayer;
  layers[206]->setName("x_model_22_cv3_2__8");
  layers[207] = new gc_MWMultiplicationLayer_yolov8;
  layers[207]->setName("x_model_22_cv3_2__7");
  layers[208] = new MWConvLayer;
  layers[208]->setName("x_model_22_cv3_2__12");
  layers[209] = new MWSigmoidLayer;
  layers[209]->setName("x_model_22_cv3_2__11");
  layers[210] = new hc_MWMultiplicationLayer_yolov8;
  layers[210]->setName("x_model_22_cv2_2__10");
  layers[211] = new MWConvLayer;
  layers[211]->setName("x_model_22_cv2_2__13");
  layers[212] = new ic_MWMultiplicationLayer_yolov8;
  layers[212]->setName("x_model_22_cv3_2__10");
  layers[213] = new MWConvLayer;
  layers[213]->setName("x_model_22_cv3_2__13");
  layers[214] = new MWConcatenationLayer;
  layers[214]->setName("x_model_22_Concat_2");
  layers[215] = new MWOutputLayer;
  layers[215]->setName("output_x_model_22_Concat_2");
  layers[215]->setInPlaceIndex(0, 0);
  targetImpl = new MWOnednnTarget::MWTargetNetworkImpl;
  inputTensors[0] = new MWTensor<real32_T>;
  inputTensors[0]->setHeight(544);
  inputTensors[0]->setWidth(640);
  inputTensors[0]->setChannels(3);
  inputTensors[0]->setBatchSize(1);
  inputTensors[0]->setSequenceLength(1);
}

yolov8n0_0::~yolov8n0_0()
{
  emlrtSetIsInDestructor((emlrtCTX *)emlrtRootTLSGlobal, true);
  try {
    if (isInitialized) {
      cleanup();
    }
    for (int32_T idx{0}; idx < 216; idx++) {
      delete layers[idx];
    }
    if (targetImpl) {
      delete targetImpl;
    }
    delete inputTensors[0];
  } catch (...) {
  }
  emlrtSetIsInDestructor((emlrtCTX *)emlrtRootTLSGlobal, false);
}

namespace coder {
namespace internal {
void dlnetwork_delete(yolov8n0_0 &obj)
{
  if (obj.isInitialized) {
    obj.cleanup();
  }
}

void dlnetwork_setup(const emlrtStack &sp, yolov8n0_0 &obj)
{
  emlrtStack st;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &g_emlrtRSI;
  try {
    obj.setup();
  } catch (std::runtime_error const &err) {
    obj.cleanup();
    checkRunTimeError(st, err.what(), __FILE__, __LINE__);
  } catch (...) {
    obj.cleanup();
    checkRunTimeError(st, "", __FILE__, __LINE__);
  }
}

void e_dlnetwork_layerPredictWithCol(const real32_T varargin_1[1392640],
                                     const real32_T varargin_2[1392640],
                                     real32_T varargout_1[1392640])
{
  for (int32_T i{0}; i <= 1392636; i += 4) {
    _mm_storeu_ps(&varargout_1[i], _mm_mul_ps(_mm_loadu_ps(&varargin_1[i]),
                                              _mm_loadu_ps(&varargin_2[i])));
  }
}

void e_dlnetwork_layerPredictWithCol(yolov8PredictStackData *SD,
                                     const real32_T varargin_1[87040],
                                     real32_T varargout_1[348160])
{
  static const int8_T xq[34]{1,  1,  2,  2,  3,  3,  4,  4,  5,  5,  6,  6,
                             7,  7,  8,  8,  9,  9,  10, 10, 11, 11, 12, 12,
                             13, 13, 14, 14, 15, 15, 16, 16, 17, 17};
  for (int32_T i{0}; i < 34; i++) {
    int8_T b_i;
    b_i = xq[i];
    for (int32_T j{0}; j < 5120; j++) {
      SD->f3.out[i + 34 * j] = varargin_1[(b_i + 17 * j) - 1];
    }
  }
  for (int32_T i{0}; i < 256; i++) {
    for (int32_T j{0}; j < 20; j++) {
      for (int32_T k{0}; k < 34; k++) {
        SD->f3.b_b[(j + 20 * k) + 680 * i] = SD->f3.out[(k + 34 * j) + 680 * i];
      }
    }
  }
  nnet::cnn::layer::Resize2DLayer::interp1CustomImpl(SD->f3.b_b, SD->f3.b);
  for (int32_T i{0}; i < 256; i++) {
    for (int32_T j{0}; j < 34; j++) {
      for (int32_T k{0}; k < 40; k++) {
        varargout_1[(j + 34 * k) + 1360 * i] =
            SD->f3.b[(k + 40 * j) + 1360 * i];
      }
    }
  }
}

void f_dlnetwork_layerPredictWithCol(const real32_T varargin_1[696320],
                                     const real32_T varargin_2[696320],
                                     real32_T varargout_1[696320])
{
  for (int32_T i{0}; i <= 696316; i += 4) {
    _mm_storeu_ps(&varargout_1[i], _mm_mul_ps(_mm_loadu_ps(&varargin_1[i]),
                                              _mm_loadu_ps(&varargin_2[i])));
  }
}

void f_dlnetwork_layerPredictWithCol(yolov8PredictStackData *SD,
                                     const real32_T varargin_1[174080],
                                     real32_T varargout_1[696320])
{
  nnet::cnn::layer::Resize2DLayer::interpAlongSpatialDim(varargin_1, SD->f4.a);
  for (int32_T k{0}; k < 128; k++) {
    for (int32_T b_k{0}; b_k < 40; b_k++) {
      for (int32_T c_k{0}; c_k < 68; c_k++) {
        SD->f4.b_b[(b_k + 40 * c_k) + 2720 * k] =
            SD->f4.a[(c_k + 68 * b_k) + 2720 * k];
      }
    }
  }
  nnet::cnn::layer::Resize2DLayer::b_interp1CustomImpl(SD->f4.b_b, SD->f4.b);
  for (int32_T k{0}; k < 128; k++) {
    for (int32_T b_k{0}; b_k < 68; b_k++) {
      for (int32_T c_k{0}; c_k < 80; c_k++) {
        varargout_1[(b_k + 68 * c_k) + 5440 * k] =
            SD->f4.b[(c_k + 80 * b_k) + 5440 * k];
      }
    }
  }
}

void g_dlnetwork_layerPredictWithCol(const real32_T varargin_1[696320],
                                     real32_T varargout_1[348160],
                                     real32_T varargout_2[348160])
{
  //  Forward input data through the layer at prediction time and
  //  output the result and updated state.
  std::copy(&varargin_1[348160], &varargin_1[696320], &varargout_1[0]);
  std::copy(&varargin_1[0], &varargin_1[348160], &varargout_2[0]);
}

void h_dlnetwork_layerPredictWithCol(const real32_T varargin_1[348160],
                                     const real32_T varargin_2[348160],
                                     real32_T varargout_1[348160])
{
  for (int32_T i{0}; i <= 348156; i += 4) {
    _mm_storeu_ps(&varargout_1[i], _mm_mul_ps(_mm_loadu_ps(&varargin_1[i]),
                                              _mm_loadu_ps(&varargin_2[i])));
  }
}

void i_dlnetwork_layerPredictWithCol(const real32_T varargin_1[348160],
                                     const real32_T varargin_2[348160],
                                     real32_T varargout_1[348160])
{
  for (int32_T i{0}; i <= 348156; i += 4) {
    _mm_storeu_ps(&varargout_1[i], _mm_mul_ps(_mm_loadu_ps(&varargin_1[i]),
                                              _mm_loadu_ps(&varargin_2[i])));
  }
}

void j_dlnetwork_layerPredictWithCol(const real32_T varargin_1[348160],
                                     real32_T varargout_1[174080],
                                     real32_T varargout_2[174080])
{
  //  Forward input data through the layer at prediction time and
  //  output the result and updated state.
  std::copy(&varargin_1[174080], &varargin_1[348160], &varargout_1[0]);
  std::copy(&varargin_1[0], &varargin_1[174080], &varargout_2[0]);
}

void k_dlnetwork_layerPredictWithCol(const real32_T varargin_1[174080],
                                     const real32_T varargin_2[174080],
                                     real32_T varargout_1[174080])
{
  for (int32_T i{0}; i <= 174076; i += 4) {
    _mm_storeu_ps(&varargout_1[i], _mm_mul_ps(_mm_loadu_ps(&varargin_1[i]),
                                              _mm_loadu_ps(&varargin_2[i])));
  }
}

void l_dlnetwork_layerPredictWithCol(const real32_T varargin_1[174080],
                                     const real32_T varargin_2[174080],
                                     real32_T varargout_1[174080])
{
  for (int32_T i{0}; i <= 174076; i += 4) {
    _mm_storeu_ps(&varargout_1[i], _mm_mul_ps(_mm_loadu_ps(&varargin_1[i]),
                                              _mm_loadu_ps(&varargin_2[i])));
  }
}

void m_dlnetwork_layerPredictWithCol(const real32_T varargin_1[174080],
                                     real32_T varargout_1[87040],
                                     real32_T varargout_2[87040])
{
  //  Forward input data through the layer at prediction time and
  //  output the result and updated state.
  std::copy(&varargin_1[87040], &varargin_1[174080], &varargout_1[0]);
  std::copy(&varargin_1[0], &varargin_1[87040], &varargout_2[0]);
}

void n_dlnetwork_layerPredictWithCol(const real32_T varargin_1[87040],
                                     const real32_T varargin_2[87040],
                                     real32_T varargout_1[87040])
{
  for (int32_T i{0}; i <= 87036; i += 4) {
    _mm_storeu_ps(&varargout_1[i], _mm_mul_ps(_mm_loadu_ps(&varargin_1[i]),
                                              _mm_loadu_ps(&varargin_2[i])));
  }
}

void o_dlnetwork_layerPredictWithCol(const real32_T varargin_1[87040],
                                     const real32_T varargin_2[87040],
                                     real32_T varargout_1[87040])
{
  for (int32_T i{0}; i <= 87036; i += 4) {
    _mm_storeu_ps(&varargout_1[i], _mm_mul_ps(_mm_loadu_ps(&varargin_1[i]),
                                              _mm_loadu_ps(&varargin_2[i])));
  }
}

void p_dlnetwork_layerPredictWithCol(const real32_T varargin_1[87040],
                                     real32_T varargout_1[43520],
                                     real32_T varargout_2[43520])
{
  //  Forward input data through the layer at prediction time and
  //  output the result and updated state.
  std::copy(&varargin_1[43520], &varargin_1[87040], &varargout_1[0]);
  std::copy(&varargin_1[0], &varargin_1[43520], &varargout_2[0]);
}

void q_dlnetwork_layerPredictWithCol(const real32_T varargin_1[43520],
                                     const real32_T varargin_2[43520],
                                     real32_T varargout_1[43520])
{
  for (int32_T i{0}; i <= 43516; i += 4) {
    _mm_storeu_ps(&varargout_1[i], _mm_mul_ps(_mm_loadu_ps(&varargin_1[i]),
                                              _mm_loadu_ps(&varargin_2[i])));
  }
}

void r_dlnetwork_layerPredictWithCol(const real32_T varargin_1[174080],
                                     real32_T varargout_1[87040],
                                     real32_T varargout_2[87040])
{
  //  Forward input data through the layer at prediction time and
  //  output the result and updated state.
  std::copy(&varargin_1[87040], &varargin_1[174080], &varargout_1[0]);
  std::copy(&varargin_1[0], &varargin_1[87040], &varargout_2[0]);
}

void s_dlnetwork_layerPredictWithCol(const real32_T varargin_1[348160],
                                     real32_T varargout_1[174080],
                                     real32_T varargout_2[174080])
{
  //  Forward input data through the layer at prediction time and
  //  output the result and updated state.
  std::copy(&varargin_1[174080], &varargin_1[348160], &varargout_1[0]);
  std::copy(&varargin_1[0], &varargin_1[174080], &varargout_2[0]);
}

void t_dlnetwork_layerPredictWithCol(const real32_T varargin_1[174080],
                                     real32_T varargout_1[87040],
                                     real32_T varargout_2[87040])
{
  //  Forward input data through the layer at prediction time and
  //  output the result and updated state.
  std::copy(&varargin_1[87040], &varargin_1[174080], &varargout_1[0]);
  std::copy(&varargin_1[0], &varargin_1[87040], &varargout_2[0]);
}

void u_dlnetwork_layerPredictWithCol(const real32_T varargin_1[87040],
                                     real32_T varargout_1[43520],
                                     real32_T varargout_2[43520])
{
  //  Forward input data through the layer at prediction time and
  //  output the result and updated state.
  std::copy(&varargin_1[43520], &varargin_1[87040], &varargout_1[0]);
  std::copy(&varargin_1[0], &varargin_1[43520], &varargout_2[0]);
}

void v_dlnetwork_layerPredictWithCol(const real32_T varargin_1[435200],
                                     const real32_T varargin_2[435200],
                                     real32_T varargout_1[435200])
{
  for (int32_T i{0}; i <= 435196; i += 4) {
    _mm_storeu_ps(&varargout_1[i], _mm_mul_ps(_mm_loadu_ps(&varargin_1[i]),
                                              _mm_loadu_ps(&varargin_2[i])));
  }
}

void w_dlnetwork_layerPredictWithCol(const real32_T varargin_1[108800],
                                     const real32_T varargin_2[108800],
                                     real32_T varargout_1[108800])
{
  for (int32_T i{0}; i <= 108796; i += 4) {
    _mm_storeu_ps(&varargout_1[i], _mm_mul_ps(_mm_loadu_ps(&varargin_1[i]),
                                              _mm_loadu_ps(&varargin_2[i])));
  }
}

void x_dlnetwork_layerPredictWithCol(const real32_T varargin_1[21760],
                                     const real32_T varargin_2[21760],
                                     real32_T varargout_1[21760])
{
  for (int32_T i{0}; i <= 21756; i += 4) {
    _mm_storeu_ps(&varargout_1[i], _mm_mul_ps(_mm_loadu_ps(&varargin_1[i]),
                                              _mm_loadu_ps(&varargin_2[i])));
  }
}

void y_dlnetwork_layerPredictWithCol(const real32_T varargin_1[27200],
                                     const real32_T varargin_2[27200],
                                     real32_T varargout_1[27200])
{
  for (int32_T i{0}; i <= 27196; i += 4) {
    _mm_storeu_ps(&varargout_1[i], _mm_mul_ps(_mm_loadu_ps(&varargin_1[i]),
                                              _mm_loadu_ps(&varargin_2[i])));
  }
}

} // namespace internal
} // namespace coder

// End of code generation (dlnetwork.cpp)
