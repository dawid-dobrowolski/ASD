//
// Created by dawiddobrowolski on 24.03.2022.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H
#pragma once
#include <iostream>



class KolejkaPriorytetowa {
    const static int maxSize = 100;
    int *array;

public:
    KolejkaPriorytetowa() {
        array = new int[maxSize];
        array[0] = 0;
    }
    int checkTheSize() {
        return array[0];
    }
    bool isEmpty() {
        if(array[0] == 0) return true;
        else return false;
    }
    void insert(int x) {
        int size = checkTheSize();
        array[size+1] = x;
        array[0] += 1;
        if(checkTheSize() > 1) {
            heap_Up(checkTheSize());
        }
    }

    void RemoveRootElem() {
        if(!isEmpty()) {
            int size = checkTheSize();
            array[1] = array[size];
            array[0]-= 1;
            array[size] = 0;
            heap_Down(1);

        }
    }

    void heap_Down(int vertex) {
        int indexOfLeftSon = vertex * 2;
        int indexOfRightSon = (vertex * 2) + 1;
        int indexOfLast = checkTheSize();
        int higherPriority;
        int temp;
        if((indexOfLeftSon <= indexOfLast) &&(array[indexOfLeftSon] < array[vertex])) {
            higherPriority = indexOfLeftSon;
        }
        else {
            higherPriority = vertex;
        }
        if((indexOfRightSon <= indexOfLast) &&(array[indexOfRightSon] < array[higherPriority])) {
            higherPriority = indexOfRightSon;
        }
        if(higherPriority != vertex) {
            temp = array[vertex];
            array[vertex] = array[higherPriority];
            array[higherPriority] = temp;
            vertex = higherPriority;
            heap_Down(vertex);
        }
    }

    void heap_Up(int vertex) {
        int valueOfVertex = array[vertex];
        int parentVertex = vertex / 2;
        while((parentVertex > 0) && (valueOfVertex < array[parentVertex])) {
            array[vertex] = array[parentVertex];
            vertex = vertex / 2;
            parentVertex = parentVertex / 2;
            array[vertex] = valueOfVertex;
        }
    }

    void print() {
        for(int i = 1; i < checkTheSize()+1; i++) {
            std::cout<<array[i]<<" ";
        }
        std::cout<<std::endl;
    }

    //only for tests
    int getVertexInQueue(int x) {
        return array[x];
    }

    int getRootElem() {
        if(!isEmpty())  return array[1];
        else
            std::cout<<"Queue is empty"<<std::endl; 
            return -1;
    }
};
#endif //QUEUE_QUEUE_H
