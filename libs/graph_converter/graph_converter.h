//
// Created by mrnobody on 11.02.16.
//

#include "../vg/visual_graph.h"
#include "../graph_algorithm/graph.h"

#ifndef ARTEMIDA_GRAPH_CONVERTER_H
#define ARTEMIDA_GRAPH_CONVERTER_H

extern visual_graph* graph_to_visual_graph(graph* g);

extern graph* visual_graph_to_graph(visual_graph* vg);

#endif //ARTEMIDA_GRAPH_CONVERTER_H
