//
// Created by jaszc on 11.01.2016.
//

#ifndef ARTEMIDA_UTILS_H
#define ARTEMIDA_UTILS_H

#include <stdlib.h>

typedef struct string{
    char* tab;
    int size;
}string;

extern string* string_init();

typedef struct vector_2d{
    float x;
    float y;
}vector_2d;

extern vector_2d make_vector_2d(float x, float y);

extern vector_2d add_vector(vector_2d a, vector_2d b);

extern vector_2d subtract_vector(vector_2d a, vector_2d b);

extern float calculate_distance(vector_2d a, vector_2d b);

extern vector_2d normalize(vector_2d a);

extern vector_2d multiply_vector(vector_2d a, float factor);

extern void debug_vector2d(vector_2d a, char* cstr);

typedef struct transform_2d{
    vector_2d position;
    float rotation;
    float scale;
}transform_2d;

typedef struct Color32{
    union{
        unsigned int rgba : 32;
        struct{
            unsigned int r : 8;
            unsigned int g : 8;
            unsigned int b : 8;
            unsigned int a : 8;
        };
    };
}Color32;

extern Color32 make_Color32(unsigned int r, unsigned int g, unsigned int b, unsigned int a);

extern void debug(char* cstr);

#endif //ARTEMIDA_UTILS_H
