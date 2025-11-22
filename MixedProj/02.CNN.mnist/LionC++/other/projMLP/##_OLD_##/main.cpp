// https://forums.developer.nvidia.com/t/how-use-the-cudnn-graph-api-for-do-a-convolution/321806
// https://hpc.pku.edu.cn/docs/20170830182053891231.pdf
// https://www.youtube.com/watch?v=GPBeiKYkuZE
// https://docs.nvidia.com/deeplearning/cudnn/archives/cudnn-892/pdf/cuDNN-Developer-Guide.pdf
// https://docs.nvidia.com/deeplearning/cudnn/backend/v9.15.0/api/cudnn-cnn-library.html
// https://docs.nvidia.com/deeplearning/cudnn/backend/v9.15.0/api/cudnn-graph-library.html#cudnncreate
//
// run:
// nvcc -lcuda -lcublas -lcudnn *.cu -o CNN
//
// echo 'g++ main.cpp -o CNN'
// nvcc main.cpp  -lcuda -lcublas -lcudnn -o CNN



#include <iostream>
#include <ctime>
#include <fstream>
#include <string.h>

#include "tools.cu"
#include "Layer.h"
#include "NNet.h"
#include "tens.h"



//#include <cuda_runtime.h>
//#include <cudnn.h>
//#include <cublas.h>
//#include <cuda.h>


// notation NHWC = first iteration by Channel (RGB), next by width (ABC), next by high (012) lastly by image numger
//    R       G       B
// 0 ***   0 ***   0 ***    <-like chess
// 1 ***   1 ***   1 ***
// 2 ***   2 ***   2 ***
//   abc     abc     abc
//
//   0   1   2   3   4   5   6   7   8   9
//  Ra0 Ga0 Ba0 Rb0 Gb0 Bb0 Rc0 Gc0 Bc0 R...
//
// image i = i*HWC
//
// w-th row in image start At:  i*HWC + w*HC
//
// h-th pix in row   start At:  i*HWC + w*HC + h*C
//
// value of channel = R: start of pix, G: start +1, B: start +2
//

//
//     for i=0;i<I
//       for h=0; h<H
//         for w=0; w<W
//           for c=0; c<C

/*  in       layer     out    =    in  -->
    X   ---> [ F ] --> Z      =    X   -->
             [ F ] --> dF
    Eout <-- [ B ] <-- Ein    =   Eout <--
*/

/*  EXAMPLE 06

XT->setPoint(0,0,0,0,1);
XT->setPoint(0,0,1,0,2);
XT->setPoint(0,0,2,0,3);
XT->setPoint(0,0,3,0,4);
XT->setPoint(0,0,4,0,5);
XT->setPoint(0,1,0,0,6);
XT->setPoint(0,1,1,0,7);
XT->setPoint(0,1,2,0,8);
XT->setPoint(0,1,3,0,9);
XT->setPoint(0,1,4,0,10);
XT->setPoint(0,2,0,0,10);
XT->setPoint(0,2,1,0,11);
XT->setPoint(0,2,2,0,12);
XT->setPoint(0,2,3,0,13);
XT->setPoint(0,2,4,0,14);
XT->setPoint(0,3,0,0,15);
XT->setPoint(0,3,1,0,16);
XT->setPoint(0,3,2,0,17);
XT->setPoint(0,3,3,0,18);
XT->setPoint(0,3,4,0,19);
XT->setPoint(0,4,0,0,20);
XT->setPoint(0,4,1,0,21);
XT->setPoint(0,4,2,0,22);
XT->setPoint(0,4,3,0,23);
XT->setPoint(0,4,4,0,24);

std::cout<<"XT:"<<std::endl;
XT->myPrint();


//tens( outputChannelNum, h, w, imageChannels);
int Fsize=3;
tens* F = new tens(2,Fsize,Fsize,1); // 20,5,5,1
      F->rand(-1,1);


// FULL p=0  // Same p=(W-1)/2  // Min  p=(W-1);
int p= 0 *((Fsize-1)/2);
tens* XTp = new tens(XT->getN(), (XT->getH()+p+p), (XT->getW()+p+p), XT->getC() );
       XT->addPadding( XTp, p ); ////result = new tens(N, H+p+p, W+p+p, C);


// Forward
tens* Y = new tens( XTp->getN(), XTp->getH()-Fsize+1, XTp->getW()-Fsize+1, (2) );


F->CNN( Y, XTp );
Y->myPrint();

//get Delta F
F->myPrint();

F->Rot180(F);

//result = new tens(); // W0= X->W -W + 1;

*/

