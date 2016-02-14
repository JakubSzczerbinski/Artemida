//
// Created by jaszc on 19.01.2016.
//

#ifndef ARTEMIDA_VISUAL_VERTEX_H
#define ARTEMIDA_VISUAL_VERTEX_H

#include "../utils/linked_list.h"
#include "../utils/utils.h"

typedef struct spacing_simulation_data{
    vector_2d speed;
    vector_2d next_position;
}spacing_simulation_data;

typedef struct visual_vertex{
    int flags;
    string* name;
    Color32 color;
    void* data;
    vector_2d position;
    unsigned int id;
    spacing_simulation_data sim_data;
}visual_vertex;

extern visual_vertex* visual_vertex_init(int id, Color32 color, void* data, int flags, string* name, vector_2d position);

extern int visual_vertex_comparator(void* a, void* b);

extern int visual_vertex_equals(visual_vertex* a, visual_vertex* b);

#endif //ARTEMIDA_VISUAL_VERTEX_H
