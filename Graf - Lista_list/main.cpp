#include "graf.h"
#include "myTest.h"
void test1()
{
    Graf* G = new Graf();
    G->createVertices(10);
    std::cout <<G->isEmpty()<<std::endl;
    G->addEdge(1, 2);
    G->addEdge(2, 3);
    G->addEdge(1, 5);
    std::cout <<G->isEmpty()<<std::endl;
    std::cout << G->vertexDegree(1)<<"\n";
    std::cout << G->vertexDegree(8) << "\n";
    std::cout << G->vertexDegree(2) << "\n";
    G->printNeighbourIndices(1);
    G->printNeighbourIndices(8);
    G->printNeighbourIndices(2);
    std::cout << G->checkEdge(1, 2)<<"\n";
    G->removeEdge(1, 2);

    G->printNeighbourIndices(1);
    std::cout << G->checkEdge(1, 2) << "\n\n\n\n\n";
}

void test2()
{
    Graf* G = new Graf();
    G->readFromFile("/home/dawiddobrowolski/Pobrane/graf_lista.txt");
    G->printNeighbourIndices(1);
    std::cout << G->getNumberOfEdges()<<std::endl;
}

int main()
{
    test1();
    test2();
    test();
}





