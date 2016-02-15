//
// Created by jaszc on 15.02.2016.
//

#include "Prim.h"
#include "../utils/queue.h"
#include "graph_changes.h"

typedef struct edge{
    unsigned int a;
    unsigned int b;
    int weight;
}edge;

int edge_comparator(void* e1, void* e2){
    edge *re1 = e1, *re2 = e2;
    return re1->weight > re2->weight;
}

linked_list *Prim(graph *g) {
    int* in_tree = malloc(sizeof(int)* (g->number_of_vertices+1));
    for(int i = 1;i <= g->number_of_vertices;i++){
        in_tree[i] = 0;
    }
    queue * q = queue_init((g->number_of_edges+1)*10);
    edge* e = malloc(sizeof(*e));
    linked_list* changes = linked_list_init(default_comparator);
    e->a = 0;
    e->b = 1;
    e->weight = 0;
    queue_push(q, e);
    while(!queue_is_empty(q)){
        debug("XD");
        edge* ce = queue_peek(q);
        queue_pop(q);
        debug(int_to_string(ce->b));
        if(in_tree[ce->b] == 0){
            in_tree[ce->b] = 1;
            graph_change* gc1 = malloc(sizeof(*gc1));
            gc1->action = SET_EDGE_COLOR;
            gc1->id = (ce->a > ce->b ? (ce->b<<16) + ce->a :  (ce->a<<16) + ce->b);
            gc1->color = make_Color32(0, 255, 0, 255);
            linked_list_add(changes, gc1);
            graph_change* gc2 = malloc(sizeof(*gc2));
            gc2->action = SET_VERTEX_COLOR;
            gc2->id = ce->b;
            gc2->color = make_Color32(0, 255, 0, 255);
            linked_list_add(changes, gc2);
        }
        else{
            continue;
        }
        linked_list* nl = g->neighbourhood_list[ce->b];
        for(node* i = nl->first;i != NULL;i = i-> next){
            debug("LM");
            neighbour *n = i->element;
            edge* ne = malloc(sizeof(*ne));
            ne->weight = n->weight;
            ne->b = n->neghbour_id;
            ne->a = ce->b;
            queue_push(q, ne);
        }
        queue_sort(q, edge_comparator);
    }

    return changes;
}


