//
// Created by jaszc on 19.01.2016.
//
#include "visual_vertex.h"
#include "visual_edge.h"

visual_vertex* visual_vertex_init(int id, Color32 color, void* data, int flags, string* name, vector_2d position){
    visual_vertex* v = malloc(sizeof(*v));
    v->color = color;
    v->data = data;
    v->flags = flags;
    v->name = name;
    v->position = position;
    v->sim_data.speed = make_vector_2d(0, 0);
    v->id = id;
    return v;
}

int visual_vertex_comparator(void *a, void *b) {
    return visual_vertex_equals((visual_vertex*) a, (visual_vertex*) b);
}

int visual_vertex_equals(visual_vertex *a, visual_vertex *b) {
    return a->id == b->id;
}
