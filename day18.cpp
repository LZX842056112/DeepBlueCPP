#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include <bitset>

void swap(int &a, int &b) {
    a = a ^ b; //11，10 01
    b = a ^ b; //01 10 11
    a = a ^ b; //01 11 10
}

void checkPermission(int permissions, int requiredPermission) {
    if (permissions & requiredPermission) {
        std::cout << "Permission granted." << std::endl;
    } else {
        std::cout << "Permission denied." << std::endl;
    }
}

template<int Size>
class BitSet {
public:
    BitSet(int n) : bits(n) {
    } // 模板构造函数，无需参数，直接使用模板参数Size

    void flip(int n) {
        bits.flip(n);
    }

    bool check(int n) {
        return bits.test(n);
    }

private:
    std::bitset<Size> bits; // 使用模板参数来定义bitset的大小
};

class Base {
public:
    int publicVar;

protected:
    int protectedVar;

private:
    int privateVar;

public:
    Base() : publicVar(1), protectedVar(2), privateVar(3) {
    }

    void show() {
        std::cout << "Base Public: " << publicVar << ", Protected: " << protectedVar << std::endl;
    }
};

class Derived : public Base {
public:
    void accessBaseMembers() {
        publicVar = 10; // OK，作为protected成员访问
        protectedVar = 20; // OK，可以访问
        // privateVar = 30;  // 错误，无法访问基类的 private 成员
    }

    void showDerived() {
        show(); // 派生类内部依然可以访问基类的public成员函数
    }
};

class Derived2 : protected Base {
public:
    void accessBaseMembers() {
        publicVar = 10; // OK，作为protected成员访问
        protectedVar = 20; // OK，可以访问
        // privateVar = 30;  // 错误，无法访问基类的 private 成员
    }

    void showDerived() {
        show(); // 派生类内部依然可以访问基类的public成员函数
    }
};

class Derived3 : private Base {
public:
    void accessBaseMembers() {
        publicVar = 10; // OK，作为protected成员访问
        protectedVar = 20; // OK，可以访问
        // privateVar = 30;  // 错误，无法访问基类的 private 成员
    }

    void showDerived() {
        show(); // 派生类内部依然可以访问基类的public成员函数
    }
};

class Derived4 : protected Derived2 {
public:
    void accessBaseMembers() {
        publicVar = 10; // OK，作为protected成员访问
        protectedVar = 20; // OK，可以访问
        // privateVar = 30;  // 错误，无法访问基类的 private 成员
    }

    void showDerived() {
        show(); // 派生类内部依然可以访问基类的public成员函数
    }
};

class Derived5 : protected Derived3 {
public:
    void accessBaseMembers() {
        // publicVar = 10;  // 错误，无法访问
        // protectedVar = 20;
        // privateVar = 30;
    }

    void showDerived() {
        // show(); // 错误，无法访问
    }
};

int main() {
    unsigned int a = 3; // 011 in binary
    unsigned int b = 5; // 101 in binary
    std::cout << "a & b: " << (a & b) << std::endl; // 输出 1 (001 in binary)

    a = 2; // 010 in binary
    b = 6; // 110 in binary
    std::cout << "a | b: " << (a | b) << std::endl; // 输出 6 (110 in binary)

    int x = 12; // 01100 in binary
    int y = 25; // 11001 in binary
    std::cout << "x ^ y: " << (x ^ y) << std::endl; // 结果为 21 (10101 in binary)

    x = 9;
    y = 12;
    swap(x, y);
    std::cout << x << " " << y << std::endl;

    unsigned int n = 1; // 00000001 in binary
    std::cout << "~n: " << (~n) << std::endl; // 注意：结果取决于系统位数

    int z = 1; // 00000001
    std::cout << "z << 2: " << (z << 2) << std::endl; // 00000100 (4 in decimal)
    std::cout << "z >> 1: " << (z >> 1) << std::endl; // 00000000 (0 in decimal)
    std::cout << "*********************************" << std::endl;

    int userPermission = 0b0101; // 读和写权限
    checkPermission(userPermission, 0b0001); // 检查读权限
    checkPermission(userPermission, 0b0010); // 检查写权限

    std::bitset<4> bits1("1010");
    bits1[0] = 1;
    std::cout << bits1[0] << std::endl;
    std::cout << bits1[1] << std::endl;
    std::cout << bits1[2] << std::endl;
    std::cout << bits1[3] << std::endl;
    std::cout << "*********************************" << std::endl;

    std::bitset<4> bset1(9); // 1001
    std::bitset<4> bset2(5); // 0101
    // 按位逻辑运算
    std::cout << "bset1 & bset2: " << (bset1 & bset2) << std::endl;
    std::cout << "bset1 | bset2: " << (bset1 | bset2) << std::endl;
    std::cout << "bset1 ^ bset2: " << (bset1 ^ bset2) << std::endl;
    // 翻转所有位
    std::cout << "~bset1: " << (~bset1) << std::endl;
    // 测试某一位
    std::cout << "Is the second bit of bset1 set? " << bset1.test(0) << std::endl;
    std::cout << "Is the second bit of bset1 set? " << bset1.test(1) << std::endl;
    std::cout << "Is the second bit of bset1 set? " << bset1.test(2) << std::endl;
    std::cout << "Is the second bit of bset1 set? " << bset1.test(3) << std::endl;
    std::cout << "*********************************" << std::endl;

    std::bitset<16> bits(100);
    std::cout << bits.count() << std::endl;
    std::cout << bits.to_string() << std::endl;
    std::cout << "*********************************" << std::endl;

    std::bitset<5> bits2("10101");
    std::cout << bits2.to_ulong() << std::endl;
    std::cout << "*********************************" << std::endl;

    try {
        BitSet<10> bs(1); // 现在可以用任意的大小来初始化BitSet了
        bs.flip(2);
        std::cout << "Bit at position 2 is: " << (bs.check(2) ? "set" : "not set") << std::endl;
        // 测试越界的情况
        bs.check(10); // 这会抛出异常
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << "*********************************" << std::endl;

    Derived d;
    d.accessBaseMembers();
    d.publicVar = 100;
    // d.protectedVar = 100; // 错误，无法访问继承自 Base 的 protectedVar
    d.show();
    d.showDerived(); // Output: Base Public: 100, Protected: 20
    Derived2 d2;
    d2.accessBaseMembers();
    // d2.publicVar = 100;  // 错误，无法访问继承自 Base 的 publicVar
    // d2.protectedVar = 100; // 错误，无法访问继承自 Base 的 protectedVar
    // d2.show();
    d2.showDerived(); // Output: Base Public: 10, Protected: 20
    Derived3 d3;
    d3.accessBaseMembers();
    // d3.publicVar = 100;  // 错误，无法访问继承自 Base 的 publicVar
    // d3.protectedVar = 100; // 错误，无法访问继承自 Base 的 protectedVar
    // d3.show();
    d3.showDerived(); // Output: Base Public: 10, Protected: 20
    std::cout << "*********************************" << std::endl;

    return 0;
}
