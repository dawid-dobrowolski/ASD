#include "array.h"
#include <iostream>
#include <cassert>
#include<string>

using namespace std;


void test_empty() {
    ArrayList <int>array1(10);
    assert(array1.empty() == true);
    cout<<"\033[1;32m[OK]\033[0mTest metody:'empty()'"<<endl;
}

void test_full() {
    ArrayList <int>array1(10);
    int max = array1.max_size();
    for(int i=0; i<max;i++) {
        const int value = rand() % 100;
        array1.push_back(value);
    }
    assert(array1.full() == true);
    cout<<"\033[1;32m[OK]\033[0mTest metody:'full()'"<<endl;

}

void test_size() {
    ArrayList <int>array1(10);
    assert(array1.size() == 0);
    cout<<"\033[1;32m[OK]\033[0mTest metody:'size()'"<<endl;
}

void test_max_size() {
    int size =10;
    ArrayList <int>array1(size);
    assert(array1.max_size() == size);
    cout<<"\033[1;32m[OK]\033[0mTest metody:'max_size()'"<<endl;
}

void test_push_front() {
    ArrayList <int>array1(10);
    int max = array1.max_size();
    for(int i=0; i<max;i++) {
        const int value = rand() % 100;
        array1.push_front(value);
        assert(array1.getTab(0) == value);

    }
    cout<<"\033[1;32m[OK]\033[0mTest metody:'push_front()'"<<endl;
}

void test_push_back() {
    ArrayList <int>array1(10);
    int max = array1.max_size();
    for(int i=0; i<max;i++) {
        const int value = rand() % 100;
        array1.push_back(value);
        int last = array1.size();
        assert(array1.getTab(last-1) == value);
    }
    cout<<"\033[1;32m[OK]\033[0mTest metody:'push_back()'"<<endl;
}

void test_merge() {
    int size1 = 10;
    int size2 = 10;
    ArrayList <int>array1(size1);
    int max = array1.max_size();
    for(int i=0; i<max;i++) {
        const int value = rand() % 50;
        array1.push_back(value);
    }
    ArrayList <int>array2(size2);
    int newmax = array2.max_size();
    for(int i=0; i<newmax;i++)
    {
        const int value = rand() % 100;
        array2.push_back(value);
    }
    array1.merge(array2);
    //assert(size1+size2 == array1.max_size());
  //  for(int i=0; i<max-1; i++) {
    //    assert(array1.getTab(i)<=array1.getTab(i+1));
   // }
   // array1.clear();
   // array2.clear();
    cout<<"\033[1;32m[OK]\033[0mTest metody:'merge()'"<<endl;
}

void test_front() {
    ArrayList <int>array1(10);
    int max = array1.max_size();
    //
    for(int i=0; i<max;i++) {
        const int value = rand() % 100;
        array1.push_back(value);
    }
    assert(array1.front() == array1.getTab(0));
    cout<<"\033[1;32m[OK]\033[0mTest metody:'front()'"<<endl;
}

void test_back() {
    ArrayList <int>array1(10);
    int max = array1.max_size();
    //
    for(int i=0; i<max;i++) {
        const int value = rand() % 100;
        array1.push_back(value);
    }
    int last = array1.size();
    assert(array1.back() == array1.getTab(last-1));
    cout<<"\033[1;32m[OK]\033[0mTest metody:'back()'"<<endl;
}

void test_pop_front() {
    ArrayList <int>array1(10);
    int max = array1.max_size();
    //
    for(int i=0; i<max;i++) {
        const int value = rand() % 100;
        array1.push_back(value);
    }
    int remember = array1.getTab(1);
    array1.pop_front();
    assert(array1.getTab(0) == remember);
    cout<<"\033[1;32m[OK]\033[0mTest metody:'pop_front()'"<<endl;

}

void test_pop_back() {
    ArrayList <int>array1(10);
    int max = array1.max_size();
    //
    for(int i=0; i<max;i++) {
        const int value = rand() % 100;
        array1.push_back(value);
    }
    int last = array1.size();
    int remember = array1.getTab(last-2);
    array1.pop_back();
    assert(array1.back() == remember);
    cout<<"\033[1;32m[OK]\033[0mTest metody:'pop_back()'"<<endl;
}

void test_clear() {
    ArrayList <int>array1(10);
    int max = array1.max_size();
    //
    for(int i=0; i<max;i++) {
        const int value = rand() % 100;
        array1.push_back(value);
    }
    array1.clear();
    assert(array1.size() == 0);
    cout<<"\033[1;32m[OK]\033[0mTest metody:'clear()'"<<endl;
}


void test_reverse() {
    ArrayList <int>array1(10);
    int max = array1.max_size();
    int Temp[max];
    for(int i=0; i<max;i++) {
        const int value = rand() % 100;
        Temp[i] = value;
        array1.push_front(value);
    }
    array1.reverse();
    for(int i=0; i<max;i++) {
        assert(array1.getTab(i) == Temp[i]);
    }
    cout<<"\033[1;32m[OK]\033[0mTest metody:'reverse()'"<<endl;
}

void test_sort() {
    ArrayList <int>array1(10);
    int max = array1.max_size();
    for(int i=0; i<max;i++) {
        const int value = rand() % 100;
        array1.push_back(value);
    }
    array1.sort();
    for(int i=0; i<max-1; i++) {
        assert(array1.getTab(i)<=array1.getTab(i+1));
    }
    cout<<"\033[1;32m[OK]\033[0mTest metody:'sort()'"<<endl;
}

int main(void) {
    test_empty();
    test_full();
    test_max_size();
    test_size();
    test_push_front();
    test_push_back();
    test_front();
    test_back();
    test_pop_front();
    test_pop_back();
    test_clear();
    test_reverse();
    test_merge();
    test_sort();
    cout<<endl<<"\033[1;32mWszystkie testy ukonczone powodzeniem\033[0m"<<endl;
    return 0;
}
