//
// Created by dawiddobrowolski on 06.01.2022.
//

#ifndef ZESTAW10_TREE_H
#define ZESTAW10_TREE_H
#include <iostream>
#include <queue>
#include <cassert>

template <typename T>
struct BSTNode {
// the default access mode and default inheritance mode are public
    T value;
    BSTNode *left, *right;
    //BSTNode *parent;   // używane w pewnych zastosowaniach
    // kostruktor domyślny
    BSTNode() : value(T()), left(nullptr), right(nullptr) {}
    BSTNode(const T& item, BSTNode *le=nullptr, BSTNode *ri=nullptr) :
            value(item), left(le), right(ri) {} // konstruktor
    ~BSTNode() {} // destruktor
};

template <typename T>
class RandomBinaryTree {
    BSTNode<T> *root;
public:
    RandomBinaryTree() : root(nullptr) {} // konstruktor domyślny
    ~RandomBinaryTree() { clear(); } // trzeba wyczyścić
    bool empty() const { return root == nullptr; }
    T& top() { assert(root != nullptr); return root->value; } // podgląd korzenia
    void insert(const T& item) { root = insert(root, item); }
    //void remove(const T& item); // na razie nie usuwamy elementów
    // Szukając element dostajemy wskaźnik do elementu lub nullptr.
    T* search(const T& item) const {
        auto ptr = search(root, item);
        return ((ptr == nullptr) ? nullptr : &(ptr->value));
    }
    void preorder() { preorder(root); }
    void inorder() { inorder(root); }
    void postorder() { postorder(root); }
    void clear() { clear(root); root = nullptr; }
    void display() { display(root, 0); }
    int calc_leafs() { return calc_leafs(root); }

    int calc_leafs(BSTNode<T> *node) {
        if(node == nullptr) {
            return 0;
        }

         int nLeft = calc_leafs(node->left);
        int nRight = calc_leafs(node->right);

        if(nLeft == 0 && nRight ==0) {
            return 1;
        }
        else {
            return nLeft + nRight;
        }
    }

    int calc_leafs_iter() {
        if( root == nullptr) {
            return 0;
        }
        std::queue<BSTNode<T> *> Q;
        int n_leafs = 0;
        Q.push(root);
        while(!Q.empty()) {
            BSTNode<T> *node = Q.front();
            Q.pop();
            if(node->left == nullptr && node->right == nullptr) {
                n_leafs++;
            }
            if(node->left != nullptr) {
                Q.push(node->left);
            }
            if(node->right != nullptr) {
                Q.push(node->right);
            }
        }
        return n_leafs;
    }

    // Metody bezpośrednio odwołujące się do node.
    // Mogą działać na poddrzewie.
    void clear(BSTNode<T> *node) {
        if (node == nullptr) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }
    BSTNode<T> * insert(BSTNode<T> *node, const T& item) {
        if (node == nullptr) {
            return new BSTNode<T>(item);
        }
        if (std::rand() % 2) { // można lepiej
            node->left = insert(node->left, item);
        } else {
            node->right = insert(node->right, item);
        }
        return node;
    } // zwraca nowy korzeń
    BSTNode<T> * search(BSTNode<T> *node, const T& item){if (node == nullptr || node->value == item) {
            return node;
        }
        T* ptr;
        ptr = search(node->left, item);
        if (ptr == nullptr) {
            ptr = search(node->right, item);
        }
        return ptr;
    };
    void preorder(BSTNode<T> *node){
        if (node == nullptr) return;
        visit(node);
        preorder(node->left);
        preorder(node->right);
    }
    void inorder(BSTNode<T> *node) {
        if (node == nullptr) return;
        inorder(node->left);
        visit(node);
        inorder(node->right);
    }
    void postorder(BSTNode<T> *node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        visit(node);
    }
    void display(BSTNode<T> *node, int level) {
        if (node == nullptr) return;
        display(node->right, level + 1);
        std::cout << std::string(3 * level, ' ') << node->value << std::endl;
        display(node->left, level + 1);
    }
    virtual void visit(BSTNode<T> *node) {
        assert(node != nullptr);
        std::cout << "visiting " << node->value << std::endl;
    }
};

#endif //ZESTAW10_TREE_H
