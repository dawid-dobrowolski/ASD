//
// Created by dawiddobrowolski on 03.12.2021.
//

#ifndef ZESTAW6_DEQUE_H
#define ZESTAW6_DEQUE_H
#include <iostream>
#include <cassert>

template <typename T>
class MyDeque {
    T* tab;
    int msize; // największa możliwa liczba elementów plus jeden
    int head; // pierwszy do pobrania
    int tail; // pierwsza wolna pozycja

public:

    MyDeque(int s=10) : msize(s+1), head(0), tail(0) {
        tab = new T[s+1];
        assert( tab != nullptr );
    } // default constructor

    ~MyDeque() { delete [] tab; }

    MyDeque(const MyDeque& other) {
        head = 0;
        tail = other.size();
        tab = new T[msize];
        assert( tab != nullptr);
        for(int i = 0; i < tail; i++) {
            tab[i] = other.tab[(other.head + 1) % msize];
        }
    } // copy constructor

    MyDeque(MyDeque&& other) {
        msize = other.msize;
        head = other.head;
        tail = other.tail;
        tab = other.tab;
        other.tab = nullptr;
        other.head = 0;
        other.tail = 0;
        other.msize = 1;
    } // move constructor

    MyDeque& operator=(const MyDeque& other) {
        if(this == &other) return *this;
        delete [] tab;
        msize = 1;
        head = 0;
        tail = 0;
        tab = new T[other.msize];
        assert( tab != nullptr);
        msize = other.msize;
        for(int i=0; i< tail; i++) {
            tab[i] = other.tab[(other.head + 1) % msize];
        }
        return *this;
    } // copy assignment operator, return *this

    MyDeque& operator=(MyDeque&& other) {
        if( this != &other ) {

            delete [] tab;

            msize = other.msize;
            tail = other.tail;
            head = other.head;

            tab = other.tab;
            other.tab = nullptr;
        }
        return *this;
    } // move assignment operator, return *this

    bool empty() const { return head == tail; }

    bool full() const { return (tail + 1) % msize == head; }

    int size() const { return (tail - head + msize) % msize; }

    int max_size() const { return msize-1; }

    void push_front(const T& item) {
        head = (head + msize -1) % msize;
        tab[head] = item;
    }

    void push_back(const T& item) {
        tab[tail] = item;
        tail = (tail + 1) % msize;
    } // dodanie na koniec O(1)


    T& front() { return tab[head]; } // zwraca poczatek

    T& back() { return tab[(tail + msize -1) % msize]; } // zwraca koniec

    void pop_front() {
        tab[head] = T();
        head = (head + 1) % msize;
    } // usuwa początek kolejki O(1)

    void pop_back() {
        tail = (tail + msize - 1) % msize;
        tab[tail] = T();
    } // usuwa koniec kolejki O(1)

    void clear() {
        for(int i = 0; !full(); i++) {
            pop_back();
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
#endif //ZESTAW6_DEQUE_H
