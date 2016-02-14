//
// Created by jaszc on 19.01.2016.
//

#include <stdio.h>
#include "visual_graph.h"

visual_graph* visual_graph_init(){
    visual_graph* g = malloc(sizeof(*g));
    g->edges = linked_list_init(visual_edge_comparator);
    debug("Created vertices list \n");
    g->vertices = linked_list_init(visual_vertex_comparator);
    debug("Created edges list \n");
    g->name = string_init();
    debug("String created \n");
    return g;
}

void visual_graph_add_vertex(visual_graph* g, visual_vertex* v){
    linked_list_add(g->vertices, (void*)v);
}

void visual_graph_add_edge(visual_graph *g, visual_edge *e) {
    linked_list_add(g->edges, (void*)e);
}
