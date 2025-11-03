#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <fstream>

struct Student {
    char gender; //male->'y' female->'x'
    int age;
    int id;
    std::string name;
};

struct Student2 {
    char gender; //male->'y' female->'x'
};

// #pragma pack(1) // 1 字节对齐
struct Student3 {
    char x;
    int y;
};

struct Student4 {
};

struct Student5 {
    char x;
    int y;
    char z;
};

enum Weekday {
    Monday = 3, // 默认值为 0
    Tuesday = 5, // 默认值为 1
    Wednesday, // 默认值为 2
    Thursday, // 默认值为 3
    Friday, // 默认值为 4
    Saturday, // 默认值为 5
    Sunday // 默认值为 6
};

union Data {
    int intValue;
    float floatValue;
    char stringValue[20];
};

union Data2 {
    char x;
    int y;
};

int add(int a, int b) {
    if (INT_MAX - a < b) {
        return a + b;
    } else {
        throw "throw";
    }
}

// 定义一个函数，计算两个整数的乘积
int multiply(int a, int b) {
    int product = a * b;
    return product;
}

// 定义一个函数，打印包含问候语的消息
void greet(std::string name) {
    std::cout << "你好, " << name << "!" << std::endl;
}

struct MyStruct {
    int x;
    char y;
};

void function1(MyStruct m1) {
    m1.x = 10;
    m1.y = 'b';
}

void function2(MyStruct &m1) {
    m1.x = 10;
    m1.y = 'b';
}

void increment(int &num) {
    num++; // 对形参 num 的修改会影响到实参
}

void printLength(const std::string &str) {
    std::cout << "字符串的长度是: " << str.length() << std::endl;
    // str[0] = 'A'; // 错误！不能修改常量引用
}

void fun1(int *ptr) {
    if (ptr != nullptr) {
        *ptr = 100;
    }
}

int main() {
    Student s1 = {'x', 19, 3, "Lucy"};
    s1 = {.gender = 'y'};
    s1.id = 2;
    s1.age = 18;
    s1.name = "John";

    std::cout << s1.id << std::endl;
    std::cout << s1.name << std::endl;
    std::cout << s1.gender << std::endl;
    std::cout << s1.age << std::endl;

    Student2 s2 = {'y'};
    std::cout << sizeof s2 << std::endl;

    Student3 s3 = {100};
    std::cout << sizeof s3 << std::endl;

    Student4 s4;
    std::cout << sizeof s4 << std::endl;

    // 默认对齐（通常为 4 或 8 字节）
    Student5 s5;
    std::cout << sizeof s5 << std::endl;

    std::cout << Monday << std::endl;
    std::cout << Tuesday << std::endl;
    std::cout << Wednesday << std::endl;
    std::cout << Thursday << std::endl;
    std::cout << Friday << std::endl;

    Weekday today = Wednesday;
    // 可以直接使用枚举常量
    if (today == Wednesday) {
        std::cout << "今天星期三，要努力学习！" << std::endl;
    }
    // 枚举常量本质上是整型，可以进行比较和运算
    if (today > Friday) {
        std::cout << "今天是周末！" << std::endl;
    }
    // 也可以显式获取枚举常量的值
    std::cout << "Wednesday 的值是: " << Wednesday << std::endl; // 输出 2

    Data data;
    std::cout << sizeof data << std::endl;
    // 存储整数值
    data.intValue = 100;
    std::cout << "intValue: " << data.intValue << std::endl;
    // 存储浮点数值，此时 intValue 的值不再有效
    data.floatValue = 3.14f;
    std::cout << "floatValue: " << data.floatValue << std::endl;
    // 此时访问 data.intValue 将会得到未定义的值
    // 存储字符串值，之前的值都不再有效
    strcpy(data.stringValue, "Hello");
    std::cout << "stringValue: " << data.stringValue << std::endl;
    std::cout << "intValue: " << data.intValue << std::endl;
    std::cout << "floatValue: " << data.floatValue << std::endl;

    Data2 data2;
    data2.y = 97;
    std::cout << data2.x << std::endl;

    std::cout << add(3, 4) << std::endl;

    int num1 = 5;
    int num2 = 10;
    // 调用 multiply 函数
    int result = multiply(num1, num2);
    std::cout << num1 << " 乘以 " << num2 << " 的结果是: " << result << std::endl;
    // 调用 greet 函数
    greet("小明");

    MyStruct my = {9, 'a'};
    function1(my);
    std::cout << my.x << my.y << std::endl;
    function2(my);
    std::cout << my.x << my.y << std::endl;

    int count = 5;
    increment(count);
    std::cout << "Count 的值是: " << count << std::endl; // 输出 6

    std::string message = "Hello";
    printLength(message);

    fun1(nullptr);

    return 0;
}
