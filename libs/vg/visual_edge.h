//
// Created by jaszc on 19.01.2016.
//

#ifndef ARTEMIDA_VISUAL_EDGE_H
#define ARTEMIDA_VISUAL_EDGE_H

#include "../utils/utils.h"
#include "visual_vertex.h"

typedef struct visual_edge{
    struct visual_vertex *v1, *v2;
    int flags;
    string* name;
    Color32 color;
    void* data;
    unsigned int id;
}visual_edge;

extern visual_edge* visual_edge_init(visual_vertex* v1, visual_vertex* v2, Color32 color, void* data, int flags, string* name);

extern int visual_edge_comparator(void* a, void* b);

extern int visual_edge_equals(visual_edge* a, visual_edge *b);


#endif //ARTEMIDA_VISUAL_EDGE_H
