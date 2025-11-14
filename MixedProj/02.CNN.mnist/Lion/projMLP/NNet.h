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
       layers[layer_num-1]->Backward(interArray[layer_num-2], eIn); // Backward ( double eOut[], const double eIn[] ){
       for (int i=(layer_num-2);i>=1;i--) {
            layers[i]->Forward(interArray[i], interArray[i-1]);
       //    std::cout<<std::endl<<std::endl<<"i:"<<i<<std::endl;
       }
       layers[0]->Forward( dn, interArray[0] );
    }


    void Forward (double Z[], const double X[]){
        layers[0]->Forward( interArray[0], X );
        for (int i=1;i<layer_num-1;i++) {
           layers[i]->Forward(interArray[i], interArray[i-1]);
        }
        layers[layer_num-1]->Forward(Z, interArray[layer_num-2]);
    }


    double crossEntropyMulticlassError( double* Z, double * S){
        return layers[layer_num-1]->crossEntropyMulticlassError( Z, S );
    }

    void vectorSsubZ(double* resultSsubZ, double* S, double *Z) {
        return layers[layer_num-1]->vectorSsubZ(  resultSsubZ, S, Z );
    }


    double accuracy(double * X[], double * Y[], int len, int class_num) {
        int goal=0;
        double* result=new double[class_num];
        for (int i=0;i<len;i++) {
            Forward( result, X[i] ); //double Z[], const double X[]
            if ( getMaxIndex( result, class_num ) == getMaxIndex( Y[i], class_num )){ goal++; }
        }
        return 100.0*goal/len;
    }




    int getMaxIndex(double* ary ,int len) {
        int ind=0; double val=ary[0];
        for (int i=1;i<len;i++) {
            if (ary[i]>val){ val=ary[i]; ind=i; }
        }
        return ind;
    }

};


#endif //PROJMLP_NN_H