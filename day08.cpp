#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

class Student {
    int id;
    char gender;
    char name[1024];

    int getId() { return id; }
    char getGender() { return gender; }
    char getName() { return *name; }
};

class Order {
    int id;
    int user_id;
    // Status prev;
    // Status st;

    // bool update(Status status) {
    //     st = status;
    // }
};

class Dog {
public:
    std::string name;
    int age;

    // 构造函数
    Dog(const std::string &dogName, int dogAge) : name(dogName), age(dogAge) {
        std::cout << "小狗 " << name << " 被创建了！" << std::endl;
    }

    Dog(std::string &dogName) : name(dogName) {
        std::cout << "小狗 " << name << " 被创建了！" << std::endl;
    }

    Dog() : name("11"), age(0) {
        std::cout << "小狗被创建了！" << std::endl;
    }

    // 析构函数
    ~Dog() {
        std::cout << "小狗 " << name << " 离开了。" << std::endl;
    }

    void bark() const {
        std::cout << "汪汪！我是 " << name << ", " << age << " 岁了！" << std::endl;
    }

    bool get_is_sleeping() {
        return is_sleeping;
    }

private:
    // 可以添加一些私有成员，例如内部状态
    bool is_sleeping = false;
};

class Cat {
public:
    std::string name;
    int age;

    // 默认构造函数
    Cat() : name("Unknown"), age(0) {
        std::cout << "一只未命名的小猫被创建了。" << std::endl;
    }

    // 参数化构造函数
    Cat(const std::string &catName, int catAge) : name(catName), age(catAge) {
        std::cout << "小猫 " << name << " 被创建了！" << std::endl;
    }

    void meow() const {
        std::cout << "喵！我是 " << name << ", " << age << " 岁了！" << std::endl;
    }
};

class MyClass {
public:
    MyClass() {
        ptr = new int;
        *ptr = 100;
        std::cout << "construct myclass ..." << std::endl;
    }

    ~MyClass() {
        delete ptr;
        ptr = nullptr;
        std::cout << "deconstruct myclass ..." << std::endl;
    }

private:
    int *ptr;
};

class ResourceHolder {
public:
    ResourceHolder() {
        resource = new int[10];
        std::cout << "资源已分配。" << std::endl;
    }

    ~ResourceHolder() {
        delete[] resource;
        resource = nullptr;
        std::cout << "资源已释放。" << std::endl;
    }

private:
    int *resource;
};

class BankAccount {
public:
    // 公有成员函数，用于操作私有成员
    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
        } else {
            std::cout << "余额不足！" << std::endl;
        }
    }

    double getBalance() const {
        return balance;
    }

private:
    // 私有成员变量，存储账户余额
    double balance = 0.0;
};

class MyClass2 {
public:
    MyClass2(int x_) {
        x = x_;
    }

private:
    int x;
    int y;
    char z;
};

class MyClass3 {
private:
};

class MyClass4 {
    int value;

public:
    MyClass4(int value) {
        // value = value;
        this->value = value;
        std::cout << static_cast<void *>(this) << std::endl;
    }

    void display() const {
        // std::cout << value << std::endl;
        std::cout << this->value << std::endl;
    }
};

class MyClass5 {
public:
    int value;

    void setValue(int value) {
        this->value = value; // 使用 this 指针区分成员变量和参数
    }

    void printValue() const {
        std::cout << "value: " << this->value << std::endl; // 使用 this 指针访问成员变量
    }
};

int count = 0;

class MyClass6 {
public:
    static int count2;

    MyClass6() {
        count2++;
        count++;
    }
};

int MyClass6::count2 = 0;


int main() {
    Dog myDog("Buddy", 3); // 调用构造函数
    Dog myDog2;
    myDog.bark(); // 调用公有成员函数
    // 可以访问公有成员变量
    std::cout << "小狗的名字是：" << myDog.name << std::endl;
    std::cout << "小狗的年龄是：" << myDog.age << std::endl;
    // 无法直接访问私有成员变量
    // std::cout << myDog.is_sleeping << std::endl; // 编译错误
    std::cout << myDog.get_is_sleeping() << std::endl;

    Cat cat1; // 调用默认构造函数
    cat1.meow();
    Cat cat2("Tom", 2); // 调用参数化构造函数
    cat2.meow();

    std::cout << "my beginning..." << std::endl;
    {
        MyClass my;
    }
    std::cout << "my end..." << std::endl;
    std::cout << "my2 beginning..." << std::endl;
    {
        MyClass *my2 = new MyClass();
        delete my2;
        my2 = nullptr;
    }
    std::cout << "my2 end..." << std::endl;

    {
        ResourceHolder holder; // 在此代码块结束时，holder 的析构函数会被调用
    }
    ResourceHolder *dynamicHolder = new ResourceHolder();
    delete dynamicHolder; // 手动删除动态分配的对象，触发析构函数

    BankAccount myAccount;
    myAccount.deposit(1000);
    myAccount.withdraw(200);
    std::cout << "账户余额：" << myAccount.getBalance() << std::endl;
    // 无法直接访问私有成员变量
    // myAccount.balance = -100; // 编译错误

    MyClass2 my2(1);
    std::cout << sizeof(my2) << std::endl;
    MyClass3 my3();
    // std::cout << sizeof(my3) << std::endl;
    std::cout << sizeof(std::cout) << std::endl;

    MyClass4 my4(5);
    my4.display();

    MyClass5 my5;
    my5.setValue(1);
    my5.printValue();

    MyClass6 my6;
    MyClass6 my61;
    std::cout << count << std::endl;
    std::cout << my6.count2 << std::endl;
    std::cout << MyClass6::count2 << std::endl;

    return 0; // myDog 对象在这里会被销毁，调用析构函数
}
