 /* =====================================================================================
 *
 *       Filename:  F7.h
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

#ifndef _F7_H
#define _F7_H

#include "Benchmarks.h"

class F7:public Benchmarks{
protected:
public:
	F7(RunParameter* runParam);
	F7();
	double compute(double* x) ;
	double compute(vector<double> x) ;
	~F7();
};

#endif
