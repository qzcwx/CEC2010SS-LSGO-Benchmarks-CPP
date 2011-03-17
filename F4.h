 /* =====================================================================================
 *
 *       Filename:  F4.h
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
#ifndef _F4_H
#define _F4_H

#include "Benchmarks.h"

class F4:public Benchmarks{
protected:
public:
	F4(RunParameter* runParam);
	F4();
	double compute(double* x) ;
	double compute(vector<double> x) ;
	~F4();
};

#endif
