//
// Created by dawiddobrowolski on 09.03.2022.
//

#ifndef SETLIST_SETLIST_H
#define SETLIST_SETLIST_H
#pragma once
#include<iostream>
#include <vector>
class setList
{
    std::vector<int> vec;

public:

    setList() {}

    ~setList() {
        vec.clear();
    }

    int getSize() {
        return vec.size();
    }

    void printSet() {
        for(auto i : vec) {
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;
    }

    void insert(int x) {
        if(!isInSet(x)) {
            vec.push_back(x);
        }
    }

    void withdraw(int x) {
        if(isInSet(x)) {
            std::vector<int>::iterator it;
            for(it = vec.begin(); it != vec.end()+1; it++) {
                if(*it == x) {
                    vec.erase(it);
                }
            }
        }
    }

    bool isInSet(int x) {
        for(auto i : vec) {
            if(i == x) return true;
        }
        return false;
    }

    setList operator+(setList& obj) {
        setList newSet;
        for(auto i : vec) {
            newSet.insert(i);
        }
        for(auto i : obj.vec) {
            if(!newSet.isInSet(i)) {
                newSet.insert(i);
            }
        }
        return newSet;
    }

    setList operator*(setList& obj) {
        setList newSet;
        for(auto i : vec) {
            if(obj.isInSet(i)) {
                newSet.insert(i);
            }
        }
        return newSet;
    }

    setList operator-(setList& obj) {
        setList newSet;
        for(auto i : vec) {
            if(!obj.isInSet(i)) {
                newSet.insert(i);
            }
        }
        return newSet;
    }

    bool operator==(setList& obj) {
        for(auto i : vec) {
            if(!obj.isInSet(i)) return false;
        }
        if(getSize() == obj.getSize()) return true;
        else return false;
    }

    bool operator<=(setList& obj) {
        for(auto i : vec) {
            if(obj.isInSet(i) && obj.getSize() >= getSize()) return true;
        }
        return false;
    }

};
#endif //SETLIST_SETLIST_H
