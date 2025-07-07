public class echo {
    public static void main(String[] args) {
        StringBuffer out = new StringBuffer();

/*
        char ch='a';
        int len=1024;

        while (len>1){
            for (int i = 0; i < len; i++, i++) {
                System.out.println(  "int " + (char)(ch + 1) + "" + i/2 + "=" + ch + "" + i + "+" + ch + "" + (i + 1) + ";");
            }
            len = len / 2;
            ch=(char)(ch+1);
        }

        if (false) {
            out.append("b=");
            for (int i = 0; i < 1024; i++) {
                out.append("+a" + i);
            }
        }


  /*      {

            for (int i = 0; i < 1024; i++) {
                out.append("int a" + i + "=" + i + ";");
            }
        }
*/


        for (int i = 0; i < 1024; i++) {
            out.append( "a"+i );
            if ( i%512==0 ) out.append(")");
            if ( i%256==0 ) out.append(")");
            if ( i%128==0 ) out.append(")");
            if ( i%64==0 ) out.append(")");
            if ( i%32==0 ) out.append(")");
            if ( i%16==0 ) out.append(")");
            if ( i%8==0 ) out.append(")");
            if ( i%4==0 ) out.append(")");
            if ( i%2==0 ) out.append(")");
            out.append("+");
            if ( i%2==0 ) out.append("(");
            if ( i%4==0 ) out.append("(");
            if ( i%8==0 ) out.append("(");
            if ( i%16==0 ) out.append("(");
            if ( i%32==0 ) out.append("(");
            if ( i%64==0 ) out.append("(");
            if ( i%128==0 ) out.append("(");
            if ( i%256==0 ) out.append("(");
            if ( i%512==0 ) out.append("(");
        }


        System.out.println(out.toString() + ";");
    }
}
