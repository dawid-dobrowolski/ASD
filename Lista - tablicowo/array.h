//
// Created by dawiddobrowolski on 03.12.2021.
//

#ifndef ZESTAW3_ARRAY_H
#define ZESTAW3_ARRAY_H
#include <iostream>
#include <cassert>
#include <algorithm>

template <typename T>
class ArrayList {
    T* tab;
    int msize;
    int last;

public:
    // default constructor
    ArrayList(int s) : msize(s), last(0) {
        tab = new T[s];
        assert( tab != nullptr );
    }

    //destroyer
    ~ArrayList() { 
        delete [] tab; 
    }

    ArrayList(const ArrayList& other) : msize(other.msize), last(other.last) {
        if(msize > 0) {
            tab = new T[msize];
            std::copy(other.tab, other.tab + size(), tab);
        }
    } // copy constructor
    // usage:   ArrayList<int> list2(list1);

    ArrayList& operator=(ArrayList&& other) {
        if(this != &other) {
            delete[] tab;
            tab = other.tab;
            other.tab = nullptr;
            msize = other.msize;
            other.msize = 0;
            last = other.last;
            other.last = 0;    
        }
         return *this;
        }
        
     // move assignment operator, return *this
    // usage:   list2 = std::move(list1);

    // checks if the container has no elements
    bool empty() const { return last == 0; }

    // checks if the container is full
    bool full() const { return last == msize; }

    // returns the number of elements in list
    int size() const { return last; }

    // return the max size of elements in list
    int max_size() const { return msize; }


    // function add new element to front of the list
    void push_front(const T& item) {
        if(full()) {
            std::cout<<"Error, tablica pelna"<<std::endl;
        }
        else {
            int i = last;
            for(i;i>0;i--) {
                tab[i] = tab[i-1];
            }
            last++;
            tab[0]=item;
        }
    }

    T getTab(int i) {
        return this->tab[i];
    }

    // add new element to the last place in list
    void push_back(const T& item) {
        if(full()) {
            std::cout<<"Tablica jest pelna, nie mozna dodac elementu"<<std::endl;
        }
        else {
            tab[last] = item;
            last++;
        }
    }

    // zwraca poczatek, nie usuwa, error dla pustej listy
    T& front() {
        if(empty()) {
            std::cout<<"Error:Lista jest pusta"<<std::endl;
        }
        return tab[0];
    }

    // return the last element of the list, error if the list is empty
    T& back() {
        if(empty()) {
            std::cout<<"Error:Lista jest pusta"<<std::endl;
        }
        return tab[last-1];
    }

    // delete the first element, error if the list is empty
    void pop_front() {
        tab[0] = T();
        for(int i=0;i<last-1;i++) {
            tab[i] = tab[i+1];
        }
        tab[last-1] = T();
        last--;
    }

    // delete the last element, error if the list is empty
    void pop_back() {
        if(empty()) {
            std::cout<<"Error:Lista jest pusta"<<std::endl;
        }
        else {
            tab[last-1] = T();
            last--;
        }
    }

    // clear the list from elements
    void clear() {
        if(empty()) {
            std::cout<<"Error:Lista jest pusta"<<std::endl;
        }
        else {
            for(int i=0; i<last; i++) {
                tab[i] = T();
            }
            last = 0;
        }

    }


    // display the contents of the list
    void display() {
        if(empty()) {
            std::cout<<"Lista jest pusta"<<std::endl;
        }
        else
            for(int i=0; i<last; i++) {
                std::cout<<tab[i]<<std::endl;
            }
        std::cout<<std::endl;
    }

    // reverses the order
    void reverse() {
        for (int i = 0, j = msize - 1; i < j; i++, j--) {
            std::swap(tab[i], tab[j]);
        }
    }

    // sortowanie listy [simple bubble sort]
    void sort() {

        for(int i=0;i<last-1;i++) {
            for(int j=0;j<last-1;j++) {
                if(tab[j] > tab[j+1]) {
                    std::swap(tab[j],tab[j+1]);
                }
            }
        }

    }


    //  merges two lists into one
    void merge(ArrayList& other) {
        int i=0;
        int j=0;
        int sizeOfTab = size() + other.size();
        T newTab[sizeOfTab];
        for(i=0; i<last;i++) {
            newTab[i] = tab[i];
        }
        for(i; i<last+other.last; i++) {
            newTab[i] = other.tab[j];
            j++;
        }
        delete tab;
        last = 0;
        tab = new T[sizeOfTab];
        msize = sizeOfTab;
        other.tab = nullptr;
        for(int i=0;i<msize; i++) {
            tab[i] = newTab[i];
            last++;
        }
        sort();
    }
};
#endif //ZESTAW3_ARRAY_H
