#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

class Base {
public:
    Base() : x(60) {
    }

    virtual void display() {
    }

    int x;
};

class Derived : public Base {
public:
    Derived() : Base(), y(100) {
    }

    int y;
};

class Animal {
public:
    virtual void speak() = 0; // 纯虚函数
};

class Dog : public Animal {
public:
    void speak() override {
        std::cout << "Woof!" << std::endl;
    } // 必须实现 speak()
};

class MyClass {
public:
    MyClass() {
        std::cout << "consturct...." << std::endl;
        ptr = new int(9);
    }

    MyClass(const MyClass &other) {
        ptr = new int;
        *ptr = *other.ptr;
    }

    ~MyClass() {
        std::cout << "deconsturct...." << std::endl;
        delete ptr;
        ptr = nullptr;
    }

    int *ptr;
};

class MyClass2 {
public:
    int *data;

    MyClass2(int value) {
        data = new int;
        *data = value;
    }

    // 默认拷贝构造函数 (浅拷贝)
};

class MyClass3 {
public:
    int *data;

    MyClass3(int value) {
        data = new int;
        *data = value;
    }

    // 自定义拷贝构造函数 (深拷贝)
    MyClass3(MyClass3 &other) {
        data = new int(*other.data);
    }

    ~MyClass3() {
        delete data;
    }
};

int main() {
    // std::string str = "a123bb44b44";
    std::string str = "123bb44b44";
    int a = std::stoi(str);
    std::cout << "a = " << a << std::endl;
    std::cout << "*********************" << std::endl;

    int i = 300;
    char c = i; // 警告：数据丢失，因为 char 只能存储 -128 到 127 的值
    std::cout << "c = " << c << std::endl;
    std::cout << "*********************" << std::endl;

    // Base *b = new Base();
    // Derived *d = static_cast<Derived *>(b); // 错误！b 实际指向 Base 对象
    // std::cout << d->y << std::endl;
    // delete d; // 未定义行为

    Base *b = new Derived(); // 现在 b 指向 Derived 对象
    Derived *d = dynamic_cast<Derived *>(b); // 安全的向下转型
    std::cout << d->x << std::endl;
    std::cout << d->y << std::endl;

    if (d) {
        std::cout << "Successful downcasting." << std::endl;
        delete d;
    } else {
        std::cout << "Failed downcasting." << std::endl;
    }
    std::cout << "*********************" << std::endl;

    Dog dog;
    dog.speak(); // 输出: Woof!
    std::cout << "*********************" << std::endl;

    MyClass m1;
    std::cout << *m1.ptr << std::endl;
    std::cout << m1.ptr << std::endl;
    // const MyClass& m2(m1);
    MyClass m2(m1);
    std::cout << *m2.ptr << std::endl;
    std::cout << m2.ptr << std::endl;
    std::cout << "*********************" << std::endl;

    MyClass2 obj1(10);
    MyClass2 obj2 = obj1; // 浅拷贝
    std::cout << *obj1.data << std::endl; // 输出: 10
    std::cout << *obj2.data << std::endl; // 输出: 10
    delete obj1.data; // 释放内存
    std::cout << "*********************" << std::endl;

    MyClass3 obj3(10);
    MyClass3 obj4 = obj3; // 深拷贝
    std::cout << *obj3.data << std::endl; // 输出: 10
    std::cout << *obj4.data << std::endl; // 输出: 10
    delete obj3.data; // 释放 obj1 的内存
    // obj2.data 指向独立的内存空间，访问安全
    std::cout << *obj4.data << std::endl; // 输出: 10
    std::cout << "*********************" << std::endl;

    return 0;
}
