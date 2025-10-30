#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string>
#include <stdexcept> // 需要包含这个头文件来处理异常
#include <vector>
#include <list>
#include <deque>
#include <forward_list>
#include <array>
#include <utility>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <numeric>
#include <exception>
#include <iomanip>
#include <fstream>

// day01
// ******************************************************
// void f1(){}
// int main() {
//
//     printf("Hello World!\n");
//     std::cout << "Hello World!\n";
//     std::cout << "Hello World!" << std::endl;
//     std::cout << "**************************" << std::endl;
//
//     int a = 1;
//     printf("%d\n", a);
//     std::cout << sizeof(a) << std::endl;
//     std::cout << "**************************" << std::endl;
//
//     char b = 'a';
//     std::cout << sizeof(b) << std::endl;
//     std::cout << "**************************" << std::endl;
//
//     float c = 1.1;
//     std::cout << sizeof(c) << std::endl;
//     std::cout << "**************************" << std::endl;
//
//     double d = 1.1;
//     std::cout << sizeof(d) << std::endl;
//     std::cout << "**************************" << std::endl;
//
//     bool e = true;
//     std::cout << sizeof(e) << std::endl;
//     std::cout << "**************************" << std::endl;
//
//     int a = 6;
//     int b = 0;
//     std::cout << a / b << std::endl;
//
//     short int a = 2;
//     std::cout << sizeof a << std::endl;
//
//     long int b = 2;
//     std::cout << sizeof b << std::endl;
//
//     long long int c = 2;
//     std::cout << sizeof c << std::endl;
//
//     return 0;
// }

// day02
// ******************************************************
// int main() {
//     int a, b, c;
//     std::cin >> a >> b >> c;
//     if (a > b) {
//         std::cout << "a > b " << std::endl;
//     } else if (a == b) {
//         std::cout << "a == b " << std::endl;
//     } else {
//         std::cout << "a < b " << std::endl;
//     }
//     if (a < b && b > c) {
//     }
//
//     char ch;
//     std::cout << "请输入一个字符: ";
//     std::cin >> ch;
//     // 完整的 if-else 结构
//     if (ch >= 'A' && ch <= 'Z') {
//         std::cout << ch << " 是大写字母" << std::endl;
//     } else {
//         std::cout << ch << " 不是大写字母" << std::endl;
//     }
//     // 单行 if 语句（不推荐在复杂逻辑中使用，易读性较差）
//     if (ch >= 'a' && ch <= 'z') {
//         std::cout << ch << " 是小写字母" << std::endl;
//     }
//
//     int i = 1, sum = 0, j = 0;
//     while (i < 6) {
//         sum += i++;
//     }
//     std::cout << "1 到 5 的和为: " << sum << std::endl;
//     do {
//     } while (j++ < 6);
//     std::cout << "1 到 5 的和为: " << sum << std::endl;
//
//     int sum1 = 0, sum2 = 0;
//     for (int i = 1; i < 6; i++) {
//         sum1 += i;
//     }
//     int k = 0;
//     for (;;) {
//         sum2 += k++;
//         if (k > 5) {
//             break;
//         }
//     }
//     std::cout << "1 到 5 的和为: " << sum1 << std::endl;
//     std::cout << "1 到 5 的和为: " << sum2 << std::endl;
//
//     int factorial = 1;
//     for (int i = 1; i <= 10; i++) {
//         factorial *= i;
//     }
//     std::cout << "10 的阶乘为: " << factorial << std::endl;
//
//     int array[3] = {1, 2};
//     for (int i: array) {
//         std::cout << i << std::endl;
//     }
//     std::cout << array[4] << std::endl;
//     std::cout << array[10] << std::endl;
//     std::cout << sizeof array << std::endl;
//
//     int array2[0];
//     int array3[] = {};
//     std::cout << sizeof array3 << std::endl;
//     int numbers[5] = {10, 20, 30, 40, 50};
//     int sum3 = 0;
//     for (int number: numbers) {
//         sum3 += number;
//     }
//     // 将 sum 强制转换为 double 类型，以获得浮点数结果
//     double average = static_cast<double>(sum3) / 5;
//     std::cout << "数组元素的平均值为: " << average << std::endl;
//
//     char myarr_char[3] = {'a', 'b', 'c'};
//     std::cout << sizeof myarr_char << std::endl;
//     char mystr[] = {'a', 'b', 'c', '\0', 'd'};
//     std::cout << sizeof mystr << std::endl;
//     std::cout << mystr[2] << std::endl;
//     std::cout << mystr[3] << std::endl;
//     std::cout << mystr[4] << std::endl;
//     char *mystr1 = "abc";
//     if (strcmp(mystr, mystr1)) {
//         std::cout << "Different" << std::endl;
//     } else {
//         std::cout << "Same" << std::endl;
//     }
//
//     ;;;1;;;2;;;;;;;
//
//     return 0;
// }

// day03
// ******************************************************
// void add(int *a, int *b) {
//     (*a)++;
//     (*b)++;
// }
//
// void add(int &a, int &b) {
//     a++;
//     b++;
// }
//
// int main() {
//     char x = 'a';
//     std::cout << &x << std::endl;
//     printf("%p\n", &x);
//     // 指针的本质是一个变量，这个变量里面存储的是另一个变量的地址
//     char *pa = &x;
//     std::cout << typeid(pa).name() << std::endl;
//
//     int a = 9;
//     int *p_a = &a;
//     int **p_p_a = &p_a;
//     int ***p_p_p_a = &p_p_a;
//     std::cout << a << std::endl;
//     std::cout << *p_a << std::endl;
//     std::cout << **p_p_a << std::endl;
//     std::cout << ***p_p_p_a << std::endl;
//     std::cout << sizeof *p_a << std::endl;
//     std::cout << sizeof **p_p_a << std::endl;
//     std::cout << sizeof ***p_p_p_a << std::endl;
//     std::cout << p_a << std::endl;
//     std::cout << p_p_a << std::endl;
//     std::cout << p_p_p_a << std::endl;
//     std::cout << sizeof p_a << std::endl;
//     std::cout << sizeof p_p_a << std::endl;
//     std::cout << sizeof p_p_p_a << std::endl;
//
//     int *pp;
//     std::cout << pp << std::endl;
//     std::cout << *pp << std::endl;
//     int *pp2 = nullptr;
//     std::cout << pp2 << std::endl;
//     std::cout << *pp2 << std::endl;
//     int aa = 9;
//     int *p_a1;
//     *p_a1 = aa + 1;
//     int *p_a2 = nullptr;
//     *p_a2 = aa + 1;
//
//
//     int a1 = 9;
//     char b = 'a';
//     void *ptr = &a1;
//     ptr = &b;
//     *(int *) ptr = 10;
//     *(char *) ptr = 'b';
//     std::cout << a1 << std::endl;
//     std::cout << b << std::endl;
//     int n = 10;
//     void *vp = &n;
//     int *ip = static_cast<int *>(vp); // 强制转换为 int*
//     std::cout << *ip << std::endl; // 现在可以解引用了
//
//     int a2 = 9;
//     char w = 'b';
//     int &ra = a2;
//     char &rw = w;
//     std::cout << ra << std::endl;
//     std::cout << rw << std::endl;
//
//     int a3 = 9;
//     int b2 = 6;
//     int &ra2 = a3;
//     ra2 = b2;
//     std::cout << a3 << std::endl;
//     std::cout << ra2 << std::endl;
//     printf("a: %p\nra: %p\n", &a3, &ra2);
//
//     int a4 = 9;
//     int b3 = 6;
//     add(&a4, &b3);
//     std::cout << a4 << std::endl;
//     std::cout << b3 << std::endl;
//     add(a4, b3);
//     std::cout << a4 << std::endl;
//     std::cout << b3 << std::endl;
//
//     int a5 = 9;
//     int b4 = 6;
//     const int *ptr_a = &a5;
//     // *ptr_a = 6;
//     ptr_a = &b4;
//     std::cout << *ptr_a << std::endl;
//
//     int *const ptr_b = &a5;
//     *ptr_b = 10;
//     // ptr_b = &b;
//     std::cout << *ptr_a << std::endl;
//
//     const int *const ptr_c = &a5;
//     // *ptr_c = 6;
//     // ptr_c = &b;
//
//     return 0;
// }

// day04
// ******************************************************
// struct Student {
//     char gender; //male->'y' female->'x'
//     int age;
//     int id;
//     std::string name;
// };
//
// struct Student2 {
//     char gender; //male->'y' female->'x'
// };
//
// // #pragma pack(1) // 1 字节对齐
// struct Student3 {
//     char x;
//     int y;
// };
//
// struct Student4 {
// };
//
// struct Student5 {
//     char x;
//     int y;
//     char z;
// };
//
// enum Weekday {
//     Monday = 3, // 默认值为 0
//     Tuesday = 5, // 默认值为 1
//     Wednesday, // 默认值为 2
//     Thursday, // 默认值为 3
//     Friday, // 默认值为 4
//     Saturday, // 默认值为 5
//     Sunday // 默认值为 6
// };
//
// union Data {
//     int intValue;
//     float floatValue;
//     char stringValue[20];
// };
//
// union Data2 {
//     char x;
//     int y;
// };
//
// int add(int a, int b) {
//     if (INT_MAX - a < b) {
//         return a + b;
//     } else {
//         throw "throw";
//     }
// }
//
// // 定义一个函数，计算两个整数的乘积
// int multiply(int a, int b) {
//     int product = a * b;
//     return product;
// }
//
// // 定义一个函数，打印包含问候语的消息
// void greet(std::string name) {
//     std::cout << "你好, " << name << "!" << std::endl;
// }
//
// struct MyStruct {
//     int x;
//     char y;
// };
//
// void function1(MyStruct m1) {
//     m1.x = 10;
//     m1.y = 'b';
// }
//
// void function2(MyStruct &m1) {
//     m1.x = 10;
//     m1.y = 'b';
// }
//
// void increment(int &num) {
//     num++; // 对形参 num 的修改会影响到实参
// }
//
// void printLength(const std::string &str) {
//     std::cout << "字符串的长度是: " << str.length() << std::endl;
//     // str[0] = 'A'; // 错误！不能修改常量引用
// }
//
// void fun1(int *ptr) {
//     if (ptr != nullptr) {
//         *ptr = 100;
//     }
// }
//
// int main() {
//     Student s1 = {'x', 19, 3, "Lucy"};
//     s1 = {.gender = 'y'};
//     s1.id = 2;
//     s1.age = 18;
//     s1.name = "John";
//
//     std::cout << s1.id << std::endl;
//     std::cout << s1.name << std::endl;
//     std::cout << s1.gender << std::endl;
//     std::cout << s1.age << std::endl;
//
//     Student2 s2 = {'y'};
//     std::cout << sizeof s2 << std::endl;
//
//     Student3 s3 = {100};
//     std::cout << sizeof s3 << std::endl;
//
//     Student4 s4;
//     std::cout << sizeof s4 << std::endl;
//
//     // 默认对齐（通常为 4 或 8 字节）
//     Student5 s5;
//     std::cout << sizeof s5 << std::endl;
//
//     std::cout << Monday << std::endl;
//     std::cout << Tuesday << std::endl;
//     std::cout << Wednesday << std::endl;
//     std::cout << Thursday << std::endl;
//     std::cout << Friday << std::endl;
//
//     Weekday today = Wednesday;
//     // 可以直接使用枚举常量
//     if (today == Wednesday) {
//         std::cout << "今天星期三，要努力学习！" << std::endl;
//     }
//     // 枚举常量本质上是整型，可以进行比较和运算
//     if (today > Friday) {
//         std::cout << "今天是周末！" << std::endl;
//     }
//     // 也可以显式获取枚举常量的值
//     std::cout << "Wednesday 的值是: " << Wednesday << std::endl; // 输出 2
//
//     Data data;
//     std::cout << sizeof data << std::endl;
//     // 存储整数值
//     data.intValue = 100;
//     std::cout << "intValue: " << data.intValue << std::endl;
//     // 存储浮点数值，此时 intValue 的值不再有效
//     data.floatValue = 3.14f;
//     std::cout << "floatValue: " << data.floatValue << std::endl;
//     // 此时访问 data.intValue 将会得到未定义的值
//     // 存储字符串值，之前的值都不再有效
//     strcpy(data.stringValue, "Hello");
//     std::cout << "stringValue: " << data.stringValue << std::endl;
//     std::cout << "intValue: " << data.intValue << std::endl;
//     std::cout << "floatValue: " << data.floatValue << std::endl;
//
//     Data2 data2;
//     data2.y = 97;
//     std::cout << data2.x << std::endl;
//
//     std::cout << add(3, 4) << std::endl;
//
//     int num1 = 5;
//     int num2 = 10;
//     // 调用 multiply 函数
//     int result = multiply(num1, num2);
//     std::cout << num1 << " 乘以 " << num2 << " 的结果是: " << result << std::endl;
//     // 调用 greet 函数
//     greet("小明");
//
//     MyStruct my = {9, 'a'};
//     function1(my);
//     std::cout << my.x << my.y << std::endl;
//     function2(my);
//     std::cout << my.x << my.y << std::endl;
//
//     int count = 5;
//     increment(count);
//     std::cout << "Count 的值是: " << count << std::endl; // 输出 6
//
//     std::string message = "Hello";
//     printLength(message);
//
//     fun1(nullptr);
//
//     return 0;
// }

