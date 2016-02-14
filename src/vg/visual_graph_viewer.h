//
// Created by jaszc on 19.01.2016.
//

#ifndef ARTEMIDA_VISUAL_GRAPH_VIEWER_H
#define ARTEMIDA_VISUAL_GRAPH_VIEWER_H

#include <SDL_video.h>
#include <SDL_render.h>
#include "visual_graph.h"

typedef struct visual_graph_viewer{
    SDL_Window* window;
    SDL_Surface* surface;
    SDL_Renderer* renderer;
    visual_graph* g;
    transform_2d transform;
}visual_graph_viewer;

extern visual_graph_viewer*  visual_graph_viewer_init(const char* title);

extern int visual_graph_viewer_update(visual_graph_viewer* vgv);

extern int visual_graph_viewer_handle_events(visual_graph_viewer* vgv);

#endif //ARTEMIDA_VISUAL_GRAPH_VIEWER_H
