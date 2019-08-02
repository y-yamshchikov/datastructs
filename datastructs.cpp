#include <iostream>

typedef struct _stack
{
	int maxsize;
	size_t size;
	int *storage;
} stack;

void stack_init(stack *s, int *start, size_t size);
int push(stack *s, int elem);
int pop(stack *s, int *elem);
void error(char *msg);

int STORAGE[256000];

int main(int argc, char *argv[])
{
	stack s;
	stack_init(&s, STORAGE, 5);

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
	return 0;
}

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
