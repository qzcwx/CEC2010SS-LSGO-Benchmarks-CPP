 /* =====================================================================================
 *
 *       Filename:  F19.cpp
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
#include "F19.h"
#include <stdio.h>

/**
 * F19: Shifted Schwefel¡¯s Problem 1.2
 *
 * as defined in "Benchmark Functions for the CEC'2010 Special Session
 * and Competition on Large-Scale Global Optimization" by Ke Tang,
 * Xiaodong Li, P. N. Suganthan, Zhenyu Yang, and Thomas Weise
 * published as technical report on January 8, 2010 at Nature Inspired
 * Computation and Applications Laboratory (NICAL), School of Computer
 * Science and Technology, University of Science and Technology of China,
 * Hefei, Anhui, China.
 */

F19::F19(RunParameter* runParam):Benchmarks(runParam){
	cout<<"F19 Class initialization"<<endl;
	dimension = runParam->dimension;
	m_havenextGaussian=0;
	Ovector = NULL;
	minX = -100;
	maxX = 100;
	ID = 19;
}

F19::F19():Benchmarks(){
	cout<<"F19 Class initialization"<<endl;
	m_havenextGaussian=0;
	Ovector = NULL;
	minX = -100;
	maxX = 100;
	ID = 19;
}

F19::~F19(){
	delete[] Ovector;
	cout<<"F19 Class destroyed"<<endl;
}

double F19::compute(double*x){
	int i;
	double result;

	if(Ovector==NULL)
	{
		Ovector=createShiftVector(dimension,minX,maxX);
	}

	for(i=0;i<dimension;i++)
	{
		anotherz[i]=x[i]-Ovector[i];
	}

	result=schwefel(anotherz, dimension);
	return(result);
}


double F19::compute(vector<double> x){
	int i;
	double result;

	if(Ovector==NULL)
	{
		Ovector=createShiftVector(dimension,minX,maxX);
	}

	for(i=0;i<dimension;i++)
	{
		anotherz[i]=x[i]-Ovector[i];
	}

	result=schwefel(anotherz, dimension);
	return(result);
}
