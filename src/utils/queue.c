//
// Created by jaszc on 14.02.2016.
//

#include <windef.h>
#include <stdlib.h>
#include "queue.h"
#include "utils.h"


queue *queue_init(unsigned int max_size) {
    if(max_size <= 0)return NULL;
    queue* q = malloc(sizeof*(q));
    q->first_index = 0;
    q->last_index = 0;
    q->max_size = max_size;
    q->tab = malloc(sizeof(*q->tab)*max_size);
    return q;
}

void queue_push(queue *q, void *element) {
    if(q->last_index == q->max_size)q->last_index = 0;
    q->tab[q->last_index] = element;
    q->last_index++;
}

void *queue_peek(queue *q) {
    return q->tab[q->first_index];
}

void queue_pop(queue *q) {
    q->first_index++;
}


int queue_is_empty(queue *q) {
    if(q->first_index == q->last_index)return 1;
    debug(int_to_string(q->first_index));
    debug(" q ");
    debug(int_to_string(q->last_index));
    debug("\n");
    return 0;
}

void queue_dispose(queue *q) {
    free(q->tab);
    free(q);
}

void queue_sort(queue *q, int (*comparator)(void *, void *)) {
    int swap = 1;
    while(swap == 1){
        swap = 0;
        for(int i = q->first_index;i != q->last_index;i++){
            if(i == q->max_size)i = 0;
            debug(int_to_string(i));
            if(q->last_index != i+1){
                if(comparator(q->tab[i], q->tab[i+1])){
                    void* tmp;
                    tmp = q->tab[i];
                    q->tab[i] = q->tab[i+1];
                    q->tab[i+1] = tmp;
                    swap = 1;
                }
            }

        }
    }
}
