 /* =====================================================================================
 *
 *       Filename:  F19.h  
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
#ifndef _F19_H
#define _F19_H

#include "Benchmarks.h"

class F19:public Benchmarks{
protected:
public:
	F19(RunParameter* runParam);
	F19();
	double compute(double* x) ;
	double compute(vector<double> x) ;
	~F19();
};

#endif


