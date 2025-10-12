//#include<iostream>
using namespace std;


int main(int argc, char **argv) {


   int len = 8;
   double X[ len ]={ 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8 };
   double W[ len ]={ 0.85, 0.75, 0.65, 0.55, 0.45, 0.35, 0.25, 0.15 };

   double sum=0.0;
   for (int i=0; i<len; i++) {
	sum+=X[i]*W[i];
   }
//  std::cout<<x;
  return 0;
}

