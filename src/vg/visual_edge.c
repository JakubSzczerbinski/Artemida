//
// Created by jaszc on 19.01.2016.
//

#include "visual_edge.h"
#include "visual_vertex.h"
#include "../utils/utils.h"

visual_edge* visual_edge_init(visual_vertex* v1, visual_vertex* v2, Color32 color, void* data, int flags, string* name){
    visual_edge* e = malloc(sizeof(*e));
    e->v1 = v1;
    e->v2 = v2;
    e->color = color;
    e->data = data;
    e->flags = flags;
    e->name = name;
    static unsigned int id = 1;
    e->id = (v1->id<<16) + v2->id;
    id++;
    return e;
}

int visual_edge_comparator(void *a, void *b) {
    return visual_edge_equals((visual_edge*) a, (visual_edge*) b);
}

int visual_edge_equals(visual_edge *a, visual_edge *b) {
    return a->id == b->id;
}
