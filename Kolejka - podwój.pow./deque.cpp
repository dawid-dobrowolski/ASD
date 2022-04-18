#include <iostream>
#include "deque.h"

void test_empty() {
    MyDeque<int> deque;
    assert(deque.empty() == 1);
    std::cout << "\033[1;32m[OK]\033[0mTest metody:'empty()'" << std::endl;

}

void test_full() {
    MyDeque<int> deque;
    for (int i = 0; i < 10; i++) {
        int value = rand() % 10;
        deque.push_back(value);
    }
    assert(deque.full() == 1);
    std::cout << "\033[1;32m[OK]\033[0mTest metody:'full()'" << std::endl;

}

void test_size() {
    MyDeque<int> deque;
    assert(deque.size() == 0);
    std::cout << "\033[1;32m[OK]\033[0mTest metody:'size()'" << std::endl;

}

void test_max_size() {
    MyDeque<int> deque;
    assert(deque.max_size() == 10);
    std::cout << "\033[1;32m[OK]\033[0mTest metody:'size()'" << std::endl;

}

void test_push_front() {
    MyDeque<int> deque;
    int value = rand() % 10;
    deque.push_front(value);
    assert(deque.front() == value);
    std::cout << "\033[1;32m[OK]\033[0mTest metody:'push_front()'" << std::endl;

}

void test_push_back() {
    MyDeque<int> deque;
    int value = rand() % 10;
    deque.push_front(value);
    assert(deque.back() == value);
    std::cout << "\033[1;32m[OK]\033[0mTest metody:'push_back()'" << std::endl;

}

void test_clear() {
    MyDeque<int> deque;
    for (int i = 0; i < 5; i++) {
        int value = rand() % 10;
        deque.push_back(value);
    }

    deque.clear();
    assert(deque.size() == 0);
    std::cout << "\033[1;32m[OK]\033[0mTest metody:'clear()'" << std::endl;
}

void test_front() {
    MyDeque<int> deque;
    int value = rand() % 10;
    deque.push_front(value);
    assert(deque.front() == value);
    std::cout << "\033[1;32m[OK]\033[0mTest metody:'front()'" << std::endl;

}

void test_back() {
    MyDeque<int> deque;
    int value = rand() % 10;
    deque.push_front(value);
    assert(deque.back() == value);
    std::cout << "\033[1;32m[OK]\033[0mTest metody:'back()'" << std::endl;

}

void test_pop_front() {
    int temp[2];
    MyDeque<int> deque;
    for (int i = 0; i < 2; i++) {
        int value = rand() % 10;
        temp[i] = value;
        deque.push_front(value);
    }
    for (int i = 2; i > 1; i--) {
        deque.pop_front();
        assert(deque.front() == temp[i - 2]);
    }
    std::cout << "\033[1;32m[OK]\033[0mTest metody:'pop_front()'" << std::endl;

}

void test_pop_back() {
    int temp[3];
    MyDeque<int> deque;
    for (int i = 0; i < 3; i++) {
        int value = rand() % 10;
        temp[i] = value;
        deque.push_back(value);
    }
    for (int i = 3; i > 1; i--) {
        deque.pop_back();
        assert(deque.back() == temp[i - 2]);
    }
    std::cout << "\033[1;32m[OK]\033[0mTest metody:'pop_back()'" << std::endl;

}

int main(void) {
    test_empty();
    test_full();
    test_size();
    test_max_size();
    test_push_back();
    test_push_front();
    test_front();
    test_back();
    test_pop_front();
    test_pop_back();
    test_clear();
    std::cout << std::endl << "\033[1;32mWszystkie testy ukonczone powodzeniem\033[0m" << std::endl;
}
