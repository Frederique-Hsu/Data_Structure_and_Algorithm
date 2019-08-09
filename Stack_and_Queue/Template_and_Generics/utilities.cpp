#include "utilities.h"
#include "Class_Templates.h"

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
}