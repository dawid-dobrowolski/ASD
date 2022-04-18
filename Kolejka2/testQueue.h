//
// Created by dawiddobrowolski on 24.03.2022.
//

#ifndef QUEUE_TESTQUEUE_H
#define QUEUE_TESTQUEUE_H

#include <cassert>
#include "queue.h"

void test_isEmpty() {
    KolejkaPriorytetowa test1;
    bool flag;
    flag = test1.isEmpty();
    assert(flag == 1);
    test1.insert(1);
    flag = test1.isEmpty();
    assert(flag == 0);
    std::cout<<"\033[1;32m[OK]\033[0m Test metody:'isEmpty()' przebiegl pomyslnie"<<std::endl;
}
void test_checkTheSize() {
    KolejkaPriorytetowa test1;
    for(int i = 0; i < 15; i++) {
        test1.insert(i);
        assert(test1.checkTheSize() == i+1);
    }
    assert(test1.checkTheSize() == 15);
    std::cout<<"\033[1;32m[OK]\033[0m Test metody:'checkTheSize()' przebiegl pomyslnie"<<std::endl;
}
void test_insert() {
    KolejkaPriorytetowa test1;
    for(int i = 0; i < 15; i++) {
        test1.insert(i);
    }
    assert(test1.checkTheSize() == 15);
    for(int i = 1; i <=15; i++) {
        assert(test1.getVertexInQueue(i) == i-1);
    }
    std::cout<<"\033[1;32m[OK]\033[0m Test metody:'insert()' przebiegl pomyslnie"<<std::endl;
}
void test_getRootElement() {
    KolejkaPriorytetowa test1;
    test1.insert(2);
    test1.insert(21);
    test1.insert(1);
    test1.insert(42);
    test1.insert(23);
    test1.insert(11);
    assert(test1.getRootElem() == 1);
    std::cout<<"\033[1;32m[OK]\033[0m Test metody:'getRootElem()' przebiegl pomyslnie"<<std::endl;
}
void test_removeRootElement() {
    KolejkaPriorytetowa test1;
    test1.insert(2);
    test1.insert(21);
    test1.insert(1);
    test1.insert(42);
    test1.insert(23);
    test1.insert(11);
    test1.RemoveRootElem();
    assert(test1.getRootElem() == 2);
    test1.RemoveRootElem();
    assert(test1.getRootElem() == 11);
    std::cout<<"\033[1;32m[OK]\033[0m Test metody:'RemoveRootElem()' przebiegl pomyslnie"<<std::endl;
}

#endif //QUEUE_TESTQUEUE_H
