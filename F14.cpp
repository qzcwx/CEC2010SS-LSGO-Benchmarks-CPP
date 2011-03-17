 /* =====================================================================================
 *
 *       Filename:  F14.cpp
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
#include "F14.h"
#include <stdio.h>

/**
 * F14: D/m-group Shifted and m-rotated Elliptic Function
 *
 * as defined in "Benchmark Functions for the CEC'2010 Special Session
 * and Competition on Large-Scale Global Optimization" by Ke Tang,
 * Xiaodong Li, P. N. Suganthan, Zhenyu Yang, and Thomas Weise
 * published as technical report on January 8, 2010 at Nature Inspired
 * Computation and Applications Laboratory (NICAL), School of Computer
 * Science and Technology, University of Science and Technology of China,
 * Hefei, Anhui, China.
 */

F14::F14(RunParameter* runParam):Benchmarks(runParam){
	cout<<"F14 Class initialization"<<endl;
	dimension = runParam->dimension;
	m_havenextGaussian=0;
	Ovector = NULL;
	minX = -100;
	maxX = 100;
	ID = 14;
}

F14::F14():Benchmarks(){
	cout<<"F14 Class initialization"<<endl;
	m_havenextGaussian=0;
	Ovector = NULL;
	minX = -100;
	maxX = 100;
	ID = 14;
}

F14::~F14(){
	delete[] Ovector;
	delete[] Pvector;
	// delete 2D array
	int i;
	for(i=0;i<dimension/(nonSeparableGroupSize);i++){
		delete[] MultiRotMatrix1D[i];
	}
	delete[] MultiRotMatrix1D;

	cout<<"F14 Class destroyed"<<endl;
}

double F14::compute(double*x){
	int i,k;
	double result=0.0;

	if(Ovector==NULL){
		Ovector=createShiftVector(dimension,minX,maxX);
		Pvector=createPermVector(dimension);
		MultiRotMatrix1D=createMultiRotateMatrix1D(nonSeparableGroupSize,dimension/(nonSeparableGroupSize));
		//	preparelookup(dimension/2);
		//	preparelookup2(nonSeparableGroupSize);
	}

	for(i=0;i<dimension;i++){
		anotherz[i]=x[i]-Ovector[i];
	}

	double* lookup = lookupprepare(nonSeparableGroupSize);

	for(k=1;k<=dimension/(nonSeparableGroupSize);k++){
		result+=rot_elliptic(anotherz,nonSeparableGroupSize,k, lookup);
	}

	delete[] lookup;
	return(result);
}

double F14::compute(vector<double> x){
	int i,k;
	double result=0.0;

	if(Ovector==NULL){
		Ovector=createShiftVector(dimension,minX,maxX);
		Pvector=createPermVector(dimension);
		MultiRotMatrix1D=createMultiRotateMatrix1D(nonSeparableGroupSize,dimension/(nonSeparableGroupSize));
		//	preparelookup(dimension/2);
		//	preparelookup2(nonSeparableGroupSize);
	}

	for(i=0;i<dimension;i++){
		anotherz[i]=x[i]-Ovector[i];
	}

	double* lookup = lookupprepare(nonSeparableGroupSize);

	for(k=1;k<=dimension/(nonSeparableGroupSize);k++){
		result+=rot_elliptic(anotherz,nonSeparableGroupSize,k, lookup);
	}

	delete[] lookup;
	return(result);
}
