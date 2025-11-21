//
// Created by john on 16.11.2025.
//

#ifndef PROJMLP_TENSOR_H
#define PROJMLP_TENSOR_H


class tens {
private:
    int N=0, H=0, W=0, C=0, NHWC=0, HWC=0, WC=0;
    static constexpr double mu=0.00001;


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


    void toFlat();
    void to3D(int n, int h, int w, int c);


    double getMax( const double Y[], int len );
    double getSum( const double Y[], int len );

    void showShape();
    void getAccuracy( tens* S);

    tens* getOneN(  int id );
    void expAryminusMax(  double Y[], double max ,int len );
    void mullAryByValue(  double Y[], double value ,int len );



    void WX       ( tens* result, tens* dF, tens* X );
    void WXSoftmax( tens* result, tens* X );



    void addN1( tens* result, tens* const  y );
    void mulN1( tens* result, double mul );
    void HamandMullAry( tens* result, tens* Y );
    void calculateGradientAtEndSoftmax(tens* result, tens* S);

    void BackWX(      tens* Eout, tens* dF, tens* eIn, tens* X );
    void BackSoftmax( tens* Eout, tens* S_Z, tens* X );

    void addPadding( tens* result, int padding);
    void CNN( tens* result,  tens* X );
    void Rot180( tens* result );
    void poolMax( tens* result, tens* dF, int size);
    void poolMaxRev(tens* result, tens* dF, int size);
    void ReLU   ( tens* result );













    //tens* WXSigmoid( tens* result, tens* dF, tens* X);



};


#endif //PROJMLP_TENSOR_H
