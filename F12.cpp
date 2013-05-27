#include "F12.h"
#include <stdio.h>

F12::F12():Benchmarks(){
  m_havenextGaussian=0;
  Ovector = NULL;
  minX = -100;
  maxX = 100;
  ID = 12;
}

F12::~F12(){
  delete[] Ovector;
}

double F12::compute(double*x){
  int i;
  double result=0.0;

  if(Ovector==NULL)
    {
      Ovector = readOvector();
    }

  for(i=0;i<dimension;i++)
    {
      anotherz[i]=x[i]-Ovector[i];
    }

  result=rosenbrock(anotherz, dimension);
  return(result);
}

