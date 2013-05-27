#include "F15.h"
#include <stdio.h>

F15::F15():Benchmarks(){
  Ovector = NULL;
  minX = -5;
  maxX = 5;
  ID = 15;
}

F15::~F15(){
  delete[] Ovector;
  delete[] Pvector;
  delete[] RotMatrix;
}

double F15::compute(double*x){
  int i,k;
  double result=0.0;
        
  if (Ovector==NULL)
    {
            
    }
        
  for(i=0;i<dimension;i++){
    anotherz[i]=x[i]-Ovector[i];
  }

  for(k=1;k<=dimension/(nonSeparableGroupSize);k++){
    result+=rot_rastrigin(anotherz,nonSeparableGroupSize,k);
  }

  return(result);
}

