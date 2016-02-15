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

void BFS_execute(graph* g, int starting_v, BFS_data* d);

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
    graph_change* gc3 = malloc(sizeof(*gc3));
    gc3->action = SET_VERTEX_COLOR;
    gc3->id = starting_v;
    gc3->color = make_Color32(0, 255, 0, 255);
    linked_list_add(d->changes, gc3);
    while(nl != NULL){
        debug(int_to_string(src));
        debug("\n");
        for(node* i = nl->first;i != NULL;i = i->next){
            neighbour* n = i->element;
            if(d->visited[n->neghbour_id] == 0){
                d->visited[n->neghbour_id] = 1;
                v_pair *vp = malloc(sizeof(*vp));
                vp->destination = n->neghbour_id;
                vp->source = src;
                queue_push(d->q, vp);
                debug("c2\n");
            }
            debug("c1\n");
        }
        if(!queue_is_empty(d->q)){
            v_pair *vpc = queue_peek(d->q);
            queue_pop(d->q);
            nl = g->neighbourhood_list[vpc->destination];
            src = vpc->destination;
            graph_change* gc1 = malloc(sizeof(*gc1));
            gc1->action = SET_EDGE_COLOR;
            gc1->id = (vpc->destination > vpc->source ? (vpc->source<<16) + vpc->destination :  (vpc->destination<<16) + vpc->source);
            gc1->color = make_Color32(0, 255, 0, 255);
            linked_list_add(d->changes, gc1);
            graph_change* gc2 = malloc(sizeof(*gc2));
            gc2->action = SET_VERTEX_COLOR;
            gc2->id = vpc->destination;
            gc2->color = make_Color32(0, 255, 0, 255);
            linked_list_add(d->changes, gc2);
        }
        else{
            nl = NULL;
            src = 0;
        }
    }

}
