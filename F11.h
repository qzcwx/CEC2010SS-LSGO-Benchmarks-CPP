 /* =====================================================================================
 *
 *       Filename:  F11.h
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
#ifndef _F11_H
#define _F11_H

#include "Benchmarks.h"

class F11:public Benchmarks{
protected:
public:
	F11(RunParameter* runParam);
	F11();
	double compute(double* x) ;
	double compute(vector<double> x) ;
	~F11();
};

#endif
