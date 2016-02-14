//
// Created by jaszc on 08.02.2016.
//

#ifndef ARTEMIDA_VECTOR_H
#define ARTEMIDA_VECTOR_H

#endif //ARTEMIDA_VECTOR_H

typedef struct vector{
    void** elements;
    int size, maxsize;
}vector;

vector* vector_init();

void vector_add_element(vector* v,  void* element);

void* vector_get_by_id(vector* v, int id);

