//
// Created by john on 11/13/25.
//

#ifndef INZ_LAYER_H
#define INZ_LAYER_H

//#define PERCEPTRON_SIGMOID 1
//#define PERCEPTRON_CROSSENTROPY_BINARY 2
//#define PERCEPTRON_SOFTMAX_MULTICLASS 3

#include <iostream>
#include <cmath>
//#include "tools.cu"

class Layer {
   // type 1=sigmoid, 3=softmaxMultiClass, 10=flatten, 20=CNN
   private:
       const int type;
        int n;
        int m;
       double** W;
       double* muX;
       double* dF;
       double* dFE;
       double* myY;
       float mu=0.003;


        int tensorC=0;
        int tensorW=0;
        int tensorH=0;
        int padding=0;
        int filterSize=0;
        int channelOut=0;
        int delta=0;

       double** Filter;

   // CNN input = C*W*H
   //    filter = F;
   //     delta = padding*2 -(F-1)/2
   //    output = C * (W+delta) * (H+delta)

   public:
    Layer(  int type_,  int n_,  int m_ )    // n - neurons num, output size , W[n][m], Y[n]
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
            myY = new double [n];
            muX = new double [m];
            for ( int i=0;i<n;i++){
                W[i]=new double[m];
                for (int j=0;j<m;j++){
                    W[i][j]=(-1.0+0.01*( rand()%200 )); //(m*0.5);//m;
                    //std::cout<<W[i][j]<<std::endl;
                    //  W[i][j]=0.01*( rand()%200 );
                }
            }
        }
        if (type==20) {
            //CNN
        }
    }




    double getMax( const double Y[], int len ) {
        double max=Y[0];
        for (int i=1;i<len;i++) {
            if (Y[i]>max) { max=Y[i]; }
        }
        return max;
    }

    double getSum( const double Y[], int len ) {
        double sum=0.0;
        for (int i=0;i<len;i++) {
            sum+=Y[i];
        }
        return sum;
    }

    void expAryminusMax(  double Y[], double max ,int len ) {
        for (int i=0;i<len;i++) {
            Y[i]=std::exp(Y[i]-max);
        }
    }

    void mullAryByValue(  double Y[], double value ,int len ) {
        for (int i=0;i<len;i++) {
            Y[i]=Y[i]/value;
        }
    }






      //type1
    void Forward ( double Z[] , const double X[]){
        for (int i=0;i<n;i++) { Z[i]=0.0; myY[i]=0.0;}
        switch(type){
            case 20: return CNNForward(Z, X);
            case 10: return FlattenForward(Z, X);
            case 1: case 3: {
                for (int i=0;i<n;i++) {
                    for (int j=0;j<m;j++) {
                        double xj=X[j];
                        double wij=W[i][j];
                        double xw=xj*wij;
                        myY[i]+=xw;
                        //myY[i]+=W[i][j]*X[j];
                    }
                }
                for (int i=0;i<n;i++) {
                    Z[i]=F(myY[i]);
                    dF[i]=dFun(Z[i]);
                }
                // save X * mu for backprop;
                for (int j=0;j<m;j++) {
                    muX[j]=mu*X[j];
                }
                if (type==1) break;

                double max = getMax( Z, n );
                expAryminusMax(Z, max, n );
                double sum = getSum( Z, n );
                mullAryByValue( Z, sum ,n );
                break;
            }
        }
    }



    double F  ( double y) const {
        switch(type){
            case 1: case 3:{ //PERCEPTRON_SIGMOID //PERCEPTRON_SOFTMAX_MULTICLASS
                return /* Z= */ 1.0/(1.0+std::exp(-y));
            }
            case 0: {
                return y;
            }
        }
        return 0.0;
    }

    double dFun  ( double z) const {
        switch(type){
            case 1: { //PERCEPTRON_SIGMOID
                return z*(1-z);
            }
            case 3: { //PERCEPTRON_SOFTMAX_MULTICLASS
                return 1;
            }
        }
        return 0.0;
    }



    void Backward ( double eOut[], const double eIn[] ){
        switch (type) {
            case 20: return CNNBackward(  eOut, eIn );
            case 10: return FlattenBackward(  eOut, eIn );
            case 1/*PERCEPTRON_SIGMOID*/: case 3/*PERCEPTRON_SOFTMAX_MULTICLASS*/: {
                for (int j=0;j<m;j++){ eOut[j]=0.0;}
                for (int i=0;i<n;i++){
                    dFE[i]=eIn[i]*dF[i];     // prepare dFE from dF[neuron] * eIn[neuron]
                }
                // SYNCHRO !!!!
                for (int i=0;i<n;i++){
                    for (int j=0;j<m;j++) {
                        eOut[j]+=dFE[i]*W[i][j];  // prepare eOUT ( sum by M  dFE[neuron]*W[neuron][m] )
                        W[i][j]+=dFE[i]*muX[j];   // update Weight dFE * X * um;
                        //if (i==0) { std::cout<<"dFE[i]: "<<dFE[i]<<" muX"<<muX[j]<<std::endl; }
                    }
                }
            }
        }
    }


    double crossEntropyMulticlassError( double* Z){
        double out = 0.0;
        for ( int i=0;i<n; i++ ){
            out += -log(Z[i]);
        }
        return -1*out;
    }

    void vectorSsubZ(double* resultSsubZ, double* S, double *Z) {
        for ( int i=0;i<n; i++ ){
            resultSsubZ[i]=S[i]-Z[i];
        }
    }


    int getN() {
        return n;
    }


    void FlattenForward( double Z[] , const double X[] ) { // int n_ out,  int m_ in )
        for (int i=0;i<n;i++){ Z[i]=X[i]; }
    }

    void FlattenBackward( double eOut[], const double eIn[] ) {
        for (int i=0;i<n;i++){ eOut[i]=eIn[i]; }
    }


