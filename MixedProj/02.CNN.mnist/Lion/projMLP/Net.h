//
// Created by john on 13.11.2025.
//

#ifndef PROJMLP_NET_H
#define PROJMLP_NET_H
#include "Layer.h"

class Net {

private:
   int layer_num;

   double *interArray;
   Layer * layers;
   double* devnull;

public:
    Net( int layer_num );
    double* Forward (const double X[]);
    void Backward(const double eIn[]);
    void addLayerAt(int index, int type, int n, int m);




};


#endif //PROJMLP_NET_H