// day05
// ******************************************************
// #include "day05/other.hpp"
//
// bool function1() {
//     std::cout << "111111111111" << std::endl;
//     return true;
// }
//
// bool function2() {
//     std::cout << "22222222222" << std::endl;
// }
//
// struct MyStruct {
//     int x;
// };
//
// void function3(MyStruct *ptr) {
//     (*ptr).x = 100;
//     ptr->x = 100;
// }
//
// #define PI 3.1415926
//
// double circle_area(double radius) {
//     return PI * radius * radius;
// }
//
// #define SQUARE(x) ((x) * (x)) // 注意加括号，防止优先级问题
//
// void function1(int arr[4]) {
//     std::cout << typeid(arr).name() << std::endl;
//     std::cout << sizeof(arr) << std::endl;
// }
//
// void function(int arr[4], int size) {
//     for (int i = 0; i < size; i++) {
//         std::cout << arr[i] << std::endl;
//     }
// }
//
// int main() {
//     int a = 1;
//     int b = 2;
//     std::cout << add(a, b) << std::endl;
//     std::cout << "**************" << std::endl;
//
//     bool a1 = -100;
//     std::cout << a1 << std::endl;
//     std::cout << "**************" << std::endl;
//
//     // a = "a";
//     a = 'a';
//     std::cout << a << std::endl;
//
//     int i = 9;
//     double j = (double) i;
//     double k = static_cast<double>(i);
//
//     std::cout << (function1() || function2()) << std::endl;
//
//     a = 5;
//     b = ++a; // a 变为 6，b 变为 6
//     int c = a++; // c 变为 6，a 变为 7
//     std::cout << b << std::endl;
//     std::cout << c << std::endl;
//
//     a = 9, b = 6;
//     int max_val = (a > b) ? a : b;
//     std::cout << max_val << std::endl;
//
//     // 整个表达式的值是 30
//     std::cout << (i = 10, j = 20, i + j) << std::endl;
//
//     std::cout << circle_area(9) << std::endl;
//
//     a = 2, b = 3;
//     std::cout << SQUARE(4) << std::endl;
//     std::cout << SQUARE(5 + 2) << std::endl;
//     std::cout << SQUARE(a-1 + b-1) << std::endl;
//
//     int myarr[4] = {1, 3, 5, 7};
//     int *ptr1 = &myarr[0];
//     ptr1 += 2;
//     std::cout << *ptr1 << std::endl;
//     ptr1 -= 1;
//     std::cout << *ptr1 << std::endl;
//
//
//     int arr[5] = {10, 20, 30, 40, 50};
//     int *ptr = arr; // 指向 arr[0]
//
//     std::cout << "Initial pointer: " << ptr << ", value: " << *ptr << std::endl;
//
//     ptr++; // 移动到下一个元素
//     std::cout << "Pointer after increment: " << ptr << ", value: " << *ptr << std::endl;
//
//     ptr += 2; // 移动两个元素
//     std::cout << "Pointer after adding 2: " << ptr << ", value: " << *ptr << std::endl;
//
//     int *endPtr = &arr[4];
//     std::cout << "Distance to the end: " << endPtr - ptr << std::endl;
//
//     if (ptr < endPtr) {
//         std::cout << "ptr is before endPtr" << std::endl;
//     }
//
//     int myarr2[4] = {1, 2, 3, 4};
//     int *ptr3 = &myarr2[0];
//     int *ptr4 = myarr2;
//
//     int (*ptr2)[4] = &myarr2;
//     std::cout << *ptr2[0] << std::endl;
//
//     std::cout << "**************" << std::endl;
//     int myarr3[4] = {1, 2, 3, 4};
//     std::cout << sizeof(myarr3) << std::endl;
//     std::cout << "**************" << std::endl;
//
//     function1(myarr3);
//     function(myarr3, sizeof(myarr3) / sizeof(int));
//
//     int myarr4[2][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}};
//     std::cout << myarr4[1][2] << std::endl;
//
//     return 0;
// #include "day05/other.txt"

// day06
// ******************************************************
// void function(int arr[], int size) {
// }
//
// int add(int a, int b) {
//     return a + b;
// }
//
// int mul(int a, int b) {
//     return a * b;
// }
//
// // 一个使用函数指针作为参数的函数
// void executeOperation(int a, int b, int (*operation)(int, int)) {
//     std::cout << "执行结果: " << (*operation)(a, b) << std::endl;
//     std::cout << "执行结果: " << operation(a, b) << std::endl;
// }
//
// // int add(double a, double b) {
// //     return a + b;
// // }
//
// // float add(float a, float b) {
// //     return a + b;
// // }
//
// // 重载的 sum 函数，处理两个整数
// int sum(int a, int b) {
//     std::cout << "调用 sum(int, int)" << std::endl;
//     return a + b;
// }
//
// // 重载的 sum 函数，处理三个整数
// int sum(int a, int b, int c) {
//     std::cout << "调用 sum(int, int, int)" << std::endl;
//     return a + b + c;
// }
//
// // 重载的 sum 函数，处理两个 double 类型
// double sum(double a, double b) {
//     std::cout << "调用 sum(double, double)" << std::endl;
//     return a + b;
// }
//
// double circle_area(double r, double PI = 3.1415926) {
//     return PI * r * r;
// }
//
// inline int add2(int a, int b) {
//     return a + b;
// }
//
// // 内联函数：计算两个整数的最大值
// inline int max(int a, int b) {
//     return a > b ? a : b;
// }
//
// // 内联函数：计算平方
// inline double square(double x) {
//     return x * x;
// }
//
// int main() {
//     int myarr[4] = {1, 2, 3, 4};
//     int (*ptr)[4] = &myarr;
//     std::cout << (*ptr)[1] << std::endl;
//     std::cout << sizeof "" << std::endl;
//     std::cout << sizeof nullptr << std::endl;
//
//     char str1[] = "Hello"; // 编译器会自动在 "Hello" 后面添加 '\0'
//     char str2[] = ""; // 空字符串，实际上是 {'\0'}
//     char str3[10]; // 定义一个可以存储 9 个字符的字符数组，留一个位置给 '\0'
//     char *p_str = str1; // 指针 p_str 指向 str1 的第一个元素 'H'
//     std::cout << "字符串 str1 的内容: " << str1 << std::endl;
//     std::cout << "字符串 str1 的长度 (不包含 '\\0'): " << strlen(str1) << std::endl; // 输出 5
//     std::cout << "str1[0] 的值: " << static_cast<char>(str1[0]) << std::endl;
//     std::cout << "str1[0] 的地址: " << static_cast<void *>(&str1[0]) << std::endl; // 强制转换为 void* 以打印地址
//     std::cout << "p_str 指向的地址: " << static_cast<void *>(p_str) << std::endl; // 两者地址相同
//     // 注意：直接打印字符数组或字符指针，会输出整个字符串直到 '\0'
//     std::cout << "str2 的内容: " << str2 << std::endl;
//     std::cout << "字符串 str2 的长度: " << strlen(str2) << std::endl; // 输出 0
//
//     int myarr2[2][2][3] = {
//         {
//             {1, 2, 3},
//             {4, 5, 6}
//         },
//         {
//             {1, 2, 3},
//             {4, 5, 6}
//         }
//     };
//     int myarr4[2][3] = {1, 2, 3, 4, 5, 6};
//     int myarr3[2][3] = {
//         {1, 2, 3},
//         {4, 5, 6}
//     };
//     int (*x)[2][3] = &myarr3;
//     int (*myptr)[3] = myarr3;
//     myptr++;
//
//     std::cout << "**************" << std::endl;
//     int matrix[2][3] = {
//         {1, 2, 3},
//         {4, 5, 6}
//     };
//     // matrix 是一个指向包含 3 个 int 的数组的指针 (行指针)
//     int (*p_row)[3] = matrix;
//     std::cout << "二维数组 matrix 的首地址: " << static_cast<void *>(matrix) << std::endl;
//     std::cout << "行指针 p_row 的值 (指向第一行): " << static_cast<void *>(p_row) << std::endl; // 与 matrix 地址相同
//     std::cout << "matrix[0] 的地址: " << static_cast<void *>(matrix[0]) << std::endl; // 第一行的首地址，与 matrix 相同
//     // p_row + 1  移动到下一行（移动了 3 个 int 的大小）
//     std::cout << "p_row + 1 的值 (指向第二行): " << static_cast<void *>(p_row + 1) << std::endl;
//     std::cout << "matrix[1] 的地址: " << static_cast<void *>(matrix[1]) << std::endl; // 第二行的首地址
//     // 使用行指针访问二维数组元素
//     // *(p_row + 1)  解引用行指针，得到第二行的首地址，类型是 int*
//     // *(p_row + 1) + 2  在第二行的首地址上偏移 2 个 int 的位置，指向 matrix[1][2]
//     // *(*(p_row + 1) + 2)  解引用，得到 matrix[1][2] 的值
//     std::cout << "matrix[1][2] 的值为: " << *(*(p_row + 1) + 2) << std::endl;
//
//     // int (*ptr_function)(int, int) = &add;
//     int (*ptr_function)(int, int) = add;
//     std::cout << (*ptr_function)(1, 2) << std::endl;
//     std::cout << ptr_function(1, 2) << std::endl;
//     void (*ptr_function2)(int [], int) = function;
//     std::cout << "**************" << std::endl;
//
//     // 声明一个指向返回 int，接受两个 int 参数的函数的指针
//     int (*funcPtr)(int, int);
//     // 将 add 函数的地址赋值给 funcPtr
//     funcPtr = add;
//     // 通过函数指针调用 add 函数
//     int result = funcPtr(5, 3);
//     std::cout << "通过函数指针调用 add: " << result << std::endl;
//     // 将 add 函数作为参数传递给 executeOperation 函数
//     executeOperation(10, 5, &add);
//     executeOperation(10, 5, mul);
//     std::cout << "**************" << std::endl;
//
//     int a = 9;
//     int b = 6;
//     double c = 9.0;
//     double d = 6.0;
//     float e = 9.0f;
//     float f = 6.0f;
//     std::cout << add(a, b) << std::endl;
//     std::cout << add(c, d) << std::endl;
//     std::cout << add(e, f) << std::endl;
//     std::cout << "**************" << std::endl;
//
//     std::cout << "sum(2, 3) = " << sum(2, 3) << std::endl; // 调用第一个 sum 函数
//     std::cout << "sum(2, 3, 4) = " << sum(2, 3, 4) << std::endl; // 调用第二个 sum 函数
//     std::cout << "sum(2.5, 3.5) = " << sum(2.5, 3.5) << std::endl; // 调用第三个 sum 函数
//     std::cout << "**************" << std::endl;
//
//     std::cout << circle_area(1) << std::endl;
//     std::cout << circle_area(1, 3.14) << std::endl;
//
//     int res = add2(a, b);
//     std::cout << res << std::endl;
//     int x2 = 10, y = 5;
//     // 编译器可能会将 max(x, y) 的代码直接替换到这里
//     std::cout << "最大值: " << max(x2, y) << std::endl;
//     double num = 3.5;
//     // 编译器可能会将 square(num) 的代码直接替换到这里
//     std::cout << "平方: " << square(num) << std::endl;
//
//     return 0;
// }

