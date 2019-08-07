#include <iostream>
#include <vector>
#include <random>
#include <functional>
#include "queue.h"
#include "queue_test.h"
#include "stack.h"

int STORAGE[256000];

void stack_test(void);

typedef struct _list_elem list_elem;
struct _list_elem
{
	int key;
	int value;
	list_elem *next;
};

void lists_init(list_elem* &holder, void *storage, size_t size);
int list_add(list_elem* &holder, list_elem* &list, int key, int value);
size_t list_size(const list_elem* list);
void list_print(const list_elem *holder);
int list_remove(list_elem* &list, list_elem* &holder, int key);
list_elem *list_find(const list_elem* list, int key);
void list_destroy(list_elem* &list, list_elem* &holder);

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

	list_elem *holder = nullptr;
	lists_init(holder, (void*)STORAGE, 10);

	list_elem *my_list = nullptr; //new empty list
	int i = 0;
	int j = 0;
	//while (list_add(holder, my_list/*elem to store*/, i++, j++) == 0);
	list_add(holder, my_list/*elem to store*/, 1, 10);
	list_add(holder, my_list/*elem to store*/, 2, 20);
	list_add(holder, my_list/*elem to store*/, 3, 30);
	list_destroy(my_list, holder);
	//std::cout<<"value by key 1: "<<list_find(my_list, 1)->value<<std::endl;
	//std::cout<<"value by key 2: "<<list_find(my_list, 2)->value<<std::endl;
	std::cout<<"list size = "<<list_size(my_list)<<std::endl;
	list_print(my_list);
	list_remove(my_list, holder, 2);
	list_print(my_list);
	std::cout<<"holder size = " << list_size(holder)<<std::endl;
	list_remove(my_list, holder, 1);
	std::cout<<"holder size = " << list_size(holder)<<std::endl;

	stack_test();
	queue_test(seed, N);

	return 0;
}

void lists_init(list_elem* &holder, void *storage, size_t size)
{
	list_elem *s = (list_elem*)storage;

	for (int i = 0; i < size-1; ++i)
	{
		s[i].next = &s[i+1];
	}

	s[size-1].next = nullptr;

	holder = &s[0];
}

void list_destroy(list_elem* &list, list_elem* &holder)
{
	if (list == nullptr)
	{
		return;
	}

	list_elem *l = list;
	for (; l->next; l = l->next); //fast-forward

	l->next = holder;
	holder = l;
	list = nullptr;
}

int list_add(list_elem* &holder, list_elem* &list, int key, int value)
{
	if (holder == nullptr)
	{
		return 1;
	}

	list_elem *new_elem = holder;
	holder = holder->next;

	new_elem->next = nullptr;
	new_elem->key = key;
	new_elem->value = value;

	if (list == nullptr)
	{
		list = new_elem;
	}
	else
	{
		list_elem *l = nullptr;
		for (l = list; l->next; l = l->next); //fast-forward the list

		l->next = new_elem;
	}

	return 0;
}

list_elem *list_find(const list_elem* list, int key)
{
	for (const list_elem *l = list; l; l = l->next)
	{
		if (l->key == key)
		{
			return const_cast<list_elem*>(l);
		}
	}

	return nullptr;
}

int list_remove(list_elem* &list, list_elem* &holder, int key)
{
	list_elem before_begin;
	before_begin.next = list;

	for (list_elem *l = &before_begin, *r = list; r; l = r, r = r->next)
	{
		if (r->key == key)
		{
			l->next = r->next;
			r->next = holder;
			holder = r;
			list = before_begin.next;
			return 0;
		}
	}

	return 1;

}

//list_elem *list_find()

size_t list_size(const list_elem* list)
{
	if (list == nullptr)
	{
		return 0;
	}

	size_t i = 1;
	for(; list->next; list = list->next)
	{
		i++;
	}

	return i;
}

void list_print(const list_elem *holder)
{
	for (; holder; holder = holder->next)
	{
		std::cout<<"{"<<holder->key<<","<<holder->value<<"}, ";
	}
	std::cout<<std::endl;
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

