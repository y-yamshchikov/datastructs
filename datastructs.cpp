#include <iostream>
#include <vector>
#include <random>
#include <functional>
#include "queue.h"
#include "queue_test.h"
#include "stack.h"

int STORAGE[256000];

void stack_test(void);

int main(int argc, char *argv[])
{
	unsigned int seed = 100;
	unsigned int N = 1;
	if (argc > 1)
	{
		seed = atoi(argv[1]);
		if (argc > 2)
		{
			N = atoi(argv[2]);
		}
	}


	stack_test();
	queue_test(seed, N);

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

