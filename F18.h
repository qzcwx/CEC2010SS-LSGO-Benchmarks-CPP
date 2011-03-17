 /* =====================================================================================
 *
 *       Filename:  F18.h  
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
#ifndef _F18_H
#define _F18_H

#include "Benchmarks.h"

class F18:public Benchmarks{
protected:
public:
	F18(RunParameter* runParam);
	F18();
	double compute(double* x) ;
	double compute(vector<double> x) ;
	~F18();
};

#endif

