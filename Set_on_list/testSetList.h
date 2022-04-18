//
// Created by dawiddobrowolski on 09.03.2022.
//

#ifndef SETLIST_TESTSETLIST_H
#define SETLIST_TESTSETLIST_H

#include <cassert>
#include "setList.h"
void test_getSize() {
    setList testSet;
    assert(testSet.getSize() == 0);
    for(int i = 0; i < 5; i++) {
        testSet.insert(i);
    }
    assert(testSet.getSize() == 5);
    std::cout<<"\033[1;32m[OK]\033[0m Test metody:'getSize()' przebiegl pomyslnie"<<std::endl;
}
void test_insert() {
    setList testSet;
    int value = 0;
    for(int i = 0; i < 5; i++) {
        value = testSet.getSize();
        testSet.insert(i);
        assert(testSet.isInSet(i) && testSet.getSize() == value + 1);
    }
    std::cout<<"\033[1;32m[OK]\033[0m Test metody:'insert()' przebiegl pomyslnie"<<std::endl;
}

void test_withdraw() {
    setList testSet;
     for(int i = 5; i < 10; i++) {
         testSet.insert(i);
     }
     int value;
     for(int i = 5; i < 10; i++) {
         value = testSet.getSize();
         testSet.withdraw(i);
         assert(!(testSet.isInSet(i)) && testSet.getSize() == value - 1);
     }
    std::cout<<"\033[1;32m[OK]\033[0m Test metody:'withdraw()' przebiegl pomyslnie"<<std::endl;
}

void test_isInSet() {
    setList testSet;
    for(int i = 0; i < 11; i++) {
        if(i % 2 == 0) {
            testSet.insert(i);
            assert(testSet.isInSet(i));
        }
        else assert(!testSet.isInSet(i));
    }
    std::cout<<"\033[1;32m[OK]\033[0m Test metody:'isInSet()' przebiegl pomyslnie"<<std::endl;
}

void test_SumOperator() {
    setList testSet1;
    setList testSet2;
    setList testSet3;

    for(int i = 0; i < 6; i++) {
        if(i % 2 == 0) {
            testSet1.insert(i);
        }
        else testSet2.insert(i);
    }
    testSet3 = testSet1 + testSet2;
    int elements = testSet1.getSize() + testSet2.getSize();
    assert(testSet3.getSize() == elements);
    for(int i = 0; i < testSet3.getSize(); i++) {
        assert(testSet3.isInSet(i));
    }
    std::cout<<"\033[1;32m[OK]\033[0m Test metody:'operator+' przebiegl pomyslnie"<<std::endl;
}

void test_DifferenceOperator() {
    setList testSet1;
    setList testSet2;
    setList testSet3;
    setList testSet4;
    for(int i = 0; i < 3; i++) {
        testSet1.insert(i);
        testSet2.insert(i+1);
    }
    testSet4 = testSet1 * testSet2;
    int numberOfcommonElem = testSet4.getSize();

    testSet3 = testSet1 - testSet2;
    assert(testSet3.getSize() == testSet1.getSize() - numberOfcommonElem);
    assert(testSet3 <= testSet1);

    setList testSet5;
    testSet5 = testSet3 + testSet4;
    assert(testSet5 == testSet1);
    std::cout<<"\033[1;32m[OK]\033[0m Test metody:'operator-' przebiegl pomyslnie"<<std::endl;
}

void test_CommonPartOperator() {
    setList testSet1;
    setList testSet2;
    setList testSet3;

    for(int i = 0; i < 3; i++) {
        testSet1.insert(i);
        testSet2.insert(i+2);
    }
    int counter = 0;
    testSet3 = testSet1 * testSet2;
    for(int i = 0; i < testSet1.getSize(); i++) {
        if(testSet3.isInSet(i) && testSet1.isInSet(i) && testSet2.isInSet(i)) {
            counter++;
        }
    }
    assert(counter == testSet3.getSize());
    std::cout<<"\033[1;32m[OK]\033[0m Test metody:'operator*' przebiegl pomyslnie"<<std::endl;
}

void test_isEqualOperator() {
    setList testSet1;
    setList testSet2;
    for(int i = 0; i < 3; i++) {
        testSet1.insert(i);
        testSet2.insert(i);
    }
    bool flag = testSet1 == testSet2;
    assert(flag);
    testSet1.insert(10);
    flag = testSet1 == testSet2;
    assert(!flag);
    testSet2.insert(10);
    testSet2.insert(55);
    flag = testSet1 == testSet2;
    assert(!flag);
    std::cout<<"\033[1;32m[OK]\033[0m Test metody:'operator==' przebiegl pomyslnie"<<std::endl;
}

void test_isConcludingOperator() {
    setList testSet1;
    setList testSet2;
    for(int i = 0; i < 3; i++) {
        testSet1.insert(i);
        testSet2.insert(i);
    }
    bool flag = testSet1 <= testSet2;
    assert(flag);
    flag = testSet2 <= testSet1;
    assert(flag);

    testSet1.insert(4);
    flag = testSet1 <= testSet2;
    assert(!flag);

    testSet2.insert(4);
    testSet2.insert(5);
    flag = testSet1 <= testSet2;
    assert(flag);
    std::cout<<"\033[1;32m[OK]\033[0m Test metody:'operator<=' przebiegl pomyslnie"<<std::endl;
}




#endif //SETLIST_TESTSETLIST_H
