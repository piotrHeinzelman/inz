//
// Created by john on 11/13/25.
//
#include <cmath>
#include "Layer.h"

Layer::Layer( const int type_, const int n_, const int m_ )    // n - neurons num, output size , W[n][m], Y[n]
                                          // m - input size X[m]
    : type{type_}
    , n{n_}
    , m{m_}
    {
    // init Weights
    if (type<4){ // sigmoid, type 1=sigmoid, 2=sigmod_CrossEntropy_Binary, 3=softmax
        srand(time(0));
        W = new double*[n];
        dF = new double [n];
        dFE = new double [n];
        muX = new double [m];
        for ( int i=0;i<m;i++){
           W[i]=new double[m];
           for (int j=0;j<m;j++){
             W[i][j]=-1.0+0.01*( rand()%200 );
             //  W[i][j]=0.01*( rand()%200 );
           }
        }
    }
}


void Layer::Forward ( double Z[] , const double X[]){
   switch(type){
       case PERCEPTRON_SIGMOID: {
         for (int i=0;i<n;i++){
             double y=0.0;
             for (int j=0;j<m;j++){
                y+=X[j]*W[i][j];
             }
             double z=F(y);
             dF[i]=z*(1-z);
              Z[i]=z;
         }
         // save X * mu for backprop;
         for (int j=0;j<m;j++) {
           muX[j]=X[j]*mu;
         }
       break;
       }
       case PERCEPTRON_SOFTMAX_MULTICLASS: {
           double* Y=dF; // ;)
           for (int i=0;i<n;i++) {
               for (int j=0;j<m;j++){
                   if (i==0){ Y[i]=0.0; }
                   Y[i]+=X[j]*W[i][j];
               }
           }
           const double maxOfY = getMax( Y );
           double sumOfY = 0.0;
           //df=1

           for (int i=0;i<n;i++) {
               Y[i]=std::exp( Y[i]- maxOfY );
               sumOfY+=Y[i];
           }
           for (int i=0;i<n;i++) {
               dF[i]=1.0;
               Z[i]=Y[i]/sumOfY;
           }
           break;
       }
   }
}

// ReSharper disable once CppMemberFunctionMayBeConst
double Layer::F( const double y) const{
    switch(type){
        case PERCEPTRON_SIGMOID: {
            return y*(1-y);
        }
    }
    return 0.0;
}



void Layer::Backward ( double eOut[], const double eIn[] ){
    switch (type) {
        case PERCEPTRON_SIGMOID: case PERCEPTRON_SOFTMAX_MULTICLASS: {
            for (int i=0;i<n;i++){
                eOut[i]=0.0;
                dFE[i]=eIn[i]*dF[i];     // prepare dFE from dF[neuron] * eIn[neuron]
            }
            // SYNCHRO !!!!
            for (int i=0;i<n;i++){
                for (int j=0;j<m;j++) {
                    W[i][j]+=dFE[i]*muX[j];   // update Weight dFE * X * um;
                    eOut[j]+=dFE[i]*W[i][j];  // prepare eOUT ( sum by M  dFE[neuron]*W[neuron][m] )
                    std::cout<<"eIn["<<i<<"]:"<<eOut[i]<<std::endl;
                }
            }
        }
    }
}







double Layer::getMax( const double Y[] ) {
   double max=Y[0];
   for (int i=1;i<n;i++) {
       if (Y[i]>max) { max=Y[i]; }
   }
   return max;
}


void Layer::print(){
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      std::cout  <<(int)(W[i][j]*10)/10.0  << " ";
    }
    std::cout<<std::endl;
  }
}