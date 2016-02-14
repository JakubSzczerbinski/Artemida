//
// Created by jaszc on 28.01.2016.
//

#ifndef ARTEMIDA_GRAPH_H
#define ARTEMIDA_GRAPH_H

#include <stdlib.h>
#include <stdio.h>
#include "../utils/linked_list.h"

typedef struct graph{
    linked_list** neighbourhood_list;
    int number_of_vertices;
    int number_of_edges;
}graph;

typedef struct neighbour{
    int neghbour_id;
    int weight;
}neighbour;

extern graph* graph_init();

extern void graph_deserialize(graph* g, FILE* f);

extern void graph_serialize(graph* g, FILE* f);

extern neighbour* neighbour_init(int id, int weight);




#endif //ARTEMIDA_GRAPH_H
