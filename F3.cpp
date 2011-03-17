 /* =====================================================================================
 *
 *       Filename:  F3.cpp
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
#include "F3.h"

/**
 * F3: Shifted Ackley¡¯s Function
 *
 * as defined in "Benchmark Functions for the CEC'2010 Special Session
 * and Competition on Large-Scale Global Optimization" by Ke Tang,
 * Xiaodong Li, P. N. Suganthan, Zhenyu Yang, and Thomas Weise
 * published as technical report on January 8, 2010 at Nature Inspired
 * Computation and Applications Laboratory (NICAL), School of Computer
 * Science and Technology, University of Science and Technology of China,
 * Hefei, Anhui, China.
 */

F3::F3(RunParameter* runParam):Benchmarks(runParam){
	cout<<"F3 Class initialization"<<endl;
	dimension = runParam->dimension;
	m_havenextGaussian=0;
	Ovector = NULL;
	minX = -32;
	maxX = 32;
	ID = 3;
}

F3::F3():Benchmarks(){
	cout<<"F3 Class initialization"<<endl;
	m_havenextGaussian=0;
	Ovector = NULL;
	minX = -32;
	maxX = 32;
	ID = 3;
}

F3::~F3(){
 	delete[] Ovector;
	cout<<"F3 Class destroyed"<<endl;
}


double F3::compute(double*x){
  int    i;
  double result;

  if(Ovector == NULL) {
    Ovector = createShiftVector(dimension,minX,maxX);
  }

  for(i = dimension - 1; i >= 0; i--) {
    anotherz[i] = x[i] - Ovector[i];
  }

  result = ackley(anotherz,dimension);
  return(result);
}


double F3::compute(vector<double> x){
  int    i;
  double result;

  if(Ovector == NULL) {
    Ovector = createShiftVector(dimension,minX,maxX);
  }

  for(i = dimension - 1; i >= 0; i--) {
    anotherz[i] = x[i] - Ovector[i];
  }

  result = ackley(anotherz,dimension);
  return(result);
}
