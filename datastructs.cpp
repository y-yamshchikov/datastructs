#include <iostream>
#include "stack.h"

int STORAGE[256000];

int main(int argc, char *argv[])
{
	stack_test();
	return 0;
}

void stack_test(void)
{
	stack s;
	stack_init(&s, STORAGE+1000, 5);

	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	push(&s, 4);
	push(&s, 5);

	int a;
	pop(&s, &a);
	std::cout<<a<<" ";
	pop(&s, &a);
	std::cout<<a<<" ";
	pop(&s, &a);
	std::cout<<a<<" ";
	pop(&s, &a);
	std::cout<<a<<" ";
	pop(&s, &a);
	std::cout<<a<<" ";
	pop(&s, &a);
	std::cout<<a<<" ";

	std::cout<<std::endl;
}
