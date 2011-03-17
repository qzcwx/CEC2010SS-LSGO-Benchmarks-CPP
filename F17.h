 /* =====================================================================================
 *
 *       Filename:  F17.h  
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
#ifndef _F17_H
#define _F17_H

#include "Benchmarks.h"

class F17:public Benchmarks{
protected:
public:
	F17(RunParameter* runParam);
	F17();
	double compute(double* x) ;
	double compute(vector<double> x) ;
	~F17();
};

#endif

