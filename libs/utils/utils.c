//
// Created by jaszc on 11.01.2016.
//

#include <stdio.h>
#include <math.h>
#include "utils.h"

string* string_init(){
    string* s = malloc(sizeof(string));
    s->size = 0;
    s->tab = NULL;
    return s;
}

Color32 make_Color32(unsigned int r, unsigned int g, unsigned int b, unsigned int a){
    Color32 color;
    color.r = r;
    color.g = g;
    color.b = b;
    color.a = a;
    return color;
}

vector_2d make_vector_2d(float x, float y){
    vector_2d vec2;
    vec2.x = x;
    vec2.y = y;
    return vec2;
}

void debug(char* cstr){
    printf(cstr);
    fflush(stdout);
}

vector_2d add_vector(vector_2d a, vector_2d b) {
    vector_2d result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    return result;
}

vector_2d subtract_vector(vector_2d a, vector_2d b) {
    vector_2d result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    return result;
}

float calculate_distance(vector_2d a, vector_2d b) {
    float result = (float)sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
    return result;
}

vector_2d normalize(vector_2d a) {
    float scale = 1/calculate_distance(make_vector_2d(0, 0), a);
    vector_2d result = make_vector_2d(scale * a.x, scale * a.y);
    return result;
}

vector_2d multiply_vector(vector_2d a, float factor) {
    vector_2d result;
    result.x = a.x*factor;
    result.y = a.y*factor;
    return result;
}

void debug_vector2d(vector_2d a, char* cstr) {
    printf(cstr);
    printf(" vector is equal to (%f,%f)\n" , a.x, a.y);
}
