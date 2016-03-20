/*****************************************************************************
 * File name	: function_object.h
 * Description	: Investigate the usage of function object.
 * Creator		: Frederick Hsu
 * Creation date: Monday,	14 March, 2016
 * Copyright(C)	2016	All rights reserved.
 *
 *****************************************************************************/


#ifndef FUNCTION_OBJECT_H
#define FUNCTION_OBJECT_H

 	class classf
 	{
 	private:
 	public:
 		classf(void);
 		double operator()(double x);
 	};

 	double sum2(classf cf, int n, int m);

 	class classf2
 	{
 	private:
 	public:
 		classf2(void);
 		double run(double x);
 	protected:
 	};

 	double sum3(classf2 obj, int n, int m);
 	
 	template<class F>
 	double sum(F f, int n, int m)
 	{
 	    double result = 0;
 	    for (int i = n; i <= m; i++)
 	    {
 	        result += f(i);
 	    }
 	    return result;
 	}
 	
#if 0
 	template<class T>
 	struct negate::public unary_function<T, T>
 	{
 	    T operator()(const T& x) const
 	    {
 	        return -x;
 	    }
 	};
#endif
 	
#endif	/*  FUNCTION_OBJECT_H  */