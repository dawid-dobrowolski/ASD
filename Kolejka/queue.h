//
// Created by dawiddobrowolski on 08.12.2021.
//

#ifndef ZESTAW8_QUEUE_H
#define ZESTAW8_QUEUE_H

#include <iostream>


template <typename T>
class MyQueue {
    T* tab;
    int msize; // największa możliwa liczba elementów plus jeden
    int head; // pierwszy do pobrania
    int tail; // pierwsza wolna pozycja
public:
    MyQueue(int s=10) : msize(s+1), head(0), tail(0) {
        tab = new T[s+1];
        assert( tab != nullptr );
    } // default constructor
    ~MyQueue() { delete [] tab; }
    MyQueue(const MyQueue& other) {
        head = 0;
        tail = other.tail;
        tab = new T[msize+1];
        assert(tab != nullptr);
        for(int i=0; i< tail; i++) {
            tab[i] = other.tab[(other.head + i) % msize];
        }
    } // copy constructor

    MyQueue(MyQueue&& other) {
        tab = other.tab;
        msize = other.msize;
        head = other.head;
        tail = other.tail;
        other.tab = nullptr;
        other.msize = 0;
        other.head = 0;
        other.tail = 0;
    } // move constructor

    MyQueue& operator=(const MyQueue& other) {
        if(this != &other) {
            delete[] tab;
            tab = new T[other.msize + 1];
            msize = other.msize;
            head = other.head;
            tail = other.tail;
            std::copy(other.tab, other.tab + msize, tab);
        }
        return *this;
    } // copy assignment operator, return *this

    MyQueue& operator=(MyQueue&& other) {
        if(this != &other) {
            delete[] tab;
            tab = new T[other.msize + 1];
            tab = other.tab;
            other.tab = nullptr;
            msize = other.msize;
            other.msize = 0;
            head = other.head;
            other.head = 0;
            tail = other.tail;
            other.tail = 0;
        }
        return *this;
    } // move assignment operator, return *this

    bool empty() const { return head == tail; }
    bool full() const { return (head + msize -1) % msize == tail; }
    int size() const { return (tail - head + msize) % msize; }
    int max_size() const { return msize-1; }
    void push(const T& item) {
            tab[tail] = item;
            tail = (tail + 1) % msize;
    } // dodanie na koniec
    void push(T&& item) {
        tab[tail] = std::move(item);
        tail = (tail + 1) % msize;
    } // dodanie na koniec
    T& front() { return tab[head]; } // zwraca poczatek
    T& back() { return tab[(tail + msize -1) % msize]; } // zwraca koniec
    void pop() {
        tab[head] = T();
        head = (head + 1) % msize;
    } // usuwa poczatek
    void clear() {
        for(int i = 0; !full(); i++) {
            pop();
        }
        head = tail = 0;
    } // czyszczenie listy z elementow
    void display() {
        for (int i = head; i != tail; i=(i+1) % msize) {
            std::cout << tab[i] << " ";
        }
        std::cout << std::endl;
    }
};


#endif //ZESTAW8_QUEUE_H
