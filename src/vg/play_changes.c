//
// Created by jaszc on 13.02.2016.
//

#include <unistd.h>
#include <stdio.h>
#include "play_changes.h"
#include "visual_graph_viewer.h"

void play_with_speed(visual_graph_viewer *vgv, linked_list *changes, float speed) {
    for(node* i = changes->first;i != NULL;i = i->next){
        graph_change* gc = i->element;
        switch (gc->action){

            case SET_VERTEX_COLOR:
                for(node* j = vgv->g->vertices->first;j != NULL;j = j->next){
                    visual_vertex* v = j->element;
                    if(v->id == gc->id) {
                        v->color = gc->color;
                        debug("Vertex color changed\n");
                    }
                }

            case SET_EDGE_COLOR:
                for(node* j = vgv->g->edges->first;j != NULL;j = j->next){
                    visual_edge* e = j->element;
                    if(e->id == gc->id) {
                        printd("MATCH : %d %d %d\n", e->v1->id, e->v2->id, gc->id);
                        e->color = gc->color;

                    }
                }
                debug("Edge color changed\n");
                break;

            case SET_VERTEX_STRING:
                for(node* j = vgv->g->vertices->first;j != NULL;j = j->next){
                    visual_vertex* v = j->element;
                    if(v->id == gc->id) {
                        string_set(v->name, gc->str);
                        debug("Vertex string changed\n");
                    }
                }
                break;

            case SET_EDGE_STRING:
                for(node* j = vgv->g->edges->first;j != NULL;j = j->next){
                    visual_edge* e = j->element;
                    if(e->id == gc->id) {
                        printd("MATCH : %d %d %d\n", e->v1->id, e->v2->id, gc->id);
                        string_set(e->name, gc->str);
                        debug("Edge string changed\n");
                    }
                }
                break;

            case PRINT_MESSAGE:
                printf(gc->str);
                break;

            default:
                debug("Unknown type of change");
                break;
        }
        sleep(1);
        visual_graph_viewer_update(vgv);
    }
}
