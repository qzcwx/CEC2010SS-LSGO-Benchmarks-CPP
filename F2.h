 /* =====================================================================================
 *
 *       Filename:  F2.h
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

#ifndef _F2_H
#define _F2_H

#include "Benchmarks.h"


class F2:public Benchmarks{
protected:

public:
	F2(RunParameter* runParam);
	F2();
	double compute(double* x) ;
	double compute(vector<double> x) ;
	~F2();
};
#endif
