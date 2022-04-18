#include <iostream>
#include <cassert>
#include "queue.h"

void test_empty() {
    MyQueue<int> queue;
    assert(queue.empty() == 1);
    std::cout << "\033[1;32m[OK]\033[0mTest metody:'empty()'" << std::endl;

}

void test_full() {
    MyQueue<int> queue;
    for (int i = 0; i < 10; i++) {
        int value = rand() % 10;
        queue.push(value);
    }
    assert(queue.full() == 1);
    std::cout << "\033[1;32m[OK]\033[0mTest metody:'full()'" << std::endl;

}

void test_size() {
    MyQueue<int> queue;
    assert(queue.size() == 0);
    std::cout << "\033[1;32m[OK]\033[0mTest metody:'size()'" << std::endl;

}

void test_max_size() {
    MyQueue<int> queue;
    assert(queue.max_size() == 10);
    std::cout << "\033[1;32m[OK]\033[0mTest metody:'size()'" << std::endl;

}

void test_push() {
    MyQueue<int> queue;
    int value = rand() % 10;
    queue.push(value);
    assert(queue.back() == value);
    std::cout << "\033[1;32m[OK]\033[0mTest metody:'push()'" << std::endl;

}

void test_clear() {
    MyQueue<int> queue;
    for (int i = 0; i < 5; i++) {
        int value = rand() % 10;
        queue.push(value);
    }

    queue.clear();
    assert(queue.size() == 0);
    std::cout << "\033[1;32m[OK]\033[0mTest metody:'clear()'" << std::endl;
}

void test_front() {
    MyQueue<int> queue;
    int value = rand() % 10;
    queue.push(value);
    assert(queue.front() == value);
    std::cout << "\033[1;32m[OK]\033[0mTest metody:'front()'" << std::endl;

}

void test_back() {
    MyQueue<int> queue;
    int value = rand() % 10;
    queue.push(value);
    assert(queue.back() == value);
    std::cout << "\033[1;32m[OK]\033[0mTest metody:'back()'" << std::endl;

}

void test_pop() {
    int temp[2];
    MyQueue<int> queue;
    for (int i = 0; i < 2; i++) {
        int value = rand() % 10;
        temp[i] = value;
        queue.push(value);
    }
    for (int i = 2; i > 1; i--) {
        queue.pop();
        assert(queue.front() == temp[i - 1]);
    }
    std::cout << "\033[1;32m[OK]\033[0mTest metody:'pop()'" << std::endl;

}


int main(void) {
    test_empty();
    test_full();
    test_size();
    test_max_size();
    test_push();
    test_front();
    test_back();
    test_pop();
    test_clear();
    std::cout << std::endl << "\033[1;32mWszystkie testy ukonczone powodzeniem\033[0m" << std::endl;
}
