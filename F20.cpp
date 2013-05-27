#include "F20.h"
#include <stdio.h>

F20::F20():Benchmarks(){
  m_havenextGaussian=0;
  Ovector = NULL;
  minX = -100;
  maxX = 100;
  ID = 20;
}

F20::~F20(){
  delete[] Ovector;
}

double F20::compute(double*x){
  int i;
  double result=0.0;

  if(Ovector==NULL)
    {
      Ovector=createShiftVector(dimension,minX,maxX-1);
    }

  for(i=0;i<dimension;i++)
    {
      anotherz[i]=x[i]-Ovector[i];
    }

  result=rosenbrock(anotherz, dimension);
  return(result);
}

double F20::compute(vector<double> x){
  int i;
  double result=0.0;

  if(Ovector==NULL)
    {
      Ovector=createShiftVector(dimension,minX,maxX-1);
    }

  for(i=0;i<dimension;i++)
    {
      anotherz[i]=x[i]-Ovector[i];
    }

  result=rosenbrock(anotherz, dimension);
  return(result);
}
