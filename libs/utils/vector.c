//
// Created by jaszc on 08.02.2016.
//

#include <stdlib.h>
#include "vector.h"

vector *vector_init() {
    vector *v = malloc(sizeof(*v));
    v->elements = malloc(sizeof(void*));
    v->maxsize = 1;
    v->size = 0;
}

void vector_add_element(vector* v, void *element) {
    while(v->size + 1 > v->maxsize){
        v->maxsize *= 2;
        void** new_array = malloc(sizeof(void*)*v->maxsize);
        for(int i = 0;i < v->size;i++){
            new_array[i] = v->elements[i];
        }
        free(v->elements);
        v->elements = new_array;
    }
    v->elements[v->size] = element;
    v->size++;
}

void* vector_get_by_id(vector* v, int id) {
    while(id >= v->maxsize){
        v->maxsize *= 2;
        void** new_array = malloc(sizeof(void*)*v->maxsize);
        for(int i = 0;i < v->size;i++){
            new_array[i] = v->elements[i];
        }
        free(v->elements);
        v->elements = new_array;
    }
    return v->elements[id];
}
