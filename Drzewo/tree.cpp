#include <iostream>
#include "tree.h"

void test_calc_leafs() {
    RandomBinaryTree<int> simplyTree2;
    simplyTree2.insert(4);
    simplyTree2.insert(2);
    simplyTree2.insert(7);
    simplyTree2.insert(3);
    simplyTree2.insert(8);
    int liscie;
    liscie = simplyTree2.calc_leafs();
    std::cout<<"Ilosc lisci : "<<liscie<<std::endl;
    assert(liscie == 2);
    std::cout<<"\033[1;32m[OK]\033[0mTest metody:'calc_leafs_iter()'"<<std::endl;
}

void test_calc_leafs_iter() {
        RandomBinaryTree<int> simplyTree;
        simplyTree.insert(5);
        simplyTree.insert(2);
        simplyTree.insert(7);
        simplyTree.insert(3);
        simplyTree.insert(8);
        simplyTree.insert(9);
        simplyTree.insert(1);
        simplyTree.insert(6);
        simplyTree.insert(5);
        simplyTree.insert(3);
        simplyTree.insert(0);
        simplyTree.insert(2);
        int liscie = simplyTree.calc_leafs_iter();
        std::cout<<"Ilosc lisci : "<<liscie<<std::endl;
        assert(liscie == 5);
    std::cout<<"\033[1;32m[OK]\033[0mTest metody:'calc_leafs_iter()'"<<std::endl;
};
int main() {
    test_calc_leafs();
    test_calc_leafs_iter();
    std::cout<<"\033[1;32mWszystkie testy ukonczone powodzeniem\033[0m"<<std::endl;
    return 0;
}
