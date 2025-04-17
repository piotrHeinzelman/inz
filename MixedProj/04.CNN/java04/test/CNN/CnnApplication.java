package CNN;

import org.junit.Test;
import pl.heinzelman.LayerDeep.LayerConv;
import pl.heinzelman.LayerDeep.LayerFlatten;
import pl.heinzelman.LayerDeep.LayerPoolingMax;
import pl.heinzelman.neu.LayerSoftmaxMultiClass;
import pl.heinzelman.neu.LayerSoftmaxMultiClassONLYFORWARD;
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
	private final LayerSoftmaxMultiClass myFCSoftmax = new LayerSoftmaxMultiClass( 13*13*2, 10 );

	private float[][][] filters = new float[ filterNum ][3][3];


	@Test
	public void forwardTest(){ // OK //
		tools.prepareData( 100 );
		float[] XX=tools.getTrainX()[0];
		// System.out.println(XX.length + " : "  + Tools2.AryToString(  XX ));
		float[][][] trainX = new float[1][][];
		            trainX[0] = tools.convertToSquare28x28( XX );
		int trainY = tools.getIndexMaxFloat(  tools.getTrainY()[0] );
		myConv.setUpByX( trainX );

		filters[0][0]= new float[]{ -0.1f, 0.1f, -0.1f };
		filters[0][1]= new float[]{  0.1f, 0.2f,  0.1f };
		filters[0][2]= new float[]{ -0.2f, 0.3f, -0.2f };

		filters[1][0]= new float[]{ -0.4f,  0.2f, -0.3f };
		filters[1][1]= new float[]{ -0.5f, -0.5f, -0.2f };
		filters[1][2]= new float[]{ -0.6f,  0.3f, -0.6f };

		myConv.getNeuron(0).setW( filters[0] );
		myConv.getNeuron(1).setW( filters[1] );

		float[][][] out = conv.forward( trainX[0], filters, filterNum );
		// perform maximum pooling  8x26x26 --> 8x13x13
					out = pool.forward( out );

		// perform softmax operation  8*13*13 --> 10
		float[][] out_l = softmax.forward( out ); // <--


		float[][][] myOUT = myConv.Forward( trainX );
		myOUT = myPool.Forward(myOUT);
		float[] flat = myFlatten.Forward( myOUT );

				for (int j=0;j<softmax.weights.length;j++){
					for (int k=0;k<softmax.weights[0].length;k++){
						myFCSoftmax.getNeuron(k).setWm( j,softmax.weights[j][k] );
					}
				}
		float[] SoftZ = myFCSoftmax.nForward(flat);

		// FORWARD CORRECT --
		//System.out.println( "out_l[0]: " + tools.AryToString( out_l[0] ) );
		//System.out.println( "SoftZ   : "+ tools.AryToString( SoftZ ) );

		float ce_loss = 0.0f; int accuracy=0;
		int correct_label = 2;
		// GRADIENT TEST // OK
		ce_loss += tools.getCeLoss_CNN( out_l[0], correct_label );
		accuracy += correct_label == tools.getIndexMaxFloat(out_l[0]) ? 1:0;

		float[] gradient = myFCSoftmax.gradientCNN( out_l[0], correct_label );

		float[][] SoftZ_Dim = new float[1][]; SoftZ_Dim[0]=SoftZ;
		float[] gradient2 = myFCSoftmax.gradientCNN( SoftZ_Dim[0], correct_label );

		// Gradiend  myFCSoftmax.gradientCNN( out_l, correct_label ); ** CORRECT **
		// tools.echo(gradient2);
		// tools.echo(gradient);

		float learn_rate = 0.01f;











		// ************************************
		// ***
		// ***       backpropagate test !
		// E OUT of SOFTMAX CORRECT

		float[][][] sm_gradient=softmax.backprop( gradient,learn_rate );
		//float[][][] mp_gradient=pool.backprop( sm_gradient );
		//conv.backprop( mp_gradient, learn_rate );

/* -> */


		float[] myFCGradient = myFCSoftmax.nBackward( gradient );
		float[][][] eOUTF    = myFlatten.Backward( myFCGradient );
//tools.echo( sm_gradient[0] );
//tools.echo( sm_gradient[1] );
//tools.echo( eOUTF[0] );
//tools.echo( eOUTF[1] );

		//
		//float[][][] backward = myConv.Backward(eOUTF);

/* -> */

// System.out.println( " sm_gradient: " + tools.AryToString( sm_gradient ) );
// System.out.println( " myFCGradient: " + tools.AryToString( eOUTF ) );
// System.out.println( " softmax.weights[0]: " + tools.AryToString(softmax.weights[0] ) );
// System.out.println( " myFCSoftmax.getNeuronWeight(0): " + tools.AryToString( myFCSoftmax.getNeuronWeight(0) ) );
// System.out.println( " myFCSoftmax.getNeuronWeight(1): " + tools.AryToString( myFCSoftmax.getNeuronWeight(1) ) );
// System.out.println( " myFCSoftmax.getNeuronWeight(2): " + tools.AryToString( myFCSoftmax.getNeuronWeight(2) ) );

	}


	@Test
	public void mainTest() {

		Teacher teacher = new Teacher();
		teacher.prepare( 8 );
		//teacher.train( 60000 );
		//teacher.train( 60000 );
		teacher.train( 128 );
		teacher.train( 128 );
		teacher.train( 128 );
		teacher.train( 128 );
		teacher.train( 128 );
		teacher.train( 128 );
		teacher.train( 128 );
		teacher.train( 128 );
		teacher.train( 128 );
		teacher.train( 128 );
		teacher.train( 128 );
		teacher.train( 128 );
		teacher.train( 128 );
		teacher.train( 128 );
		teacher.train( 128 );
		teacher.train( 128 );
		teacher.train( 128 );
		teacher.train( 128 );
		teacher.train( 128 );
		teacher.train( 128 );
		teacher.train( 128 );
		teacher.train( 128 );
		teacher.train( 128 );
		teacher.train( 128 );

		teacher.test( 10000 );

	}

}
