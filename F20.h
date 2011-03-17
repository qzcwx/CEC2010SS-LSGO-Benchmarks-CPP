 /* =====================================================================================
 *
 *       Filename:  F20.h
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
#ifndef _F20_H
#define _F20_H

#include "Benchmarks.h"

class F20:public Benchmarks{
protected:
public:
	F20(RunParameter* runParam);
	F20();
	double compute(double* x) ;
	double compute(vector<double> x) ;
	~F20();
};

#endif