/*


tens* dF = new tens(1, 5, 5, 1); // size X
tens* XXX;
XT->poolMax(XXX, dF, 2);
XXX->myPrint();
dF->myPrint();

Y->myPrint();
Y->HamandMullAry(Y, dF);

std::cout<<"Y:"<<std::endl;

Y->myPrint();



Y->poolMax(Y, dF, 2);


*/

/*  Example 5

tens* T = new tens(1,3,3,1);
    T->setPoint(0,0,0,0,1);
    T->setPoint(0,0,1,0,2);
    T->setPoint(0,0,2,0,3);
    T->setPoint(0,1,0,0,4);
    T->setPoint(0,1,1,0,5);
    T->setPoint(0,1,2,0,6);
    T->setPoint(0,2,0,0,7);
    T->setPoint(0,2,1,0,8);
    T->setPoint(0,2,2,0,9);

    T->myPrint();
    tens* T2 = T->Rot180();
    T2->myPrint();
*/
/* Example 4

    tens* T = new tens(1,5,5,1);
          T->setPoint(0,0,0,0,1);
          T->setPoint(0,0,1,0,2);
          T->setPoint(0,0,2,0,3);
          T->setPoint(0,0,3,0,4);
          T->setPoint(0,0,4,0,5);
          T->setPoint(0,1,0,0,6);
          T->setPoint(0,1,1,0,7);
          T->setPoint(0,1,2,0,8);
          T->setPoint(0,1,3,0,9);
          T->setPoint(0,1,4,0,0);
          T->setPoint(0,2,0,0,1);
          T->setPoint(0,2,1,0,2);
          T->setPoint(0,2,2,0,3);
          T->setPoint(0,2,3,0,4);
          T->setPoint(0,2,4,0,5);
          T->setPoint(0,3,0,0,6);
          T->setPoint(0,3,1,0,7);
          T->setPoint(0,3,2,0,8);
          T->setPoint(0,3,3,0,9);
          T->setPoint(0,3,4,0,0);
          T->setPoint(0,4,0,0,1);
          T->setPoint(0,4,1,0,2);
          T->setPoint(0,4,2,0,3);
          T->setPoint(0,4,3,0,4);
          T->setPoint(0,4,4,0,5);

          T->myPrint();


    tens* T3 = new tens(1,3,3,1);
    T3->setPoint(0,0,0,0,1);
    T3->setPoint(0,0,1,0,2);
    T3->setPoint(0,0,2,0,3);
    T3->setPoint(0,1,0,0,4);
    T3->setPoint(0,1,1,0,5);
    T3->setPoint(0,1,2,0,6);
    T3->setPoint(0,2,0,0,7);
    T3->setPoint(0,2,1,0,8);
    T3->setPoint(0,2,2,0,9);


    tens* F = new tens(1,3,3,1);
    F->setPoint(0,0,0,0,1);
    F->setPoint(0,0,1,0,0);
    F->setPoint(0,0,2,0,1);
    F->setPoint(0,1,0,0,0);
    F->setPoint(0,1,1,0,1);
    F->setPoint(0,1,2,0,0);
    F->setPoint(0,2,0,0,1);
    F->setPoint(0,2,1,0,0);
    F->setPoint(0,2,2,0,1);

    F->myPrint();

    tens* result;
    result = F->CNN(T3,1);
    std::cout<<"RESULT:"<<std::endl;
    result->myPrint();


    // F->CNN( T->addPadding(1) );

    //tens* Conv = F->CNN( T->addPadding(2) );
    //Conv->myPrint();

    F->myPrint();


*/
/* Example 3 MLP 48000 images, 28*28 * 64 + 64*64 + 64*10


    //XT->myPrint();
    //ST->myPrint();
//W1
    tens*    W1 = new tens(1, Out1, In1 ,1); // <- H - output size, W input size (neuron number)
             W1->rand(-1,1);
    tens*    X1 = XT;// new tens(1,1,In1,1);
    tens* Eout1 = new tens(LEN,1,In1,1);
    // -----
    tens*    Z1 = new tens(LEN,1,Out1,1);
    tens*   dF1 = new tens(LEN,1,Out1,1);

//W2
    tens*    W2 = new tens(1, Out2, In2 ,1); // <- H - output size, W input size (neuron number)
             W2->rand(-1,1);
    tens*    X2 = Z1; //= new tens(1,1,In2,1);
    tens* Eout2 = new tens(LEN,1,In2,1);
    // -----
    tens*    Z2 = new tens(LEN,1,Out2,1);
    tens*   dF2 = new tens(LEN,1,Out2,1);

//W3
    tens*    W3 = new tens(1, Out3, In3 ,1); // <- H - output size, W input size (neuron number)
             W3->rand(-1,1);
    tens*    X3 = Z2; //new tens(1,1,In3,1);
    tens* Eout3 = new tens(LEN,1,In3,1);
    // -----
    tens*    Z3 = new tens(LEN,1,Out3,1);
    tens*   dF3 = new tens(1,1,Out3,1);


    end_loadData = clock();
    start_train = clock();


for (int x=0;x<10;x++) {
    for (int e=0;e<epochs;e++) {
        std::cout << "Epoch: " << x*10+e << std::endl;
        W1->WX(Z1, dF1, XT); //W1->showShape();
        W2->WX(Z2, dF2, X2);
        W3->WXSoftmax(Z3, X3);

        //Z3->myPrint();
        //ST->myPrint();
        Z3->getAccuracy(ST);
        Z3->calculateGradientAtEndSoftmax(ST);
        tens*S_Z=Z3;

        //S_Z->myPrint();

        W3->BackSoftmax(Eout3, S_Z, X3);
        W2->BackWX(Eout2, dF2, Eout3, X2);
        W1->BackWX(Eout1, dF1, Eout2, X1);
    }
}

    end_train = clock();
    start_accu = clock();

    W1->WX(Z1, dF1, XT); //W1->showShape();
    W2->WX(Z2, dF2, X2);
    W3->WXSoftmax(Z3, X3);
    //Z3->calculateGradientAtEndSoftmax(ST);
    Z3->getAccuracy(ST);

    end_accu = clock();

    //X2->myPrint();

    W1->WX(Z1, dF1, XT); //W1->showShape();
    W2->WX(Z2, dF2, X2);
    W3->WXSoftmax(Z3, X3);

    int TEST=3;
    tens* X0=XT->getOneN( TEST );

    W1->WX(Z1, dF1, X0); //W1->showShape();
    W2->WX(Z2, dF2, X2);
    W3->WXSoftmax(Z3, X3);
    //Z3->myPrint();
    (Z3->getOneN( TEST ))->myPrint();
    (ST->getOneN( TEST ))->myPrint();

    std::cout << "LOAD: " << (end_loadData-start_loadData)*1000 << "[msek.]" << std::endl;
    std::cout << "Train: "<< (end_train-start_train)*1000 << "[msek.]" << std::endl;
    std::cout << "Accu: " << (end_accu-start_accu)*1000 << "[msek.]" << std::endl;
    return 0;


*/
/*

   // /* **** Example 2 ****
      h=1,  w=3, c=1;
    tens*    W1 = new tens(1, Out1, In1 ,1); // <- H - output size, W input size (neuron number)
    tens*    X1 = new tens(1,1,In1,1);
    tens* Eout1 = new tens(1,1,In1,1);
// -----
    tens*    Z1 = new tens(1,1,Out1,1);
    tens*   dF1 = new tens(1,1,Out1,1);

    tens*    W2 = new tens(1, Out2, In2 ,1); // <- H - output size, W input size (neuron number)
    tens*    X2 = Z1 ; //new tens(1,1,In2,1);
    tens* Eout2 = new tens(1,1,In2,1);
    // -----
    tens*    Z2 = new tens(1,1,Out2,1);
    //tens*   dF2 = new tens(1,1,Out2,1);

    tens*    S2 = new tens(1,1,Out2,1);

    X1->setPoint(0,0,0,0,1); X1->setPoint(0,0,1,0,2); W1->setPoint(0,0,0,0, 1.0); W1->setPoint(0,0,1,0,-1.0); W1->setPoint(0,1,0,0, 1.0); W1->setPoint(0,1,1,0, 1.0); W1->setPoint(0,2,0,0,-1.0); W1->setPoint(0,2,1,0, 1.0); W2->setPoint(0,0,0,0, 1.0); W2->setPoint(0,0,1,0,-1.0); W2->setPoint(0,0,2,0, 1.0); W2->setPoint(0,1,0,0,-1.0); W2->setPoint(0,1,1,0, 1.0); W2->setPoint(0,1,2,0,-1.0);
    S2->setPoint(0,0,0,0,1.0);

    W1->WX(Z1, dF1, X1);

    W2->WXSoftmax(Z2, X2);


    Z2->myPrint();
    Z2->calculateGradientAtEndSoftmax( S2 );
    tens* S_Z = Z2;

    W2->BackSoftmax( Eout2, S_Z, X2 ); //tens* Eout, tens* dF, tens* S_Z, tens* X
    S_Z->myPrint();
    //dF2->myPrint();
    W2->myPrint();

    W1->BackWX(Eout1, dF1, Eout2, X1);
    W1->myPrint();

    return 0;
*/
/*  Example1
    tens* W1 = new tens(1, Out1, In1 ,1); // <- H - output size, W input size (neuron number)
    tens* W2 = new tens(1, Out2, In2 ,1); // <- H - output size, W input size (neuron number)

    tens* X = new tens(1,1,2,1);
    X->setPoint(0,0,0,0,1);
    X->setPoint(0,0,1,0,2);
    X->myPrint();

    W1->setPoint(0,0,0,0, 1.0);
    W1->setPoint(0,0,1,0,-1.0);
    W1->setPoint(0,1,0,0, 1.0);
    W1->setPoint(0,1,1,0, 1.0);
    W1->setPoint(0,2,0,0,-1.0);
    W1->setPoint(0,2,1,0, 1.0);
    W1->myPrint();

    tens*res1=new tens(1,1,3,1);
    tens*dF1  =new tens(1,1,3,1);

    W1->WX(res1, dF1, X );

    // stage 2
    W2->setPoint(0,0,0,0,1);
    W2->setPoint(0,0,1,0,-1);
    W2->setPoint(0,0,2,0,1);
    W2->setPoint(0,1,0,0,-1);
    W2->setPoint(0,1,1,0,1);
    W2->setPoint(0,1,2,0,-1);
    W2->myPrint();

    tens*res2 =new tens(1,1,2,1);
    tens*dF2  =new tens(1,1,2,1);
    tens*Eout2=new tens(1,1,3,1);

    W2->WX(res2 ,dF2, res1);
    std::cout<<" res2: "<<std::endl;
    res2->myPrint();
    res2->mulN1(-1);
    //res2->myPrint();

    tens* SminusZ =new tens(1,1,2,1);
          SminusZ->setPoint(0,0,0,0,1);
          SminusZ->addN1(res2);
          SminusZ->myPrint();

    std::cout<<" res1: "<<std::endl;
    res1->myPrint();

    std::cout<<" dF2: "<<std::endl;
    dF2->myPrint();

    std::cout<<" SminusZ: "<<std::endl;
    SminusZ->myPrint();

    W2->BackWX( Eout2, dF2, SminusZ, res1  ); //( tens* Eout, tens* dF, tens* eIn, tens* X )
    std::cout<<" Eout: "<<std::endl;
    Eout2->myPrint();
    W2->myPrint();

    tens* Eou1 = new tens(1,1,2,1);

    W1->BackWX( Eou1, dF1, Eout2,  X);
    W1->myPrint();
    */

