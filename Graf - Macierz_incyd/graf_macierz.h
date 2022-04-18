//
// Created by dawiddobrowolski on 18.03.2022.
//

#ifndef GRAF_MACIERZ_GRAF_MACIERZ_H
#define GRAF_MACIERZ_GRAF_MACIERZ_H
#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "edge.h"


class Graf
{
    const static int maxSize = 1200;
    int matrix[maxSize][maxSize];
    int numberOfVertices;

public:
    Graf() {}

    void createVertices(int ile) {
        numberOfVertices = ile;
    }
    int getNumberofVertices() {
        return numberOfVertices;
    }

    void addEdge(int i_Vertex_Index_1, int i_Vertex_Index_2) {
        matrix[i_Vertex_Index_1][i_Vertex_Index_2] = 1;
    }

    void removeEdge(int i_Vertex_Index_1, int i_Vertex_Index_2) {
        matrix[i_Vertex_Index_1][i_Vertex_Index_2] = 0;
    }

    bool checkEdge(int i_Vertex_Index_1, int i_Vertex_Index_2) {
        if(matrix[i_Vertex_Index_1][i_Vertex_Index_2] == 1) return true;
        else return false;
    }

    int vertexDegree(int idx) {
        int counter = 0;
        for(int i = 0; i < maxSize; i++) {
            if(matrix[idx][i] == 1) {
                counter++;
            }
        }
        return counter;
    }

    std::vector<int> getNeighbourIndices(int idx) {
        std::vector<int> neighbour;
        for(int i = 0; i < maxSize; i++) {
            if(checkEdge(idx,i)) {
                neighbour.push_back(i);
            }
        }
        return neighbour;
    }

    void printNeighbourIndices(int idx) {
        for(int i = 0; i < maxSize; i++) {
            if(checkEdge(idx,i)) {
                std::cout<<i<<" ";
            }
    }
        std::cout<<std::endl;
    }

    int getNumberOfEdges() {
        int counter = 0;
        for(int i = 0; i < maxSize; i++) {
            for(int j = 0; j < maxSize; j++) {
                if(checkEdge(i,j)){
                    counter++;
                }
            }
        }
        return counter;
    }

    void readFromFile(std::string path) {
    std::ifstream graf;
    int ile;
    int value1,value2;
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

private:
    void clear() {
        numberOfVertices = 0;
        for(int i = 0; i < maxSize; i++) {
            for(int j = 0; j < maxSize; j++) {
                if(checkEdge(i,j)){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

#endif //GRAF_MACIERZ_GRAF_MACIERZ_H
