#include <iostream>
#include <vector>
#include <random>
#include <functional>
#include "queue.h"
#include "queue_test.h"

static int STORAGE[256000];

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

	int number_of_shocks = dice();
	std::cout << "Test begins. Number of shocks = "<< number_of_shocks <<std::endl;

	for (size_t i = 0; i < number_of_shocks; i++)
	{
		//TODO coverage counters
		size_t dist[] = {1,1,1,1,0,0,5,2,0,0,0,100};
		size_t sd = sizeof(dist)/sizeof(dist[0]);
		size_t f = dist[dice()%sd];
		int elem = -1;
		int number = -1;

		for (size_t j = 0; j < f; ++j)
		{
			number = dice();
			if (queue_push(&q, number) == 0)
			{
				in.push_back(number);
			}
			else
			{
				elem = -1;
				if (queue_pop(&q, &elem) == 0)
				{
					out.push_back(elem);
				}
				else
				{
					if (queue_isfull(&q))
					{
						std::cerr<<"cant't pop from full queue, inconsistence"<<std::endl;
						return 1;
					}
					std::cerr<<"can't pop as well as push to the queue, inconsistence"<<std::endl;
					return 1;
				}
			}
		}


		elem = -1;
		f = dist[dice()%sd];
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
