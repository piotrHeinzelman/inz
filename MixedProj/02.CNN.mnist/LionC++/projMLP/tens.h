//
// Created by john on 16.11.2025.
//

#ifndef PROJMLP_TENSOR_H
#define PROJMLP_TENSOR_H


class tens {
private:
    int N=0, H=0, W=0, C=0, NHWC=0, HWC=0, WC=0;


public:
    double* data;

    tens(int N, int H,int W,int C)
    : N{N}
    , H{H}
    , W{W}
    , C{C} {
         NHWC=N*H*W*C;
         HWC=H*W*C;
         WC=W*C;
        data = new double[ NHWC ];
        for (int i=0; i<NHWC; i++) data[i]=0;
    };

    tens(int N, int H,int W,int C, double* ary)
    : N{N}
    , H{H}
    , W{W}
    , C{C} {
        NHWC=N*H*W*C;
        HWC=H*W*C;
        WC=W*C;
        data = new double[ NHWC ];
        for (int i=0; i<NHWC; i++) ary[i]=0;
    };

    ~tens() {
        delete data;
    };


    int getH(); int getW(); int getC(); int getN(); void myPrint();

    double getPoint(        int h, int w, int c );
    double getPoint( int n, int h, int w, int c );
    void   setPoint(        int h, int w, int c, double value );
    void   setPoint( int n, int h, int w, int c, double value );
    void       rand( int min, int max );



    // Without operator overloading:
    tens* addN1( tens* const  y );
    tens* mulN1( tens* x,  double mul );

    void toFlat();
    void to3D(int n, int h, int w, int c);

    void WX( tens* result,  tens* dF,  tens* X ); //N11
    void WXSoftmax( tens* result, tens* X ); //N11

    double getMax( const double Y[], int len );
    double getSum( const double Y[], int len );
    void expAryminusMax(  double Y[], double max ,int len );
    void mullAryByValue(  double Y[], double value ,int len );

    //tens* WXSigmoid( tens* result, tens* dF, tens* X);



};


#endif //PROJMLP_TENSOR_H
