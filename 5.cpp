#include <iostream>

#include <string>

 

int main() {

    std::string name;  // объявляем переменную name

    std::cout << "What is your name?\n";

    std::cin >> name;  // считываем её значение с клавиатуры

    std::cout << "Hello, " << name << "!\n";

}