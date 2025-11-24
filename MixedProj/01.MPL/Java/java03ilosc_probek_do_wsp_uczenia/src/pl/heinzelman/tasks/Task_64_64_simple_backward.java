package pl.heinzelman.tasks;

import pl.heinzelman.neu.LType;
import pl.heinzelman.neu.Layer;
import pl.heinzelman.tools.Tools;

import java.awt.image.BufferedImage;
import java.util.Arrays;
import java.time.Instant;
import java.time.temporal.ChronoUnit;


public class Task_64_64_simple_backward implements Task{

    private float[][] testX;
    private float[][] testY;
    private float[][] trainX;
    private float[][] trainY;

    private Layer layer1;
    private Layer layer2;
    private Layer layer3;

    private Tools tools = new Tools();

    int cepo=0;
    int numOfEpoch=41;
	String code="k";
    float[] CSBin_data=new float[numOfEpoch];

    @Override
    public void prepare() {
	Instant start=Instant.now();
        tools.prepareData( 100 );

        testX = tools.getTestX();
        testY = tools.getTestY();
        trainX = tools.getTrainX();
        trainY = tools.getTrainY();

        layer1=new Layer( LType.sigmod , 64 ,784 ); layer1.setName("Layer1"); // n neurons
        layer1.rnd();

        layer2=new Layer( LType.sigmod , 64 ,64 ); layer2.setName("Layer2"); // n neurons
        layer2.rnd();

        layer3=new Layer( LType.softmaxMultiClass , 10 ,64 ); layer3.setName("Layer3"); // n neurons
        layer3.rnd();

	Instant end=Instant.now();
	Double time=( ChronoUnit.MILLIS.between(start,end))/1000.0;

        System.out.println("time prepare data:" +  time );


    }

    @Override
    public void run() {
		
        for (int cycle=0;cycle<1;cycle++) {

            float Loss = 0.0f;
            int step=1;
            for (int epoch = 0; epoch < numOfEpoch; epoch++) {
                step++;
                cepo++;
                for ( int index = 0; index < trainX.length; index++ ) {

                    // ONE CYCLE
                    int ind_ex = /*index; //*/ (index*step) % trainX.length;


                    layer1.setX( trainX[ ind_ex ] );
                    layer1.nForward();
                    layer2.setX( layer1.getZ() );
                    layer2.nForward();
                    layer3.setX( layer2.getZ() );
                    layer3.nForward();

                    float[] S_Z = tools.vectorSubstSsubZ( trainY[ ind_ex ], layer3.getZ() );
                    layer3.nBackward( S_Z );
                    Loss += Tools.crossEntropyMulticlassError( layer3.getZ() );
                    layer2.nBackward( layer3.getEout() );
                    layer1.nBackward( layer2.getEout() );
                }
                //CSBin_data[epoch]=Loss/trainX.length;
			
								switch(epoch){
									case 5: case 10: case 15: case 20: case 25: case 30: case 35: case 40:		
								int len = testX.length;
								int accuracy = 0;
								for (int i = 0; i < len; i++) {
									layer1.setX( testX[i] );
									layer1.nForward();
									layer2.setX( layer1.getZ() );
									layer2.nForward();
									layer3.setX( layer2.getZ() );
									layer3.nForward();

									int netClassId = tools.getIndexMaxFloat( layer3.getZ() );
									int fileClassId = tools.getIndexMaxFloat( testY[i] );
									if (fileClassId == netClassId) {
										accuracy++;
									}
								}
								String s="0";
								if (epoch==5) s="0";
								if (epoch==10) s="1";
								if (epoch==15) s="2";
								if (epoch==20) s="3";
								if (epoch==25) s="4";
								if (epoch==30) s="5";
								if (epoch==35) s="6";
								if (epoch==40) s="7";
								
								System.out.println(code+"["+s + "]="+ 1.0f*accuracy / len);
								break;
								}
            }
            //System.out.println( Arrays.toString( layer1.getNeuronWeight(0)));
            //System.out.println( Arrays.toString( layer3.getX()));
            //System.out.println( Arrays.toString( layer3.getZ()));

            // check accuracy
	Instant Astart=Instant.now();

           
			/*
	Instant Aend=Instant.now();
	Double time=( ChronoUnit.MILLIS.between(Astart,Aend))/1000.0;
        System.out.println("Accuracy Time::" +  time );


                    layer1.setX( trainX[ 17 ] );
                    layer1.nForward();
                    layer2.setX( layer1.getZ() );
                    layer2.nForward();
                    layer3.setX( layer2.getZ() );
                    layer3.nForward();

	            int netClassId = tools.getIndexMaxFloat( layer3.getZ() );

            System.out.println("18 element należy do klasy: " + netClassId );
*/
        }
    }
}
