package pl.heinzelman.yyy.net;

import java.text.DecimalFormat;

public class TT {

    private static final char[] table={'.',',','-','~',':',';','=','!','*','#','$','@'};
    private static final DecimalFormat formatter = new DecimalFormat("###0.000");

    public static String printRow( int[] row ){
        String out="";
        for (int x=0;x<row.length;x++){
            out += " "+row[x]+", ";
        }
        return ( out );
    }

    public static String printRow( Double[] row ){
        String out="";
        for (int x=0;x<row.length;x++){
            if ( row[x]==null ) { out +="null, "; } else
            out += " "+formatter.format( row[x]) +", ";
        }
        return ( out );
    }

    public static String printRow( float[] row ){
        String out="";
        for (int x=0;x<row.length;x++){
            //if ( row[x]==null ) { out +="null, "; } else
                out += " "+formatter.format( row[x]) +", ";
        }
        return ( out );
    }

    public static String printRow2( int[] row ){
        String out="";
        for (int x=0;x<row.length;x++){
            int v=row[x];
            if ( v==0 ) { out += " "; }
            else if ( v < 10 ) { out += ""+v; }
            else { out+= table[ (int)(v/22)]; }
        }
        return ( out );
    }


    public static void printTable( int[][] table ){
        for (int y=0;y<table[0].length;y++){
            System.out.println( printRow( table[y] )); // 2
        }
    }

    public static void printTable( Double[][] table ){
        for (int y=0;y<table[0].length;y++){
            System.out.println( printRow( table[y] ));
        }
    }


    public static void printTable( float[][] table ){
        for (int y=0;y<table[0].length;y++){
            System.out.println( printRow( table[y] ));
        }
    }


    public static void printTable2( int[][] table ){
        System.out.println( " incorrect class  ->  [0]  |  [1]  |  [2]  |  [3]  |  [4]  |  [5]  |  [6]  |  [7]  |  [8]  |  [9]\n" );
        for (int y=0;y<table[0].length;y++){
            System.out.println("True class    ("+y+")   " + printRow3( table[y] ));
        }
    }

    public static String printRow3( int[] row ){
        String out="";
        for (int x=0;x<row.length;x++){
            out += "  "+ ((row[x])>9 ? "" : " " ) +  ( row[x]==0 ? "." : row[x] )   +"   |";
        }
        return ( out );
    }

    public static int[] squareToline(int[][] square){
        int[] out = new int[ square.length * square[0].length ];
        for (int j=0;j<square.length;j++){
            for (int i=0;i<square[0].length;i++){
                out[ ( j*square.length )+i ]=square[j][i];
            }
        }
        return out;
    }

    public static int[][] lineToSquare(int[] line){
        int n=(int) Math.pow( line.length, 0.5);
        int[][] out = new int[n][n];
        for (int j=0;j<n;j++){
            for (int i=0;i<n;i++){
                out[j][i]=line[ ( j*n )+i ];
            }
        }
        return out;
    }


    public static Double[] lineIntTolineDouble( int[] line ){
        Double[] out = new Double[line.length];
        for (int i=0;i< line.length;i++){
                out[i]= Double.valueOf( line[i]);
        }
        return out;
    }

    public static float[][] squareIntToSquareFLoat( int[][] square ){
        int n=square.length;
        float[][] out = new float[n][n];
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++) {
                out[i][j] = Float.valueOf( square[i][j] )/255;
            }
        }
        return out;
    }

}
