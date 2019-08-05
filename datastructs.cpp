#include <iostream>
#include <vector>
#include <random>
#include "queue.h"
#include "stack.h"
#include <functional>

int STORAGE[256000];

void stack_test(void);
int queue_test(unsigned int seed, unsigned int n);

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

int queue_test(unsigned int seed, unsigned int n)
{
	if (n == 0)
	{
		return 0;
	}

	std::default_random_engine generator(seed);
	std::uniform_int_distribution<int> distribution(1, 999999);
	auto dice = std::bind(distribution, generator);

	queue q;
	queue_init(&q, STORAGE, 5);

	std::vector<int> in;
	std::vector<int> out;

	int test_set_size = dice();
	std::cout<<test_set_size<<std::endl;

	for (size_t i = 0; i < test_set_size; i++)
	{
		int number = dice();
		in.push_back(number);
		int elem = -1;
		if (queue_isfull(&q))
		{
			if (queue_pop(&q, &elem) == 0)
			{
				out.push_back(elem);
			}
			else
			{
				std::cerr<<"cant't pop from full queue, inconsistence"<<std::endl;
				return 1;
			}
		}
		elem = -1;
		queue_push(&q, number);
		int dist[] = {1,1,1,1,0,0,5,2,0,0,0};
		size_t sd = sizeof(dist)/sizeof(dist[0]);
		int f = dist[dice()%sd];
		for (size_t j = 0; j < f; ++j)
		{
			if (queue_pop(&q, &elem) == 0)
			{
				out.push_back(elem);
			}
		}
	}
	size_t q_size = queue_size(&q);
	for (size_t i = 0; i < q_size; ++i)
	{
		int elem = -1;
		if (queue_pop(&q, &elem) == 0)
		{
			out.push_back(elem);
		}
		else
		{
			std::cerr<<"queue size is inconsistent"<<std::endl;
			return 1;
		}
	}
	if (in.size() != out.size())
	{
		std::cerr<<"in and out sets are of different size"<<std::endl;
		std::cerr<<"in.size = "<<in.size()<<"; out.size = "<<out.size()<<std::endl;
		return 1;
	}
	size_t in_size = in.size();
	for (size_t i = 0; i < in_size; ++i)
	{
		if (in[i] != out[i])
		{
			std::cerr<<"in and out queues differ at position "<<i<<", seed = "<<seed<<std::endl;
			return 1;
		}
		if (out[i] == -1)
		{
			std::cerr<<"dumb value encountered, queue is corrupted"<<std::endl;
			return 0;
		}
	}
	std::cerr<<"queue passed the test"<<std::endl;
	return queue_test(seed-1, n-1);
}
