//
// Created by dawiddobrowolski on 08.03.2022.
//

#ifndef ZESTAWY_SETARRAY_H
#define ZESTAWY_SETARRAY_H
#include <iostream>

class SetArray {
    int size;
    static const int maxSize = 100;
    bool *table;
    bool checkIFmeetsTheLimit(int x) {
        if(x >= maxSize) return false;
        else return true;
    }

public:
    //default constructor
    SetArray() {
        size = 0;
        table = new bool[maxSize];
    }

    //default destructor
    ~SetArray() {}

    bool isEmpty() {
        if(size == 0) return true;
        else return false;
    }

    // add element to set
    void insert(int x) {
        if(checkIFmeetsTheLimit(x) && !isInSet(x)) {
            table[x] = true;
            size++;
        }
        else std::cout<<"Cannot add this element to set, because of the limit or is already in the set"<<std::endl;
    }
    // removes element from set
    void withdraw(int x) {
        if(isInSet(x)) {
            table[x] = false;
            size--;
        }
        else std::cout<<"Cannot withdraw this element from set, because this element isnt in set"<<std::endl;
    }

    // check if the element is in our set
    bool isInSet(int x) {
        if(table[x]) return true;
        else return false;
    }

    int getSize() {
        return size;
    }

    void clearSet() {
        if(!isEmpty()) {
            for(int i = 0; i < maxSize; i++) {
                if(isInSet(i))  withdraw(i);
            }
        }
    }

    void printSet() {
        if(!isEmpty()) {
            for(int i = 0; i < maxSize; i++) {
                if(isInSet(i)) std::cout<<i<<" ";
            }
            std::cout<<std::endl;
        }
    }

    SetArray operator+(SetArray& object) {
        SetArray newSet;
        for(int i = 0; i< maxSize; i++) {
            if(table[i] | object.table[i]) newSet.insert(i);
        }
        return newSet;
    }

    SetArray operator*(SetArray& object) {
        SetArray newSet;
        for(int i = 0; i < maxSize; i++) {
            if(table[i] & object.table[i]) newSet.insert(i);
        }
        return newSet;
    }

    SetArray operator-(SetArray& object) {
        SetArray newSet;
        for(int i = 0; i< maxSize; i++) {
            if(table[i] & ~object.table[i]) newSet.insert(i);
        }
        return newSet;
    }

    bool operator==(SetArray& object) {
        for (int i = 0; i < maxSize; i++) {
         if((isInSet(i) != object.isInSet(i))) return false;
        }
        return true;
    }

    bool operator <= (SetArray& object) {
        for(int i = 0; i < maxSize; i++) {
            if(isInSet(i) && !object.isInSet(i)) return false;
        }
        return true;
    }
};
#endif //ZESTAWY_SETARRAY_H
