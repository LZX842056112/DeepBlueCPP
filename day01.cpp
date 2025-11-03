#include <iostream>
#include <stdio.h>
#include <string>
#include <exception>
#include <iomanip>
#include <fstream>

void f1() {
}

int main() {
    printf("Hello World!\n");
    std::cout << "Hello World!\n";
    std::cout << "Hello World!" << std::endl;
    std::cout << "**************************" << std::endl;

    int a = 1;
    printf("%d\n", a);
    std::cout << sizeof(a) << std::endl;
    std::cout << "**************************" << std::endl;

    char b = 'a';
    std::cout << sizeof(b) << std::endl;
    std::cout << "**************************" << std::endl;

    float c = 1.1;
    std::cout << sizeof(c) << std::endl;
    std::cout << "**************************" << std::endl;

    double d = 1.1;
    std::cout << sizeof(d) << std::endl;
    std::cout << "**************************" << std::endl;

    bool e = true;
    std::cout << sizeof(e) << std::endl;
    std::cout << "**************************" << std::endl;

    int a1 = 6;
    int b1 = 0;
    std::cout << a1 / b1 << std::endl;

    short int a2 = 2;
    std::cout << sizeof a2 << std::endl;

    long int b2 = 2;
    std::cout << sizeof b2 << std::endl;

    long long int c1 = 2;
    std::cout << sizeof c1 << std::endl;

    return 0;
}
