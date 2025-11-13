//
// Created by john on 11/13/25.
//

#ifndef INZ_LAYER_H
#define INZ_LAYER_H

#define PERCEPTRON_SIGMOID 1

#include <iostream>

class Layer {
   // type 1=sigmoid, 2=sigmod_CrossEntropy_Binary, 3=softmaxMultiClass, 10=flatten, 20=CNN
   private:
       const int type;
       const int n;
       const int m;
       double** W;
       double* dF;

   public:
      Layer(  const int type_,  const int n_,  const int m_ );

      //type1
      void Forward (double Z[], const double X[]);
      double F( double y);
      void Backward (double eOut[], const double eIn[]);
      //void Forward (double Z[], const double X[]);
      void print();

};

#endif //INZ_LAYER_H