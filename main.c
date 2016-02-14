#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "src/vg/visual_graph.h"
#include "src/graph_algorithm/graph.h"
#include "src/vg/visual_graph_viewer.h"
#include "src/graph_converter/graph_converter.h"
#include "src/vg/spacing_simulator.h"
#include "src/graph_algorithm/DFS.h"
#include "src/vg/play_changes.h"


int main( int argc, char* args[] ){
    graph *current_graph = NULL;
    linked_list *changes = NULL;
    debug("Program started\n");
    visual_graph_viewer* vgv = visual_graph_viewer_init("Artemida");
    int quit = 0;
    char command[100];
    while(visual_graph_viewer_update(vgv) && !quit){
        scanf("%s", &command);
        //CREATE
        if(strcmp(command, "create") == 0){
            graph_dispose(current_graph);
            current_graph = graph_create();
            vgv->g = graph_to_visual_graph(current_graph);
            spacing_simulator* ss = spacing_simulator_init(vgv->g, 2, 1, 1, 1, 0.5);
            int xd = 400;
            while(ss->friction_factor > 0.1f) {
                ss->friction_factor = 200.0f / xd++;
                spacing_simulator_step(ss);
            }
        }

        //DFS
        if(strcmp(command, "DFS") == 0){
            if(current_graph == NULL){
                printf("No graph loaded");
                continue;
            }
            printf("Type starting vertex index ");
            unsigned a;
            scanf("%u", &a);
            changes = DFS(current_graph, a);
        }

        //PLAY
        if(strcmp(command, "play") == 0){
            if(changes == NULL){
                printf("You need to run an algorithm first\n");
                continue;
            }
            play_with_speed(vgv, changes, 1.0);
        }

        //QUIT
        if(strcmp(command, "quit") == 0){
            quit = 1;
        }

        //RESET
        if(strcmp(command, "reset") == 0){
            if(current_graph == NULL){
                printf("No graph loaded");
                continue;
            }
            vgv->g = graph_to_visual_graph(current_graph);
            spacing_simulator* ss = spacing_simulator_init(vgv->g, 2, 1, 1, 1, 0.5);
            int xd = 400;
            while(ss->friction_factor > 0.1f) {
                ss->friction_factor = 200.0f / xd++;
                spacing_simulator_step(ss);
            }
        }
    }

}




