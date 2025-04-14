package CNN;

import org.junit.Test;
import pl.heinzelman.LayerDeep.LayerConv;
import pl.heinzelman.tools.Tools;
import pl.heinzelman.tools.Tools2;

public class CnnApplication {

	Tools2 tools = new Tools2();
	int filterNum = 2;
	private final Convolution conv = new Convolution();
	private final MaxPool pool=new MaxPool();
	private SoftMax softmax=new SoftMax( 13*13*filterNum, 10, filterNum );


	private final LayerConv myConv = new LayerConv( 3, 2, null, null );

	private float[][][] filters = new float[ filterNum ][3][3];

	@Test
	public void forwardTest(){
		tools.prepareData(100);
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
		myConv.setX( trainX );
		float[][][] myOUT = myConv.Forward();
		System.out.println( "conv Z:" + tools.AryToString( out ) );
		System.out.println( "\r\n\r\n\r\n" );
		System.out.println( "myConv Z:" + tools.AryToString( myOUT ) );




	}


	@Test
	public void mainTest() {

		Teacher teacher = new Teacher();
		teacher.prepare( 8 );

		teacher.train( 1000 );
		teacher.test( 1000 );

		teacher.train( 1000 );
		teacher.test( 1000 );

		teacher.train( 1000 );
		teacher.test( 1000 );

	}

}
