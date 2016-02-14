//
// Created by jaszc on 28.01.2016.
//

#include "graph.h"

graph *graph_init() {
    graph* g = malloc(sizeof(*g));
    g->neighbourhood_list = NULL;
    g->number_of_edges = 0;
    g->number_of_vertices = 0;
    return g;
}

void graph_deserialize(graph* g, FILE *f) {
    int buffer;
    fread(&buffer, 1, sizeof(int), f);
    g->number_of_vertices = buffer;
    g->neighbourhood_list = malloc((g->number_of_vertices + 1)*sizeof(*g->neighbourhood_list));
    fread(&buffer, 1, sizeof(int), f);
    g->number_of_edges = buffer;
    for(int i = 1;i <= g->number_of_vertices;i++){
        fread(&buffer, 1, sizeof(int), f);
        int number_of_neighbours = buffer;
        g->neighbourhood_list[i] = linked_list_init(default_comparator);
        for(int j = 0;j < number_of_neighbours;j++){
            fread(&buffer, 1, sizeof(int), f);
            int vertex = buffer;
            fread(&buffer, 1, sizeof(int), f);
            int weight = buffer;
            neighbour* n = malloc(sizeof(*n));
            n->neghbour_id = vertex;
            n->weight = weight;
            linked_list_add(g->neighbourhood_list[i], (void*)n);
        }
    }

}

void graph_serialize(graph* g, FILE *f) {
    int buffer;
    buffer = g->number_of_vertices;
    fwrite(&buffer, 1, sizeof(int), f);
    buffer = g->number_of_edges;
    fwrite(&buffer, 1, sizeof(int), f);
    for(int i = 1;i <= g->number_of_vertices;i++){
        buffer = g->neighbourhood_list[i]->size;
        fwrite(&buffer, 1, sizeof(int), f);
        for(node* j = g->neighbourhood_list[i]->first;j != NULL;j = j->next){
            neighbour *n = j->element;
            buffer = n->neghbour_id;
            fwrite(&buffer, 1, sizeof(int), f);
            buffer = n->weight;
            fwrite(&buffer, 1, sizeof(int), f);
        }
    }
}

neighbour *neighbour_init(int id, int weight) {
    neighbour* n = malloc(sizeof(*n));
    n->neghbour_id = id;
    n->weight = weight;
    return n;
}
