//
// Created by john on 11/13/25.
//

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
             std::cout<<"Z[n]:"<<Z[n]<<std::endl;
             for (int j=0;j<m;j++){
                y+=X[j]*W[i][j];
             }
             dF[i]=y*(1-y);
              Z[i]=F(y);
         }
       break;
       }
   }
}

double Layer::F( double y){
    switch(type){
        case PERCEPTRON_SIGMOID: {
            return y*(1-y);
        }
    }
}



void Layer::Backward ( double eOut[], const double eIn[] ){
    for (int i=0;i<n;i++){
        eOut[i]=0.0;

      // uzupelnic !!
    }
/*
    public void nBackward( float[] Ein ){ // S-Z or Ein
        for ( int i=0;i<neurons.length;i++ ){ Eout[i]=0.0f; }
        for ( int n=0; n< neurons.length; n++ ){
            neurons[n].Backward( Ein[n] * dFofZ[n] );
        }
    }
*/

}











void Layer::print(){
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      std::cout  <<(int)(W[i][j]*10)/10.0  << " ";
    }
    std::cout<<std::endl;
  }
}