#include "F8.h"
#include <stdio.h>

F8::F8():Benchmarks(){
  Ovector = NULL;
  minX = -100;
  maxX = 100;
  ID = 8;
  s_size = 20;
}

F8::~F8(){
  delete[] Ovector;
  delete[] Pvector;
}

double F8::compute(double* x){
  int    i;
  double result;

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
      result += w[i] * elliptic(anotherz1, s[i]);
      delete []anotherz1;
      // cout<<result<<endl;
    }
  
  return(result);
}
