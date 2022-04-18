//
// Created by dawiddobrowolski on 19.03.2022.
//

#ifndef GRAF_LISTALIST_GRAF_H
#define GRAF_LISTALIST_GRAF_H
#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include "edge.h"


class Graf
{
    std::vector<std::vector<edge>> vertexList;
    std::vector<edge> listInside;

public:
    Graf(){

    };
    void createVertices(int ile) {
        for(int i = 0; i < ile; i++) {
            vertexList.push_back(listInside);
        }
    }
    bool isEmpty() {

        for(int i = 0; i < vertexList.size(); i++) {
        if(vertexList[i].empty() == false) return false;
        }
        return true;
    }

    void addEdge(int i_Vertex_Index_1, int i_Vertex_Index_2) {
        if(checkEdge(i_Vertex_Index_1,i_Vertex_Index_2) == false) {
            edge newEdge(i_Vertex_Index_1, i_Vertex_Index_2);
            vertexList[i_Vertex_Index_1].push_back(newEdge);
        }
    }

    void removeEdge(int i_Vertex_Index_1, int i_Vertex_Index_2) {
        if(isEmpty() == false) {
            for (auto iter = vertexList[i_Vertex_Index_1].begin(); iter != vertexList[i_Vertex_Index_1].end(); iter++) {
                if (iter->vertex_Index2 == i_Vertex_Index_2) {
                    iter = vertexList[i_Vertex_Index_1].erase(iter);
                    break;
                }
            }
        }
    }

    bool checkEdge(int i_Vertex_Index_1, int i_Vertex_Index_2) {
        if(isEmpty() == false) {
            for (int j = 0; j < vertexList[i_Vertex_Index_1].size(); j++) {
                if (vertexList[i_Vertex_Index_1][j].vertex_Index2 == i_Vertex_Index_2) return true;
            }
            }
            return false;
        }

    int vertexDegree(int idx) {
        return vertexList[idx].size();
    }
    std::vector<int> getNeighbourIndices(int idx) {
        std::vector<int> NeighbourIndices;
        for (int j = 0; j < vertexList[idx].size(); j++) {
            int index = vertexList[idx][j].vertex_Index2;
            NeighbourIndices.push_back(index);
        }
        return NeighbourIndices;
    }

    void printNeighbourIndices(int idx) {
        std::cout<<"Neighbour Indices of "<<idx<<" : ";
            for (int j = 0; j < vertexList[idx].size(); j++) {
                std::cout << vertexList[idx][j].vertex_Index2 <<" ";
            }
            std::cout<<std::endl;
        }

    int getNumberOfEdges() {
        int numOfEdges = 0;
        for(int i = 0; i < vertexList.size(); i++) {
            numOfEdges = numOfEdges + vertexDegree(i);
        }
        return numOfEdges;
    }

    void readFromFile(std::string path) {
        std::ifstream graf;
        int ile;
        int value1;
        int value2;
        graf.open(path);
        if(!graf.good()) {
            std::cout<<"Cannot open file"<<std::endl;
            exit(1);
        }
        std::string str;
        getline(graf,str);
        std::cout<<"Odczytana wartosc z getline : "<<str<<std::endl;
        ile = stoi(str);
        createVertices(ile);
        while(!graf.eof()) {
            graf >> value1 >>value2;
            addEdge(value1,value2);

        }
    }
};



#endif //GRAF_LISTALIST_GRAF_H