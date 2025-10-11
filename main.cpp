#include <iostream>
#include <cstring>
#include <stdio.h>

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
