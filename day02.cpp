#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string>
#include <fstream>


int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    if (a > b) {
        std::cout << "a > b " << std::endl;
    } else if (a == b) {
        std::cout << "a == b " << std::endl;
    } else {
        std::cout << "a < b " << std::endl;
    }
    if (a < b && b > c) {
    }

    char ch;
    std::cout << "请输入一个字符: ";
    std::cin >> ch;
    // 完整的 if-else 结构
    if (ch >= 'A' && ch <= 'Z') {
        std::cout << ch << " 是大写字母" << std::endl;
    } else {
        std::cout << ch << " 不是大写字母" << std::endl;
    }
    // 单行 if 语句（不推荐在复杂逻辑中使用，易读性较差）
    if (ch >= 'a' && ch <= 'z') {
        std::cout << ch << " 是小写字母" << std::endl;
    }

    int i = 1, sum = 0, j = 0;
    while (i < 6) {
        sum += i++;
    }
    std::cout << "1 到 5 的和为: " << sum << std::endl;
    do {
    } while (j++ < 6);
    std::cout << "1 到 5 的和为: " << sum << std::endl;

    int sum1 = 0, sum2 = 0;
    for (int i = 1; i < 6; i++) {
        sum1 += i;
    }
    int k = 0;
    for (;;) {
        sum2 += k++;
        if (k > 5) {
            break;
        }
    }
    std::cout << "1 到 5 的和为: " << sum1 << std::endl;
    std::cout << "1 到 5 的和为: " << sum2 << std::endl;

    int factorial = 1;
    for (int i = 1; i <= 10; i++) {
        factorial *= i;
    }
    std::cout << "10 的阶乘为: " << factorial << std::endl;

    int array[3] = {1, 2};
    for (int i: array) {
        std::cout << i << std::endl;
    }
    std::cout << array[4] << std::endl;
    std::cout << array[10] << std::endl;
    std::cout << sizeof array << std::endl;

    int array2[0];
    int array3[] = {};
    std::cout << sizeof array3 << std::endl;
    int numbers[5] = {10, 20, 30, 40, 50};
    int sum3 = 0;
    for (int number: numbers) {
        sum3 += number;
    }
    // 将 sum 强制转换为 double 类型，以获得浮点数结果
    double average = static_cast<double>(sum3) / 5;
    std::cout << "数组元素的平均值为: " << average << std::endl;

    char myarr_char[3] = {'a', 'b', 'c'};
    std::cout << sizeof myarr_char << std::endl;
    char mystr[] = {'a', 'b', 'c', '\0', 'd'};
    std::cout << sizeof mystr << std::endl;
    std::cout << mystr[2] << std::endl;
    std::cout << mystr[3] << std::endl;
    std::cout << mystr[4] << std::endl;
    char *mystr1 = "abc";
    if (strcmp(mystr, mystr1)) {
        std::cout << "Different" << std::endl;
    } else {
        std::cout << "Same" << std::endl;
    };;;
    1;;;
    2;;;;;;;

    return 0;
}
