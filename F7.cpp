#include "F7.h"
#include <stdio.h>


F7::F7():Benchmarks(){
	Ovector = NULL;
	minX = -100;
	maxX = 100;
	ID = 7;
        s_size = 7;
}

F7::~F7(){
	delete[] Ovector;
	delete[] Pvector;
}


double F7::compute(double*x){
  int    i;
  double result = 0.0;

  if(Ovector == NULL) {
    Ovector = readOvector();
    Pvector = readPermVector();
    r25 = readR(25);
    r50 = readR(50);
    r100 = readR(100);
    s = readS(s_size);
    w = readW(s_size);
  }

  for(i = 0; i < dimension; i++) {
    anotherz[i] = x[i] - Ovector[i];
  }

  // s_size non-separable part with rotation
  int c = 0;
  for (i = 0; i < s_size; i++)
    {
      // cout<<"c="<<c<<", i="<<i<<endl;
      anotherz1 = rotateVector(i, c);
      // cout<<"done rot"<<endl;
      result += w[i] * schwefel(anotherz1, s[i]);
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
  
  result += sphere(z, dimension-c);
  free(z);


  return(result);
}

double F7::compute(vector<double> x){
  int    m = nonSeparableGroupSize;
  int    i;
  double result;

  if(Ovector == NULL) {
	  Ovector = createShiftVector(dimension,minX,maxX);
		Pvector   = createPermVector(dimension);
  }

  for(i = 0; i < dimension; i++) {
    anotherz[i] = x[i] - Ovector[i];
  }

  for(i = 0; i < m; i++) {
    anotherz1[i] = anotherz[Pvector[i]];
  }

  for(i = m; i < dimension; i++) {
    anotherz2[i - m] = anotherz[Pvector[i]];
  }

  result = schwefel(anotherz1,m) * 1e6 + sphere(anotherz2,dimension - m);
  return(result);
}
