//
// Created by john on 16.11.2025.
//

#include "tens.h"

#include <iostream>
#include <cmath>

//int H, W, C;
//double* data;
//  data = new double[H*W*C];

int tens::getN(){ return this->N; };
int tens::getH(){ return this->H; };
int tens::getW(){ return this->W; };
int tens::getC(){ return this->C; };

double tens::getPoint( int h, int w, int c) {
    if ( h>=H || w>=W || c>=C || h<0 || w<0 || c<0 ) return 0;
       return data[1*HWC + h*WC + w*C + c];// <<" "; //   getPoint(h,w,c)
};

double tens::getPoint( int n, int h, int w, int c) {
    if ( h>=H || w>=W || c>=C || h<0 || w<0 || c<0 ) return 0;
    return data[n*HWC + h*WC + w*C + c];//getPoint(n,h,w,c)
};


void tens::setPoint(int h, int w, int c, double value) {
   // if ( h>=H || w>=W || c>=C || h<0 || w<0 || c<0 ) return;
    data[1*HWC + h*WC + w*C + c]=value;
};

void tens::setPoint(int n, int h, int w, int c, double value) {
    //if ( n>N || h>=H || w>=W || c>=C || n<0 || h<0 || w<0 || c<0 ) return;
    data[n*HWC + h*WC + w*C + c]=value;
};

void tens::rand(int min, int max) {
    srand(time(0));
    int delta=max-min;
    for (int i=0;i<NHWC;i++) data[i]=( min+0.001*( std::rand()%(delta*1000) )); //(m*0.5);//m;;
};

void tens::addN1(  tens* result, tens* const y ) {
    for (int i=0;i<NHWC;i++){
        result->data[i]=data[i] + y->data[i];
    }
};


void tens::mulN1(  tens* result, double mul ){
    for ( int i=0;i<HWC;i++){
        result->data[i]=data[i]*mul;
    }
};

void tens::HamandMullAry(  tens* result, tens* Y ){
    for ( int i=0;i<HWC;i++){
        result->data[i] = data[i] * Y->data[i];
    }
};

void tens::toFlat() {
   W=HWC;
   H=1;
   C=1;
   HWC=H*W*C;
   WC=W*C;
};


void tens::to3D( int N, int H, int W, int C ) {
    this->N=N;
    this->H=H;
    this->W=W;
    this->C=C;
    NHWC=N*H*W*C;
    HWC=H*W*C;
    WC=W*C;
};



void tens::myPrint() {
    for (int n=0;n<N;n++) {
        std::cout<<std::endl<<"n: "<<n<<std::endl;
        for (int h=0;h<H;h++) {
            std::cout<<" | ";
            for (int wc=0;wc<(W*C);wc++) {
                std::cout << data[n*HWC + h*WC + wc] <<" "; //   getPoint(n,h,w,c) // n*HWC + h*WC + w*C + c]
            }
            std::cout<<" | "<<std::endl;
        }std::cout<<std::endl;
    }
};


void tens::WX( tens* result, tens* dF, tens* X ) { //H, W, 1   W[H,W,1]  X[H,1,1], result Y[H,1,1]
    int Xn=X->getN();// X images number

    double y=0;
    double z=0;
    for (int n=0; n<Xn; n++) {

        for (int h=0; h<H; h++) {
            y=0;
            for (int wc=0;wc<WC;wc++) {
                y += ( data[ h*WC + wc ]  *   X->data[ (n*WC + wc) ]);
            }
            z  = 1.0/(1.0 + std::exp(-y));
                dF->data[ (n*H + h) ] =  (z*(1-z));
            result->data[ (n*H + h) ] = z;        // <- W IS OK !!! (shape change)
            //result->showShape();

            //std::cout<< "n:"<<n <<", h:"<< h <<", w:"    << " : " <<z*(1-z) <<std::endl;
            // F'
        }
    }
    //for (int i=0;i<9999;i++){result->data[i]=9;}
};









