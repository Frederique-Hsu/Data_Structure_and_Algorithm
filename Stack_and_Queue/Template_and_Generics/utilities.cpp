#include "utilities.h"
#include "Class_Templates.h"

#include <vector>

void instantiate_class_templates(void)
{
	Queue<int> qi;
	short s = 42;
	int i = 56;
	qi.push(s);
	qi.push(i);
	qi.showQueue();

	qi.push(-5);
	qi.push(0xFF);
	qi.showQueue();

	qi.pop();
	qi.showQueue();
	qi.push(0xA0A0);
	qi.showQueue();

    qi.push(1314);
	std::cout << qi;
}

void instantiate_access_member_template(void)
{
	short a[] = { 0, 3, 6, 9, 15, -10, 8, 30, 50, -200 };
	Queue<int> qi(a, a + 5);
	std::vector<int> vi(a, a + 8);

	qi.showQueue();
	std::cout << qi << std::endl;

	qi.assign(vi.begin(), vi.end());
	std::cout << qi << std::endl;
}