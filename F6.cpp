#include "F6.h"
#include <stdio.h>

F6::F6():Benchmarks(){
  m_havenextGaussian=0;
  Ovector = NULL;
  minX = -32;
  maxX = 32;
  ID = 6;
  s_size = 7;
}

F6::~F6(){
  delete[] Ovector;
  delete[] Pvector;
}

double F6::compute(double*x){
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

  // cout<<"non"<<endl;
  
  // s_size non-separable part with rotation
  int c = 0;
  for (i = 0; i < s_size; i++)
    {
      // cout<<"c="<<c<<", i="<<i<<endl;
      anotherz1 = rotateVector(i, c);
      // cout<<"done rot"<<endl;
      result += w[i] * ackley(anotherz1, s[i]);
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
  result += ackley(z, dimension-c);
  free(z);
  
  return(result);
}

