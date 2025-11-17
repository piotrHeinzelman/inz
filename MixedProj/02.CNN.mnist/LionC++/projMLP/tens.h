//
// Created by john on 16.11.2025.
//

#ifndef PROJMLP_TENSOR_H
#define PROJMLP_TENSOR_H


class tens {
private:
    int H, W, C;
    double* data;

public:
    tens(int H,int W,int C)
    : H{H}
    , W{W}
    , C{C} {
        data = new double[H*W*C];
        for (int i=0;i<H*W*C;i++) data[i]=0;
    };

    ~tens() {
        delete data;
    };


    int getH(); int getW(); int getC(); void myPrint();
    double getPoint(int h, int w, int c);

    void setPoint(int h, int w, int c, double value);
    double* getRows(int h, int w_start, int w_end );
    void    setRows(int h, int w_start, int w_end, double* ary );
    // Without operator overloading:
    tens* add( tens* const  y);
    tens* mul( tens* x,  double mul);

};


#endif //PROJMLP_TENSOR_H
