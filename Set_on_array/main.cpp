#include "testSetArray.h"
#include "setArray.h"
int main(void) {
       std::cout << "Set testy\n***********************\n";
   
    SetArray X= SetArray();
    std::cout << X.isInSet(10) <<"\n";   
    X.insert(10);
    std::cout << X.isInSet(10) << "\n";  

    X.insert(50); X.insert(11); X.insert(11); X.insert(2); X.insert(3);
    std::cout << "set size  "<<X.getSize();

    std::cout << "\nSet X    ";
    X.printSet();

    SetArray Y = SetArray();
    Y.insert(1); Y.insert(2); Y.insert(5);
    std::cout << "Set Y    ";
    Y.printSet();

    std::cout << "Sum of sets\n";
    SetArray Z = X + Y;
    std::cout << "Set Z    ";
    Z.printSet();

    std::cout << "Intersection of sets\n";
    SetArray Z1 = X * Y;
    std::cout << "Set Z1    ";
    Z1.printSet();

    std::cout << "Difference of sets\n";
    SetArray Z2 = X - Y;
    std::cout << "Set Z2    ";
    Z2.printSet();

    std::cout << "\n\nTest dodania zbyt duzej liczby\n";
    X.insert(111);



    std::cout << "\n\n\nTest porownywania/zawierania zbiorow\n";
    SetArray C = SetArray();
    C.insert(1); C.insert(2); C.insert(4);
    SetArray D = SetArray();
    D.insert(1); D.insert(2); D.insert(4); D.insert(7);

    
    std::cout << (bool)(C <= D)<<"\n";
    std::cout << (bool)(D <= C)<<"\n";
    std::cout << (bool)(C == C) << "\n";
}
