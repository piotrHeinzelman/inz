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

       double** Filter;
       double* expandedX;

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


    int getN() { return n; }
    double* getFilter(int i){ return Filter[i];}


    void FlattenForward( double Z[] , const double X[] ) { // int n_ out,  int m_ in )
        for (int i=0;i<n;i++){ Z[i]=X[i]; }
    }

    void FlattenBackward( double eOut[], const double eIn[] ) {
        for (int i=0;i<n;i++){ eOut[i]=eIn[i]; }
    }


// CNN !!!

    void setupCNN( int filterSize, int channelOut, int tensorW, int tensorH, int tensorC ) {
        this->tensorC=tensorC;
        this->tensorW=tensorW;
        this->tensorH=tensorH;
        this->padding=(filterSize-1)/2;
        this->filterSize=filterSize;
        this->channelOut=channelOut;

        this->m=tensorC*tensorH*tensorW;    // in
        this->n=channelOut*tensorH*tensorW; // out
        this->myY = new double [n];
        this->expandedX=new double[(tensorW+filterSize-1)*(tensorH+filterSize-1)*tensorC];

        std::cout<<"inputSize= "<<m<< std::endl;
        std::cout<<"outputSize="<<n<<" = ("<<  tensorH << " * " << tensorW << " * "<< tensorC << ") "  <<  std::endl;


        srand(time(0));
        int HWC=tensorC*tensorH*tensorW;
        Filter = new double*[channelOut];
        for (int i=0;i<channelOut;i++) {
            Filter[i] = new double[HWC];
            for (int j=0;j<HWC;j++){
                Filter[i][j] = 1;// (-1.0+0.01*( rand()%200 ));
            }
        }
    }

    void CNNForward( double Z[] , const double X[] ) {
        for (int c=0;c<channelOut;c++) {
            int offset=c*tensorH*tensorW;
            CNNForwardOneChannel( Z+offset , X,  Filter[c] );
        }
    }

    void CNNForwardOneChannel(double Z[] , const double X[], double* F ) {
        extendAry( expandedX, X );
        //printTensor(expandedX, 5,5,2  );//double* X, int H, int W, int C
        int tWF1 = tensorW+filterSize-1;
        int yStep=(tWF1*tensorC);
        int xStep=tensorC;
        for (int y=0;y<0+tensorH;y++) {
            for (int x=0;x< 0+tensorW ;x++) {

                double val=0;
                for (int _y=0;_y<filterSize;_y++) {
                        for (int _xc=0;_xc<filterSize*tensorC;_xc++) {
                            // std::cout<<"X:"<< expandedX[ y*yStep + x*xStep + _y*yStep +_xc] << std::endl;
                            val +=  expandedX[ y*yStep + x*xStep + _y*yStep +_xc ]* F[ _y*filterSize*tensorC + _xc];
                            // + pozostale wartosci z kadratu
                            // std::cout<<"F: ["<< _y*filterSize*tensorC+ _xc<<"]="<< F[ _y*filterSize*tensorC+ _xc]<<  std::endl;
                            // std::cout<<"X: ["<< (_y+y)*tensorW*tensorC+ ( x*tensorC + _xc )<<"]="<< extendAry[ (_y+y)*tensorW*tensorC+ ( x*tensorC + _xc )]<<  std::endl;
                        }
                }
                //std::cout<<"y:"<< y <<", x:" << x <<", X[x,y]:"<< val<<std::endl;
                //std::cout<<"SaveValue:["<<x<<","<<y<<"]: "<< val << std::endl;
                Z[ y*tensorW + x]=val;
            }
        }
        //delete expandedX;
        //printTensor(Z, tensorH,tensorW, tensorC  );
        //std::cout<<"*** END OF CONVOUTIONS ***"<<std::endl;
    }


   void CNN () {
        
    }


    void CNNBackward( double eOut[], const double eIn[] ){

    }


    void extendAry( double* outX , const double* X ){
        int Hpp=( tensorH+filterSize-1 );
        int Wpp=( tensorW+filterSize-1 );
        for (int i=0;i<Hpp * Wpp * tensorC;i++){ outX[i]=0.0; }

        int startOffset=(tensorW + 2*padding + 1 )*padding*tensorC;
        int heightOffset= (2*padding)*tensorC;

        for (int i=0;i<tensorH;i++) {
            for (int j=0;j<tensorC*tensorW;j++) {
                outX[startOffset + i* heightOffset + i*tensorW*tensorC+j] = X[i*tensorW*tensorC+j];
            }
        }
    }
};

#endif //INZ_LAYER_H
