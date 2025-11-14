//
// Created by john on 14.11.2025.
//

#ifndef PROJMLP_NN_H
#define PROJMLP_NN_H



#include "Layer.h"

class NNet {

private:
    int layer_num;
    double **interArray;
    Layer ** layers;
    double* dn;
    const int PERCEPTRON_SIGMOID=1;
    //#define PERCEPTRON_CROSSENTROPY_BINARY 2
    const int PERCEPTRON_SOFTMAX_MULTICLASS=3;

public:
    NNet(){};
    NNet(const int layer_num) : layer_num(layer_num), interArray(nullptr), layers(nullptr), dn(nullptr) {};
    void addL( int ind, int typ,  int n,  int m){
        if (ind==0) {
            layers = new Layer * [ layer_num ];
            interArray = new double * [ layer_num ];
            dn = new double[ m ];
        }

        layers[ind] = new Layer(typ, n, m); // ( type, n, m )
        interArray[ind] = new double[ n ];
    }

    void Backward(const double eIn[]) {

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




    void Forward (double Z[], const double X[]){
        layers[0]->Forward( interArray[0], X );
        for (int i=1;i<layer_num-1;i++) {
            layers[i]->Forward(interArray[i], interArray[i-1]);
        }
        layers[(layer_num-1)]->Forward( Z, interArray[(layer_num-1)] );
    }

};


#endif //PROJMLP_NN_H