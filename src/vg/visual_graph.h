//
// Created by jaszc on 19.01.2016.
//

#ifndef ARTEMIDA_VISUAL_GRAPH_H
#define ARTEMIDA_VISUAL_GRAPH_H
#include "../utils/linked_list.h"
#include "../utils/utils.h"
#include "visual_vertex.h"
#include "visual_edge.h"

typedef struct visual_graph{
    linked_list* vertices;
    linked_list* edges;
    string* name;
    int flags;
}visual_graph;

extern visual_graph* visual_graph_init();

extern void visual_graph_add_vertex(visual_graph* g, visual_vertex* v);

extern void visual_graph_add_edge(visual_graph* g, visual_edge* e);

#endif //ARTEMIDA_VISUAL_GRAPH_H
