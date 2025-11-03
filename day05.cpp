#include <iostream>
#include <exception>
#include <fstream>
#include "day05/other.hpp"

bool function1() {
    std::cout << "111111111111" << std::endl;
    return true;
}

bool function2() {
    std::cout << "22222222222" << std::endl;
}

struct MyStruct {
    int x;
};

void function3(MyStruct *ptr) {
    (*ptr).x = 100;
    ptr->x = 100;
}

#define PI 3.1415926

double circle_area(double radius) {
    return PI * radius * radius;
}

#define SQUARE(x) ((x) * (x)) // 注意加括号，防止优先级问题

void function1(int arr[4]) {
    std::cout << typeid(arr).name() << std::endl;
    std::cout << sizeof(arr) << std::endl;
}

void function(int arr[4], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << std::endl;
    }
}

int main() {
    int a = 1;
    int b = 2;
    // std::cout << add(a, b) << std::endl;
    std::cout << "**************" << std::endl;

    bool a1 = -100;
    std::cout << a1 << std::endl;
    std::cout << "**************" << std::endl;

    // a = "a";
    a = 'a';
    std::cout << a << std::endl;

    int i = 9;
    double j = (double) i;
    double k = static_cast<double>(i);

    std::cout << (function1() || function2()) << std::endl;

    a = 5;
    b = ++a; // a 变为 6，b 变为 6
    int c = a++; // c 变为 6，a 变为 7
    std::cout << b << std::endl;
    std::cout << c << std::endl;

    a = 9, b = 6;
    int max_val = (a > b) ? a : b;
    std::cout << max_val << std::endl;

    // 整个表达式的值是 30
    std::cout << (i = 10, j = 20, i + j) << std::endl;

    std::cout << circle_area(9) << std::endl;

    a = 2, b = 3;
    std::cout << SQUARE(4) << std::endl;
    std::cout << SQUARE(5 + 2) << std::endl;
    std::cout << SQUARE(a-1 + b-1) << std::endl;

    int myarr[4] = {1, 3, 5, 7};
    int *ptr1 = &myarr[0];
    ptr1 += 2;
    std::cout << *ptr1 << std::endl;
    ptr1 -= 1;
    std::cout << *ptr1 << std::endl;


    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr; // 指向 arr[0]

    std::cout << "Initial pointer: " << ptr << ", value: " << *ptr << std::endl;

    ptr++; // 移动到下一个元素
    std::cout << "Pointer after increment: " << ptr << ", value: " << *ptr << std::endl;

    ptr += 2; // 移动两个元素
    std::cout << "Pointer after adding 2: " << ptr << ", value: " << *ptr << std::endl;

    int *endPtr = &arr[4];
    std::cout << "Distance to the end: " << endPtr - ptr << std::endl;

    if (ptr < endPtr) {
        std::cout << "ptr is before endPtr" << std::endl;
    }

    int myarr2[4] = {1, 2, 3, 4};
    int *ptr3 = &myarr2[0];
    int *ptr4 = myarr2;

    int (*ptr2)[4] = &myarr2;
    std::cout << *ptr2[0] << std::endl;

    std::cout << "**************" << std::endl;
    int myarr3[4] = {1, 2, 3, 4};
    std::cout << sizeof(myarr3) << std::endl;
    std::cout << "**************" << std::endl;

    function1(myarr3);
    function(myarr3, sizeof(myarr3) / sizeof(int));

    int myarr4[2][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}};
    std::cout << myarr4[1][2] << std::endl;

    return 0;
#include "day05/other.txt"
