//
// Created by jaszc on 13.02.2016.
//

#include <unistd.h>
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
                        debug("Color changed");
                    }
                }
                break;
            default:
                debug("Unknown type of change");
                break;
        }
        sleep(1);
        visual_graph_viewer_update(vgv);
    }
}
