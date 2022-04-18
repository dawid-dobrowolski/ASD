//
// Created by dawiddobrowolski on 31.03.2022.
//

#ifndef GRAF_LISTALIST_MYTEST_H
#define GRAF_LISTALIST_MYTEST_H

#include "graf.h"

void test() {
    Graf* G = new Graf();
    G->createVertices(10);
    std::cout<<G->isEmpty()<<std::endl;
    for(int i = 0; i < 5; i++) {
        G->addEdge(i,i+1);
    }
    std::cout<<G->getNumberOfEdges()<<std::endl;

    std::cout<<G->isEmpty()<<std::endl;
    G->printNeighbourIndices(1);
    for(int i = 0 ; i < 4; i++) {
        G->addEdge(1,i+10);
    }
    G->printNeighbourIndices(1);
    std::cout<<G->vertexDegree(1)<<std::endl;
    G->addEdge(1,2);
    G->printNeighbourIndices(1);
    std::cout<<G->vertexDegree(1)<<std::endl;

    G->removeEdge(1,11);
    G->printNeighbourIndices(1);
    std::cout<<G->vertexDegree(1)<<std::endl;
    G->removeEdge(0,1);
    G->printNeighbourIndices(0);
    std::cout<<G->vertexDegree(0)<<std::endl;

    std::vector<int> testVector;
    testVector = G->getNeighbourIndices(1);
    for(int i = 0; i < testVector.size(); i++) {
        std::cout<<testVector.at(i)<<" ";
    }
    std::cout<<std::endl;
}

#endif //GRAF_LISTALIST_MYTEST_H
