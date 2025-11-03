#include <iostream>
#include <stdio.h>
#include <string>
#include <stdexcept> // 需要包含这个头文件来处理异常
#include <vector>
#include <list>
#include <deque>
#include <forward_list>
#include <array>
#include <iomanip>
#include <fstream>

void func(std::array<int, 5> x) {
    std::cout << x.size() << std::endl;
}

void func2(const std::array<int, 5> &x) {
    std::cout << x.size() << std::endl;
}

int main() {
    std::string str("abc");
    std::cout << str << std::endl;
    std::cout << str[1] << std::endl;
    std::cout << str.at(1) << std::endl;
    // std::cout << str.at(-1) << std::endl;
    std::cout << "*********************************" << std::endl;

    std::string s1; // 默认构造函数，创建一个空字符串
    std::string s2("Hello"); // 使用 C 风格字符串初始化
    std::string s3 = "World"; // 拷贝初始化
    std::string s4(s2); // 拷贝构造函数
    std::string s5(s2, 1, 3); // 使用 s2 的子串初始化 (从索引 1 开始，长度为 3)
    std::string s6(10, 'a'); // 创建包含 10 个 'a' 的字符串
    std::string s7(s2.begin(), s2.end()); // 使用迭代器初始化

    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;
    std::cout << "s3: " << s3 << std::endl;
    std::cout << "s4: " << s4 << std::endl;
    std::cout << "s5: " << s5 << std::endl;
    std::cout << "s6: " << s6 << std::endl;
    std::cout << "s7: " << s7 << std::endl;
    std::cout << s7.length() << std::endl;
    std::cout << s7.empty() << std::endl;
    std::cout << "*********************************" << std::endl;

    std::string str2 = "Hello";
    std::string world = " World";
    // 连接字符串
    std::string greeting = str2 + world;
    std::cout << "Greeting: " << greeting << std::endl; // 输出：Hello World
    // 追加字符串
    greeting += "!";
    std::cout << "Greeting: " << greeting << std::endl; // 输出：Hello World!
    // 查找子串
    size_t pos = greeting.find("World");
    if (pos != std::string::npos) {
        std::cout << "'World' found at position: " << pos << std::endl; // 输出：'World' found at position: 6
    }
    // 截取子串
    std::string sub = greeting.substr(0, 5);
    std::cout << "Substring: " << sub << std::endl; // 输出：Hello
    // 替换子串
    greeting.replace(6, 5, "Universe");
    std::cout << "Greeting after replace: " << greeting << std::endl; // 输出：Hello Universe!
    std::cout << "*********************************" << std::endl;

    std::string str3 = "Hello";
    std::cout << "First character: " << str3[0] << std::endl; // 输出：H
    std::cout << "First character: " << str3.at(0) << std::endl; // 输出：H
    std::cout << "First character: " << str3.front() << std::endl; // 输出：H
    std::cout << "Last character: " << str3.back() << std::endl; // 输出：o
    try {
        // str.at(10); // 这会抛出 std::out_of_range 异常
    } catch (const std::out_of_range &e) {
        std::cerr << "Caught an out_of_range exception: " << e.what() << std::endl;
    }
    std::cout << "*********************************" << std::endl;

    std::string str4("abc");
    const char *x = str4.c_str();
    std::cout << x << std::endl;
    std::cout << "*********************************" << std::endl;

    std::vector<int> vecs = {};
    for (int i = 0; i < 5; i++) {
        vecs.push_back(1);
        std::cout << vecs.size() << std::endl;
        std::cout << vecs.capacity() << std::endl;
        std::cout << "******" << std::endl;
    }

    for (int i: vecs) {
        vecs.pop_back();
        std::cout << vecs.size() << std::endl;
        std::cout << vecs.capacity() << std::endl;
        std::cout << "******" << std::endl;
    }
    std::cout << "*********************************" << std::endl;

    std::vector<int> vecs2 = {1, 2, 3};
    std::cout << vecs2[1] << std::endl;
    std::cout << vecs2.at(1) << std::endl;

    // 嵌套 vector
    std::cout << "Accessing elements from nested vector:" << std::endl;
    std::vector<std::vector<int> > matrix = {{1, 2}, {3, 4}, {5, 6}};
    for (const auto &row: matrix) {
        for (int elem: row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "*********************************" << std::endl;

    std::list<int> numbers = {1, 2, 3};
    numbers.push_back(4);
    numbers.push_front(4);
    numbers.push_front(0);

    for (int num: numbers) {
        std::cout << num << std::endl;
    }
    std::cout << numbers.size() << std::endl;
    std::cout << "*********************************" << std::endl;


    std::deque<int> d1 = {1, 2, 3};
    d1.push_back(4);
    d1.push_front(4);
    d1.push_front(0);
    for (int num: d1) {
        std::cout << num << std::endl;
    }
    std::cout << d1.size() << std::endl;
    std::cout << "*********************************" << std::endl;

    std::forward_list<int> fl = {1, 2, 3, 4};
    fl.push_front(4);
    for (int num: fl) {
        std::cout << num << std::endl;
    }
    std::cout << "*********************************" << std::endl;

    std::array<int, 5> arr = {1, 2, 3, 4, 5};
    for (int num: arr) {
        std::cout << num << std::endl;
    }
    std::cout << arr.size() << std::endl;
    std::cout << "*********************************" << std::endl;

    func(arr);
    func2(arr);

    return 0;
}
