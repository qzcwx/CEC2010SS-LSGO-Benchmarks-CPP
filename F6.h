 /* =====================================================================================
 *
 *       Filename:  F6.h
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
#ifndef _F6_H
#define _F6_H

#include "Benchmarks.h"

class F6:public Benchmarks{
protected:
public:
	F6(RunParameter* runParam);
	F6();
	double compute(double* x) ;
	double compute(vector<double> x) ;
	~F6();
};

#endif
