package CNN;

import org.junit.Test;
import pl.heinzelman.LayerDeep.LayerConv;
import pl.heinzelman.LayerDeep.LayerFlatten;
import pl.heinzelman.LayerDeep.LayerPoolingMax;
import pl.heinzelman.neu.LayerSigmoidFullConn;
import pl.heinzelman.neu.LayerSoftmaxMultiClass;
import pl.heinzelman.tools.Tools;
import pl.heinzelman.tools.Tools2;

public class CnnApplication {

	Tools2 tools = new Tools2();
	int filterNum = 2;
	private final Convolution conv = new Convolution();
	private final MaxPool pool=new MaxPool();
	private SoftMax softmax=new SoftMax( 13*13*filterNum, 10, filterNum );

	private final LayerConv myConv = new LayerConv( 3, 2, null, null );
	private final LayerPoolingMax myPool = new LayerPoolingMax(2,2);

	private final LayerFlatten myFlatten = new LayerFlatten();
	private final LayerSigmoidFullConn myFC = new LayerSigmoidFullConn(13*13*2, 10);
	private final LayerSoftmaxMultiClass mySoftmax = new LayerSoftmaxMultiClass( 10 );

	private float[][][] filters = new float[ filterNum ][3][3];

	@Test
	public void forwardTest(){
		tools.prepareData( 100 );
		float[] XX=tools.getTrainX()[0];
		// System.out.println(XX.length + " : "  + Tools2.AryToString(  XX ));
		float[][][] trainX = new float[1][][];
		            trainX[0] = tools.convertToSquare28x28( XX );
		int trainY = tools.getIndexMaxFloat(  tools.getTrainY()[0] );
		myConv.setUpByX( trainX );

		filters[0][0]= new float[]{-0.1f, 0.1f, -0.1f};
		filters[0][1]= new float[]{ 0.1f, 0.2f,  0.1f};
		filters[0][2]= new float[]{-0.2f, 0.3f, -0.2f};

		filters[1][0]= new float[]{-0.4f,  0.2f, -0.3f};
		filters[1][1]= new float[]{-0.5f, -0.5f, -0.2f};
		filters[1][2]= new float[]{-0.6f,  0.3f, -0.6f};

		myConv.getNeuron(0).setW( filters[0] );
		myConv.getNeuron(1).setW( filters[1] );

		float[][][] out = conv.forward( trainX[0], filters, filterNum );
		// perform maximum pooling  8x26x26 --> 8x13x13
					out = pool.forward( out );

		// perform softmax operation  8*13*13 --> 10
		// softmax.weights =
		 float[][] out_l = softmax.forward( out );


		System.out.println( "out_l:" + tools.AryToString( out_l ) );
		System.out.println( "\r\n\r\n\r\n" );


		myConv.setX( trainX );
		float[][][] myOUT = myConv.Forward();
		myPool.setX( myOUT );
		myOUT = myPool.Forward();
		float[] flat = myFlatten.Forward( myOUT );

		for (int j=0;j<13*13*2;j++){
			for (int k=0;k<10;k++){
				myFC.getNeuron(k).setWm( j,softmax.weights[j][k] );
			}
		}
		float[] Z = myFC.nForward(flat);
		float[] SoftZ = mySoftmax.nForward(Z);

		System.out.println( "myConv Z:" + tools.AryToString( SoftZ ) );
	}


	@Test
	public void mainTest() {

		Teacher teacher = new Teacher();
		teacher.prepare( 8 );


		teacher.train( 100 );
		teacher.train( 100 );
		teacher.train( 100 );
		teacher.train( 100 );
		teacher.train( 100 );
		teacher.train( 100 );
		teacher.train( 100 );
		teacher.train( 100 );
		teacher.train( 100 );
		teacher.train( 100 );
		teacher.train( 100 );
		teacher.train( 100 );
		teacher.train( 100 );
		teacher.train( 100 );
		teacher.train( 100 );
		teacher.train( 100 );
		teacher.train( 100 );
		teacher.train( 100 );
		teacher.train( 100 );
		teacher.train( 100 );
		teacher.train( 100 );
		teacher.train( 100 );
		teacher.train( 100 );

		teacher.test( 1000 );

	}

}
