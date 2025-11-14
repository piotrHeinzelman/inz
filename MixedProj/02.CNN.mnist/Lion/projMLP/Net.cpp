//
// Created by john on 13.11.2025.
//

#include "Net.h"


Net::Net( int layer_num ) : layer_num(layer_num) {}


Net::config(int **net_config) {
/*
    // deep copy netConfig
    this->layer_num = layer_num_;
    netConfig=new int*[layer_num];
    for (int i=0;i<layer_num;i++) {
        this->netConfig[i]=new int[3];
        for (int j=0;j<3;j++) {
        this->netConfig[i][j]=netConfig_[i][j];
        }
    }
*/
 //   Layer* layers;
 //   double** interArray;

    // create layers & interArray


    for (int i=0;i<layer_num;i++) {
        for (int j=0;j<3;j++) {

        }
    }

}

double* Net::Forward (const double X[]) {

    layers[0]->Forward(X, interArray[0]);
    for (int i=1;i<layer_num;i++) {
        layers[i]->Forward(X, interArray[i]);
    }
    return interArray[i];
}

void Net::Backward(const double eIn[]) {
    /*
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
    */
}



void Net::addLayerAt(int index, int type, int n, int m){
    if (index==0) {
        layers = new Layer[layer_num];
        interArray = new double[layer_num];
        devnull = new double[ netConfig[0][2] ];
    }

    layers[index] = new Layer(type, n, m); // ( type, n, m )
    interArray[index] = new double[ n ];
}
