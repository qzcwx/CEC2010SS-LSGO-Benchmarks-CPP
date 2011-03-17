 /* =====================================================================================
 *
 *       Filename:  F8.h
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
#ifndef _F8_H
#define _F8_H

#include "Benchmarks.h"

class F8:public Benchmarks{
protected:
public:
	F8(RunParameter* runParam);
	F8();
	double compute(double* x) ;
	double compute(vector<double> x) ;
	~F8();
};

#endif
