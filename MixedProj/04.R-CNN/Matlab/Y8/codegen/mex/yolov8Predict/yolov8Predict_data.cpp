//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// yolov8Predict_data.cpp
//
// Code generation for function 'yolov8Predict_data'
//

// Include files
#include "yolov8Predict_data.h"
#include "rt_nonfinite.h"

// Variable Definitions
emlrtCTX emlrtRootTLSGlobal{nullptr};

const volatile char_T *emlrtBreakCheckR2012bFlagVar{nullptr};

emlrtContext emlrtContextGlobal{
    true,                                                 // bFirstTime
    false,                                                // bInitialized
    131674U,                                              // fVersionInfo
    nullptr,                                              // fErrorFunction
    "yolov8Predict",                                      // fFunctionName
    nullptr,                                              // fRTCallStack
    false,                                                // bDebugMode
    {2507028324U, 3082164388U, 2502856102U, 2452866138U}, // fSigWrd
    nullptr                                               // fSigMem
};

emlrtRSInfo g_emlrtRSI{
    1,                     // lineNo
    "dlnetwork/callSetup", // fcnName
    "C:"
    "\\ProgramData\\MATLAB\\SupportPackages\\R2025a\\toolbox\\shared\\dlcoder_"
    "base\\supportpackages\\shared_dl_targets\\+coder\\+in"
    "ternal\\@dlnetwork\\dlnetwork.p" // pathName
};

emlrtRSInfo p_emlrtRSI{
    20,                               // lineNo
    "eml_int_forloop_overflow_check", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_"
    "overflow_check.m" // pathName
};

emlrtRSInfo nb_emlrtRSI{
    23,                          // lineNo
    "dlarray/permuteExplicitly", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\nnet\\deepcoder\\+deep\\+internal\\+"
    "coder\\@dlarray\\permuteExplicitly.m" // pathName
};

emlrtRSInfo ob_emlrtRSI{
    61,        // lineNo
    "permute", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\elmat\\permute.m" // pathName
};

emlrtRSInfo pb_emlrtRSI{
    65,        // lineNo
    "permute", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\elmat\\permute.m" // pathName
};

emlrtRSInfo qb_emlrtRSI{
    52,                  // lineNo
    "reshapeSizeChecks", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" // pathName
};

emlrtRTEInfo b_emlrtRTEI{
    88,                  // lineNo
    23,                  // colNo
    "reshapeSizeChecks", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" // pName
};

emlrtRTEInfo c_emlrtRTEI{
    81,                  // lineNo
    13,                  // colNo
    "reshapeSizeChecks", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" // pName
};

emlrtRTEInfo d_emlrtRTEI{
    121,               // lineNo
    9,                 // colNo
    "computeDimsData", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" // pName
};

emlrtRTEInfo
    e_emlrtRTEI{
        93,    // lineNo
        27,    // colNo
        "cat", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2025a\\toolbox\\eml\\lib\\matlab\\elmat\\cat.m" // pName
    };

emlrtRSInfo ve_emlrtRSI{
    54,    // lineNo
    "div", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2025a\\toolbox\\eml\\eml\\+coder\\+internal\\div.m" // pathName
};

// End of code generation (yolov8Predict_data.cpp)
