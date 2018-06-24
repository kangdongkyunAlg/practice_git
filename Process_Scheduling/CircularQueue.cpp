#include "CircularQueue.h"
#include <stdlib.h>
#include <stdio.h>
void init(QueueType *q) {

	q->front = q->rear = 0;

}
int is_empty(QueueType *q) {

	return (q->front == q->rear);

}
int is_full(QueueType *q) {

	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);

}
void enqueue(QueueType *q, Time process) {

	if (is_full(q)) {

		//printf("Å¥ ¾È : [%d]\n", process.id+1);

		fprintf(stderr, " error\n");

	}

	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;

	q->queue[q->rear] = process;

}
Time dequeue(QueueType *q) {

	/**/if (is_empty(q)) {

		fprintf(stderr, "error!\n");

	}

	q->front = (q->front + 1) % MAX_QUEUE_SIZE;

	return q->queue[q->front];

}