#include "F17.h"
#include <stdio.h>

/**
 * Single-group Shifted and m-rotated Elliptic Function
 *
 * as defined in "Benchmark Functions for the CEC'2010 Special Session
 * and Competition on Large-Scale Global Optimization" by Ke Tang,
 * Xiaodong Li, P. N. Suganthan, Zhenyu Yang, and Thomas Weise
 * published as technical report on January 8, 2010 at Nature Inspired
 * Computation and Applications Laboratory (NICAL), School of Computer
 * Science and Technology, University of Science and Technology of China,
 * Hefei, Anhui, China.
 */

F17::F17(RunParameter* runParam):Benchmarks(runParam){
	dimension = runParam->dimension;
	m_havenextGaussian=0;
	Ovector = NULL;
	minX = -100;
	maxX = 100;
	ID = 17;
}

F17::F17():Benchmarks(){
	m_havenextGaussian=0;
	Ovector = NULL;
	minX = -100;
	maxX = 100;
	ID = 17;
}

F17::~F17(){
	delete[] Ovector;
	delete[] Pvector;
}

double F17::compute(double*x){
  int i,k;
  double result=0.0;

  if(Ovector==NULL){
    Ovector=createShiftVector(dimension,minX,maxX);
    Pvector=createPermVector(dimension);
  }

  for(i=0;i<dimension;i++){
    anotherz[i]=x[i]-Ovector[i];
  }

  for(k=1;k<=dimension/(nonSeparableGroupSize);k++){
    result+=schwefel(anotherz,nonSeparableGroupSize,k);
  }
  return(result);
}

double F17::compute(vector<double> x){
  int i,k;
  double result=0.0;

  if(Ovector==NULL){
    Ovector=createShiftVector(dimension,minX,maxX);
    Pvector=createPermVector(dimension);
  }

  for(i=0;i<dimension;i++){
    anotherz[i]=x[i]-Ovector[i];
  }

  for(k=1;k<=dimension/(nonSeparableGroupSize);k++){
    result+=schwefel(anotherz,nonSeparableGroupSize,k);
  }
  return(result);
}
