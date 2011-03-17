 /* =====================================================================================
 *
 *       Filename:  F16.h
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
#ifndef _F16_H
#define _F16_H

#include "Benchmarks.h"

class F16:public Benchmarks{
protected:
public:
	F16(RunParameter* runParam);
	F16();
	double compute(double* x) ;
	double compute(vector<double> x) ;
	~F16();
};

#endif

