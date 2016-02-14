//
// Created by Jakub Szczerbinski on 11.02.16.
//

#include "graph_converter.h"
#include "../graph_algorithm/graph.h"

visual_graph* graph_to_visual_graph(graph *g) {
    Color32 default_color = make_Color32(255, 0, 0, 255);
    visual_graph* result = visual_graph_init();
    visual_vertex** vertices = malloc((g->number_of_vertices+1)*sizeof(*vertices));
    for(int i = 1;i <= g->number_of_vertices;i++){
        vertices[i] = malloc(sizeof(*vertices[i]));
        visual_vertex* v = visual_vertex_init(i, default_color, NULL, 0, string_init(), make_vector_2d(i*10, rand()%400));
        vertices[i] = v;
        string_set(v->name, int_to_string(v->id));
        visual_graph_add_vertex(result, v);
    }
    for(int i = 1;i <= g->number_of_vertices;i++){
        linked_list* nl = g->neighbourhood_list[i];
        for(node *j = nl->first;j != NULL; j = j->next){
            neighbour* n = j->element;
            if(i > n->neghbour_id)continue;
            visual_edge* e = visual_edge_init(vertices[i], vertices[n->neghbour_id], default_color, NULL, 0, string_init());
            visual_graph_add_edge(result, e);
        }
    }
    return result;
}

graph* visual_graph_to_graph(visual_graph *vg) {
    graph* result;
    return result;
}
