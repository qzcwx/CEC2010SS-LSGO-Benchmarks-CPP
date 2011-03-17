 /* =====================================================================================
 *
 *       Filename:  F10.h
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
#ifndef _F10_H
#define _F10_H

#include "Benchmarks.h"

class F10:public Benchmarks{
protected:
public:
	F10(RunParameter* runParam);
	F10();
	double compute(double* x) ;
	double compute(vector<double> x) ;
	~F10();
};

#endif
