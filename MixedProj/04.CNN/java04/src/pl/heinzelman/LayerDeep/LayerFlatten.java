package pl.heinzelman.LayerDeep;

public class LayerFlatten {

    protected String name;

    protected int channels;
    protected int xsize;

    public LayerFlatten () {}



    public void setName( String name ) { this.name = name; }

    public float[] Forward ( float[][][] _x ) {
        this.channels= _x.length;
        this.xsize=_x[0].length;

        float[] Z = new float[ channels*xsize*xsize ];
            for (int c=0;c<channels;c++){
                for (int i=0;i<xsize;i++){
                    for (int j=0;j<xsize;j++) {
                        Z[ c*xsize*xsize + i*xsize + j ] = _x[c][i][j];
                    }
                }
            }
        return Z;
    }


    public float[][][] Backward( float[]delta ){ // delta = (s-z)*d....
        float[][][] OUT = new float[ channels][xsize][xsize];
        for (int c=0;c<channels;c++){
            for (int i=0;i<xsize;i++){
                for (int j=0;j<xsize;j++) {
                    OUT[c][i][j] = delta[ c*xsize*xsize + i*xsize + j ];
                }
            }
        }
        return OUT;
    }
}
