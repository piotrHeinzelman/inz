#include <iostream>
#include <ctime>
#include <fstream>
#include <string.h>

#include "tools.cu"
#include "Layer.h"
#include "NNet.h"
#include "tens.h"

#include "test.cpp"



 void test() {
        tens* X;

 }





/*

    int height=28*28, width=1, channel=1;
    //len=7;
    int L1In =28*28;
    int L1Out=64;
    int L2Out=64;

    tens* XT = load_images_asTensor( "../../../01.MPL/data/train-images-idx3-ubyte", len, height, width, channel ); // int N, int H, int W, int C )
    tens* ST = load_labels( "../../../01.MPL/data/train-labels-idx1-ubyte", len, class_num);

    tens* weight1 = new tens(1, L1In , L1Out     ,1); // <- H - input size, W output size (neuron number)
    tens* weight2 = new tens(1, L1Out, L2Out     ,1); // <- H - input size, W output size (neuron number)
    tens* weight3 = new tens(1, L2Out, class_num ,1); // <- H - input size, W output size (neuron number)

    weight1->rand(-1,1);
    weight2->rand(-1,1);
    weight3->rand(-1,1);
    //weight->myPrint();

              tens* Eout1=new tens(len, L1In, 1, 1); // FAKE /dev/null
                // X*W, Layer sigmoid
                tens* ZT1=new tens(len, L1Out, 1, 1);
                tens* dF1=new tens(len, L1Out, 1, 1);
              tens* Eout2=new tens(len, L1Out, 1, 1);

                tens* ZT2=new tens(len, L2Out, 1, 1);
                tens* dF2=new tens(len, L2Out, 1, 1);
              tens* Eout3=new tens(len, L2Out, 1, 1);

                tens* ZT =new tens(len, class_num, 1, 1);


    for (int e=0;e<epochs;e++) {
        //  *** PLAN ***
        weight1->       WX( ZT1, dF1, XT ); // FORWARD !!!
        weight2->       WX( ZT2, dF2, ZT1 );
        weight3->WXSoftmax( ZT,       ZT2 );

        // ZT->myPrint();
        // ST->myPrint();

        ZT->getAccuracy(ST);
        //ZT->myPrint();
        //ZT->showShape();

        ZT->calculateGradientAtEndSoftmax(ST);  // CALCULATE VECTOR !!!
        tens* Ein=ZT;


        //Eout3->myPrint();


        weight3->BackSoftmax( Eout3, ZT, ZT2 );
        weight2->BackWX( Eout2, dF2, Eout3, ZT1 );
        weight1->BackWX( Eout1, dF1, Eout2, XT ); //tens* Eout, tens* dF, tens* eIn, tens* X
        //ZT->myPrint();   //     "run on Tensor WEIGHT "
        //weight3->myPrint();
        //dF->myPrint();
        //XT->myPrint();

        //ZT->myPrint();
        //ZT->myPrint();
    }

    weight1->       WX( ZT1, dF1, XT ); // FORWARD !!!
    weight2->       WX( ZT2, dF2, ZT1 );
    weight3->WXSoftmax( ZT,       ZT2 );


*/