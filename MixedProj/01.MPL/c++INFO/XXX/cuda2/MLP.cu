// https://cplusplus.com/forum/beginner/284862/
#ifndef MLPdefs                        // <==== don't call it the same name as the class
#define MLPdefs                        // <==== 
#include <vector>
#include <Eigen/Core>                  // <==== depends on your setup (mine is different from yours)
using namespace std;

class MLP
{
private:
   vector<Eigen::Matrix<double,9,9>> weights;
   vector<Eigen::Matrix<double,9,1>> biases;
   double output;
   double squaredError(vector<double> output, vector<double> target);
public:
   void feedforward(vector<double> x);
   void backprop(vector<double> x, double y);
   MLP( int layers ) : weights(layers,Eigen::Matrix<double,9,9>()){}          // <==== note the extra ()
};




#endif
