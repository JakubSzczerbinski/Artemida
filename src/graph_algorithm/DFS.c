//
// Created by mrnobody on 11.02.16.
//

#include "DFS.h"
#include "graph_changes.h"

typedef struct DFS_data{
    int* visited;
    linked_list* changes;
}DFS_data;

void DFS_execute(graph* g, unsigned int starting_v, DFS_data* d);

linked_list* DFS(graph* g, unsigned int starting_v){
    DFS_data* d = malloc(sizeof(*d));
    d->changes = linked_list_init(default_comparator);
    d->visited = malloc(sizeof(int)*(g->number_of_vertices+1));
    for(int i = 1;i <= g->number_of_vertices;i++){
        d->visited[i] = 0;
    }
    DFS_execute(g, starting_v, d);
    return d->changes;
}

void DFS_execute(graph* g, unsigned int starting_v, DFS_data* d){
    linked_list* nl = g->neighbourhood_list[starting_v];
    d->visited[starting_v] = 1;
    graph_change* gc1 = malloc(sizeof(*gc1));
    gc1->action = SET_VERTEX_COLOR;
    gc1->id = starting_v;
    gc1->color = make_Color32(0, 255, 0, 255);
    printf("DFS v%d\n", gc1->id);
    linked_list_add(d->changes, gc1);
    for(node* i = nl->first;i != NULL;i = i->next){
        neighbour* n = i->element;
        printf("XD%d\n", n->neghbour_id);
        if(d->visited[n->neghbour_id] == 0) {
            graph_change* gc2 = malloc(sizeof(*gc2));
            gc2->action = SET_EDGE_COLOR;
            gc2->id = (starting_v > n->neghbour_id ? (n->neghbour_id<<16) + starting_v :  (starting_v<<16) + n->neghbour_id);
            gc2->color = make_Color32(0, 255, 0, 255);
            linked_list_add(d->changes, gc2);
            DFS_execute(g, n->neghbour_id, d);
        }
    }

}