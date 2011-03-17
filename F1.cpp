 /* =====================================================================================
 *
 *       Filename:  F1.cpp
 *
 *        Version:  1.0
 *        Created:  02/24/2011 07:56:20 PM
 *       Revision:  none
 *
 *       Compiler:  g++
 *         Author:  Wenxiang Chen (http://cs-chen.net), chenwx.ustc@gmail.com
 *        Company:  Nature Inspired Computation and Application Laboratory (NICAL), USTC
 *
 * =====================================================================================
 */

#include "F1.h"

/**
 * F1: Shifted Elliptic Function
 *
 * as defined in "Benchmark Functions for the CEC'2010 Special Session
 * and Competition on Large-Scale Global Optimization" by Ke Tang,
 * Xiaodong Li, P. N. Suganthan, Zhenyu Yang, and Thomas Weise
 * published as technical report on January 8, 2010 at Nature Inspired
 * Computation and Applications Laboratory (NICAL), School of Computer
 * Science and Technology, University of Science and Technology of China,
 * Hefei, Anhui, China.
 */

F1::F1(RunParameter* runParam):Benchmarks(runParam){
	cout<<"F1 Class initialization"<<endl;
	dimension = runParam->dimension;
	m_havenextGaussian=0;
	Ovector = NULL;
	minX = -100;
	maxX = 100;
	ID = 1;
}

F1::F1():Benchmarks(){
	cout<<"F1 Class initialization"<<endl;
	m_havenextGaussian=0;
	Ovector = NULL;
	minX = -100;
	maxX = 100;
	ID = 1;
}

F1::~F1(){
 	delete[] Ovector;
	cout<<"F1 Class destroyed"<<endl;
}

double F1::compute(double* x) {
  double result;
  int    i;

  if(Ovector == NULL) {
    Ovector = createShiftVector(dimension,minX,maxX);
  }

  for(i = dimension - 1; i >= 0; i--) {
    anotherz[i] = x[i] - Ovector[i];
  }

  result = elliptic(anotherz,dimension);
  return(result);
}


double F1::compute(vector<double> x){
  double result;
  int    i;

  if(Ovector == NULL) {
    Ovector = createShiftVector(dimension,minX,maxX);
  }

  for(i = dimension - 1; i >= 0; i--) {
    anotherz[i] = x[i] - Ovector[i];
  }

  result = elliptic(anotherz,dimension);
  return(result);
}
