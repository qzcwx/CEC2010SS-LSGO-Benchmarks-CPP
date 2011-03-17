 /* =====================================================================================
 *
 *       Filename:  F3.h
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

#ifndef _F3_H
#define _F3_H

#include "Benchmarks.h"


class F3:public Benchmarks{
protected:

public:
	F3(RunParameter* runParam);
	F3();
	double compute(double* x) ;
	double compute(vector<double> x) ;
	~F3();
};
#endif