// day07
// ******************************************************
// // 计算阶乘
// int factorial(int n) {
//     if (n == 0) {
//         return 1;
//     }
//     return n * factorial(n - 1);
// }
//
// // 使用递归计算斐波那契数列
// int fibonacci(int n) {
//     if (n <= 1) {
//         return n;
//     }
//     return fibonacci(n - 1) + fibonacci(n - 2);
// }
//
// struct MyStruct {
//     int x;
//     double y;
// };
//
// int *createOnHeap() {
//     int *num = new int(100); // 在堆区分配内存
//     return num;
// }
//
// void functionOnStack() {
//     int localVar = 50; // 在栈区分配内存
//     std::cout << "栈区变量 localVar 的地址: " << &localVar << std::endl;
// }
//
// int a = 0;
//
// int func1() {
//     a++;
//     std::cout << a << std::endl;
//     static int b = 1;
//     b++;
//     std::cout << b << std::endl;
//     return a;
// }
//
// // 全局变量
// static int globalVar = 10;
//
// void func() {
//     // 局部变量
//     int localVar = 20;
//     // static 静态局部变量
//     static int staticVar = 30;
//     static int *ptr = new int(100);
//
//     std::cout << "函数 func 被调用" << std::endl;
//     std::cout << "全局变量: " << globalVar << "，地址: " << &globalVar << std::endl;
//     std::cout << "局部变量: " << localVar << "，地址: " << &localVar << std::endl;
//     std::cout << "静态变量: " << staticVar << "，地址: " << &staticVar << std::endl;
//
//     localVar++;
//     staticVar++;
// }
//
// // 值传递
// void swapByValue(int a, int b) {
//     std::cout << "值传递函数内部：交换前 a = " << a << ", b = " << b << std::endl;
//     int temp = a;
//     a = b;
//     b = temp;
//     std::cout << "值传递函数内部：交换后 a = " << a << ", b = " << b << std::endl;
// }
//
// // 指针传递
// void swapByPointer(int *a, int *b) {
//     std::cout << "指针传递函数内部：交换前 *a = " << *a << ", *b = " << *b << std::endl;
//     int temp = *a;
//     *a = *b;
//     *b = temp;
//     std::cout << "指针传递函数内部：交换后 *a = " << *a << ", *b = " << *b << std::endl;
// }
//
// // 引用传递
// void swapByReference(int &a, int &b) {
//     std::cout << "引用传递函数内部：交换前 a = " << a << ", b = " << b << std::endl;
//     int temp = a;
//     a = b;
//     b = temp;
//     std::cout << "引用传递函数内部：交换后 a = " << a << ", b = " << b << std::endl;
// }
//
// void modifyArray(int arr[], int size) {
//     // 实际上 arr 被当作 int* 处理
//     std::cout << "函数内部 sizeof(arr): " << sizeof(arr) << std::endl; // 输出指针的大小，而非数组大小
//     for (int i = 0; i < size; ++i) {
//         arr[i] *= 2;
//     }
// }
//
//
// int main() {
//     char xx = 'a';
//     double yy = 3.14;
//     char *ptr_x = &xx;
//     double *ptr_y = &yy;
//     char *ptr_z = (char *) (ptr_y);
//
//     int num = 5;
//     std::cout << num << " 的阶乘是: " << factorial(num) << std::endl;
//     std::cout << "斐波那契数列第 10 项是: " << fibonacci(10) << std::endl;
//
//     int n;
//     std::cout << "请输入一个整数 n，并要求程序分配 n个整数的空间" << std::endl;
//     std::cin >> n;
//     // int arr[n]; // 它不是 C+标准支持的行为，ISO
//     int *ptr = new int[n];
//     for (int i = 0; i < n; i++) {
//         ptr[i] = i + 2;
//     }
//     delete[] ptr;
//     ptr = nullptr;
//
//     MyStruct *ptr2 = new MyStruct;
//     ptr2->x = 100;
//     ptr2->y = 100.1;
//
//     std::cout << ptr2->x << " " << ptr2->y << std::endl;
//
//     delete ptr2;
//     ptr2 = nullptr;
//
//     MyStruct *ptr1 = new MyStruct[2];
//
//     delete[] ptr1;
//     ptr1 = nullptr;
//
//     // 使用 new 分配一个 int 类型的内存空间
//     int *ptr3 = new int;
//     *ptr3 = 10;
//     std::cout << "ptr3 指向的值: " << *ptr3 << std::endl;
//     // 使用 delete 释放内存
//     delete ptr3;
//     ptr3 = nullptr; // 释放后将指针置空，防止悬 dangling 指针
//
//     std::cout << std::endl;
//
//     // 使用 new [] 分配一个包含 5 个 int 类型的数组
//     int *arr = new int[5];
//     for (int i = 0; i < 5; ++i) {
//         arr[i] = i * 2;
//     }
//     std::cout << "动态分配的数组元素：";
//     for (int i = 0; i < 5; ++i) {
//         std::cout << arr[i] << " ";
//     }
//     std::cout << std::endl;
//     // 使用 delete [] 释放数组内存
//     delete[] arr;
//     arr = nullptr; // 释放后将指针置空
//     delete[] arr;
//     std::cout << "***************" << std::endl;
//
//     // 栈区变量
//     int a = 10;
//     std::cout << "栈区变量 a 的地址: " << &a << std::endl;
//     // 堆区变量
//     int *b = new int;
//     *b = 20;
//     std::cout << "堆区变量 b 的地址: " << b << std::endl;
//     functionOnStack();
//     int *heapVar = createOnHeap();
//     std::cout << "堆区变量 heapVar 的地址: " << heapVar << std::endl;
//     std::cout << "堆区变量 heapVar 指向的值: " << *heapVar << std::endl;
//     delete b;
//     b = nullptr;
//     delete heapVar;
//     heapVar = nullptr;
//
//     func1();
//     func1();
//     std::cout << "main 函数中的全局变量: " << globalVar << std::endl;
//     func();
//     func();
//
//
//     int x = 10, y = 20;
//     std::cout << "交换前：x = " << x << ", y = " << y << std::endl;
//     // 值传递
//     swapByValue(x, y);
//     std::cout << "值传递后：x = " << x << ", y = " << y << std::endl;
//     // 指针传递
//     swapByPointer(&x, &y);
//     std::cout << "指针传递后：x = " << x << ", y = " << y << std::endl;
//     // 引用传递
//     swapByReference(x, y);
//     std::cout << "引用传递后：x = " << x << ", y = " << y << std::endl;
//
//
//     int arr2[5] = {1, 2, 3, 4, 5};
//     std::cout << "函数外部 sizeof(arr): " << sizeof(arr2) << std::endl; // 输出整个数组的大小
//     modifyArray(arr2, 5);
//     std::cout << "修改后的数组：";
//     for (int i = 0; i < 5; ++i) {
//         std::cout << arr2[i] << " ";
//     }
//     std::cout << std::endl; // 输出：2 4 6 8 10
//
//
//     // 使用 new 分配一个整数
//     int *p = new int;
//     *p = 10;
//     std::cout << "*p: " << *p << std::endl;
//     delete p; // 释放单个对象的内存
//     p = nullptr;
//     // 使用 new[] 分配一个包含 5 个整数的数组
//     int *arr3 = new int[5];
//     for (int i = 0; i < 5; ++i) {
//         arr3[i] = i * 2;
//     }
//     std::cout << "动态分配的数组：";
//     for (int i = 0; i < 5; ++i) {
//         std::cout << arr3[i] << " ";
//     }
//     std::cout << std::endl; // 输出：0 2 4 6 8
//     delete[] arr3; // 释放数组内存
//     arr3 = nullptr;
//
//     int arr4[5] = {1, 2, 3, 4, 5};
//     for (int i = 0; i <= 5; ++i) {
//         // 错误：循环条件应为 i < 5
//         std::cout << arr4[i] << " ";
//     }
//     std::cout << std::endl; // 最后一个访问 arr[5] 越界
//
//     return 0;
// }

// day08
// ******************************************************
// class Student {
//     int id;
//     char gender;
//     char name[1024];
//
//     int getId() { return id; }
//     char getGender() { return gender; }
//     char getName() { return *name; }
// };
//
// class Order {
//     int id;
//     int user_id;
//     // Status prev;
//     // Status st;
//
//     // bool update(Status status) {
//     //     st = status;
//     // }
// };
//
// class Dog {
// public:
//     std::string name;
//     int age;
//
//     // 构造函数
//     Dog(const std::string &dogName, int dogAge) : name(dogName), age(dogAge) {
//         std::cout << "小狗 " << name << " 被创建了！" << std::endl;
//     }
//
//     Dog(std::string &dogName) : name(dogName) {
//         std::cout << "小狗 " << name << " 被创建了！" << std::endl;
//     }
//
//     Dog() : name("11"), age(0) {
//         std::cout << "小狗被创建了！" << std::endl;
//     }
//
//     // 析构函数
//     ~Dog() {
//         std::cout << "小狗 " << name << " 离开了。" << std::endl;
//     }
//
//     void bark() const {
//         std::cout << "汪汪！我是 " << name << ", " << age << " 岁了！" << std::endl;
//     }
//
//     bool get_is_sleeping() {
//         return is_sleeping;
//     }
//
// private:
//     // 可以添加一些私有成员，例如内部状态
//     bool is_sleeping = false;
// };
//
// class Cat {
// public:
//     std::string name;
//     int age;
//
//     // 默认构造函数
//     Cat() : name("Unknown"), age(0) {
//         std::cout << "一只未命名的小猫被创建了。" << std::endl;
//     }
//
//     // 参数化构造函数
//     Cat(const std::string &catName, int catAge) : name(catName), age(catAge) {
//         std::cout << "小猫 " << name << " 被创建了！" << std::endl;
//     }
//
//     void meow() const {
//         std::cout << "喵！我是 " << name << ", " << age << " 岁了！" << std::endl;
//     }
// };
//
// class MyClass {
// public:
//     MyClass() {
//         ptr = new int;
//         *ptr = 100;
//         std::cout << "construct myclass ..." << std::endl;
//     }
//
//     ~MyClass() {
//         delete ptr;
//         ptr = nullptr;
//         std::cout << "deconstruct myclass ..." << std::endl;
//     }
//
// private:
//     int *ptr;
// };
//
// class ResourceHolder {
// public:
//     ResourceHolder() {
//         resource = new int[10];
//         std::cout << "资源已分配。" << std::endl;
//     }
//
//     ~ResourceHolder() {
//         delete[] resource;
//         resource = nullptr;
//         std::cout << "资源已释放。" << std::endl;
//     }
//
// private:
//     int *resource;
// };
//
// class BankAccount {
// public:
//     // 公有成员函数，用于操作私有成员
//     void deposit(double amount) {
//         balance += amount;
//     }
//
//     void withdraw(double amount) {
//         if (balance >= amount) {
//             balance -= amount;
//         } else {
//             std::cout << "余额不足！" << std::endl;
//         }
//     }
//
//     double getBalance() const {
//         return balance;
//     }
//
// private:
//     // 私有成员变量，存储账户余额
//     double balance = 0.0;
// };
//
// class MyClass2 {
// public:
//     MyClass2(int x_) {
//         x = x_;
//     }
//
// private:
//     int x;
//     int y;
//     char z;
// };
//
// class MyClass3 {
// private:
// };
//
// class MyClass4 {
//     int value;
//
// public:
//     MyClass4(int value) {
//         // value = value;
//         this->value = value;
//         std::cout << static_cast<void *>(this) << std::endl;
//     }
//
//     void display() const {
//         // std::cout << value << std::endl;
//         std::cout << this->value << std::endl;
//     }
// };
//
// class MyClass5 {
// public:
//     int value;
//
//     void setValue(int value) {
//         this->value = value; // 使用 this 指针区分成员变量和参数
//     }
//
//     void printValue() const {
//         std::cout << "value: " << this->value << std::endl; // 使用 this 指针访问成员变量
//     }
// };
//
// int count = 0;
//
// class MyClass6 {
// public:
//     static int count2;
//
//     MyClass6() {
//         count2++;
//         count++;
//     }
// };
//
// int MyClass6::count2 = 0;
//
//
// int main() {
//     Dog myDog("Buddy", 3); // 调用构造函数
//     Dog myDog2;
//     myDog.bark(); // 调用公有成员函数
//     // 可以访问公有成员变量
//     std::cout << "小狗的名字是：" << myDog.name << std::endl;
//     std::cout << "小狗的年龄是：" << myDog.age << std::endl;
//     // 无法直接访问私有成员变量
//     // std::cout << myDog.is_sleeping << std::endl; // 编译错误
//     std::cout << myDog.get_is_sleeping() << std::endl;
//
//     Cat cat1; // 调用默认构造函数
//     cat1.meow();
//     Cat cat2("Tom", 2); // 调用参数化构造函数
//     cat2.meow();
//
//     std::cout << "my beginning..." << std::endl;
//     {
//         MyClass my;
//     }
//     std::cout << "my end..." << std::endl;
//     std::cout << "my2 beginning..." << std::endl;
//     {
//         MyClass *my2 = new MyClass();
//         delete my2;
//         my2 = nullptr;
//     }
//     std::cout << "my2 end..." << std::endl;
//
//     {
//         ResourceHolder holder; // 在此代码块结束时，holder 的析构函数会被调用
//     }
//     ResourceHolder *dynamicHolder = new ResourceHolder();
//     delete dynamicHolder; // 手动删除动态分配的对象，触发析构函数
//
//     BankAccount myAccount;
//     myAccount.deposit(1000);
//     myAccount.withdraw(200);
//     std::cout << "账户余额：" << myAccount.getBalance() << std::endl;
//     // 无法直接访问私有成员变量
//     // myAccount.balance = -100; // 编译错误
//
//     MyClass2 my2(1);
//     std::cout << sizeof(my2) << std::endl;
//     MyClass3 my3();
//     // std::cout << sizeof(my3) << std::endl;
//     std::cout << sizeof(std::cout) << std::endl;
//
//     MyClass4 my4(5);
//     my4.display();
//
//     MyClass5 my5;
//     my5.setValue(1);
//     my5.printValue();
//
//     MyClass6 my6;
//     MyClass6 my61;
//     std::cout << count << std::endl;
//     std::cout << my6.count2 << std::endl;
//     std::cout << MyClass6::count2 << std::endl;
//
//     return 0; // myDog 对象在这里会被销毁，调用析构函数
// }

