//
// Created by jaszc on 19.01.2016.
//

#include <stdio.h>
#include "visual_graph_viewer.h"
#include "../SDL2_gfx-1.0.1/SDL2_gfxPrimitives.h"

visual_graph_viewer*  visual_graph_viewer_init(const char* title){
    debug("Creating graph viewer\n");
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        debug("ERROR: unable to initialize SDL_VIDEO");
        return NULL;
    }
    else{
        visual_graph_viewer *gv = malloc(sizeof(*gv));
        debug("Allocated graph viewer\n");
        gv->window = (SDL_Window *) SDL_CreateWindow(title,
                                                     SDL_WINDOWPOS_UNDEFINED,
                                                     SDL_WINDOWPOS_UNDEFINED,
                                                     800,
                                                     600,
                                                     SDL_WINDOW_SHOWN);
        debug("Window created\n");
        if(gv->window == NULL){
            debug("ERROR: Window is NULL");
            free(gv);
            return NULL;
        }
        else{
            gv->renderer = SDL_CreateRenderer( gv->window, -1, SDL_RENDERER_ACCELERATED );
            debug("Renderer created\n");
            if( gv->renderer == NULL ) {
                debug("ERROR: unable to create renderer");
             
                free(gv);
                return  NULL;
            }
            SDL_SetRenderDrawColor(gv->renderer, 0, 0, 0, 255);
            gv->surface = SDL_GetWindowSurface(gv->window);
            debug("Created surface \n");
            if(gv->surface == NULL){
                debug("ERROR: unable to get window surface");
             
                free(gv);
                return NULL;
            }
            gv->g = visual_graph_init();
            debug("Graph created \n");
            if(gv->g == NULL){
                debug("ERROR: unable to initialize visual_graph");
                free(gv);
                return NULL;
            }
            return gv;
        }
    }
}

int visual_graph_viewer_update(visual_graph_viewer* vgv){
    SDL_SetRenderDrawColor(vgv->renderer, 0, 0, 0, 255);
    SDL_RenderClear( vgv->renderer );
    linked_list* llv = vgv->g->vertices;
    linked_list* lle = vgv->g->edges;
    for(node* i = lle->first;i != NULL;i = i->next){
        visual_edge* e = (visual_edge*)i->element;
        aalineColor(vgv->renderer, e->v1->position.x, e->v1->position.y, e->v2->position.x, e->v2->position.y, e->color.rgba);
    }
    for(node* i = llv->first; i != NULL; i = i->next) {
        visual_vertex *v = (visual_vertex *) i->element;
        filledCircleColor(vgv->renderer, v->position.x, v->position.y, 10, v->color.rgba);
        aacircleColor(vgv->renderer, v->position.x, v->position.y, 10, v->color.rgba);
    }
    SDL_RenderPresent(vgv->renderer);
    return visual_graph_viewer_handle_events(vgv);
}

int visual_graph_viewer_handle_events(visual_graph_viewer *vgv) { //SDL EVENT handling
    SDL_Event e;
    while( SDL_PollEvent( &e ) != 0 )
    {
        if( e.type == SDL_QUIT )
        {
            debug("Quiting \n");
         
            return 0;
        }
    }
    return 1;
}
