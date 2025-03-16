package pl.heinzelman.neu;

import pl.heinzelman.tools.Tools;

import javax.tools.Tool;
import java.util.Random;

//
//  Fupdate  = F - u dL/dF ; = Conv ( X, delta )     ; // delta = dL/dO
//  deltaOut = dL/dX = FullConv ( rot180 F , delta ) ; // delta = dL/dO
//

public class LayerConv {

    private String name;
    private Neuron2D[] filters;
    private float X[][][];
    private float Y[][][];
    private float Z[][];
    private float dFofZ[][];
    //private  float Ein[]; // S-Z for last
    private float Eout[]; // S-Z for last //   Eout is F size

    public LayerConv(int filterSize, int filterNum) {
        this.filters = new Neuron2D[filterNum];
        for (int i = 0; i < filterNum; i++) {
            this.filters[i] = new Neuron2D(filterSize, this);
        }
    }

    public void rnd() {
        Random rand = new Random();
        for (int i = 0; i < filters.length; i++) {
            filters[i].rnd(rand);
        }
    }

    public void setName(String _name) {
        this.name = _name;
    }

    public String toString() {
        StringBuffer out = new StringBuffer("\n" + name + "\n");
        for (int i = 0; i < filters.length; i++) {
            out.append(Tools.AryToString(filters[i].getMyWeight()));
        }
        return out.toString();
    }


    public void setX(float[][][] _x) {
        this.X = new float[_x.length][_x[0].length][_x[0].length];
        for (int n = 0; n < _x.length; n++) {
            for (int i = 0; i < _x[0].length; i++) {
                for (int j = 0; j < _x[0].length; j++) {
                    X[n][i][j] = _x[n][i][j];
                }
            }
        }
    }


    public float[][][] nForward() {
        float Y[][][] = new float[ filters.length * X.length ][ X[0].length ][ X[0].length ];
        //int i=0;
        for ( int xlen=0;xlen<X.length; xlen++ ){
            for ( int flen=0; flen< filters.length; flen++ ){
                Y[ xlen*filters.length + flen ] = filters[flen].Forward( X[xlen] );
                //System.out.println( " -- TEST -- xlen:" + xlen + ", flen:" + flen + ", -- " + Tools.AryToString( filters[flen].Forward( X[xlen] ) ) );
                //i++;
            }
        }
        return Y;
    }
}
