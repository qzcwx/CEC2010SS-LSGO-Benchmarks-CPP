 /* =====================================================================================
 *
 *       Filename:  F14.h
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
#ifndef _F14_H
#define _F14_H

#include "Benchmarks.h"

class F14:public Benchmarks{
protected:
public:
	F14(RunParameter* runParam);
	F14();
	double compute(double* x) ;
	double compute(vector<double> x) ;
	~F14();
};

#endif

