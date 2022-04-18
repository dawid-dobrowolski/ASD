// singlelist.h

#ifndef SINGLELIST_H
#define SINGLELIST_H

#include <iostream>
#include <cassert>

template <typename T>
struct SingleNode {
// the default access mode and default inheritance mode are public
    T value;
    SingleNode *next;
    SingleNode() : value(T()), next(nullptr) {} // konstruktor domyslny
    SingleNode(const T& item, SingleNode *ptr=nullptr) : value(item), next(ptr) {}
    ~SingleNode() {} // destruktor
};

template <typename T>
class SingleList {
    SingleNode<T> *head, *tail;
public:
    SingleList() : head(nullptr), tail(nullptr) {}

    ~SingleList() {
      for (SingleNode<T> *node; !empty(); ) {
          node = head->next; // zapamietujemy
          delete head;
          head = node; // kopiowanie wskaznika
      }
    } // tu trzeba wyczyscic wezly

    SingleList(const SingleList& other) {

        head =nullptr;
        tail = nullptr;
        SingleNode<T> *node = other.head;
        while(node != nullptr) {
            push_back(node->value);
            node = node->next;
        }
    } // copy constructor
    // usage:   SingleList<int> list2(list1)

    SingleList& operator=(const SingleList& other) {
        if(head != other.head && tail != other.tail) {
            SingleList<T> list(other);
            std::swap(list.head, head);
            std::swap(list.tail, tail);
            return *this;
        }
        else return *this;
    } // copy assignment operator, return *this
    // usage:   list2 = list1;
    bool empty() const { return head == nullptr; }

    int size() const {
      int count;
      SingleNode<T> *node = head;
      if (head == nullptr)
      {
        return 0;
      }
      else {
      while (node != nullptr) { 
        count++;
        node = node->next;
         }
      return count;
        }
    } // O(n) bo trzeba policzyc

    void push_front(const T& item) {
        if (!empty()) {
            head = new SingleNode<T>(item, head);
        } else {
            head = tail = new SingleNode<T>(item);
        }
    } // O(1), L.push_front(item)

    void push_back(const T& item) {
        if (!empty()) {
            tail->next = new SingleNode<T>(item);
            tail = tail->next;
        } else {
            head = tail = new SingleNode<T>(item);
        }
    } // O(1), L.push_back(item)

    T& front() const { return head->value; } // zwraca poczatek, nie usuwa

    T& back() const { return tail->value; } // zwraca koniec, nie usuwa

    void pop_front() {
        assert(!empty());
        SingleNode<T> *node = head; // zapamietujemy
        if (head == tail) { // jeden wezel na liscie
            head = tail = nullptr;
        } else { // wiecej niz jeden wezel na liscie
            head = head->next;
        }
        delete node;
    } // usuwa poczatek O(1)

    void pop_back() {
        assert(!empty());
        SingleNode<T> *node = tail; // zapamietujemy
        if (head == tail) { // jeden wezel na liscie
            head = tail = nullptr;
        } else { // wiecej niz jeden wezel na liscie
            // Szukamy poprzednika ogona.
            SingleNode<T> *before=head;
            while (before->next != tail) {
                before = before->next;
            }
            tail = before;
            tail->next = nullptr;
        }
        delete node;
    } // usuwa koniec O(n)

    void clear() {
        SingleNode<T> *before=nullptr;
        SingleNode<T> *node = head;
        while(node != nullptr) {
            before = node;
            head = head->next;
            node = node->next;
            before = nullptr;
        }
    } // czyszczenie listy z elementow O(n)

    void display() {
        SingleNode<T> *node = head;

        while (node != nullptr){
            std::cout << node->value << " ";
            node = node->next;
        }
        std::cout << std::endl;
    } // O(n)
    
    T& position(int i) {
        SingleNode<T> *node = head;
        for(int j=0; j<i; j++)
        {
            node = node->next;
        }
      return node->value;
    }

    void reverse() {
        SingleNode<T> *before=nullptr;
        SingleNode<T> *node = head;
        SingleNode<T> *temp = nullptr;
        
        while (node != nullptr){
            temp = node->next;
            node->next = before;
            before = node;
            node = temp;
        }
        head = before;

    } // O(n)


};

#endif
