 /* =====================================================================================
 *
 *       Filename:  F13.h
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
#ifndef _F13_H
#define _F13_H

#include "Benchmarks.h"

class F13:public Benchmarks{
protected:
public:
	F13(RunParameter* runParam);
	F13();
	double compute(double* x) ;
	double compute(vector<double> x) ;
	~F13();
};

#endif

