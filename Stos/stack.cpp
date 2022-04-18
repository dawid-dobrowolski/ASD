#include <iostream>
#include <string>
#include <vector>
#include "stack.h"

int main() {
    MyStack<std::string> stackONP;
    std::vector<std::string> input {"2","3","+","6","*"};
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == "+" || input[i] == "-" || input[i] == "/" || input[i] == "*") {
            std::string a = stackONP.top();
            stackONP.pop();
            std::string b = stackONP.top();
            stackONP.pop();
            int aInt = stoi(a);
            int bInt = stoi(b);
            if (input[i] == "+") {
                int result = bInt + aInt;
                a = std::to_string(result);
                stackONP.push(a);
            }

            if (input[i] == "-") {
                int result = bInt - aInt;
                a = std::to_string(result);
                stackONP.push(a);
            }

            if (input[i] == "*") {
                int result = bInt * aInt;
                a = std::to_string(result);
                stackONP.push(a);

            }

            if (input[i] == "/") {
                if (aInt == 0) throw std::invalid_argument("Nie dzielimy [przez zero");
                int result = bInt / aInt;
                a = std::to_string(result);
                stackONP.push(a);
            }
        }
        else {
            stackONP.push(input[i]);
        }
    }
    std::cout<<"Wynik:"<<stackONP.top()<<std::endl;
    return 0;
}