void tens::WXSoftmax( tens* result, tens* X ) {
    int Xn=X->getN();// X images number
    double y=0;
    double sum=0;
    for (int n=0;n<Xn;n++) {

        sum=0;
        for (int h=0; h<H; h++) {
            y=0;
            for (int wc=0;wc<WC;wc++) {
                y += ( data[ h*WC + wc]) * ( X->data[ n*WC + wc ]);
            }
            result->data[ n*H + h ] = exp(y);
            sum += exp(y); // save Y
        }
        for (int h=0; h<H; h++) {
            result->data[ n*H + h ] = result->data[ n*H + h ]/sum;
        }
    }

};


void tens::BackWX( tens* Eout, tens* dF, tens* eIn, tens* X ) {
    double sum=0;
    int Xn=X->getN(); // number of images
    for (int n=0;n<Xn;n++) { // by images

        for (int w=0;w<W;w++) { //           W = 64 (input size)
            sum=0;
            for (int h=0;h<H;h++) { // H = 10 (output size)
                // prepare Eout
                // sum[] = W[m]   * Ein*dF <-- over n
                sum += (data[ h*W + w ]) * (eIn->data[ n*H + h ]) * (dF->data[n*H + h]);
                data[h*W + w ]=data[h*W + w ] + mu*  (eIn->data[ n*H + h ]) * (dF->data[n*H + h])  * X->data[n*WC + w];
            }
            Eout->data[n*H + w]=sum;
        }
    }
};



void tens::BackSoftmax( tens* Eout, tens* eIn, tens* X ) {
    double sum=0;
    int Xh=X->getH();
    int Xn=X->getN(); // number of images
    for (int n=0;n<Xn;n++) { // by images



        for (int w=0;w<W;w++) { // x[Xh] = 64 (input size)
            sum=0;
            for (int h=0;h<H;h++) { //10
               // prepare Eout
               // sum[] = W[m]   * Ein  <-- over n
               // sum[] = W[i64, 10neu] * Ein[neu10 , n]         <--over neu
               sum += (data[h*WC + w])*(eIn->data[ n*H + h ]);


               //update
               // W[m] = W[m] - ( X[m] * Ein )  <-- over n
               // W[m] = W[i64 , 10neu] - ( X[i64 , n] * Ein[10neo , n] )
               data[h*WC + w]=data[h*WC + w] + mu * eIn->data[n*H + h]* X->data[n*WC + w];
            }
             Eout->data[ n*WC + w ]=sum;
        }
    }
};














double tens::getMax( const double Y[], int len ) {
    double max=Y[0];
    for (int i=1;i<len;i++) {
        if (Y[i]>max) { max=Y[i]; }
    }
    return max;
};


double tens::getSum( const double Y[], int len ) {
    double sum=0.0;
    for (int i=0;i<len;i++) {
        sum+=Y[i];
    }
    return sum;
};

void tens::expAryminusMax(  double Y[], double max ,int len ) {
    for (int i=0;i<len;i++) {
        Y[i]=std::exp(Y[i]-max);
    }
};

void tens::mullAryByValue(  double Y[], double value ,int len ) {
    for (int i=0;i<len;i++) {
        Y[i]=Y[i]/value;
    }
};

void tens::showShape() {
    std::cout<<"N: "<<N<<", H: "<<H<<", W: "<<W<<", C:"<<C<<std::endl;
};


void tens::calculateGradientAtEndSoftmax( tens* result, tens* S) { // this is Z
    //   [1] - [0.54]
    //   [0] - [0.47]
     for (int i=0;i<NHWC;i++) {
         result->data[i]= S->data[i] - data[i];
     }
    //for (int i=0;i<NHWC;i++){ data[i]=data[i] -1*S->data[i]; }
    //for (int i=0;i<NHWC;i++){ data[i]= -.3+ S->data[i]; }
};