// day09
// ******************************************************
// class MyClass {
// public:
//     // 声明静态成员变量
//     static int count;
//
//     static void printCount() {
//         // 声明静态成员函数
//         std::cout << "Count: " << count << std::endl;
//     }
//
// private:
//     int x;
// };
//
// // 在类定义外部初始化静态成员变量
// int MyClass::count = 0;
//
// class MyClass2 {
// public:
//     // MyClass2(int x){
//     //     this->x = x;
//     // }
//     // 尽可能使用这种形式，因为它更快，特殊场合必须用它
//     MyClass2(int x, int y) : x(x), y(y) {
//     }
//
//     void display() const {
//         std::cout << x << ", " << y << std::endl;
//     }
//
// private:
//     int x;
//     int y;
// };
//
// class MyClass3 {
// public:
//     // MyClass2(int x){
//     //     this->x = x;
//     // }
//     // 尽可能使用这种形式，因为它更快，特殊场合必须用它
//     MyClass3(int id) : id(id) {
//     }
//
//     void display() const {
//         std::cout << id << std::endl;
//     }
//
// private:
//     const int id;
// };
//
// class MyClass4 {
// public:
//     const int value1;
//     int &value2;
//
//     MyClass4(int val1, int &val2) : value1(val1), value2(val2) {
//         //
//     }
// };
//
// // 基类
// class Animal {
// public:
//     std::string name;
//
//     Animal(std::string n) : name(n) {
//     }
//
//     void eat() { std::cout << name << " is eating." << std::endl; }
// };
//
// // 派生类
// // final不能被继承
// class Bird final : public Animal {
// public:
//     int wingspan;
//
//     Bird(std::string n, int w) : Animal(n), wingspan(w) {
//     }
//
//     void fly() { std::cout << name << " is flying." << std::endl; }
// };
//
// class Animal2 {
// protected:
//     void move() {
//         std::cout << "animal can move" << std::endl;
//     }
// };
//
// class Dog : public Animal2 {
// public:
//     void func1() {
//         move();
//     }
// };
//
// class hbaDog : public Dog {
// public:
//     void func2() {
//         move();
//     }
// };
//
// class MyClass5 {
// public:
//     void print() {
//         std::cout << "this is MyClass5" << std::endl;
//     }
// };
//
// class MyClass6 {
// public:
//     void print() {
//         std::cout << "this is MyClass6" << std::endl;
//     }
// };
//
// class MyClass7 : public MyClass5, public MyClass6 {
// };
//
// class Animal3 {
// public:
//     void eat() {
//         std::cout << "Animal is eating." << std::endl;
//     }
// };
//
// class Mammal {
// public:
//     void giveBirth() {
//         std::cout << "Mammal is giving birth." << std::endl;
//     }
// };
//
// class Bat : public Animal3, public Mammal {
// public:
//     void fly() {
//         std::cout << "Bat is flying." << std::endl;
//     }
// };
//
// class A {
// public:
//     void print() {
//         std::cout << "Class A" << std::endl;
//     }
//
//     void print(int i) {
//         std::cout << "i = " << i << std::endl;
//     }
// };
//
// class B {
// public:
//     void print(float j) {
//         std::cout << "j = " << j << std::endl;
//     }
//
//     void print() {
//         std::cout << "Class A" << std::endl;
//     }
// };
//
// class C : public A, public B {
// public:
//     // 发生歧义，需要避免
//     // void print() {
//     //     std::cout << "Class C" << std::endl;
//     // }
//     // void print(int i) {
//     //     std::cout << "i = " << i << std::endl;
//     // }
//
//     // void print(float j) {
//     //     std::cout << "j = " << j << std::endl;
//     // }
// };
//
// int main() {
//     // 通过类名访问静态成员变量
//     MyClass::count = 10;
//     // 通过类名访问静态成员函数
//     MyClass::printCount();
//     MyClass my;
//     // 通过对象访问静态成员变量
//     my.count = 20;
//     // 通过对象访问静态成员函数
//     my.printCount();
//
//     std::cout << sizeof(MyClass) << std::endl;
//
//     MyClass2 my2(1, 2);
//     my2.display();
//
//     MyClass3 my3(1);
//     my3.display();
//
//     int x = 10;
//     MyClass4 my4(5, x);
//
//     Bird sparrow("Sparrow", 20);
//     sparrow.eat(); // 调用基类的成员函数
//     sparrow.fly(); // 调用派生类的成员函数
//
//     Dog dog;
//     hbaDog hb;
//     dog.func1();
//     hb.func2();
//     // dog.age = 5;  // 错误，无法直接访问 protected 成员
//
//     MyClass7 m7;
//     m7.MyClass5::print();
//     m7.MyClass6::print();
//
//     Bat bat;
//     bat.eat();
//     bat.giveBirth();
//     bat.fly();
//
//     C c;
//     c.A::print();
//     c.A::print(1);
//     c.B::print(1);
//     // c.print(1);// 发生歧义，编译错误
//
//     return 0;
// }

// day10
// ******************************************************
// class Person {
// public:
//     explicit Person(const int age) : age(age) {
//         std::cout << "Person构造" << std::endl;
//     }
//
//     ~Person() {
//         std::cout << "Person析构" << std::endl;
//     }
//
//     int age;
// };
//
// class Student : virtual public Person {
// public:
//     Student(const int age, const int id) : Person(age), student_id(id) {
//         std::cout << "Student构造" << std::endl;
//     }
//
//     ~Student() {
//         std::cout << "Student析构" << std::endl;
//     }
//
//     int student_id;
// };
//
// class Teacher : virtual public Person {
// public:
//     Teacher(const int age, const int id) : Person(age), teacher_id(id) {
//         std::cout << "Teacher构造" << std::endl;
//     }
//
//     ~Teacher() {
//         std::cout << "Student析构" << std::endl;
//     }
//
//     int teacher_id;
// };
//
// class TeacAssit : public Student, public Teacher {
// public:
//     TeacAssit(const int age, const int s_id, const int t_id) : Person(age), Student(age, s_id), Teacher(age, t_id) {
//         std::cout << "TeacAssit构造" << std::endl;
//     }
//
//     ~TeacAssit() {
//         std::cout << "TeacAssit析构" << std::endl;
//     }
// };
//
// class Animal {
// public:
//     Animal(int id) : id(id) {
//     }
//
//     void sound() {
//     }
//
//     int id;
// };
//
// class Cat : public Animal {
// public:
//     Cat() : Animal(0) {
//     }
//
//     void sound() {
//         std::cout << "meow  ..." << std::endl;
//     }
// };
//
// class Dog : public Animal {
// public:
//     Dog() : Animal(1) {
//     }
//
//     void sound() {
//         std::cout << "wang wang ..." << std::endl;
//     }
// };
//
// class Durk : public Animal {
// public:
//     Durk() : Animal(2) {
//     }
//
//     void sound() {
//         std::cout << "gua gua ..." << std::endl;
//     }
// };
//
// void business_function(Animal *ptr) {
//     if (ptr->id == 1) {
//         ((Dog *) (ptr))->sound();
//     } else if (ptr->id == 0) {
//         ((Cat *) (ptr))->sound();
//     } else if (ptr->id == 2) {
//         ((Durk *) (ptr))->sound();
//     }
// }
//
// class Animal2 {
// public:
//     virtual void sound() {
//         std::cout << "Animal sound ..." << std::endl;
//     }
// };
//
// class Cat2 : public Animal2 {
// public:
//     void sound() override {
//         std::cout << "meow  ..." << std::endl;
//     }
// };
//
// class Dog2 : public Animal2 {
// public:
//     void sound() override {
//         std::cout << "wang wang ..." << std::endl;
//     }
// };
//
// class Durk2 : public Animal2 {
// public:
//     void sound() override {
//         std::cout << "gua gua ..." << std::endl;
//     }
// };
//
// void business_function2(Animal2 *ptr) {
//     ptr->sound();
// }
//
// void business_function3(Animal2 &ptr) {
//     ptr.sound();
// }
//
// class Shape {
// public:
//     //虚函数
//     virtual void draw() const {
//         std::cout << "Drawing a shape." << std::endl;
//     }
// };
//
// class Circle : public Shape {
// public:
//     void draw() const override {
//         std::cout << "Drawing a circle." << std::endl;
//     }
// };
//
// class Square : public Shape {
// public:
//     void draw() const override {
//         std::cout << "Drawing a square." << std::endl;
//     }
// };
//
// int main() {
//     TeacAssit ta(18, 1001, 9001);
//     std::cout << ta.student_id << std::endl;
//     std::cout << ta.teacher_id << std::endl;
//     std::cout << ta.Student::age << std::endl;
//     std::cout << ta.Teacher::age << std::endl;
//     std::cout << ta.age << std::endl;
//     std::cout << &ta.age << std::endl;
//     std::cout << &ta.Student::age << std::endl;
//     std::cout << &ta.Teacher::age << std::endl;
//     std::cout << "*********************" << std::endl;
//
//     Dog dog;
//     Cat cat;
//     Durk durk;
//     business_function(&cat);
//     business_function(&dog);
//     business_function(&durk);
//     std::cout << "*********************" << std::endl;
//
//     Animal2 animal;
//     Dog2 dog2;
//     Cat2 cat2;
//     Durk2 durk2;
//     business_function2(&animal);
//     business_function2(&cat2);
//     business_function2(&dog2);
//     business_function2(&durk2);
//     business_function3(cat2);
//     std::cout << "*********************" << std::endl;
//
//     Shape *shape1 = new Circle();
//     Shape *shape2 = new Square();
//     shape1->draw(); // 调用 Circle::draw()
//     shape2->draw(); // 调用 Square::draw()
//     delete shape1;
//     delete shape2;
//     std::cout << "*********************" << std::endl;
//
//     return 0;
// }

