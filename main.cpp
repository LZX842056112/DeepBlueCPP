#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string>

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
void function(int arr[], int size) {
}

int add(int a, int b) {
    return a + b;
}

int mul(int a, int b) {
    return a * b;
}

// 一个使用函数指针作为参数的函数
void executeOperation(int a, int b, int (*operation)(int, int)) {
    std::cout << "执行结果: " << (*operation)(a, b) << std::endl;
    std::cout << "执行结果: " << operation(a, b) << std::endl;
}

// int add(double a, double b) {
//     return a + b;
// }

// float add(float a, float b) {
//     return a + b;
// }

// 重载的 sum 函数，处理两个整数
int sum(int a, int b) {
    std::cout << "调用 sum(int, int)" << std::endl;
    return a + b;
}

// 重载的 sum 函数，处理三个整数
int sum(int a, int b, int c) {
    std::cout << "调用 sum(int, int, int)" << std::endl;
    return a + b + c;
}

// 重载的 sum 函数，处理两个 double 类型
double sum(double a, double b) {
    std::cout << "调用 sum(double, double)" << std::endl;
    return a + b;
}

double circle_area(double r, double PI = 3.1415926) {
    return PI * r * r;
}

inline int add2(int a, int b) {
    return a + b;
}

// 内联函数：计算两个整数的最大值
inline int max(int a, int b) {
    return a > b ? a : b;
}

// 内联函数：计算平方
inline double square(double x) {
    return x * x;
}

int main() {
    int myarr[4] = {1, 2, 3, 4};
    int (*ptr)[4] = &myarr;
    std::cout << (*ptr)[1] << std::endl;
    std::cout << sizeof "" << std::endl;
    std::cout << sizeof nullptr << std::endl;

    char str1[] = "Hello"; // 编译器会自动在 "Hello" 后面添加 '\0'
    char str2[] = ""; // 空字符串，实际上是 {'\0'}
    char str3[10]; // 定义一个可以存储 9 个字符的字符数组，留一个位置给 '\0'
    char *p_str = str1; // 指针 p_str 指向 str1 的第一个元素 'H'
    std::cout << "字符串 str1 的内容: " << str1 << std::endl;
    std::cout << "字符串 str1 的长度 (不包含 '\\0'): " << strlen(str1) << std::endl; // 输出 5
    std::cout << "str1[0] 的值: " << static_cast<char>(str1[0]) << std::endl;
    std::cout << "str1[0] 的地址: " << static_cast<void *>(&str1[0]) << std::endl; // 强制转换为 void* 以打印地址
    std::cout << "p_str 指向的地址: " << static_cast<void *>(p_str) << std::endl; // 两者地址相同
    // 注意：直接打印字符数组或字符指针，会输出整个字符串直到 '\0'
    std::cout << "str2 的内容: " << str2 << std::endl;
    std::cout << "字符串 str2 的长度: " << strlen(str2) << std::endl; // 输出 0

    int myarr2[2][2][3] = {
        {
            {1, 2, 3},
            {4, 5, 6}
        },
        {
            {1, 2, 3},
            {4, 5, 6}
        }
    };
    int myarr4[2][3] = {1, 2, 3, 4, 5, 6};
    int myarr3[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    int (*x)[2][3] = &myarr3;
    int (*myptr)[3] = myarr3;
    myptr++;

    std::cout << "**************" << std::endl;
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    // matrix 是一个指向包含 3 个 int 的数组的指针 (行指针)
    int (*p_row)[3] = matrix;
    std::cout << "二维数组 matrix 的首地址: " << static_cast<void *>(matrix) << std::endl;
    std::cout << "行指针 p_row 的值 (指向第一行): " << static_cast<void *>(p_row) << std::endl; // 与 matrix 地址相同
    std::cout << "matrix[0] 的地址: " << static_cast<void *>(matrix[0]) << std::endl; // 第一行的首地址，与 matrix 相同
    // p_row + 1  移动到下一行（移动了 3 个 int 的大小）
    std::cout << "p_row + 1 的值 (指向第二行): " << static_cast<void *>(p_row + 1) << std::endl;
    std::cout << "matrix[1] 的地址: " << static_cast<void *>(matrix[1]) << std::endl; // 第二行的首地址
    // 使用行指针访问二维数组元素
    // *(p_row + 1)  解引用行指针，得到第二行的首地址，类型是 int*
    // *(p_row + 1) + 2  在第二行的首地址上偏移 2 个 int 的位置，指向 matrix[1][2]
    // *(*(p_row + 1) + 2)  解引用，得到 matrix[1][2] 的值
    std::cout << "matrix[1][2] 的值为: " << *(*(p_row + 1) + 2) << std::endl;

    // int (*ptr_function)(int, int) = &add;
    int (*ptr_function)(int, int) = add;
    std::cout << (*ptr_function)(1, 2) << std::endl;
    std::cout << ptr_function(1, 2) << std::endl;
    void (*ptr_function2)(int [], int) = function;
    std::cout << "**************" << std::endl;

    // 声明一个指向返回 int，接受两个 int 参数的函数的指针
    int (*funcPtr)(int, int);
    // 将 add 函数的地址赋值给 funcPtr
    funcPtr = add;
    // 通过函数指针调用 add 函数
    int result = funcPtr(5, 3);
    std::cout << "通过函数指针调用 add: " << result << std::endl;
    // 将 add 函数作为参数传递给 executeOperation 函数
    executeOperation(10, 5, &add);
    executeOperation(10, 5, mul);
    std::cout << "**************" << std::endl;

    int a = 9;
    int b = 6;
    double c = 9.0;
    double d = 6.0;
    float e = 9.0f;
    float f = 6.0f;
    std::cout << add(a, b) << std::endl;
    std::cout << add(c, d) << std::endl;
    std::cout << add(e, f) << std::endl;
    std::cout << "**************" << std::endl;

    std::cout << "sum(2, 3) = " << sum(2, 3) << std::endl; // 调用第一个 sum 函数
    std::cout << "sum(2, 3, 4) = " << sum(2, 3, 4) << std::endl; // 调用第二个 sum 函数
    std::cout << "sum(2.5, 3.5) = " << sum(2.5, 3.5) << std::endl; // 调用第三个 sum 函数
    std::cout << "**************" << std::endl;

    std::cout << circle_area(1) << std::endl;
    std::cout << circle_area(1, 3.14) << std::endl;

    int res = add2(a, b);
    std::cout << res << std::endl;
    int x2 = 10, y = 5;
    // 编译器可能会将 max(x, y) 的代码直接替换到这里
    std::cout << "最大值: " << max(x2, y) << std::endl;
    double num = 3.5;
    // 编译器可能会将 square(num) 的代码直接替换到这里
    std::cout << "平方: " << square(num) << std::endl;


    return 0;
}
