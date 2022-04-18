//
// Created by dawiddobrowolski on 08.12.2021.
//

#ifndef ZESTAW9_PRIORITYQUEUE_H
#define ZESTAW9_PRIORITYQUEUE_H

#include <algorithm>   // make_heap, push_heap, pop_heap
#include <vector>
#include <iostream>

template <typename T>
class MyPriorityQueue {
    std::vector<T> lst;
public:
    MyPriorityQueue(int s=10) { lst.reserve(s); } // default constructor
    ~MyPriorityQueue() { lst.clear(); }

    MyPriorityQueue(const MyPriorityQueue& other) {
        if(this != &other) {
            lst.reserve(other.lst.capacity());
            lst = other.lst;
        }
    } // copy constructor

    MyPriorityQueue(MyPriorityQueue&& other) {
        if(this != &other) {
            lst.reserve(other.lst.capacity());
            lst = other.lst;
            other.lst.clear();
        }
    } // move constructor

    MyPriorityQueue& operator=(const MyPriorityQueue& other) {
        if(this != &other) {
            lst.clear();
            lst.reserve(other.lst.capacity());
            lst = other.lst;
        }
        return *this;
    } // copy assignment operator, return *this

    MyPriorityQueue& operator=(MyPriorityQueue&& other) {
        if(this != &other) {
            lst.clear();
            lst = other.lst;
            other.lst.clear();
        }
        return *this;
    } // move assignment operator, return *this

    bool empty() const { return lst.empty(); }
    int size() const { return lst.size(); } // liczba elementow w kolejce
    void push(const T& item) { // dodanie do kolejki
        lst.push_back(item);
        std::push_heap(lst.begin(), lst.end());
    }
    void push(T&& item) { // dodanie do kolejki
        lst.push_back(std::move(item));
        std::push_heap(lst.begin(), lst.end());
    }
    T& top() { return lst.front(); } // zwraca element najwiekszy, nie usuwa
    void pop() { // usuwa element najwiekszy
        std::pop_heap(lst.begin(), lst.end());
        lst.pop_back();
    }
    void clear() { lst.clear(); } // czyszczenie listy z elementow
    void display() {
        for(int i=0; i<lst.size(); i++) {
            std::cout<<lst[i]<<std::endl;
        }
        std::cout<<std::endl;
    }

};

#endif //ZESTAW9_PRIORITYQUEUE_H
