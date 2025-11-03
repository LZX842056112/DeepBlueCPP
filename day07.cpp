#include <iostream>
#include <fstream>

// 计算阶乘
int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

// 使用递归计算斐波那契数列
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

struct MyStruct {
    int x;
    double y;
};

int *createOnHeap() {
    int *num = new int(100); // 在堆区分配内存
    return num;
}

void functionOnStack() {
    int localVar = 50; // 在栈区分配内存
    std::cout << "栈区变量 localVar 的地址: " << &localVar << std::endl;
}

int a = 0;

int func1() {
    a++;
    std::cout << a << std::endl;
    static int b = 1;
    b++;
    std::cout << b << std::endl;
    return a;
}

// 全局变量
static int globalVar = 10;

void func() {
    // 局部变量
    int localVar = 20;
    // static 静态局部变量
    static int staticVar = 30;
    static int *ptr = new int(100);

    std::cout << "函数 func 被调用" << std::endl;
    std::cout << "全局变量: " << globalVar << "，地址: " << &globalVar << std::endl;
    std::cout << "局部变量: " << localVar << "，地址: " << &localVar << std::endl;
    std::cout << "静态变量: " << staticVar << "，地址: " << &staticVar << std::endl;

    localVar++;
    staticVar++;
}

// 值传递
void swapByValue(int a, int b) {
    std::cout << "值传递函数内部：交换前 a = " << a << ", b = " << b << std::endl;
    int temp = a;
    a = b;
    b = temp;
    std::cout << "值传递函数内部：交换后 a = " << a << ", b = " << b << std::endl;
}

// 指针传递
void swapByPointer(int *a, int *b) {
    std::cout << "指针传递函数内部：交换前 *a = " << *a << ", *b = " << *b << std::endl;
    int temp = *a;
    *a = *b;
    *b = temp;
    std::cout << "指针传递函数内部：交换后 *a = " << *a << ", *b = " << *b << std::endl;
}

// 引用传递
void swapByReference(int &a, int &b) {
    std::cout << "引用传递函数内部：交换前 a = " << a << ", b = " << b << std::endl;
    int temp = a;
    a = b;
    b = temp;
    std::cout << "引用传递函数内部：交换后 a = " << a << ", b = " << b << std::endl;
}

void modifyArray(int arr[], int size) {
    // 实际上 arr 被当作 int* 处理
    std::cout << "函数内部 sizeof(arr): " << sizeof(arr) << std::endl; // 输出指针的大小，而非数组大小
    for (int i = 0; i < size; ++i) {
        arr[i] *= 2;
    }
}


int main() {
    char xx = 'a';
    double yy = 3.14;
    char *ptr_x = &xx;
    double *ptr_y = &yy;
    char *ptr_z = (char *) (ptr_y);

    int num = 5;
    std::cout << num << " 的阶乘是: " << factorial(num) << std::endl;
    std::cout << "斐波那契数列第 10 项是: " << fibonacci(10) << std::endl;

    int n;
    std::cout << "请输入一个整数 n，并要求程序分配 n个整数的空间" << std::endl;
    std::cin >> n;
    // int arr[n]; // 它不是 C+标准支持的行为，ISO
    int *ptr = new int[n];
    for (int i = 0; i < n; i++) {
        ptr[i] = i + 2;
    }
    delete[] ptr;
    ptr = nullptr;

    MyStruct *ptr2 = new MyStruct;
    ptr2->x = 100;
    ptr2->y = 100.1;

    std::cout << ptr2->x << " " << ptr2->y << std::endl;

    delete ptr2;
    ptr2 = nullptr;

    MyStruct *ptr1 = new MyStruct[2];

    delete[] ptr1;
    ptr1 = nullptr;

    // 使用 new 分配一个 int 类型的内存空间
    int *ptr3 = new int;
    *ptr3 = 10;
    std::cout << "ptr3 指向的值: " << *ptr3 << std::endl;
    // 使用 delete 释放内存
    delete ptr3;
    ptr3 = nullptr; // 释放后将指针置空，防止悬 dangling 指针

    std::cout << std::endl;

    // 使用 new [] 分配一个包含 5 个 int 类型的数组
    int *arr = new int[5];
    for (int i = 0; i < 5; ++i) {
        arr[i] = i * 2;
    }
    std::cout << "动态分配的数组元素：";
    for (int i = 0; i < 5; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    // 使用 delete [] 释放数组内存
    delete[] arr;
    arr = nullptr; // 释放后将指针置空
    delete[] arr;
    std::cout << "***************" << std::endl;

    // 栈区变量
    int a = 10;
    std::cout << "栈区变量 a 的地址: " << &a << std::endl;
    // 堆区变量
    int *b = new int;
    *b = 20;
    std::cout << "堆区变量 b 的地址: " << b << std::endl;
    functionOnStack();
    int *heapVar = createOnHeap();
    std::cout << "堆区变量 heapVar 的地址: " << heapVar << std::endl;
    std::cout << "堆区变量 heapVar 指向的值: " << *heapVar << std::endl;
    delete b;
    b = nullptr;
    delete heapVar;
    heapVar = nullptr;

    func1();
    func1();
    std::cout << "main 函数中的全局变量: " << globalVar << std::endl;
    func();
    func();


    int x = 10, y = 20;
    std::cout << "交换前：x = " << x << ", y = " << y << std::endl;
    // 值传递
    swapByValue(x, y);
    std::cout << "值传递后：x = " << x << ", y = " << y << std::endl;
    // 指针传递
    swapByPointer(&x, &y);
    std::cout << "指针传递后：x = " << x << ", y = " << y << std::endl;
    // 引用传递
    swapByReference(x, y);
    std::cout << "引用传递后：x = " << x << ", y = " << y << std::endl;


    int arr2[5] = {1, 2, 3, 4, 5};
    std::cout << "函数外部 sizeof(arr): " << sizeof(arr2) << std::endl; // 输出整个数组的大小
    modifyArray(arr2, 5);
    std::cout << "修改后的数组：";
    for (int i = 0; i < 5; ++i) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl; // 输出：2 4 6 8 10


    // 使用 new 分配一个整数
    int *p = new int;
    *p = 10;
    std::cout << "*p: " << *p << std::endl;
    delete p; // 释放单个对象的内存
    p = nullptr;
    // 使用 new[] 分配一个包含 5 个整数的数组
    int *arr3 = new int[5];
    for (int i = 0; i < 5; ++i) {
        arr3[i] = i * 2;
    }
    std::cout << "动态分配的数组：";
    for (int i = 0; i < 5; ++i) {
        std::cout << arr3[i] << " ";
    }
    std::cout << std::endl; // 输出：0 2 4 6 8
    delete[] arr3; // 释放数组内存
    arr3 = nullptr;

    int arr4[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i <= 5; ++i) {
        // 错误：循环条件应为 i < 5
        std::cout << arr4[i] << " ";
    }
    std::cout << std::endl; // 最后一个访问 arr[5] 越界

    return 0;
}
