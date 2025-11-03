#include <iostream>
#include <stdio.h>
#include <string>
#include <exception>
#include <fstream>


void add(int *a, int *b) {
    (*a)++;
    (*b)++;
}

void add(int &a, int &b) {
    a++;
    b++;
}

int main() {
    char x = 'a';
    std::cout << &x << std::endl;
    printf("%p\n", &x);
    // 指针的本质是一个变量，这个变量里面存储的是另一个变量的地址
    char *pa = &x;
    std::cout << typeid(pa).name() << std::endl;

    int a = 9;
    int *p_a = &a;
    int **p_p_a = &p_a;
    int ***p_p_p_a = &p_p_a;
    std::cout << a << std::endl;
    std::cout << *p_a << std::endl;
    std::cout << **p_p_a << std::endl;
    std::cout << ***p_p_p_a << std::endl;
    std::cout << sizeof *p_a << std::endl;
    std::cout << sizeof **p_p_a << std::endl;
    std::cout << sizeof ***p_p_p_a << std::endl;
    std::cout << p_a << std::endl;
    std::cout << p_p_a << std::endl;
    std::cout << p_p_p_a << std::endl;
    std::cout << sizeof p_a << std::endl;
    std::cout << sizeof p_p_a << std::endl;
    std::cout << sizeof p_p_p_a << std::endl;

    int *pp;
    std::cout << pp << std::endl;
    std::cout << *pp << std::endl;
    int *pp2 = nullptr;
    std::cout << pp2 << std::endl;
    std::cout << *pp2 << std::endl;
    int aa = 9;
    int *p_a1;
    *p_a1 = aa + 1;
    int *p_a2 = nullptr;
    *p_a2 = aa + 1;


    int a1 = 9;
    char b = 'a';
    void *ptr = &a1;
    ptr = &b;
    *(int *) ptr = 10;
    *(char *) ptr = 'b';
    std::cout << a1 << std::endl;
    std::cout << b << std::endl;
    int n = 10;
    void *vp = &n;
    int *ip = static_cast<int *>(vp); // 强制转换为 int*
    std::cout << *ip << std::endl; // 现在可以解引用了

    int a2 = 9;
    char w = 'b';
    int &ra = a2;
    char &rw = w;
    std::cout << ra << std::endl;
    std::cout << rw << std::endl;

    int a3 = 9;
    int b2 = 6;
    int &ra2 = a3;
    ra2 = b2;
    std::cout << a3 << std::endl;
    std::cout << ra2 << std::endl;
    printf("a: %p\nra: %p\n", &a3, &ra2);

    int a4 = 9;
    int b3 = 6;
    add(&a4, &b3);
    std::cout << a4 << std::endl;
    std::cout << b3 << std::endl;
    add(a4, b3);
    std::cout << a4 << std::endl;
    std::cout << b3 << std::endl;

    int a5 = 9;
    int b4 = 6;
    const int *ptr_a = &a5;
    // *ptr_a = 6;
    ptr_a = &b4;
    std::cout << *ptr_a << std::endl;

    int *const ptr_b = &a5;
    *ptr_b = 10;
    // ptr_b = &b;
    std::cout << *ptr_a << std::endl;

    const int *const ptr_c = &a5;
    // *ptr_c = 6;
    // ptr_c = &b;

    return 0;
}
