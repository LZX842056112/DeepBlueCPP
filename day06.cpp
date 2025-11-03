#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string>
#include <fstream>

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