// day11
// ******************************************************
// class Base {
// public:
//     Base() : x(60) {
//     }
//
//     virtual void display() {
//     }
//
//     int x;
// };
//
// class Derived : public Base {
// public:
//     Derived() : Base(), y(100) {
//     }
//
//     int y;
// };
//
// class Animal {
// public:
//     virtual void speak() = 0; // 纯虚函数
// };
//
// class Dog : public Animal {
// public:
//     void speak() override {
//         std::cout << "Woof!" << std::endl;
//     } // 必须实现 speak()
// };
//
// class MyClass {
// public:
//     MyClass() {
//         std::cout << "consturct...." << std::endl;
//         ptr = new int(9);
//     }
//
//     MyClass(const MyClass &other) {
//         ptr = new int;
//         *ptr = *other.ptr;
//     }
//
//     ~MyClass() {
//         std::cout << "deconsturct...." << std::endl;
//         delete ptr;
//         ptr = nullptr;
//     }
//
//     int *ptr;
// };
//
// class MyClass2 {
// public:
//     int *data;
//
//     MyClass2(int value) {
//         data = new int;
//         *data = value;
//     }
//
//     // 默认拷贝构造函数 (浅拷贝)
// };
//
// class MyClass3 {
// public:
//     int *data;
//
//     MyClass3(int value) {
//         data = new int;
//         *data = value;
//     }
//
//     // 自定义拷贝构造函数 (深拷贝)
//     MyClass3(MyClass3 &other) {
//         data = new int(*other.data);
//     }
//
//     ~MyClass3() {
//         delete data;
//     }
// };
//
// int main() {
//     // std::string str = "a123bb44b44";
//     std::string str = "123bb44b44";
//     int a = std::stoi(str);
//     std::cout << "a = " << a << std::endl;
//     std::cout << "*********************" << std::endl;
//
//     int i = 300;
//     char c = i; // 警告：数据丢失，因为 char 只能存储 -128 到 127 的值
//     std::cout << "c = " << c << std::endl;
//     std::cout << "*********************" << std::endl;
//
//     // Base *b = new Base();
//     // Derived *d = static_cast<Derived *>(b); // 错误！b 实际指向 Base 对象
//     // std::cout << d->y << std::endl;
//     // delete d; // 未定义行为
//
//     Base *b = new Derived(); // 现在 b 指向 Derived 对象
//     Derived *d = dynamic_cast<Derived *>(b); // 安全的向下转型
//     std::cout << d->x << std::endl;
//     std::cout << d->y << std::endl;
//
//     if (d) {
//         std::cout << "Successful downcasting." << std::endl;
//         delete d;
//     } else {
//         std::cout << "Failed downcasting." << std::endl;
//     }
//     std::cout << "*********************" << std::endl;
//
//     Dog dog;
//     dog.speak(); // 输出: Woof!
//     std::cout << "*********************" << std::endl;
//
//     MyClass m1;
//     std::cout << *m1.ptr << std::endl;
//     std::cout << m1.ptr << std::endl;
//     // const MyClass& m2(m1);
//     MyClass m2(m1);
//     std::cout << *m2.ptr << std::endl;
//     std::cout << m2.ptr << std::endl;
//     std::cout << "*********************" << std::endl;
//
//     MyClass2 obj1(10);
//     MyClass2 obj2 = obj1; // 浅拷贝
//     std::cout << *obj1.data << std::endl; // 输出: 10
//     std::cout << *obj2.data << std::endl; // 输出: 10
//     delete obj1.data; // 释放内存
//     std::cout << "*********************" << std::endl;
//
//     MyClass3 obj3(10);
//     MyClass3 obj4 = obj3; // 深拷贝
//     std::cout << *obj3.data << std::endl; // 输出: 10
//     std::cout << *obj4.data << std::endl; // 输出: 10
//     delete obj3.data; // 释放 obj1 的内存
//     // obj2.data 指向独立的内存空间，访问安全
//     std::cout << *obj4.data << std::endl; // 输出: 10
//     std::cout << "*********************" << std::endl;
//
//     return 0;
// }

// day12
// ******************************************************
// #include <memory>
// class MyClass {
// public:
//     MyClass() {
//         std::cout << "construct ..." << std::endl;
//         x = new int(9);
//     }
//
//     ~MyClass() {
//         std::cout << "deconstruct ..." << std::endl;
//         delete x;
//         x = nullptr;
//     }
//
//     int *x;
// };
//
// void process(MyClass *ptr) {
//     *ptr->x = 100;
// }
//
// void process2(std::shared_ptr<MyClass> ptr) {
//     *ptr->x = 100;
//     std::cout << ptr.use_count() << std::endl;
// }
//
// void process3(std::shared_ptr<MyClass> ptr) {
//     *ptr->x = 200;
//     process2(ptr);
//     std::cout << ptr.use_count() << std::endl;
// }
//
// class Complex {
// public:
//     Complex(const int r, const int i) : real(r), imag(i) {
//     }
//
//     Complex operator+(const Complex &other) {
//         std::cout << "call member fun" << std::endl;
//         return Complex(this->real + other.real, this->imag + other.imag);
//     }
//
//     int real;
//     int imag;
// };
//
// void print(const Complex &c) {
//     std::cout << "real = " << c.real << " " << "imag = " << c.imag << std::endl;
// }
//
// Complex complex_add(const Complex &c1, const Complex c2) {
//     return Complex(c1.real + c2.real, c1.imag + c2.imag);
// }
//
// Complex operator+(const Complex &c1, const Complex c2) {
//     std::cout << "call global fun" << std::endl;
//     return Complex(c1.real + c2.real, c1.imag + c2.imag);
// }
//
// std::ostream &operator<<(std::ostream &os, const Complex &c) {
//     os << "{" << "\n";
//     os << "\treal: " << c.real << "\n";
//     os << "\timag: " << c.imag << "\n";
//     os << "}";
//     return os;
// }
//
// int main() {
//     {
//         {
//             MyClass *ptr_my = new MyClass;
//             delete ptr_my;
//             ptr_my = nullptr;
//         }
//         std::cout << "**************************" << std::endl;
//
//         std::unique_ptr<MyClass> ptr_my2 = std::make_unique<MyClass>();
//         std::unique_ptr<MyClass> ptr2 = std::move(ptr_my2);
//         std::cout << "**************************" << std::endl;
//
//         std::shared_ptr<MyClass> ptr_my3 = std::make_shared<MyClass>();
//         std::cout << ptr_my3.use_count() << std::endl;
//         process3(ptr_my3);
//         std::cout << ptr_my3.use_count() << std::endl;
//         std::cout << "**************************" << std::endl;
//
//         Complex c1(1, 2);
//         print(c1);
//         Complex c2(3, 4);
//         print(c2);
//         Complex result = complex_add(c1, c2);
//         Complex result2 = c1 + c2;
//         Complex result3 = c1.operator+(c2);
//         print(result);
//         print(result2);
//         print(result3);
//         std::cout << "**************************" << std::endl;
//         std::cout << c1 << std::endl;
//         std::cout << c2 << std::endl;
//         std::cout << result3 << std::endl;
//     }
//     return 0;
// }

// day13
// ******************************************************
// void func(std::array<int, 5> x) {
//     std::cout << x.size() << std::endl;
// }
// void func2(const std::array<int, 5> &x) {
//     std::cout << x.size() << std::endl;
// }
// int main() {
//     std::string str("abc");
//     std::cout << str << std::endl;
//     std::cout << str[1] << std::endl;
//     std::cout << str.at(1) << std::endl;
//     // std::cout << str.at(-1) << std::endl;
//     std::cout << "*********************************" << std::endl;
//
//     std::string s1; // 默认构造函数，创建一个空字符串
//     std::string s2("Hello"); // 使用 C 风格字符串初始化
//     std::string s3 = "World"; // 拷贝初始化
//     std::string s4(s2); // 拷贝构造函数
//     std::string s5(s2, 1, 3); // 使用 s2 的子串初始化 (从索引 1 开始，长度为 3)
//     std::string s6(10, 'a'); // 创建包含 10 个 'a' 的字符串
//     std::string s7(s2.begin(), s2.end()); // 使用迭代器初始化
//
//     std::cout << "s1: " << s1 << std::endl;
//     std::cout << "s2: " << s2 << std::endl;
//     std::cout << "s3: " << s3 << std::endl;
//     std::cout << "s4: " << s4 << std::endl;
//     std::cout << "s5: " << s5 << std::endl;
//     std::cout << "s6: " << s6 << std::endl;
//     std::cout << "s7: " << s7 << std::endl;
//     std::cout << s7.length() << std::endl;
//     std::cout << s7.empty() << std::endl;
//     std::cout << "*********************************" << std::endl;
//
//     std::string str2 = "Hello";
//     std::string world = " World";
//     // 连接字符串
//     std::string greeting = str2 + world;
//     std::cout << "Greeting: " << greeting << std::endl; // 输出：Hello World
//     // 追加字符串
//     greeting += "!";
//     std::cout << "Greeting: " << greeting << std::endl; // 输出：Hello World!
//     // 查找子串
//     size_t pos = greeting.find("World");
//     if (pos != std::string::npos) {
//         std::cout << "'World' found at position: " << pos << std::endl; // 输出：'World' found at position: 6
//     }
//     // 截取子串
//     std::string sub = greeting.substr(0, 5);
//     std::cout << "Substring: " << sub << std::endl; // 输出：Hello
//     // 替换子串
//     greeting.replace(6, 5, "Universe");
//     std::cout << "Greeting after replace: " << greeting << std::endl; // 输出：Hello Universe!
//     std::cout << "*********************************" << std::endl;
//
//     std::string str3 = "Hello";
//     std::cout << "First character: " << str3[0] << std::endl; // 输出：H
//     std::cout << "First character: " << str3.at(0) << std::endl; // 输出：H
//     std::cout << "First character: " << str3.front() << std::endl; // 输出：H
//     std::cout << "Last character: " << str3.back() << std::endl; // 输出：o
//     try {
//         // str.at(10); // 这会抛出 std::out_of_range 异常
//     } catch (const std::out_of_range &e) {
//         std::cerr << "Caught an out_of_range exception: " << e.what() << std::endl;
//     }
//     std::cout << "*********************************" << std::endl;
//
//     std::string str4("abc");
//     const char *x = str4.c_str();
//     std::cout << x << std::endl;
//     std::cout << "*********************************" << std::endl;
//
//     std::vector<int> vecs = {};
//     for (int i = 0; i < 5; i++) {
//         vecs.push_back(1);
//         std::cout << vecs.size() << std::endl;
//         std::cout << vecs.capacity() << std::endl;
//         std::cout << "******" << std::endl;
//     }
//
//     for (int i: vecs) {
//         vecs.pop_back();
//         std::cout << vecs.size() << std::endl;
//         std::cout << vecs.capacity() << std::endl;
//         std::cout << "******" << std::endl;
//     }
//     std::cout << "*********************************" << std::endl;
//
//     std::vector<int> vecs2 = {1, 2, 3};
//     std::cout << vecs2[1] << std::endl;
//     std::cout << vecs2.at(1) << std::endl;
//
//     // 嵌套 vector
//     std::cout << "Accessing elements from nested vector:" << std::endl;
//     std::vector<std::vector<int> > matrix = {{1, 2}, {3, 4}, {5, 6}};
//     for (const auto &row: matrix) {
//         for (int elem: row) {
//             std::cout << elem << " ";
//         }
//         std::cout << std::endl;
//     }
//     std::cout << "*********************************" << std::endl;
//
//     std::list<int> numbers = {1, 2, 3};
//     numbers.push_back(4);
//     numbers.push_front(4);
//     numbers.push_front(0);
//
//     for (int num: numbers) {
//         std::cout << num << std::endl;
//     }
//     std::cout << numbers.size() << std::endl;
//     std::cout << "*********************************" << std::endl;
//
//
//     std::deque<int> d1 = {1, 2, 3};
//     d1.push_back(4);
//     d1.push_front(4);
//     d1.push_front(0);
//     for (int num: d1) {
//         std::cout << num << std::endl;
//     }
//     std::cout << d1.size() << std::endl;
//     std::cout << "*********************************" << std::endl;
//
//     std::forward_list<int> fl = {1, 2, 3, 4};
//     fl.push_front(4);
//     for (int num: fl) {
//         std::cout << num << std::endl;
//     }
//     std::cout << "*********************************" << std::endl;
//
//     std::array<int, 5> arr = {1, 2, 3, 4, 5};
//     for (int num: arr) {
//         std::cout << num << std::endl;
//     }
//     std::cout << arr.size() << std::endl;
//     std::cout << "*********************************" << std::endl;
//
//     func(arr);
//     func2(arr);
//
//     return 0;
// }

