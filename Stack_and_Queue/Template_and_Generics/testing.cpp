#include "testing.h"
#include "Function_Templates.h"
#include "Class_Templates.h"
#include "utilities.h"

#include <string>
using namespace std;

void execute_test_cases(void)
{
	instantiate_class_templates();
}





void execute_array_init(void)
{
	int x[42];
	double y[10];
	array_init(x);		/* instantiates array_init(int(&)[42]) */
	array_init(y);		/* instantiates array_init(double(&)[10]) */

	const int sz = 40;
	int z[sz + 2];
	array_init(z);		/* instantiates array_init(int(&)[42]), equaivalent instantiation to array_init(x) */
}

void execute_compare(void)
{
	compare(1, 0);			/* OK : binds template parameter to int */
	compare(3.14, 2.7);		/* OK : binds template parameter to double */

	short si;
	compare(si, 1024);		/* OK : binds compare(short, int) */
}

void cast_typename_arguments(void)
{
	string s1("a value");
	const string s2("another value");
	fobj(s1, s2);		/* OK : calls fobj(string, string), const is ignored */
	fref(s1, s2);		/* OK : non const object s1 converted to const reference */

	int a[10], b[42];
	fobj(a, b);			/* OK : calls fobj(int*, int*) */
	// fref(a, b);			/* Error : array type doesn't match; arguments aren't converted to pointers. */

	double d = 3.14;
	sum(1024, d);		/* OK : instantiates sum(int, int), convert d to int */
	sum(1.4, d);		/* OK : instantiates sum(double, int), convert d to int */
	// sum(s1, s2);		/* Error : s2 cannot be converted to int */

	/* pfcompare points to the instantiation int compare(const int&, const int&) */
	int (*pfcompare)(const int&, const int&) = compare;
	// func(compare);		/* cannot determine which instance of overloaded function "compare" is intended */
    func(compare<int>);		/* OK : explicitly specify which version of compare */
}

void explicit_template_arguments(void)
{
	int i = 5;
	long lng = 128L;
	long result = alternative_sum<long, int, long>(i, lng);		/* OK : all three parameters are explicitly specified. */
}