/*

private LayerConv conv = new LayerConv( 5 , 20, null, null  );
    private LayerPoolingMax poolMax = new LayerPoolingMax(2,2);
    private LayerFlatten flatten = new LayerFlatten();
    private LayerSoftmaxMultiClass softmax = new LayerSoftmaxMultiClass( 12*12*20, 10 );

    public float[] forward_( float[][] X ){
        float[][][] oneX = new float[1][][];
        oneX[0]=X;
        return softmax.nForward( flatten.Forward( poolMax.Forward( conv.Forward( oneX ))));
    }

    public float[][][] backward_( float[] gradient ){
        return conv.Backward(  poolMax.Backward( flatten.Backward(  softmax.nBackward( gradient ))));
    }


*/

int main() {
    int const percent = 1; //80
    long  LEN = percent*600;
    int const class_num=10;
    const long epochs = 120; //500

    clock_t start_loadData, end_loadData, start_train, end_train, start_accu, end_accu;
    start_loadData = clock();
    // *******************

    int h0=28,  w0=28, c0=1;
    //LEN=50;


    tens* XT = load_images_asTensor( "../../../01.MPL/data/train-images-idx3-ubyte", LEN, h0, w0, c0 ); // int N, int H, int W, int C )
    tens* ST = load_labels( "../../../01.MPL/data/train-labels-idx1-ubyte", LEN, class_num);





    // layer 1 CNN
    // Filter size:
    int FSize = 5;
    // Output channel:
    int c1 = 20; //20 //
    // output sizes:
    int h1 = h0-FSize+1;
    int w1 = w0-FSize+1;
    tens* W1 = new tens(LEN, FSize, FSize, c0*c1 ); W1->rand(-1,1);
    tens* deltaW1 = new tens(W1);
    tens* Y1 = new tens(LEN, h1, w1, c1);

    int pool=2;
    tens* dY1Pool = new tens(Y1);
    tens*  Y1Pool = new tens(LEN, Y1->getH()/pool, Y1->getW()/pool, Y1->getC());
    tens*  EOut1  = Y1;



    tens* X2 = Y1Pool ;// output od con layer1;

    int In2 = (12*12*c0);
    int In3 = class_num;

    tens*    W2 = new tens(1, In3, In2 ,1); // <- H - output size, W input size (neuron number)
             W2->rand(-1,1);

    // -----
    tens*    Z2 = new tens(LEN,1,In3,1);
    tens*   dF2 = new tens(Z2);
    tens* EOut2 = new tens(X2);
    tens*   S_Z = new tens(LEN,1,class_num,1 );


for (int e=0;e<epochs;e++) {
    // FORWARD



    W1->CNN( Y1, XT );
    Y1->ReLU();
    //Y1->myPrint();
    Y1->poolMax(Y1Pool, dY1Pool, pool);
    Y1Pool->toFlat();

    W2->WXSoftmax(Z2, X2);

    Z2->getAccuracy(ST);
    Z2->calculateGradientAtEndSoftmax(S_Z, ST);

    W2->BackSoftmax(Y1Pool, S_Z, X2);

    Y1Pool->to3D(LEN, 12, 12, 20);


    Y1Pool->poolMaxRev(EOut1, dY1Pool, pool);

    EOut1->CNN(deltaW1, XT);
    W1->F_updateFilter(deltaW1);


    //W1->F_updateFilter(delta);


    //EIn1->myPrint();
    //std::cout<<"Ein1"<<std::endl;
    //EIn1->showShape();
    //std::cout<<"F1delta"<<std::endl;
    //F1delta->showShape();
    //std::cout<<"XT"<<std::endl;
    //XT->showShape();
    //break;
    //EIn1->CNN(F1delta, XT);
   //XT->CNN(F1delta, EIn1);

    //F1->F_updateFilter( F1delta );
    //F1->myPrint();
}
    //Ein13->showShape();






    //W1->BackWX(Eout1, dF1, Eout2, X1);



};