//
// Created by dawiddobrowolski on 19.03.2022.
//

#ifndef GRAF_LISTALIST_EDGE_H
#define GRAF_LISTALIST_EDGE_H
#pragma once

struct edge
{
    int vertex_Index1;
    int vertex_Index2;
    float waga;

public:
    edge(int i_Vertex_Index1, int i_Vertex_Index2) {
        this->vertex_Index1 = i_Vertex_Index1;
        this->vertex_Index2 = i_Vertex_Index2;
    }
    edge(int i_Vertex_Index_1, int i_Vertex_Index_2, float i_weight);
};



#endif //GRAF_LISTALIST_EDGE_H
