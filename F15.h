 /* =====================================================================================
 *
 *       Filename:  F15.h
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
#ifndef _F15_H
#define _F15_H

#include "Benchmarks.h"

class F15:public Benchmarks{
protected:
public:
	F15(RunParameter* runParam);
	F15();
	double compute(double* x) ;
	double compute(vector<double> x) ;
	~F15();
};

#endif
