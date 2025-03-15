package pl.heinzelman.neu;

public class LayerConv {

private String name;
        private  Neuron2D[] filters;
        private  float X[][];
        private  float Y[][];
        private  float Z[][];
        private  float dFofZ[][];
        //private  float Ein[]; // S-Z for last
        private  float Eout[]; // S-Z for last

        public LayerConv(  int filterSize, int filterNum ) {
            this.filters = new Neuron2D[filterNum];
            for (int i=0; i<filterNum ; i++){
                this.filters[i]=new Neuron2D( filterSize, this);
            }
            /*
            X = new float[m];
            Y = new float[n];
            Z = new float[n];
            dFofZ = new float[n];
            //Ein = new float[n];
            Eout = new float[m];

             */
        }



}
