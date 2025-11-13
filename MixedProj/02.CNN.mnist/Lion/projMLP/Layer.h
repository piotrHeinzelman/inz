//
// Created by john on 11/13/25.
//

#ifndef INZ_LAYER_H
#define INZ_LAYER_H

#define PERCEPTRON_SIGMOID 1
//#define PERCEPTRON_CROSSENTROPY_BINARY 2
#define PERCEPTRON_SOFTMAX_MULTICLASS 3

#include <iostream>

class Layer {
   // type 1=sigmoid, 3=softmaxMultiClass, 10=flatten, 20=CNN
   private:
       const int type;
       const int n;
       const int m;
       double** W;
       double* muX;
       double* dF;
       double* dFE;
       float mu=0.01;

   public:
      Layer(  const int type_,  const int n_,  const int m_ );

      //type1
     void Forward (double Z[], const double X[]);
   double F       ( double y) const;
     void Backward(double eOut[], const double eIn[]);
   double getMax  ( double const Y[] );//n
      //void Forward (double Z[], const double X[]);
     void print();
   double crossEntropyMulticlassError( double* Z, double * S);
     void vectorSsubZ(double* resultSsubZ, double* S, double *Z);

};

#endif //INZ_LAYER_H