void tens::getAccuracy(tens* S) { //Z-S
    float max=0; int index; double acc=0;
    for (int n=0;n<N;n++) {
        max=0; index=0;
        for ( int i=0;i<W;i++ ) {
            if (data[ n*HWC + i]>max){ max=data[ n*HWC + i]; index=i; }
        }
        //std::cout<<"?:"<<data[ n*HWC + index*WC] << " : " <<  S->data[ n*HWC + index] << std::endl;
        if ( (S->data[ n*HWC + index]) > 0.8 ) { acc++; }
    }
    std::cout<<"ACC:"<<(acc/N)<<" "<<std::endl;
};

tens* tens::getOneN( int index ) {
    tens* t = new tens(1, H, W, C );
    for (int i=0;i<HWC;i++){ t->data[i]=data[index*HWC + i]; }
    return t;
};

/*
    p    W    p
   ### ##### ###
 p ### ##### ###  p           c( 2p*p + Wp + p  )
   ### ##### ###

 1 ### ooooo ###
   ### ooooo ###
       ...
         ooo ***

   ### ##### ###
p  ### ##### ###  p
   ### ##### ###

*/



void tens::addPadding( tens* result, int p) { //result = new tens(N, H+p+p, W+p+p, C);
    int offset=     C*( p*(p+p+W+1) );
    int NSize = (N *(H+p+p) * (W+p+p) * C);
    for (int n=0;n<N;n++) {
        for (int h=0;h<H;h++) {
            for (int cw=0;cw<WC;cw++) {
                result->data[ n*NSize + offset + h*(W+p+p)*C + cw] = data[n*HWC + h*WC +cw ];
            }
        }
    }
    //std::cout << "SIZE:" << t->NHWC<<std::endl;
    //std::cout << "offset:" << t->NHWC<<std::endl;
};


// CNN 3*3 x 3*3
// a) Full padding (F-1)  input = output
// b) Half center of Filter over all images padding (F-1)/2


//  Y = X - F + 1   (min)

//  Y = X + F - 1   (Full)

// forward:  Y = X*F  ->  F.CNN(Y,X)

// backward: delta  = Conv(X,Ein)   ->   Ein.CNN(delta, X); F=F-u*delta


void tens::CNN( tens* result, tens* X  ) { // I am a FILTER ! // result = new tens(Xn, H0, W0, N); // W0= X->W -W + 1;
                                                                   // min p=0
                                                                   // Same p=(W-1)/2
                                                                   // FULL  p=W-1;
    int Xn=X->getN();                                              // tens* X = new tens(N, H+p+p, W+p+p, C);
    int ChannelOut = result->getC();
    int ChannelIn  = X->getC();
    // int p=0;
    // if (OneHalfOrZero>.7){ p=W-1; } // start=end=0 Full convolution | start=end=(F-1)/2 Half convolution | start=end=(F-1) Inner convolution
    // if (OneHalfOrZero<.7 && OneHalfOrZero>.1){ p=(W-1)/2;  }


   int W0= X->W -W + 1;
   int H0= X->H -H + 1;

// show info !  **********
//
// std::cout<<"res: (n:"<<Xn<<", h:"<<H0<<", w:"<<W0<<", c:" << ChannelOut << "); "<<std::endl;
//  result->showShape();

   int W0Cin = W0*ChannelIn;
   double sum=0;


        for (int n=0; n<X->getN(); n++ ) {
            for (int h=0; h<H0; h++ ) {  // over image
                for (int w=0; w<W0; w++) {

                    for (int co=0; co<ChannelOut; co++ ) {
                    sum=0;
                    for (int y=0; y<H; y++) {  // over filter
                        for (int x=0; x<W; x++ ) {

                                for (int ci=0; ci<ChannelIn; ci++) {

                                    // std::cout << "?" <<std::endl;
                                    //if ( n==1 && h==0 && y==1 && w==0 && x==0  && co==0  ) {
                                    //    std::cout<< "ci:" << ci << ", "<< X->data[ n*Xn*X->W*ChannelIn +  (y+h)*X->W*ChannelIn  + (w+x)*ChannelIn + co*0 + ci]  <<std::endl;
                                    //    std::cout << data[ n*HWC + (h+y)*WC + (w+x)*C + co*ChannelIn + ci ]<<std::endl;
                                    //}
                                    sum += data[ n*0 + (h+y)*WC + (w+x)*C + co*ChannelIn + ci ] * X->data[ n*X->H*X->W*ChannelIn +  (y+h)*X->W*ChannelIn  + (w+x)*ChannelIn + co*0 + ci];

                                }
                            }
                        }
                       result->data[ n*W0*H0*ChannelOut + h*W0*ChannelOut + w*ChannelOut + co ]=sum;
                    }
                }
            }
        }



/*
   for (int n=0;n<Xn;n++) { // over images
     for (int ch=0;ch<N;ch++) {
         for (int h=0;h<(H0);h++) {
             for (int w=0;w<(W0);w++) {
                 sum=0;
                 //
                     for (int i=0;i<H;i++) {
                         for (int wc=0;wc<WC;wc++) {
                                 sum+=data[ ch*HWC + i*WC + wc] *  X->data[ n*X->HWC + (h+i)*X->WC + wc+w]; //sum+=data[n, i, j] *  X->data[n, h+i, cw+j];
                         }
                     }
                     result->data[n*H0*W0*N + h*W0*N + w*N + ch] = sum; //t->data[n,h,cw] = sum;
                 }
             }
       }
    }
  */
   };


