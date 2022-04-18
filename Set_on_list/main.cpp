#include "testSetList.h"
int main(void) {
     std::cout << std::boolalpha;

    setList X = setList();
    X.insert(2);
    X.insert(4);
    X.insert(5);
    X.insert(9);
    X.insert(6);
    X.insert(9);
    X.insert(7);

    X.printSet();
    std::cout << "set size: " << X.getSize()<<"\n";

    X.withdraw(4);
    X.printSet();
    std::cout << "set size: " << X.getSize()<<"\n";
   
    setList Y = setList();
    Y.insert(1); Y.insert(2); Y.insert(8); Y.insert(1000);

    std::cout << "\n\nSet X ";
    X.printSet();
    std::cout << "Set Y  ";
    Y.printSet();

    setList Z = X + Y;
    std::cout << "suma X+Y   ";
    Z.printSet();

    setList Z1 = X * Y;
    std::cout << "czesc wspolna X * Y   ";
    Z1.printSet();

    setList Z2 = X - Y;
    std::cout << "roznica X - Y   ";
    Z2.printSet();

    std::cout << "\n\n\nTest porownywania/zawierania zbiorow\n";
    setList C = setList();
    C.insert(1); C.insert(2); C.insert(4);
    setList D = setList();
    D.insert(1); D.insert(2); D.insert(4); D.insert(7);

    std::cout << (bool)(C <= D) << "\n";
    std::cout << (bool)(D <= C) << "\n";
    std::cout << (bool)(C == C) << "\n";
    return 0;
}
