//
// Created by jaszc on 28.01.2016.
//

#include "graph.h"
#include "../utils/utils.h"

graph *graph_init() {
    graph* g = malloc(sizeof(*g));
    g->neighbourhood_list = NULL;
    g->number_of_edges = 0;
    g->number_of_vertices = 0;
    debug("Graph created \n");
    return g;
}

void graph_deserialize(graph* g, FILE *f) {
    unsigned int buffer;
    fread(&buffer, 1, sizeof(int), f);
    g->number_of_vertices = buffer;
    g->neighbourhood_list = malloc((g->number_of_vertices + 1)*sizeof(*g->neighbourhood_list));
    fread(&buffer, 1, sizeof(int), f);
    g->number_of_edges = buffer;
    for(int i = 1;i <= g->number_of_vertices;i++){
        fread(&buffer, 1, sizeof(int), f);
        unsigned int number_of_neighbours = buffer;
        g->neighbourhood_list[i] = linked_list_init(default_comparator);
        for(int j = 0;j < number_of_neighbours;j++){
            fread(&buffer, 1, sizeof(int), f);
            unsigned int vertex = buffer;
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

graph* graph_create(){
    graph *g = graph_init();
    printf("Number of vertices :\n");
    unsigned int a;
    scanf("%u", &a);
    g->number_of_vertices = a;
    g->neighbourhood_list = malloc(sizeof(*g->neighbourhood_list)*(g->number_of_vertices+1));
    printf("Number of edges :\n");
    scanf("%u", &a);
    g->number_of_edges = a;
    char b;
    printf("Does your graph need weights ?(Y/N, deufalt=N)\n");
    getchar();
    scanf("%c", &b);
    if(b == 'Y' || b == 'y'){
        printf("Type vertex index and edge weights\nEnd list of neighbours with 0 (Vertices are indexed from 1)\n");
        for(int i = 1;i <= g->number_of_vertices;i++){
            g->neighbourhood_list[i] = linked_list_init(default_comparator);
            printf("%d : ", i);
            while(1) {
                int c;
                scanf("%u %d", &a, &c);
                if(a == 0)break;
                neighbour *n = malloc(sizeof(*n));
                n->neghbour_id = a;
                n->weight = c;
                linked_list_add(g->neighbourhood_list[i], n);
            }
        }
    }
    else{
        printf("Type vertex index\nEnd list of neighbours with 0 (Vertices are indexed from 1)\n");
        for(int i = 1;i <= g->number_of_vertices;i++){
            g->neighbourhood_list[i] = linked_list_init(default_comparator);
            printf("%d : ", i);
            while(1) {
                scanf("%u", &a);
                if(a == 0)break;
                neighbour *n = malloc(sizeof(*n));
                n->neghbour_id = a;
                n->weight = 1;
                linked_list_add(g->neighbourhood_list[i], n);
            }
        }
    }
    return g;
}

void graph_dispose(graph* g) {
    if(g == NULL)return;
    for(int i = 1;i <= g->number_of_vertices;i++) {
        linked_list_dispose(g->neighbourhood_list[i]);
    }
    free(g->neighbourhood_list);
    free(g);
}