// CNN !!!

    void setupCNN( int filterSize, int padding, int tensorW, int tensorH, int tensorC, int channelOut ) {
        this->tensorC=tensorC;
        this->tensorW=tensorW;
        this->tensorH=tensorH;
        this->padding=padding;
        this->filterSize=filterSize;
        this->channelOut=channelOut;

        this->delta= padding*2 - (filterSize-1)/2;
        this->m=tensorC*tensorH*tensorW;
        this->n=channelOut*(tensorH+delta)*(tensorW+delta);
        this->myY = new double [n];

        std::cout<<"inputSize= "<<m<< std::endl;
        std::cout<<"outputSize="<<n<<" = ("<<  tensorH << " * " << tensorW << " * "<< tensorC << ") " << delta <<  std::endl;


        srand(time(0));
        int HWC=tensorC*tensorH*tensorW;
        Filter = new double*[channelOut];
        for (int i=0;i<channelOut;i++) {
            Filter[i] = new double[HWC];
            for (int j=0;j<HWC;j++){
                Filter[i][j] = (-1.0+0.01*( rand()%200 ));
            }
        }
    }

    void CNNForward( double Z[] , const double X[] ) {
        for (int c=0;c<channelOut;c++) {
            int offset=c*(tensorH+delta)*(tensorW+delta)*tensorC;
            CNNForwardOneChannel( Z+offset , X,  Filter[c] );
        }
    }

    void CNNForwardOneChannel(double Z[] , const double X[], double* F ) {
        int x0 = (filterSize-1)/2;
        int y0 = x0;

        double val=0.0;
        for (int j=-x0*tensorC ; j<=x0*tensorC; j++ ) {

        }






        // dodac wiecej kanalow !!
        for (int i=0;i<(n);i++)Z[i]=0.0;
        for (int h=0;h<(tensorH+delta);h++) {
            for (int w=0;w<tensorW+delta;w++){
                for (int c=0;c<tensorC;c++) {
                    double val=0.0;
                    int targI= h*tensorC*(tensorW+delta) +w*tensorC+c;

                    //=X[]*   Filter[ (0+filterOffset)*filterSize + 0+filterOffset];
                    Z[targI]=val;
                }
            }
        }

        //

    }

    void CNNBackward( double eOut[], const double eIn[] ){

    }


};

#endif //INZ_LAYER_H
