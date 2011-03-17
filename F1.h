 /* =====================================================================================
 *
 *       Filename:  F1.h
 *
 *    Description:  Header file associtated with F1.cpp
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

#ifndef _F1_H
#define _F1_H

#include "Benchmarks.h"

class F1:public Benchmarks{
public:
	F1(RunParameter* runParam);
	F1();
	double compute(double* x) ;
	double compute(vector<double> x) ;
	~F1();
};
#endif
