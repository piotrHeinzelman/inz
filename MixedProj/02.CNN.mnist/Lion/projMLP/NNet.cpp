//
// Created by john on 14.11.2025.
//

#include "NNet.h"





void nn::Backward(const double eIn[]) {

    // prepare
    Layer* lay0 = new Layer(PERCEPTRON_SIGMOID,99,128);
    double* lay0_to1 = new double[99];
    Layer* lay1 = new Layer(PERCEPTRON_SOFTMAX_MULTICLASS,10,99);
    double* ZZ = new double[10];

    //Forward
    double* XX = new double[2]{0.2,0.3};
    lay0->Forward(lay0_to1, XX);
    lay1->Forward(ZZ, lay0_to1);




    //Backward ( double eOut[], const double eIn[] )
    lay1->Backward(lay0_to1, ZZ);
    double* devnull=new double[128];
    lay0->Backward(devnull, lay0_to1);

}


