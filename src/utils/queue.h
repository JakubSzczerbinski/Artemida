//
// Created by jaszc on 14.02.2016.
//

#ifndef ARTEMIDA_QUEUE_H
#define ARTEMIDA_QUEUE_H

typedef struct queue{
    void** tab;
    int max_size;
    int first_index;
    int last_index;
}queue;

queue* queue_init(unsigned int max_size);

void queue_push(queue* q,void* element);

void* queue_peek(queue* q);

void queue_pop(queue* q);

int queue_is_empty(queue *q);

void queue_dispose(queue *q);

void queue_sort(queue *q, int (*comparator)(void*, void*));

#endif //ARTEMIDA_QUEUE_H
