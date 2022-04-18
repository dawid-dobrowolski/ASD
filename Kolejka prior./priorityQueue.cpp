#include <iostream>
#include <cassert>
#include "priorityQueue.h"

void test_push() {
    MyPriorityQueue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    assert(queue.top() == 3);
    std::cout << "\033[1;32m[OK]\033[0mTest metody:'push()'" << std::endl;
}
void test_empty() {
    MyPriorityQueue<int> queue;
    assert(queue.empty() == true);
    std::cout << "\033[1;32m[OK]\033[0mTest metody:'empty()'" << std::endl;
}
void test_size() {
    MyPriorityQueue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    assert(queue.size() == 3);
    std::cout << "\033[1;32m[OK]\033[0mTest metody:'size()'" << std::endl;
}
void test_pop() {
    MyPriorityQueue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.pop();
    assert(queue.top() == 2);
    std::cout << "\033[1;32m[OK]\033[0mTest metody:'pop()'" << std::endl;
}
void test_clear() {
    MyPriorityQueue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.clear();
    assert(queue.size() == 0);
    std::cout << "\033[1;32m[OK]\033[0mTest metody:'clear()'" << std::endl;
}
void test_copy_constructor() {
    MyPriorityQueue<int> queue1;
    queue1.push(1);
    queue1.push(2);
    queue1.push(3);
    queue1.push(4);

    MyPriorityQueue<int> queue2(queue1);
    for(int i = 0; i <= queue1.size(); i++) {
        assert(queue1.top() == queue2.top());
        queue1.pop();
        queue2.pop();
    }
    std::cout << "\033[1;32m[OK]\033[0mTest copy_constructor()'" << std::endl;
}

void test_move_assignment_operator() {
    MyPriorityQueue<int> queue1;
    queue1.push(1);
    queue1.push(2);
    queue1.push(3);
    queue1.push(4);

    MyPriorityQueue<int> queue2;
    MyPriorityQueue<int> queue3(queue1);

    queue2 = std::move(queue1);

    for(int i = 0; i <= queue1.size(); i++) {
        assert(queue3.top() == queue2.top());
        queue3.pop();
        queue2.pop();
    }
    std::cout << "\033[1;32m[OK]\033[0mTest move_assignment_operator'" << std::endl;
}
void test_copy_assignment_operator() {
    MyPriorityQueue<int> queue1;
    queue1.push(1);
    queue1.push(2);
    queue1.push(3);
    queue1.push(4);

    MyPriorityQueue<int> queue2;

    queue2 = queue1;

    for(int i = 0; i <= queue1.size(); i++) {
        assert(queue1.top() == queue2.top());
        queue1.pop();
        queue2.pop();
    }
    std::cout << "\033[1;32m[OK]\033[0mTest copy_assignment_operator'" << std::endl;
}



int main(void) {
    test_push();
    test_size();
    test_empty();
    test_pop();
    test_copy_constructor();
    test_copy_assignment_operator();
    test_move_assignment_operator();
    test_clear();
    return 0;
}
