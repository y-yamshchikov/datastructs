#include <iostream>
#include "queue.h"
#include "stack.h"

int STORAGE[256000];

void stack_test(void);
void queue_test(void);

int main(int argc, char *argv[])
{
	stack_test();
	queue_test();

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

void queue_test(void)
{
	queue q;
	queue_init(&q, STORAGE, 5);

	queue_push(&q, 1);
	queue_push(&q, 2);
	queue_push(&q, 3);
	queue_push(&q, 4);
	queue_push(&q, 5);

	int a;
	queue_pop(&q, &a);
	std::cout<<a<<" ";
	queue_pop(&q, &a);
	std::cout<<a<<" ";
	queue_pop(&q, &a);
	std::cout<<a<<" ";
	queue_pop(&q, &a);
	std::cout<<a<<" ";
	queue_pop(&q, &a);
	std::cout<<a<<" ";
	queue_pop(&q, &a);
	std::cout<<a<<" ";

	std::cout<<std::endl;
}