void tens::Rot180( tens* result ) { //result = new tens( N,H,W,C );
    int W1=W-1;
    int H1=H-1;
    for (int n=0;n<N;n++) {
        for (int h=0;h<H;h++) {
            for (int w=0;w<W;w++) {
                for (int c=0;c<C;c++) {
                    result->data[n*HWC + h*WC + w*C + c ] =  data[ n*HWC + (H1-h)*WC + (W1-w)*C + c ];
                }
            }
        }
    }
};



void tens::poolMax(tens* result, tens* dF, int size) { // result = new tens(N, H/size, W/size, C);
    int maxI, maxJ;
    double maxVal;

    for (int n=0;n<N;n++) {
        for (int c=0;c<C;c++) {

            for (int h=0;h<H/size;h++) {
                for (int w=0;w<W/size;w++) {

                    maxVal=0;maxI=0;maxJ=0;
                    for (int i=0;i<size;i++){
                         for (int j=0;j<size;j++){
                            if ( data[n*HWC + (h*size+i)*WC + (w*size+j)*C + c] > maxVal ) {  maxVal=data[n*HWC + (h*size+i)*WC + (w*size+j)*C + c]; maxI=i; maxJ=j; }
                         }
                    }
                    int t0=n*HWC;
                    int t1=(h*size+maxI)*WC;
                    int t2=(w*size+maxJ)*C;
                    int t3=c;
                    dF->data[n*HWC + (h*size+maxI)*WC + (w*size+maxJ)*C + c]=1;
                    result->data[n*(H/size)*(W/size)*C + h*(W/size)*C + w*C + c]=maxVal;
                }
            }
        }
    }
};


void tens::poolMaxRev(tens* result, tens* dF, int size) { // result = new tens(N, H/size, W/size, C); // I-am Ein
    double val;
    for (int n=0;n<N;n++) {
        for (int c=0;c<C;c++) {

            for (int h=0;h<H/size;h++) {
                for (int w=0;w<W/size;w++) {

                    val = data[n*(H/size)*(W/size)*C + h*(W/size)*C + w*C + c];
                    for (int i=0;i<size;i++){
                        for (int j=0;j<size;j++){

   result->data[n*HWC + (h*size+i)*WC + (w*size+i)*C + c] = val * dF->data[n*HWC + (h*size+i)*WC + (w*size+i)*C + c];
                        }
                    }
                }
            }
        }
    }
};





void tens::F_updateFilter(tens* delta) { // F = F -u * delta
    for (int i=8;i<NHWC;i++) {
        data[i]= data[i] - mu*delta->data[i];
    }
}











void tens::ReLU( tens* result ) {
    for (int i=0;i<HWC;i++) {
        result->data[i]= (data[i]>0)? data[i]:0;
    }
}