// day14
// ******************************************************
// class MyClass {
// public:
//     int id;
//     std::string name;
// };
//
// bool operator<(const MyClass &a, const MyClass &b) {
//     return a < b;
// }
//
// template<typename T>
// T add(T a, T b) {
//     return a + b;
// }
//
// template<typename T>
// T max(T a, T b) {
//     return (a > b) ? a : b;
// }
//
// class Complex {
// public:
//     int real;
//     int imag;
// };
//
// Complex operator+(const Complex &c1, const Complex &c2) {
//     return {c1.real + c2.real, c1.imag + c2.imag};
// }
//
// std::ostream &operator<<(std::ostream &os, const Complex &c) {
//     os << "{real: " << c.real << ", imag: " << c.imag << "}";
//     return os;
// }
//
// template<typename T>
// class MyArray {
// private:
//     T *data;
//     int size;
//
// public:
//     MyArray(int size) : size(size) {
//         data = new T[size];
//     }
//
//     ~MyArray() {
//         delete[] data;
//         data = nullptr;
//     }
//
//     void set(int index, T value) {
//         data[index] = value;
//     }
//
//     T get(int index) {
//         return data[index];
//     }
// };
//
// int main() {
//     std::pair<int, std::string> p1 = {1, "abc"};
//     std::pair<int, std::string> p2 = {2, "def2"};
//     std::pair<int, std::string> p3 = {3, "def3"};
//     std::pair<int, std::string> p4 = {4, "def4"};
//     std::pair<int, std::string> p5 = {5, "def5"};
//     std::pair<int, std::string> p6 = {6, "def6"};
//     std::cout << p1.first << std::endl;
//     std::cout << p1.second << std::endl;
//     std::cout << "*********************************" << std::endl;
//
//     std::vector<std::pair<int, std::string> > students = {p1, p2, p3, p4, p5, p6};
//     for (int i = 0; i < students.size(); i++) {
//         if (students[i].first == 3) {
//             std::cout << "right: " << students[i].second << std::endl;
//         } else {
//             std::cout << "wroing: " << students[i].second << std::endl;
//         }
//     }
//     std::cout << "*********************************" << std::endl;
//
//     std::map<int, std::string> students1 = {p2, p4, p1, p5, p3, p6};
//     for (auto &e: students1) {
//         std::cout << e.first << ": " << e.second << std::endl;
//     }
//     std::cout << "*********************************" << std::endl;
//
//     std::map<int, std::string> student_map;
//     // 插入元素
//     student_map[101] = "Alice";
//     student_map[102] = "Bob";
//     student_map[103] = "Charlie";
//     // 遍历 map
//     std::cout << "Student IDs and names:" << std::endl;
//     for (const auto &pair: student_map) {
//         std::cout << "ID: " << pair.first << ", Name: " << pair.second << std::endl;
//     }
//     // 查找元素
//     int id_to_find = 102;
//     auto it = student_map.find(id_to_find);
//     if (it != student_map.end()) {
//         std::cout << "Student with ID " << id_to_find << " is " << it->second << std::endl;
//     } else {
//         std::cout << "Student with ID " << id_to_find << " not found." << std::endl;
//     }
//     std::cout << "*********************************" << std::endl;
//
//     std::map<int, std::string> m = {{1, "abc"}, {2, "def"}, {3, "xyz"}};
//     std::cout << m[4] << std::endl;
//     std::cout << m[3] << std::endl;
//     std::map<std::string, int> m2 = {{"abc", 1}, {"def", 2}, {"xyz", 3}};
//     std::cout << m2["123"] << std::endl;
//     std::cout << m2["abc"] << std::endl;
//     std::cout << "*********************************" << std::endl;
//
//     std::map<std::string, int> m3 = {{"abc", 1}, {"def", 2}};
//     m3["xyz"] = 3;
//     m3.insert({"mnh", 4});
//     std::cout << m3["xyz"] << std::endl;
//     std::cout << m3["mnh"] << std::endl;
//     m3.insert({"abc", 33});
//     std::cout << m3["abc"] << std::endl;
//     std::cout << "*********************************" << std::endl;
//
//     std::set<int> s = {1, 2, 3, 1, 2, 3, 4, 5, 4};
//     std::cout << s.size() << std::endl;
//     std::cout << "*********************************" << std::endl;
//
//
//     std::set<int> unique_numbers = {10, 20, 30, 20, 40, 10};
//
//     std::cout << "Elements in set: ";
//     for (int num: unique_numbers) {
//         std::cout << num << " "; // 输出 10 20 30 40，自动去重和排序
//     }
//     std::cout << std::endl;
//
//     // 查找元素
//     if (unique_numbers.find(20) != unique_numbers.end()) {
//         std::cout << "20 is found in the set." << std::endl;
//     } else {
//         std::cout << "20 is not found in the set." << std::endl;
//     }
//     std::cout << "*********************************" << std::endl;
//
//     std::map<MyClass, int> scores;
//     MyClass m4 = {.id = 101, .name = "abc"};
//     scores[m4] = 99;
//     std::cout << "*********************************" << std::endl;
//
//     int a = 9;
//     int b = 6;
//     double a1 = 9.1;
//     double b1 = 6.1;
//     std::string a2 = "abc";
//     std::string b2 = "def";
//     std::cout << add<int>(a, b) << std::endl;
//     std::cout << add(a1, b1) << std::endl;
//     std::cout << add(a2, b2) << std::endl;
//     std::cout << "*********************************" << std::endl;
//
//     int a3 = 5, b3 = 10;
//     std::cout << "Max of " << a3 << " and " << b3 << " is: " << max(a3, b3) << std::endl;
//     double c3 = 3.14, d3 = 2.71;
//     std::cout << "Max of " << c3 << " and " << d3 << " is: " << max(c3, d3) << std::endl;
//     std::cout << "*********************************" << std::endl;
//
//     Complex c1 = {.real = 1, .imag = 2};
//     Complex c2 = {.real = 3, .imag = 4};
//     std::cout << add(c1, c2) << std::endl;
//
//     std::cout << "*********************************" << std::endl;
//
//     MyArray<int> intArray(5);
//     intArray.set(0, 10);
//     std::cout << "Value at index 0: " << intArray.get(0) << std::endl;
//
//     MyArray<double> doubleArray(3);
//     doubleArray.set(1, 3.14);
//     std::cout << "Value at index 1: " << doubleArray.get(1) << std::endl;
//
//     return 0;
// }

// day15
// ******************************************************
// template<typename T>
// class MyContainer {
// private:
//     T value;
//
// public:
//     MyContainer(T value) : value(value) {
//     }
//
//     template<typename U>
//     void printWith(U prefix) {
//         std::cout << prefix << ": " << value << std::endl;
//     }
// };
//
// template<typename T>
// struct MyStack {
//     MyStack() {
//     }
//
//     void push(const T &t) {
//         stack_inside_.push_back(t);
//     }
//
//     T top() {
//         return stack_inside_.back();
//     }
//
//     void pop() {
//         return stack_inside_.pop_back();
//     }
//
//     bool empty() {
//         return stack_inside_.empty();
//     }
//
//     std::vector<T> stack_inside_;
// };
//
// int main() {
//     MyContainer<int> intContainer(10);
//     intContainer.printWith<const char *>("Integer");
//
//     MyContainer<double> doubleContainer(3.14);
//     doubleContainer.printWith<const char *>("Double");
//     doubleContainer.printWith<std::string>("Double");
//     doubleContainer.printWith<int>(132);
//     std::cout << "*********************************" << std::endl;
//
//     std::vector<int> vecs = {1, 2, 3, 4};
//     // std::vector<int>::iterator iter = vecs.begin();
//     for (auto iter = vecs.begin(); iter != vecs.end(); ++iter) {
//         std::cout << *iter << " ";
//     }
//     std::cout << std::endl;
//     std::list<int> vecs2 = {1, 2, 3, 4};
//     for (auto iter = vecs.begin(); iter != vecs.end(); ++iter) {
//         std::cout << *iter << " ";
//     }
//     std::cout << std::endl;
//     std::cout << "*********************************" << std::endl;
//
//     std::map<int, std::string> vecs3 = {{1, "abc"}, {2, "def"}, {3, "xyx"}};
//     for (auto iter = vecs3.begin(); iter != vecs3.end(); ++iter) {
//         std::cout << (*iter).first << ":" << iter->second << std::endl;
//     }
//     std::cout << "*********************************" << std::endl;
//
//     std::vector<int> numbers;
//     numbers.push_back(1);
//     numbers.push_back(2);
//     numbers.push_back(3);
//     auto iter = numbers.begin();
//     iter += 2;
//     std::cout << *iter << std::endl;
//     ++iter;
//     numbers.insert(iter, 100);
//     std::cout << *iter << std::endl;
//     std::cout << "*********************************" << std::endl;
//
//     std::list<int> numbers2;
//     numbers2.push_back(1);
//     numbers2.push_back(2);
//     numbers2.push_back(3);
//     auto iter2 = numbers2.begin();
//     std::cout << *iter2 << std::endl;
//     ++iter2;
//     ++iter2;
//     // numbers2.erase(iter2);
//     numbers2.insert(iter2, 100);
//     std::cout << *iter2 << std::endl;
//     std::cout << "*********************************" << std::endl;
//
//     std::vector<int> numbers3 = {1, 2, 3, 4, 5};
//     auto it = std::find(numbers3.begin(), numbers3.end(), 3);
//     if (it != numbers3.end()) {
//         std::cout << "Found 3 at index: " << std::distance(numbers3.begin(), it) << std::endl;
//     } else {
//         std::cout << "3 not found." << std::endl;
//     }
//     std::cout << "*********************************" << std::endl;
//
//     std::list<int> numbers4;
//     numbers4.push_back(1);
//     numbers4.push_back(2);
//     numbers4.push_back(3);
//     auto iter3 = numbers4.begin();
//     std::advance(iter3, 2);
//     std::cout << *iter3 << std::endl;
//     std::cout << "*********************************" << std::endl;
//
//     std::list<int> numbers5;
//     numbers5.push_back(1);
//     numbers5.push_back(2);
//     numbers5.push_back(3);
//     numbers5.push_back(2);
//     numbers5.push_back(4);
//     numbers5.remove(2);
//     std::cout << numbers5.size() << std::endl;
//     std::cout << "*********************************" << std::endl;
//
//     std::deque<int> numbers6 = {2, 3};
//     numbers6.push_front(1);
//     for (std::deque<int>::iterator it = numbers6.begin(); it != numbers6.end(); ++it) {
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;
//     std::cout << "*********************************" << std::endl;
//
//     std::queue<int> numbers7;
//     numbers7.push(1);
//     numbers7.push(2);
//     numbers7.push(3);
//
//     while (!numbers7.empty()) {
//         std::cout << numbers7.front() << " ";
//         numbers7.pop();
//     }
//     std::cout << std::endl;
//     std::cout << "*********************************" << std::endl;
//
//     std::map<std::string, int> ages;
//     ages.insert(std::pair<std::string, int>("Alice", 25));
//     ages["Bob"] = 30;
//     for (std::map<std::string, int>::iterator it = ages.begin(); it != ages.end(); ++it) {
//         std::cout << it->first << ": " << it->second << std::endl;
//     }
//     std::cout << "*********************************" << std::endl;
//
//     MyStack<int> stack;
//     stack.push(1);
//     stack.push(2);
//     if (!stack.empty()) {
//         std::cout << stack.top() << std::endl;
//     }
//     stack.pop();
//     std::cout << "*********************************" << std::endl;
//
//     std::vector<int> vec = {2, 4, 6, 8, 10};
//     bool all_even = std::all_of(vec.begin(), vec.end(), [](int i) { return i % 2 == 0; });
//     std::cout << (all_even ? "All elements are even" : "Not all elements are even") << std::endl;
//
//     vec = {1, 3, 5, 7, 8};
//     bool has_even = std::any_of(vec.begin(), vec.end(), [](int i) { return i % 2 == 0; });
//     std::cout << (has_even ? "There is at least one even element" : "All elements are odd") << std::endl;
//
//     vec = {1, 3, 5, 7};
//     bool none_even = std::none_of(vec.begin(), vec.end(), [](int i) { return i % 2 == 0; });
//     std::cout << (none_even ? "None of the elements are even" : "There is at least one even element") << std::endl;
//     std::cout << "*********************************" << std::endl;
//
//     std::for_each(vec.begin(), vec.end(), [](int &n) { n *= n; });
//     for (const auto &n: vec) {
//         std::cout << n << " ";
//     }
//     std::cout << std::endl;
//     std::cout << "*********************************" << std::endl;
//
//     vec = {1, 2, 3, 4, 5};
//     std::vector<int> result(vec.size());
//     std::transform(vec.begin(), vec.end(), result.begin(), [](int v) { return v * v; });
//     for (const auto &v: vec) {
//         std::cout << v << " ";
//     }
//     std::cout << std::endl;
//     std::cout << "*********************************" << std::endl;
//
//     std::vector<int> destination(vec.size());
//     std::copy(vec.begin(), vec.end(), destination.begin());
//     for (const auto &v: destination) {
//         std::cout << v << " ";
//     }
//     std::cout << std::endl;
//     std::cout << "*********************************" << std::endl;
//
//     std::vector<int> vec2 = {1, 2, 3, 2, 4, 2, 5};
//     std::replace(vec2.begin(), vec2.end(), 2, 10);
//     for (const auto &v: vec2) {
//         std::cout << v << " ";
//     }
//     std::cout << std::endl;
//
//
//     return 0;
// }

