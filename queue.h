#include <stddef.h>

typedef struct _queue
{
	int *storage;
	int *head;
	int *tail;
	size_t size;
	size_t maxsize;
} queue;

void queue_init(queue *q, int *storage, size_t size);
int queue_push(queue *q, int elem);
int queue_pop(queue *q, int *elem);
size_t queue_size(queue *q);
int queue_elem(queue *q, int *elem);
