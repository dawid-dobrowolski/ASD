//
// Created by dawiddobrowolski on 08.03.2022.
//

#ifndef ZESTAWY_TESTSETARRAY_H
#define ZESTAWY_TESTSETARRAY_H

#include <cassert>
#include "setArray.h"

void test_isEmpty() {
    SetArray testSet;
    assert(testSet.isEmpty());
    testSet.insert(1);
    assert(!testSet.isEmpty());
    std::cout<<"\033[1;32m[OK]\033[0m Test metody:'isEmpty()' przebiegl pomyslnie"<<std::endl;
}

void test_insert() {
    SetArray testSet;
    for(int i = 0; i< 10; i++) {
        if((i % 2 ) == 0) {
            int sizeCheck = testSet.getSize();
            testSet.insert(i);
            assert(testSet.isInSet(i) && (testSet.getSize() == sizeCheck+1));
        }
    }
    std::cout<<"\033[1;32m[OK]\033[0m Test metody:'insert()' przebiegl pomyslnie"<<std::endl;
}

void test_withdraw() {
    SetArray testSet;
    for(int j = 0; j < 5; j++) {
        testSet.insert(j);
    }
    for(int i = 0; i< testSet.getSize(); i++) {
            int sizeCheck = testSet.getSize();
            testSet.withdraw(i);
            assert(!(testSet.isInSet(i)) && (testSet.getSize() == sizeCheck-1));
        }
    std::cout<<"\033[1;32m[OK]\033[0m Test metody:'withdraw()' przebiegl pomyslnie"<<std::endl;
}

void test_isInSet() {
    SetArray testSet;
    testSet.insert(99);
    assert(testSet.isInSet(99));
    testSet.withdraw(99);
    assert(!testSet.isInSet(99));
    std::cout<<"\033[1;32m[OK]\033[0m Test metody:'isInSet()' przebiegl pomyslnie"<<std::endl;
}

void test_getSize() {
    SetArray testSet;
    assert(testSet.getSize() == 0);
    for(int i = 0; i < 90; i++) {
        if((i % 3)==0) {
            testSet.insert(i);
        }
    }
    assert(testSet.getSize() == 30);
    std::cout<<"\033[1;32m[OK]\033[0m Test metody:'getSize()' przebiegl pomyslnie"<<std::endl;
}

void test_clearSet() {
    SetArray testSet;
    for(int i = 0; i < 10; i++) {
        testSet.insert(i);
    }
    assert(testSet.getSize() == 10);
    testSet.clearSet();
    assert(testSet.getSize() == 0);
    std::cout<<"\033[1;32m[OK]\033[0m Test metody:'clearSet()' przebiegl pomyslnie"<<std::endl;
}

void test_SumOperator() {
    SetArray testSet1;
    SetArray testSet2;
    for(int i = 0; i<=10; i++) {
        if((i % 2) == 0) {
            testSet1.insert(i);
        }
        else {
            testSet2.insert(i);
        }
    }
    int elementOfSum = testSet2.getSize() + testSet1.getSize();
    SetArray testSet3;
    testSet3 = testSet1 + testSet2;
    assert(testSet3.getSize() == elementOfSum );
    for(int j = 0; j <= 10; j++) {
        assert(testSet3.isInSet(j));
    }
    std::cout<<"\033[1;32m[OK]\033[0m Test metody:'operator+' przebiegl pomyslnie"<<std::endl;
}

void test_DifferenceOperator() {
    SetArray testSet1;
    SetArray testSet2;
    for(int i = 0; i<10; i++) {
        if((i % 2) == 0) {
            testSet2.insert(i);
        }
            testSet1.insert(i);
    }
    SetArray testSet3;
    testSet3 = testSet1 - testSet2;
    assert(testSet3.getSize() == testSet2.getSize() );
    int i = 1;
    while(i < testSet2.getSize()) {
        assert(testSet3.isInSet(i));
        i = i + 2;
    }
    std::cout<<"\033[1;32m[OK]\033[0m Test metody:'operator-' przebiegl pomyslnie"<<std::endl;
}

void test_CommonPartOperator() {
    SetArray testSet1;
    SetArray testSet2;
    SetArray testSet3;

    for(int i = 0; i < 3; i++) {
        testSet1.insert(i);
        testSet2.insert(i+2);
    }
    testSet3 = testSet1 * testSet2;
    assert(testSet3.getSize() == 1);
    assert(testSet3.isInSet(2));
    int counter = 0;
    for(int i = 0; i < testSet2.getSize(); i++) {
        if(testSet3.isInSet(i) && testSet1.isInSet(i) && testSet2.isInSet(i)) {
            counter++;
        }
    }
    assert(counter == testSet3.getSize());
    std::cout<<"\033[1;32m[OK]\033[0m Test metody:'operator*' przebiegl pomyslnie"<<std::endl;
}

void test_isEqualOperator() {
    SetArray testSet1;
    SetArray testSet2;
    for(int i = 0; i<=10; i++) {
        if((i % 2) == 0) {
            testSet2.insert(i);
        }
        testSet1.insert(i);
    }
    assert(!(testSet1 == testSet2));
    testSet1.clearSet();
    testSet2.clearSet();
    assert(testSet1 == testSet2);
    std::cout<<"\033[1;32m[OK]\033[0m Test metody:'operator==' przebiegl pomyslnie"<<std::endl;
}

void test_isConcludingOperator() {
    SetArray testSet1;
    SetArray testSet2;
    SetArray testSet3;
    testSet3.insert(1);
    assert(testSet1<=testSet3);
    assert(testSet2 <= testSet1);
    for(int i = 0; i<=10; i++) {
        if((i % 2) == 0) {
            testSet2.insert(i);
        }
        testSet1.insert(i);
    }
    assert(testSet2 <= testSet1);
    testSet2.insert(99);
    assert(!(testSet2 <= testSet1));
    std::cout<<"\033[1;32m[OK]\033[0m Test metody:'operator<=' przebiegl pomyslnie"<<std::endl;
}


#endif //ZESTAWY_TESTSETARRAY_H
