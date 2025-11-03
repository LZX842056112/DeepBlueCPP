#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

class MyClass {
public:
    // 声明静态成员变量
    static int count;

    static void printCount() {
        // 声明静态成员函数
        std::cout << "Count: " << count << std::endl;
    }

private:
    int x;
};

// 在类定义外部初始化静态成员变量
int MyClass::count = 0;

class MyClass2 {
public:
    // MyClass2(int x){
    //     this->x = x;
    // }
    // 尽可能使用这种形式，因为它更快，特殊场合必须用它
    MyClass2(int x, int y) : x(x), y(y) {
    }

    void display() const {
        std::cout << x << ", " << y << std::endl;
    }

private:
    int x;
    int y;
};

class MyClass3 {
public:
    // MyClass2(int x){
    //     this->x = x;
    // }
    // 尽可能使用这种形式，因为它更快，特殊场合必须用它
    MyClass3(int id) : id(id) {
    }

    void display() const {
        std::cout << id << std::endl;
    }

private:
    const int id;
};

class MyClass4 {
public:
    const int value1;
    int &value2;

    MyClass4(int val1, int &val2) : value1(val1), value2(val2) {
        //
    }
};

// 基类
class Animal {
public:
    std::string name;

    Animal(std::string n) : name(n) {
    }

    void eat() { std::cout << name << " is eating." << std::endl; }
};

// 派生类
// final不能被继承
class Bird final : public Animal {
public:
    int wingspan;

    Bird(std::string n, int w) : Animal(n), wingspan(w) {
    }

    void fly() { std::cout << name << " is flying." << std::endl; }
};

class Animal2 {
protected:
    void move() {
        std::cout << "animal can move" << std::endl;
    }
};

class Dog : public Animal2 {
public:
    void func1() {
        move();
    }
};

class hbaDog : public Dog {
public:
    void func2() {
        move();
    }
};

class MyClass5 {
public:
    void print() {
        std::cout << "this is MyClass5" << std::endl;
    }
};

class MyClass6 {
public:
    void print() {
        std::cout << "this is MyClass6" << std::endl;
    }
};

class MyClass7 : public MyClass5, public MyClass6 {
};

class Animal3 {
public:
    void eat() {
        std::cout << "Animal is eating." << std::endl;
    }
};

class Mammal {
public:
    void giveBirth() {
        std::cout << "Mammal is giving birth." << std::endl;
    }
};

class Bat : public Animal3, public Mammal {
public:
    void fly() {
        std::cout << "Bat is flying." << std::endl;
    }
};

class A {
public:
    void print() {
        std::cout << "Class A" << std::endl;
    }

    void print(int i) {
        std::cout << "i = " << i << std::endl;
    }
};

class B {
public:
    void print(float j) {
        std::cout << "j = " << j << std::endl;
    }

    void print() {
        std::cout << "Class A" << std::endl;
    }
};

class C : public A, public B {
public:
    // 发生歧义，需要避免
    // void print() {
    //     std::cout << "Class C" << std::endl;
    // }
    // void print(int i) {
    //     std::cout << "i = " << i << std::endl;
    // }

    // void print(float j) {
    //     std::cout << "j = " << j << std::endl;
    // }
};

int main() {
    // 通过类名访问静态成员变量
    MyClass::count = 10;
    // 通过类名访问静态成员函数
    MyClass::printCount();
    MyClass my;
    // 通过对象访问静态成员变量
    my.count = 20;
    // 通过对象访问静态成员函数
    my.printCount();

    std::cout << sizeof(MyClass) << std::endl;

    MyClass2 my2(1, 2);
    my2.display();

    MyClass3 my3(1);
    my3.display();

    int x = 10;
    MyClass4 my4(5, x);

    Bird sparrow("Sparrow", 20);
    sparrow.eat(); // 调用基类的成员函数
    sparrow.fly(); // 调用派生类的成员函数

    Dog dog;
    hbaDog hb;
    dog.func1();
    hb.func2();
    // dog.age = 5;  // 错误，无法直接访问 protected 成员

    MyClass7 m7;
    m7.MyClass5::print();
    m7.MyClass6::print();

    Bat bat;
    bat.eat();
    bat.giveBirth();
    bat.fly();

    C c;
    c.A::print();
    c.A::print(1);
    c.B::print(1);
    // c.print(1);// 发生歧义，编译错误

    return 0;
}
