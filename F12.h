 /* =====================================================================================
 *
 *       Filename:  F12.h
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
#ifndef _F12_H
#define _F12_H

#include "Benchmarks.h"

class F12:public Benchmarks{
protected:
public:
	F12(RunParameter* runParam);
	F12();
	double compute(double* x) ;
	double compute(vector<double> x) ;
	~F12();
};

#endif