// day16
// ******************************************************
// class Order {
// public:
//     int order_lit;
//
//     Order() {
//         order_lit = 0;
//     }
//
//     Order(const int i) {
//         order_lit = i;
//     }
//
//     Order operator+(const Order &other) const {
//         return {this->order_lit + other.order_lit};
//     }
// };
//
// class MyClass {
// public:
//     MyClass() {
//     }
//
//     MyClass operator++() {
//     }
// };
//
// std::ostream &operator<<(std::ostream &, const MyClass &order) {
// }
//
// struct Person {
//     std::string name;
//     int age;
// };
//
// bool compare_by_age(const Person &a, const Person &b) {
//     return a.age < b.age;
// }
//
// bool operator==(const Person &a, const Person &b) {
//     return a.age == b.age;
// }
//
// bool operator<(const Person &a, const Person &b) {
//     return a.age < b.age;
// }
//
// struct Result {
//     int real_value;
//     bool divide_by_zero;
// };
//
// Result divide(int a, int b) {
//     if (b == 0) {
//         return Result{-1, true};
//     }
//     return Result{a / b, false};
// }
//
// struct MyError {
//     std::string message;
//
//     MyError() : message("error") {
//     }
// };
//
// int divide2(int a, int b) {
//     if (b == 0) {
//         throw MyError();
//     }
//     return a / b;
// }
//
// int divide3(int a, int b) {
//     if (b == 0) {
//         throw 100;
//     }
//     return a / b;
// }
//
// class MyException : public std::exception {
// public:
//     const char *what() noexcept {
//         return "MyException";
//     }
// };
//
// class FileOpenError : public std::runtime_error {
// public:
//     FileOpenError(const std::string &filename) : std::runtime_error("Failed to open file: " + filename),
//                                                  filename_(filename) {
//     }
//
//     const std::string &getFilename() const {
//         return filename_;
//     }
//
// private:
//     std::string filename_;
// };
//
// void function2() {
//     throw 1;
// }
//
// void function1() {
//     function2();
// }
//
// void function() {
//     function1();
// }
//
// int main() {
//     std::vector<int> vec = {1, 2, 3, 4, 5};
//     int sum = std::accumulate(vec.begin(), vec.end(), 0);
//     std::cout << "Sum: " << sum << std::endl;
//
//     std::vector<Order> vec2 = {Order{1}, Order{2}, Order{3}};
//     Order sum2 = std::accumulate(vec2.begin(), vec2.end(), Order());
//     std::cout << "Sum2: " << sum2.order_lit << std::endl;
//     std::cout << "*********************************" << std::endl;
//
//
//     std::vector<int> vec3(5);
//     std::iota(vec3.begin(), vec3.end(), 3);
//     for (const auto &v: vec3) {
//         std::cout << v << " ";
//     }
//     std::cout << std::endl;
//
//
//     // std::vector<MyClass> vec4(5);
//     // std::iota(vec4.begin(), vec4.end(), MyClass());
//     // for (const auto &v: vec4) {
//     //     std::cout << v << " ";
//     // }
//     std::cout << std::endl;
//     std::cout << "*********************************" << std::endl;
//
//
//     std::vector<int> vec5 = {3, 1, 4, 1, 5, 9, 2};
//     std::sort(vec5.begin(), vec5.end());
//     for (const auto &v: vec5) {
//         std::cout << v << " ";
//     }
//     std::cout << std::endl;
//     std::cout << "*********************************" << std::endl;
//
//     std::vector<Person> people = {
//         {"Bob", 20},
//         {"Bob2", 20},
//         {"Bob3", 20},
//         {"Bob4", 20},
//         {"Charlie", 30},
//         {"Charlie2", 30},
//         {"Charlie3", 30},
//         {"Charlie4", 30},
//         {"Charlie5", 30},
//         {"Charlie6", 30},
//         {"Charlie7", 30},
//         {"Charlie8", 30},
//         {"Alice1", 30},
//         {"Alice2", 40},
//         {"Alice3", 30},
//         {"Alice4", 30},
//         {"Alice5", 30},
//         {"Alice6", 30},
//         {"Dave", 20},
//         {"Dave2", 20},
//         {"Dave3", 20},
//         {"Dave4", 20},
//     };
//     std::vector<Person> people2 = people;
//     std::vector<Person> people3 = people;
//     std::sort(people.begin(), people.end(), compare_by_age);
//     for (const auto &person: people) {
//         std::cout << person.name << " (" << person.age << ")" << std::endl;
//     }
//     std::cout << "*********************************" << std::endl;
//
//     std::stable_sort(people2.begin(), people2.end(), compare_by_age);
//     for (const auto &person: people2) {
//         std::cout << person.name << " (" << person.age << ")" << std::endl;
//     }
//     std::cout << "*********************************" << std::endl;
//
//     std::vector<int> vec6 = {9, 3, 7, 1, 3, 6, 5, 8, 2, 4};
//     std::partial_sort(vec6.begin(), vec6.begin() + 5, vec6.end());
//     for (const auto &v: vec6) {
//         std::cout << v << " ";
//     }
//     std::cout << std::endl;
//     std::cout << "*********************************" << std::endl;
//
//     std::vector<int> vec7 = {9, 1, 8, 3, 7, 2, 6, 4, 5};
//     std::nth_element(vec7.begin(), vec7.begin() + 4, vec7.end());
//     std::cout << "Element at index 4: " << vec7[4] << std::endl;
//     std::cout << "Array after nth_element: ";
//     for (const auto &v: vec7) {
//         std::cout << v << " ";
//     }
//     std::cout << std::endl;
//     std::cout << "*********************************" << std::endl;
//
//     std::sort(people3.begin(), people3.end(), compare_by_age);
//     auto iter = std::lower_bound(people3.begin(), people3.end(), Person{.name = "abc", .age = 40});
//     std::cout << iter->name << std::endl;
//     std::cout << "*********************************" << std::endl;
//
//     std::vector<int> vec8 = {1, 2, 3, 3, 3, 4, 5};
//     auto range = std::equal_range(vec8.begin(), vec8.end(), 3);
//     std::cout << "First occurrence of 3 at position: " << std::distance(vec8.begin(), range.first) << std::endl;
//     std::cout << "Last occurrence of 3 at position: " << std::distance(vec8.begin(), range.second) - 1 << std::endl;
//     std::cout << "*********************************" << std::endl;
//
//     int a;
//     int b;
//     std::cout << "请输入 a" << std::endl;
//     std::cin >> a;
//     std::cout << "请输入 b" << std::endl;
//     std::cin >> b;
//     Result result = divide(a, b);
//     if (result.divide_by_zero) {
//         std::cout << "divide by zero, fatal action" << std::endl;
//     } else {
//         std::cout << result.real_value << std::endl;
//     }
//
//     try {
//         int res = divide2(a, b);
//     } catch (const MyError &e) {
//         std::cout << e.message << std::endl;
//     } catch (int e) {
//         std::cout << e << std::endl;
//     }
//
//     try {
//         int res = divide3(a, b);
//     } catch (const MyError &e) {
//         std::cout << e.message << std::endl;
//     } catch (int e) {
//         std::cout << e << std::endl;
//     }
//     std::cout << "*********************************" << std::endl;
//
//     std::vector<int> vecs = {1, 2, 3};
//     try {
//         std::cout << vecs.at(3) << std::endl;
//     } catch (const std::out_of_range &e) {
//         std::cout << e.what() << std::endl;
//     }
//     std::cout << "*********************************" << std::endl;
//
//     try {
//         std::string filename = "important_data.txt";
//         // 模拟文件打开失败的情况
//         if (true) {
//             throw FileOpenError(filename);
//         }
//         // ... 其他文件操作 ...
//     } catch (const FileOpenError &e) {
//         std::cerr << "File error: " << e.what() << std::endl;
//         std::cerr << "Filename: " << e.getFilename() << std::endl;
//     } catch (const std::runtime_error &e) {
//         std::cerr << "Runtime error: " << e.what() << std::endl;
//     }
//     std::cout << "*********************************" << std::endl;
//
//     try {
//         function();
//     } catch (int &e) {
//         std::cout << e << std::endl;
//     }
//
//     return 0;
// }

