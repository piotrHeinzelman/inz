package pl.heinzelman.yyy;

import org.junit.jupiter.api.Test;
import pl.heinzelman.LayerDeep.LayerConv;
import pl.heinzelman.tools.Tools;
import pl.heinzelman.yyy.net.Convolution;
import pl.heinzelman.yyy.net.Teacher;

import java.util.Arrays;


public class CnnApplication {

	@Test
	public void ConvTest(){
		float[][][] filters = new float[2][3][3];
		filters[0][0] = new float[]{ .1f, .2f, .3f };
		filters[0][1] = new float[]{ .4f, .5f, .5f };
		filters[0][2] = new float[]{ .7f, .8f, .8f };

		filters[1][0] = new float[]{ .1f, .0f, -.2f };
		filters[1][1] = new float[]{ .0f, .1f, .0f };
		filters[1][2] = new float[]{ -.2f, .0f, .1f };

		float[][][] X = new float[1][5][5];
		X[0][0] = new float[]{ -.9f, -.8f, -.7f, -.6f, -.5f };
		X[0][1] = new float[]{ -.4f, -.3f, -.2f, -.1f, .0f };
		X[0][2] = new float[]{ .1f, .2f, .3f, .4f, .5f };
		X[0][3] = new float[]{ .6f, .7f, .8f, .9f, .2f };
		X[0][4] = new float[]{ .1f, .2f, .3f, .4f, .5f };

		Convolution conv = new Convolution();
		float[][][] C = conv.forward (X[0], filters, 2) ;
//System.out.println(Tools.AryToString( C ));

		LayerConv myConv = new LayerConv( 3 , 2 , null , null );
		myConv.setUpByX( X );
		myConv.setX( X );
		myConv.getNeuron(0).setW( filters[0] );
		myConv.getNeuron(1).setW( filters[1] );
		float[][][] myC = myConv.Forward();
//System.out.println(Tools.AryToString( myC ));




		float[][][] gradient = new float[2][3][3];
		gradient[0][0] = new float[]{ -.2f, -.1f, .0f };
		gradient[0][1] = new float[]{ -.4f, -.2f, .1f };
		gradient[0][2] = new float[]{ -.6f, -.4f, .2f };

		gradient[1][0] = new float[]{ .2f, -.7f, .6f };
		gradient[1][1] = new float[]{ .4f, .2f, -.5f };
		gradient[1][2] = new float[]{ .1f, .3f, .2f };

// System.out.println( Tools.AryToString( gradient ));

		conv.backprop( gradient, 0.01f );
// System.out.println( Tools.AryToString(  conv.filters ));

		myConv.Backward( gradient );
// System.out.println( Tools.AryToString( myConv.getNeuron(0).getMyWeight() ));
// System.out.println( Tools.AryToString( myConv.getNeuron(1).getMyWeight() ));






	}


	@Test
	public void main() {

		Teacher.prepare( 8 );
		Teacher.train( 5000 );

		Teacher.test( 1000 );

		Teacher.train( 5000 );
		Teacher.test( 1000 );

		Teacher.train( 5000 );
		Teacher.test( 1000 );

		Teacher.train( 5000 );
		Teacher.test( 1000 );

		Teacher.train( 5000 );
		Teacher.test( 1000 );

		Teacher.train( 5000 );
		Teacher.test( 1000 );

		Teacher.train( 5000 );
		Teacher.test( 1000 );

		Teacher.train( 5000 );
		Teacher.test( 1000 );

		Teacher.train( 5000 );
		Teacher.test( 1000 );

		Teacher.train( 5000 );
		Teacher.test( 10000 );
		/**/
	}

}
