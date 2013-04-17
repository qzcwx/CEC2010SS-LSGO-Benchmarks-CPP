#include "F2.h"

F2::F2():Benchmarks(){
	m_havenextGaussian=0;
	Ovector = NULL;
	minX = -5;
	maxX = 5;
	ID = 2;
}

F2::~F2(){
 	delete[] Ovector;
}


double F2::compute(double* x){
  int    i;
  double result;

  if(Ovector == NULL) {
    // Ovector = createShiftVector(dimension,minX,maxX);
    Ovector = readOvector();
  }

  for(i = 0; i < dimension; i++) {
    anotherz[i] = x[i] - Ovector[i];
  }

  // T_{osz}
  transform_osz(anotherz);
  
  // T_{asy}^{0.2}
  transform_asy(anotherz, 0.2);

  // lambda
  Lambda(anotherz, 10);

  result = rastrigin(anotherz,dimension);
  return(result);
}

// double F2::compute(vector<double> x){
//   int    i;
//   double result;

//   if(Ovector == NULL) {
//     Ovector = createShiftVector(dimension,minX,maxX);
//   }

//   for(i = 0; i < dimension; i++) {
//     anotherz[i] = x[i] - Ovector[i];
//   }

//   result = rastrigin(anotherz,dimension);
//   return(result);
// }
