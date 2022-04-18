//
// Created by dawiddobrowolski on 04.12.2021.
//

#ifndef ZESTAW7V2_STACK_H
#define ZESTAW7V2_STACK_H
#include <vector>
// Interfejs stosu na bazie kontenera std::vector.
template <typename T>
class MyStack {
    std::vector<T> lst;
public:
    MyStack(int s=10) { lst.reserve(s); } // default constructor
    ~MyStack() { lst.clear(); }
    MyStack(const MyStack& other); // copy constructor
    MyStack(MyStack&& other); // move constructor
    MyStack& operator=(const MyStack& other); // copy assignment operator, return *this
    MyStack& operator=(MyStack&& other); // move assignment operator, return *this
    bool empty() const { return lst.empty(); } // checks if the container has no elements
    bool full() const { return lst.size() == lst.capacity(); }
    int size() const { return lst.size(); }
    int max_size() const { return lst.capacity(); }
    void push(const T& item) { lst.push_back(item); }
    void push(T&& item) { lst.push_back(std::move(item)); }
    T& top() { return lst.back(); } // zwraca koniec, nie usuwa
    void pop() { lst.pop_back(); } // usuwa koniec
    void clear() { lst.clear(); }
    void display();
};
#endif //ZESTAW7V2_STACK_H
