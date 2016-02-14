//
// Created by mrnobody on 11.02.16.
//

#ifndef ARTEMIDA_GRAPH_CHANGES_H
#define ARTEMIDA_GRAPH_CHANGES_H

#include "../utils/utils.h"

typedef struct graph_change{
    unsigned int action;
    unsigned int id;
    union{
        Color32 color;
        char* str;
        int value;
    };
}graph_change;

enum actions{
    SET_VERTEX_COLOR,
    SET_VERTEX_STRING,
    SET_EDGE_COLOR,
    SET_EDGE_STRING,
    PRINT_MESSAGE
};

#endif //ARTEMIDA_GRAPH_CHANGES_H
