//
// Created by jaszc on 14.02.2016.
//

#include "BFS.h"
#include "../utils/queue.h"
#include "graph_changes.h"

typedef struct BFS_data{
    int* visited;
    linked_list* changes;
    queue *q;
}BFS_data;

typedef struct v_pair{
    unsigned int source;
    unsigned int destination;
}v_pair;

linked_list *BFS(graph *g, int starting_v) {
    BFS_data* d = malloc(sizeof(*d));
    d->changes = linked_list_init(default_comparator);
    d->visited = malloc(sizeof(int)*(g->number_of_vertices+1));
    d->q = queue_init(g->number_of_edges);
    for(int i = 1;i <= g->number_of_vertices;i++){
        d->visited[i] = 0;
    }
    BFS_execute(g, starting_v,  d);
    return d->changes;
}

void BFS_execute(graph* g, int starting_v, BFS_data* d){
    linked_list* nl = g->neighbourhood_list[starting_v];
    d->visited[starting_v] = 1;
    unsigned int src = starting_v;
    while(nl != NULL){
        for(node* i = nl->first;i != NULL;i = i->next){
            neighbour* n = i->element;
            if(d->visited[n->neghbour_id] == 0){
                d->visited[n->neghbour_id] = 1;
                v_pair *vp = malloc(sizeof(*vp));
                vp->destination = n->neghbour_id;
                vp->source = src;
                queue_push(d->q, vp);
            }
        }
        if(!queue_is_empty(d->q)){
            v_pair *vpc = queue_peek(d->q);
            nl = g->neighbourhood_list[vpc->destination];
            src = vpc->destination;
            graph_change* gc
        }
    }

}
