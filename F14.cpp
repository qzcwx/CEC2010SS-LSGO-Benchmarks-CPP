#include "F14.h"
#include <stdio.h>

F14::F14():Benchmarks(){
  OvectorVec = NULL;
  minX = -100;
  maxX = 100;
  ID = 14;
  s_size = 20;
  dimension = 905;        // because of overlapping
  overlap = 5;
}

F14::~F14(){
  delete[] Ovector;
  delete[] Pvector;
}

double F14::compute(double*x){
  int i;
  double result=0.0;
  
  if(OvectorVec == NULL)
    {
      s = readS(s_size);
      OvectorVec = readOvectorVec();
      // // inspect OvectorVec
      // for (int i = 0; i < s_size; ++i)
      //   {
      //     for (int j=0; j< s[i]; j++)
      //       {
      //         printf("%.1f\t",OvectorVec[i][j]);
      //       }
      //     printf("\n");
      //   }
      Pvector = readPermVector();
      r25 = readR(25);
      r50 = readR(50);
      r100 = readR(100);
      w = readW(s_size);
    }

  
  // for(i=0;i<dimension;i++){
  //   anotherz[i]=x[i]-Ovector[i];
  // }
  
  return(result);
}
