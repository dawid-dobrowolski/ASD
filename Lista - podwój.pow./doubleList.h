// doublelist.h

#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <iostream>     // deklaracje strumieni cout, cin, cerr
#include <cassert>    // assert()

template <typename T>
struct DoubleNode {
// the default access mode and default inheritance mode are public
    T value;
    DoubleNode *next, *prev;
    // konstruktor domyslny (niepotrzebny)
    DoubleNode() : value(T()), next(nullptr), prev(nullptr) {}
    DoubleNode(const T& item, DoubleNode *nptr=nullptr, DoubleNode *pptr=nullptr)
        : value(item), next(nptr), prev(pptr) {} // konstruktor
    ~DoubleNode() {} // destruktor
};


template <typename T>
class DoubleList {
    DoubleNode<T> *head, *tail;
public:
    DoubleList() : head(nullptr), tail(nullptr) {}
    ~DoubleList() {
        for (DoubleNode<T> *node; !empty(); ) {
          node = head->next; // zapamietujemy
          delete head;
          head = node; // kopiowanie wskaznika
        }
    } // tu trzeba wyczyscic wezly
    DoubleList(const DoubleList& other) {
        head = nullptr;
        tail = nullptr;
        DoubleNode<T> *node = other.head;
        while(node != nullptr) {
            push_back(node->value);
            node = node->next;
    }
    } // copy constructor
    // usage:   DoubleList<int> list2(list1);
    DoubleList& operator=(const DoubleList& other) {
        if(head != other.head && tail != other.tail) {
            DoubleList<T> list(other);
            std::swap(list.head, head);
            std::swap(list.tail, tail);
            return *this;
        }
        else return *this;
    } // copy assignment operator, return *this
    // usage:   list2 = list1;

    bool empty() const { return head == nullptr; }

    int size() const {
        int counter;
        DoubleNode<T> *node = head;
        if(head == nullptr) {
            return 0;
        }
        else {
        while(node != nullptr) {
            counter++;
            node = node->next;
        }
    }
        return counter;
    } // O(n) bo trzeba policzyc

    void push_front(const T& item) {
    if (!empty()) {
        head = new DoubleNode<T>(item, head);
        head->next->prev = head;
    } else {
        head = tail = new DoubleNode<T>(item);
    }
} // O(1)

    void push_back(const T& item) {
        if(!empty()) {
            DoubleNode<T> *node = new DoubleNode<T>(item);
            tail->next = node;
            node->prev = tail;
            tail = node;

        } else {
            head = tail = new DoubleNode<T>(item);
        }
    } // O(1)

    T& front() const { return head->value; } // zwraca poczatek, nie usuwa
    
    T& back() const { return tail->value; } // zwraca koniec, nie usuwa
    
    void pop_front() {
        assert(!empty());
        DoubleNode<T> *node = head;
        if(head == tail) {
            head = tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete node;
    } // usuwa poczatek O(1)
    
    void pop_back() {
        assert(!empty());
        DoubleNode<T> *node = tail;
        if(head == tail) {
            head = tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete node;
        
    } // usuwa koniec O(1)
    
    void clear() {
        assert(!empty());
        DoubleNode<T> *before=nullptr;
        DoubleNode<T> *node = head;
        while(node != nullptr) {
            before = node;
            head = head->next;
            node = node->next;
            before = nullptr;
    }
    } // czyszczenie listy z elementow O(n)
    
    T& position(int i) {
        DoubleNode<T> *node = head;
        for(int j=0; j<i; j++)
        {
            node = node->next;
        }
      return node->value;
    }

    void display() {
        DoubleNode<T> *node = head;

        while (node != nullptr){
            std::cout << node->value << " ";
            node = node->next;
        }
        std::cout << std::endl;
    } // O(n)
    void display_reversed() {
        DoubleNode<T> *node = tail;        
        while(node != nullptr) {
            std::cout<< node->value << " ";
            node = node->prev;
        }
        std::cout << std::endl;
    } // O(n)
    
};

#endif

// EOF