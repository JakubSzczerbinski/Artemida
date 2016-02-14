//
// Created by mrnobody on 11.02.16.
//

#include "DFS.h"
#include "graph_changes.h"

typedef struct DFS_data{
    int* visited;
    linked_list* changes;
}DFS_data;

void DFS_execute(graph* g, int starting_v, DFS_data* d);

linked_list* DFS(graph* g, int starting_v){
    DFS_data* d = malloc(sizeof(*d));
    d->changes = linked_list_init(default_comparator);
    d->visited = malloc(sizeof(int)*(g->number_of_vertices+1));
    DFS_execute(g, starting_v, d);
    return d->changes;
}

void DFS_execute(graph* g, int starting_v, DFS_data* d){
    if(d->visited[starting_v] == 1) return;
    linked_list* nl = g->neighbourhood_list[starting_v];
    d->visited[starting_v] = 1;
    graph_change* gc = malloc(sizeof(*gc));
    gc->action = SET_VERTEX_COLOR;
    gc->id = starting_v;
    gc->color = make_Color32(0, 255, 0, 255);
    printf("DFS v%d\n", gc->id);
    linked_list_add(d->changes, gc);
    for(node* i = nl->first;i != NULL;i = i->next){
        neighbour* n = i->element;
        DFS_execute(g, n->neghbour_id, d);
    }

}