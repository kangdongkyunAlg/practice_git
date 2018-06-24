#pragma once
#include "eachTime.h"

#define MAX_QUEUE_SIZE 5

typedef struct {
	Time queue[MAX_QUEUE_SIZE];
	int front, rear;
	int count = 0;
}QueueType;

void init(QueueType *q);
int is_empty(QueueType *q);
int is_full(QueueType *q);
void enqueue(QueueType *q, Time process);
Time dequeue(QueueType *q);