#include "F5.h"
#include <stdio.h>



F5::F5():Benchmarks(){
	m_havenextGaussian=0;
	Ovector = NULL;
	minX = -5;
	maxX = 5;
	ID = 5;
        s_size = 7;
}

F5::~F5(){
 	delete[] Ovector;
 	delete[] Pvector;
}

double F5::compute(double*x){
  int    i;
  double result = 0.0;

  if(Ovector == NULL) {
    // Ovector   = createShiftVector(dimension,minX,maxX);
    Ovector = readOvector();
    // Pvector   = createPermVector(dimension);
    Pvector = readPermVector();
    // RotMatrix = createRotMatrix1D(nonSeparableGroupSize);
    r25 = readR(25);
    r50 = readR(50);
    r100 = readR(100);
    s = readS(s_size);
    w = readW(s_size);
  }

  for(i = 0; i < dimension; i++) {
    anotherz[i] = x[i] - Ovector[i];
  }
  
  // put them inside rastrigin function
  // // T_{osz}
  // transform_osz(anotherz, dimension);
  
  // // T_{asy}^{0.2}
  // transform_asy(anotherz, 0.2);

  // // lambda
  // Lambda(anotherz, 10);

  // s_size non-separable part with rotation
  int c = 0;
  for (i = 0; i < s_size; i++)
    {
      // cout<<"c="<<c<<", i="<<i<<endl;
      anotherz1 = rotateVector(i, c);
      // cout<<"done rot"<<endl;
      result += w[i] * rastrigin(anotherz1, s[i]);
      delete []anotherz1;
      // cout<<result<<endl;
    }

  // one separable part without rotation
  double* z = new double[dimension-c];
  for (i = c; i < dimension; i++)
    {
      // cout<<i-c<<" "<<Pvector[i]<<" "<<anotherz[Pvector[i]]<<endl;
      z[i-c] = anotherz[Pvector[i]];
    }
  
  // cout<<"sep"<<endl;
  // cout<<rastrigin(z, dimension-c)<<endl;
  
  result += rastrigin(z, dimension-c);
  free(z);
  
  delete[] z;


  return(result);
}

// double F5::compute(vector<double> x){ 
//   int    i;
//   double result = 0.0;

//   if(Ovector == NULL) {
// 		Ovector   = createShiftVector(dimension,minX,maxX);
// 	  Pvector   = createPermVector(dimension);
// 	  RotMatrix = createRotMatrix1D(nonSeparableGroupSize);

// /*
// 		Pvector = new int[dimension];
// 		for (int i=0; i<dimension; i++){
// 			Pvector[i] = i; 
// 		}
// 		*/
//   }

//   for(i = 0; i < dimension; i++) {
//     anotherz[i] = x[i] - Ovector[i];
//   }

//   for(i = 0; i < nonSeparableGroupSize; i++) {
//     anotherz1[i] = anotherz[Pvector[i]];
//   }

//   for(i = nonSeparableGroupSize; i < dimension; i++) {
//     anotherz2[i - nonSeparableGroupSize] = anotherz[Pvector[i]];
//   }

//   result =
//     rot_rastrigin(anotherz1,nonSeparableGroupSize) * 1.0e6 + rastrigin(
//       anotherz2,dimension - nonSeparableGroupSize);
//   return(result);
// }
