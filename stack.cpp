#include <iostream>
#include "stack.h"
void stack_init(stack *s, int *start, size_t size)
{
	s->storage = start;
	s->size = 0;
	s->maxsize = size;
}

int push(stack *s, int elem)
{
	if (s->size == s->maxsize)
	{
		return 1;
	}
	s->storage[s->size++] = elem;

	return 0;
}

int pop(stack *s, int *elem)
{
	if (s->size == 0)
	{
		return 1;
	}

	*elem = s->storage[--s->size];
	return 0;
}

void error(char *msg)
{
	std::cout<<msg<<std::endl;
	exit(1);
}
