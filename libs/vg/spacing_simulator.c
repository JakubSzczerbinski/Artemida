//
// Created by jaszc on 23.01.2016.
//

#include <stdio.h>
#include "spacing_simulator.h"

spacing_simulator *spacing_simulator_init(visual_graph *g, float origin_point_force, float vertex_repulsion_force,
                                          float edge_attraction_force, float step, float friction_factor) {
    spacing_simulator* ss = malloc(sizeof(*ss));
    ss->origin_point_force = origin_point_force;
    ss->edge_attraction_force = edge_attraction_force;
    ss->vertex_repulsion_force = vertex_repulsion_force;
    ss->step = step;
    ss->friction_factor = friction_factor;
    ss->vg = g;
    return ss;
}

void spacing_simulator_step(spacing_simulator *ss) {
    linked_list* vertices = ss->vg->vertices;
    linked_list* edges = ss->vg->edges;
    for(node* i = vertices->first; i != NULL;i = i->next){
        visual_vertex* v1 = (visual_vertex*)i->element;
        v1->sim_data.speed = subtract_vector(make_vector_2d(400, 300), v1->position);
        v1->sim_data.speed = multiply_vector(normalize(v1->sim_data.speed), ss->origin_point_force);
        //debug_vector2d(v1->position, "POSITION");
        //debug_vector2d(v1->sim_data.speed, "SPEED");
        //debug("VVVVVVVVVV\n");
    }
    for(node* i = vertices->first; i != NULL;i = i->next){
        visual_vertex* v1 = (visual_vertex*)i->element;
        for(node* j = i->next;j != NULL;j = j->next){
            visual_vertex* v2 = (visual_vertex*)j->element;
            vector_2d speed1 = subtract_vector(v1->position, v2->position);
            vector_2d speed2 = subtract_vector(v2->position, v1->position);
            float distance = calculate_distance(v1->position, v2->position);
            float force_factor = 100-distance;
            force_factor = (force_factor > 0 ? force_factor : 0)*2;
            speed1 = normalize(speed1);
            speed2 = normalize(speed2);
            speed1 = multiply_vector(speed1, force_factor);
            speed2 = multiply_vector(speed2, force_factor);
            v1->sim_data.speed = add_vector(v1->sim_data.speed, speed1);
            v2->sim_data.speed = add_vector(v2->sim_data.speed, speed2);
            //debug_vector2d(speed1, "SPEED1");
            //debug_vector2d(speed2, "SPEED2");
        }
    }
    for(node* i = edges->first;i != NULL;i = i->next){
        visual_edge* e = (visual_edge*)i->element;
        vector_2d pos1 = e->v1->position;
        vector_2d pos2 = e->v2->position;
        float distance = calculate_distance(pos1, pos2);
        vector_2d direction1 = normalize(subtract_vector(pos2, pos1));
        vector_2d direction2 = normalize(subtract_vector(pos1, pos2));
        vector_2d speed1 = multiply_vector(direction1, distance*distance/500);
        vector_2d speed2 = multiply_vector(direction2, distance*distance/500);
        e->v1->sim_data.speed = add_vector(e->v1->sim_data.speed, speed1);
        e->v2->sim_data.speed = add_vector(e->v2->sim_data.speed, speed2);
    }
    for(node* i = vertices->first; i != NULL;i = i->next){
        visual_vertex* v1 = (visual_vertex*)i->element;
        v1->sim_data.speed = multiply_vector(v1->sim_data.speed, ss->friction_factor);
        v1->position = add_vector(v1->position, v1->sim_data.speed);
    }
}
