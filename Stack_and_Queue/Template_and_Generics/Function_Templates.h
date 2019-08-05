#ifndef FUNCTIONS_TEMPLATES_H
#define FUNCTIONS_TEMPLATES_H

	#include <ctype.h>

	template<typename Type>
	int compare(const Type& v1, const Type& v2)
	{
		if (v1 < v2)
			return (-1);
		if (v2 < v1)
			return 1;
		return 0;
	}

	template<typename A, typename B>
	int compare(const A& v1, const B& v2)
	{
		if (v1 < v2)
			return (-1);
		if (v2 < v1)
			return 1;
		return 0;
	}

	template<typename T>
	inline T min(const T& v1, const T& v2)
	{
		if (v1 < v2)
			return v1;
		else
			return v2;
	}

	template<class T, size_t N>
	void array_init(T (&parm)[N])
	{
		for (size_t i = 0; i != N; ++i)
		{
			parm[i] = 0;
		}
	}

	template<typename T> T fobj(T obja, T objb)		/* arguments are copied */
	{
		return (obja);
	}

	template<typename T> T fref(const T& refa, const T& refb)		/* reference arguments */
	{
		return (refa + refb);
	}

	template<class Type>
	Type sum(const Type& op1, int op2)
	{
		return op1 + op2;
	}

#endif	/* FUNCTIONS_TEMPLATES_H */
