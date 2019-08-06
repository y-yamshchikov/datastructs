#ifndef STACK_H
#define STACK_H
#include <stddef.h>

typedef struct _stack
{
	int maxsize;
	size_t size;
	int *storage;
} stack;

void stack_init(stack *s, int *start, size_t size);
int push(stack *s, int elem);
int pop(stack *s, int *elem);
#endif
