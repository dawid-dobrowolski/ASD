#include <iostream>
#include "graf_macierz.h"
#include "myTest.h"
int main() {
    Graf* Gr = new Graf();
    Gr->readFromFile("/home/dawiddobrowolski/Pobrane/graf_lista.txt");
    Gr->printNeighbourIndices(1);
    std::cout << Gr->getNumberOfEdges()<<std::endl;
    std::cout << Gr->getNumberofVertices()<<std::endl;
    std::cout<<"---------------------------------------"<<std::endl;
    test();
    return 0;
}