// day17
// ******************************************************
// class Complex {
// public:
//     Complex(int real, int imag) : real(real), imag(imag) {
//     }
//
//     friend Complex operator+(const Complex &c1, const Complex &c2);
//
//     friend std::ostream &operator<<(std::ostream &os, const Complex &c);
//
// private:
//     int real;
//     int imag;
// };
//
// Complex operator+(const Complex &c1, const Complex &c2) {
//     return {c1.real + c2.real, c1.imag + c2.imag};
// }
//
// std::ostream &operator<<(std::ostream &os, const Complex &c) {
//     os << "{real: " << c.real << ", imag: " << c.imag << "}";
//     return os;
// }
//
// class Box {
// private:
//     double width;
//
// public:
//     Box(double w) : width(w) {
//     }
//
//     friend void printWidth(Box &b); // friend 声明友元函数
// };
//
// void printWidth(Box &b) {
//     std::cout << "Width of box: " << b.width << std::endl; // 访问私有成员
// }
//
// class Cuboid2 {
// private:
//     double length, width, height;
//
// public:
//     Cuboid2(double l, double w, double h) : length(l), width(w), height(h) {
//     }
//
//     // 友元函数声明
//     friend double calculateVolume(const Cuboid2 &c);
//
//     friend void updateDimensions(Cuboid2 &c, double l, double w, double h);
// };
//
// // 友元函数定义
// double calculateVolume(const Cuboid2 &c) {
//     return c.length * c.width * c.height; // 访问私有成员
// }
//
// void updateDimensions(Cuboid2 &c, double l, double w, double h) {
//     c.length = l;
//     c.width = w;
//     c.height = h; // 修改私有成员
// }
//
// class ClassA {
// private:
//     int privateMember;
//
// public:
//     ClassA() : privateMember(42) {
//     }
//
//     friend class ClassB; // ClassB 将是 ClassA 的友元类
// };
//
// class ClassB {
// public:
//     void displayPrivateMember(const ClassA &a) {
//         std::cout << "Private member of ClassA: " << a.privateMember << std::endl;
//     }
// };
//
// class Parent {
// private:
//     int parentPrivate;
//
// protected:
//     int parentProtected;
//
// public:
//     Parent() : parentPrivate(10), parentProtected(20) {
//     }
//
//     friend void friendFunction(Parent &p);
// };
//
// void friendFunction(Parent &p) {
//     std::cout << "Parent Private: " << p.parentPrivate << std::endl;
//     std::cout << "Parent Protected: " << p.parentProtected << std::endl;
// }
//
// class Child : public Parent {
// private:
//     int childPrivate;
//
// public:
//     Child() : Parent(), childPrivate(30) {
//     }
//
//     // Note: friendFunction() inherits permission to access Parent's members
//     friend void childFriendFunction(Child &c);
// };
//
// void childFriendFunction(Child &c) {
//     // 可以访问父类的私有和受保护部分
//     friendFunction(c);
//
//     // 仅可以访问子类的受保护成员,无法访问子类私有成员
//     // std::cout << "Child Private: " << c.parentPrivate << std::endl;
//     std::cout << "Child Private: " << c.childPrivate << std::endl;
//     std::cout << "Parent Protected Access via Child: " << c.parentProtected << std::endl;
// }
//
// class Cuboid {
// private:
//     double length, width, height;
//
// public:
//     Cuboid(double l, double w, double h) : length(l), width(w), height(h) {
//     }
//
//     // 友元函数重载 `+` 运算符
//     friend Cuboid operator+(const Cuboid &a, const Cuboid &b);
//
//     // 友元函数重载 `<<` 运算符
//     friend std::ostream &operator<<(std::ostream &os, const Cuboid &c);
// };
//
// // 重载 `+` 运算符
// Cuboid operator+(const Cuboid &a, const Cuboid &b) {
//     double newLength = a.length + b.length;
//     double newWidth = std::max(a.width, b.width);
//     double newHeight = std::max(a.height, b.height);
//     return Cuboid(newLength, newWidth, newHeight);
// }
//
// // 重载 `<<` 运算符
// std::ostream &operator<<(std::ostream &os, const Cuboid &c) {
//     os << "Cuboid(" << c.length << ", " << c.width << ", " << c.height << ")";
//     return os;
// }
//
// struct Person {
//     std::string name;
//     int age;
//     std::string city;
// };
//
// // 解析CSV格式的字符串
// std::vector<Person> parseCSV(const std::string &csvData) {
//     std::vector<Person> people;
//     std::istringstream ss(csvData);
//     std::string line;
//
//     // 跳过标题行
//     std::getline(ss, line);
//
//     while (std::getline(ss, line)) {
//         std::istringstream lineStream(line);
//         std::string field;
//         std::vector<std::string> fields;
//
//         // 分割每行的字段
//         while (std::getline(lineStream, field, ',')) {
//             fields.push_back(field);
//         }
//
//         if (fields.size() >= 3) {
//             Person p;
//             p.name = fields[0];
//             p.age = std::stoi(fields[1]);
//             p.city = fields[2];
//             people.push_back(p);
//         }
//     }
//
//     return people;
// }
//
// // 将人员数据转换为HTML表格
// std::string toHTMLTable(const std::vector<Person> &people) {
//     std::ostringstream html;
//     html << "<table border='1'>\n";
//     html << "<tr><th>姓名</th><th>年龄</th><th>城市</th></tr>\n";
//
//     for (const auto &p: people) {
//         html << "<tr><td>" << p.name
//                 << "</td><td>" << p.age
//                 << "</td><td>" << p.city
//                 << "</td></tr>\n";
//     }
//
//     html << "</table>";
//     return html.str();
// }
//
// int main() {
//     Complex c1(1, 2);
//     Complex c2(3, 4);
//     Complex result = c1 + c2;
//     std::cout << result << std::endl;
//     std::cout << "*********************************" << std::endl;
//
//     Box box(10.0);
//     printWidth(box);
//     std::cout << "*********************************" << std::endl;
//
//     Cuboid2 c3(2.0, 3.0, 4.0);
//     std::cout << "Initial Volume of c1: " << calculateVolume(c3) << std::endl;
//     updateDimensions(c3, 5.0, 5.0, 5.0);
//     std::cout << "Updated Volume of c1: " << calculateVolume(c3) << std::endl;
//     std::cout << "*********************************" << std::endl;
//
//     ClassA a;
//     ClassB b;
//     b.displayPrivateMember(a);
//     std::cout << "*********************************" << std::endl;
//
//     Child c;
//     childFriendFunction(c);
//     std::cout << "*********************************" << std::endl;
//
//     Cuboid c4(3.0, 2.0, 1.0);
//     Cuboid c5(4.0, 1.0, 5.0);
//     Cuboid result2 = c4 + c5;
//
//     std::cout << "Cuboid 1: " << c4 << "\n";
//     std::cout << "Cuboid 2: " << c5 << "\n";
//     std::cout << "Result: " << result2 << "\n";
//     std::cout << "*********************************" << std::endl;
//
//     char ch;
//     std::cout << "请输入一个字符：";
//     std::cin.get(ch); // 读取一个字符（包括空格）
//     std::cout << "您输入的字符是：" << ch << std::endl;
//     char buffer[80];
//     std::cout << "请输入一行文本：";
//     std::cin.ignore(); // 清除缓冲区中的换行符
//     std::cin.getline(buffer, 80); // 读取一行文本
//     std::cout << "您输入的文本是：" << buffer << std::endl;
//     // 使用 string 和 getline() 读取一行
//     std::string line;
//     std::cout << "请输入另一行文本 (string): ";
//     std::getline(std::cin, line); // string版本的getline不需要ignore()
//     std::cout << "您输入的文本是: " << line << std::endl;
//     std::cout << "*********************************" << std::endl;
//
//     char ch1 = 'A';
//     std::cout.put(ch1); // 输出字符 'A'
//     std::cout << std::endl;
//     const char *str = "Hello, world!";
//     std::cout.write(str, 5); // 输出字符串的前 5 个字符 "Hello"
//     std::cout << std::endl;
//     std::cout << "*********************************" << std::endl;
//
//     // 格式化输出学生成绩表格
//     std::cout << std::left << std::setw(15) << "姓名"
//             << std::setw(8) << "语文"
//             << std::setw(8) << "数学"
//             << std::setw(8) << "英语"
//             << std::setw(10) << "平均分" << std::endl;
//
//     std::cout << std::string(49, '-') << std::endl;
//     std::cout << std::left << std::setw(15) << "张三"
//             << std::setw(8) << 85
//             << std::setw(8) << 92
//             << std::setw(8) << 78
//             << std::fixed << std::setprecision(2) << std::setw(10) << (85 + 92 + 78) / 3.0 << std::endl;
//
//     std::cout << std::left << std::setw(15) << "李四"
//             << std::setw(8) << 76
//             << std::setw(8) << 88
//             << std::setw(8) << 90
//             << std::fixed << std::setprecision(2) << std::setw(10) << (76 + 88 + 90) / 3.0 << std::endl;
//     std::cout << "*********************************" << std::endl;
//
//     // 使用原始字符串字面量表示文件路径
//     std::ifstream inputFile(R"(example.txt)"); // 打开文件
//     if (inputFile.is_open()) {
//         // 检查文件是否成功打开
//         std::string line;
//         while (std::getline(inputFile, line)) {
//             // 逐行读取
//             std::cout << line << std::endl; // 输出每一行
//         }
//         inputFile.close(); // 关闭文件
//     } else {
//         std::cerr << "无法打开文件！" << std::endl;
//     }
//     std::cout << "*********************************" << std::endl;
//
//     std::ofstream outputFile("output.txt"); // 以写入模式打开文件
//     //等效于 std::ofstream outputFile("output.txt", std::ios::out);
//     if (outputFile.is_open()) {
//         outputFile << "Hello, file!" << std::endl;
//         outputFile << "This is a new line." << std::endl;
//         outputFile.close();
//     } else {
//         std::cerr << "无法创建文件！" << std::endl;
//     }
//     // 以二进制模式写入文件
//     std::ofstream binaryFile("data.bin", std::ios::binary);
//     if (binaryFile.is_open()) {
//         int data[] = {97, 2, 3, 4, 5};
//         // 使用 reinterpret_cast 将整数数组转换为字符指针
//         binaryFile.write(reinterpret_cast<char *>(data), sizeof(data));
//         binaryFile.close();
//     } else {
//         std::cerr << "无法创建二进制文件！" << std::endl;
//     }
//     std::cout << "*********************************" << std::endl;
//
//     // 创建一个简单的数据库文件
//     std::ofstream dbFile("database.txt");
//     dbFile << "001 张三 25 北京\n";
//     dbFile << "002 李四 30 上海\n";
//     dbFile << "003 王五 28 广州\n";
//     dbFile.close();
//     // 修改李四的年龄为31
//     std::fstream file("database.txt", std::ios::in | std::ios::out);
//     if (!file.is_open()) {
//         std::cerr << "无法打开数据库文件！" << std::endl;
//         return 1;
//     }
//     std::string line2;
//     while (std::getline(file, line2)) {
//         if (line2.find("002 李四") != std::string::npos) {
//             // 找到李四的记录，计算当前位置
//             std::streampos pos = file.tellg();
//             // 回到行首
//             file.seekp(pos - line2.length() - 3);
//             // 写入修改后的记录
//             file << "002 李四 31 上海\n";
//             break;
//         }
//     }
//     file.close();
//     // 显示修改后的文件内容
//     std::ifstream displayFile("database.txt");
//     std::cout << "修改后的数据库内容：" << std::endl;
//     while (std::getline(displayFile, line2)) {
//         std::cout << line2 << std::endl;
//     }
//     displayFile.close();
//     std::cout << "*********************************" << std::endl;
//
//     // 模拟CSV格式的数据
//     std::string csvData = "姓名,年龄,城市\n"
//             "张三,25,北京\n"
//             "李四,30,上海\n"
//             "王五,28,广州\n";
//     // 解析CSV数据
//     std::vector<Person> people = parseCSV(csvData);
//     // 转换为HTML表格
//     std::string htmlTable = toHTMLTable(people);
//     // 输出结果
//     std::cout << "生成的HTML表格：" << std::endl;
//     std::cout << htmlTable << std::endl;
//
//     return 0;
// }
