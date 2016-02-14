//
// Created by jaszc on 23.01.2016.
//

#ifndef ARTEMIDA_SPACING_SIMULATOR_H
#define ARTEMIDA_SPACING_SIMULATOR_H

#include "visual_graph.h"

typedef struct spacing_simulator{
    visual_graph* vg;
    float origin_point_force;
    float vertex_repulsion_force;
    float edge_attraction_force;
    float friction_factor;
    float step;
}spacing_simulator;

extern spacing_simulator* spacing_simulator_init(visual_graph * g, float origin_point_force, float vertex_repulsion_force, float edge_attraction_force, float step, float friction_factor);

 extern void spacing_simulator_step(spacing_simulator* ss);


#endif //ARTEMIDA_SPACING_SIMULATOR_H
