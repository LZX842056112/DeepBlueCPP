#include <iostream>
#include <utility>
#include <algorithm>
#include <iomanip>
#include <fstream>

#include <memory>

class MyClass {
public:
    MyClass() {
        std::cout << "construct ..." << std::endl;
        x = new int(9);
    }

    ~MyClass() {
        std::cout << "deconstruct ..." << std::endl;
        delete x;
        x = nullptr;
    }

    int *x;
};

void process(MyClass *ptr) {
    *ptr->x = 100;
}

void process2(std::shared_ptr<MyClass> ptr) {
    *ptr->x = 100;
    std::cout << ptr.use_count() << std::endl;
}

void process3(std::shared_ptr<MyClass> ptr) {
    *ptr->x = 200;
    process2(ptr);
    std::cout << ptr.use_count() << std::endl;
}

class Complex {
public:
    Complex(const int r, const int i) : real(r), imag(i) {
    }

    Complex operator+(const Complex &other) {
        std::cout << "call member fun" << std::endl;
        return Complex(this->real + other.real, this->imag + other.imag);
    }

    int real;
    int imag;
};

void print(const Complex &c) {
    std::cout << "real = " << c.real << " " << "imag = " << c.imag << std::endl;
}

Complex complex_add(const Complex &c1, const Complex c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

Complex operator+(const Complex &c1, const Complex c2) {
    std::cout << "call global fun" << std::endl;
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

std::ostream &operator<<(std::ostream &os, const Complex &c) {
    os << "{" << "\n";
    os << "\treal: " << c.real << "\n";
    os << "\timag: " << c.imag << "\n";
    os << "}";
    return os;
}

int main() {
    {
        {
            MyClass *ptr_my = new MyClass;
            delete ptr_my;
            ptr_my = nullptr;
        }
        std::cout << "**************************" << std::endl;

        std::unique_ptr<MyClass> ptr_my2 = std::make_unique<MyClass>();
        std::unique_ptr<MyClass> ptr2 = std::move(ptr_my2);
        std::cout << "**************************" << std::endl;

        std::shared_ptr<MyClass> ptr_my3 = std::make_shared<MyClass>();
        std::cout << ptr_my3.use_count() << std::endl;
        process3(ptr_my3);
        std::cout << ptr_my3.use_count() << std::endl;
        std::cout << "**************************" << std::endl;

        Complex c1(1, 2);
        print(c1);
        Complex c2(3, 4);
        print(c2);
        Complex result = complex_add(c1, c2);
        Complex result2 = c1 + c2;
        Complex result3 = c1.operator+(c2);
        print(result);
        print(result2);
        print(result3);
        std::cout << "**************************" << std::endl;
        std::cout << c1 << std::endl;
        std::cout << c2 << std::endl;
        std::cout << result3 << std::endl;
    }
    return 0;
}
