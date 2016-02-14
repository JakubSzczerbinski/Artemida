#include<stdio.h>
#include <stdlib.h>
#include "libs/vg/visual_graph.h"
#include "libs/vg/visual_graph_viewer.h"
#include "libs/vg/visual_vertex.h"
#include "libs/vg/visual_edge.h"
#include "libs/SDL2_gfx-1.0.1/SDL2_gfxPrimitives.h"
#include "libs/vg/spacing_simulator.h"
#include "libs/graph_algorithm/graph.h"
#include "libs/graph_converter/graph_converter.h"
#include "libs/graph_algorithm/DFS.h"
#include "libs/vg/play_changes.h"


int main( int argc, char* args[] ){
    debug("Program started\n");
    visual_graph_viewer* vgv = visual_graph_viewer_init("Artemida");
    debug("Graph viewer created\n");
    fflush(stdout);
    graph* g = graph_init();
    g->neighbourhood_list = malloc(8*sizeof(*g->neighbourhood_list));
    for(int i = 1;i <= 7;i++){
        g->neighbourhood_list[i] = linked_list_init(default_comparator);
    }
    for(int i = 1;i <= 4;i++){
        g->neighbourhood_list[i] = linked_list_init(default_comparator);
        linked_list_add(g->neighbourhood_list[i], neighbour_init(i+1, 1));
        linked_list_add(g->neighbourhood_list[i+1], neighbour_init(i, 1));
        linked_list_add(g->neighbourhood_list[i], neighbour_init(i+3, 1));
        linked_list_add(g->neighbourhood_list[i+3], neighbour_init(i, 1));
    }

    //linked_list_add(g->neighbourhood_list[7], neighbour_init(1, 1));
    g->number_of_edges = 2;
    g->number_of_vertices = 7;
    /*visual_vertex* v1 = visual_vertex_init(1, make_Color32(0, 128, 255, 255),
                                           NULL,
                                           0,
                                           string_init(),
                                           make_vector_2d(20, 20));
    visual_vertex* v2 = visual_vertex_init(2, make_Color32(0, 128, 255, 255),
                                           NULL,
                                           0,
                                           string_init(),
                                           make_vector_2d(200, 200));
    visual_vertex* v3 = visual_vertex_init(3, make_Color32(0, 128, 255, 255),
                                           NULL,
                                           0,
                                           string_init(),
                                           make_vector_2d(30, 50));
    debug("Vertices created\n");
    visual_graph_add_vertex(vgv->g, v1);
    visual_graph_add_vertex(vgv->g, v2);
    visual_graph_add_vertex(vgv->g, v3);
    debug("Vertices added\n");
    visual_edge* e1 = visual_edge_init(v1,
                                       v2,
                                       make_Color32(255, 128, 0, 255),
                                       NULL,
                                       0,
                                       string_init());
    visual_edge* e2 = visual_edge_init(v2,
                                      v3,
                                      make_Color32(255, 128, 0, 255),
                                      NULL,
                                      0,
                                      string_init());
    debug("Edges created\n");
    int xd = 0;
    visual_graph_add_edge(vgv->g, e1);
    visual_graph_add_edge(vgv->g, e2);*/
    vgv->g = graph_to_visual_graph(g);
    spacing_simulator* ss = spacing_simulator_init(vgv->g, 2, 1, 1, 1, 0.5);
    debug("Edges added\n");
    int xd = 400;
    for(node* j = vgv->g->vertices->first;j != NULL;j = j->next){
        visual_vertex* v = j->element;
        printf("%d\n", v->id);
    }
    int once = 0;
    while(visual_graph_viewer_update(vgv)){
        ss->friction_factor = 200.0/xd++;

        if(ss->friction_factor > 0.1)spacing_simulator_step(ss);
        else{
            if(once == 0) {
                linked_list *changes = DFS(g, 1);
                play_with_speed(vgv, changes, 1.0);
                once= 1;
            }
        }
    };
    return 0;

}




