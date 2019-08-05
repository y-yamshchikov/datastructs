#include "queue.h"

void queue_init(queue *q, int *storage, size_t size)
{
	q->storage = storage;
	q->maxsize = size;
	q->size = 0;
	q->head = storage;
	q->tail = storage;
}

int queue_push(queue *q, int elem)
{
	if (q->maxsize == q->size)
	{
		return 1;
	}

	if (q->head == q->storage + q->maxsize)
	{
		q->head = q->storage;
	}

	*(q->head) = elem;
	q->head++;
	q->size++;
	return 0;
}

int queue_pop(queue *q, int *elem)
{
	if (q->size == 0)
	{
		return 1;
	}

	*elem = *(q->tail);
	q->tail++;

	if (q->tail == q->storage + q->maxsize)
	{
		q->tail = q->storage;
	}
	q->size--;
	return 0;
}

size_t queue_size(queue *q)
{
	return q->size;
}

int queue_elem(queue *q, int *elem)
{
	if(q->size == 0)
	{
		return 1;
	}
	
	*elem = *(q->head);

	return 0;
}
