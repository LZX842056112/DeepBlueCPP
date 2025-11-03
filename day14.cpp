#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <iomanip>
#include <fstream>

class MyClass {
public:
    int id;
    std::string name;
};

bool operator<(const MyClass &a, const MyClass &b) {
    return a < b;
}

template<typename T>
T add(T a, T b) {
    return a + b;
}

template<typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

class Complex {
public:
    int real;
    int imag;
};

Complex operator+(const Complex &c1, const Complex &c2) {
    return {c1.real + c2.real, c1.imag + c2.imag};
}

std::ostream &operator<<(std::ostream &os, const Complex &c) {
    os << "{real: " << c.real << ", imag: " << c.imag << "}";
    return os;
}

template<typename T>
class MyArray {
private:
    T *data;
    int size;

public:
    MyArray(int size) : size(size) {
        data = new T[size];
    }

    ~MyArray() {
        delete[] data;
        data = nullptr;
    }

    void set(int index, T value) {
        data[index] = value;
    }

    T get(int index) {
        return data[index];
    }
};

int main() {
    std::pair<int, std::string> p1 = {1, "abc"};
    std::pair<int, std::string> p2 = {2, "def2"};
    std::pair<int, std::string> p3 = {3, "def3"};
    std::pair<int, std::string> p4 = {4, "def4"};
    std::pair<int, std::string> p5 = {5, "def5"};
    std::pair<int, std::string> p6 = {6, "def6"};
    std::cout << p1.first << std::endl;
    std::cout << p1.second << std::endl;
    std::cout << "*********************************" << std::endl;

    std::vector<std::pair<int, std::string> > students = {p1, p2, p3, p4, p5, p6};
    for (int i = 0; i < students.size(); i++) {
        if (students[i].first == 3) {
            std::cout << "right: " << students[i].second << std::endl;
        } else {
            std::cout << "wroing: " << students[i].second << std::endl;
        }
    }
    std::cout << "*********************************" << std::endl;

    std::map<int, std::string> students1 = {p2, p4, p1, p5, p3, p6};
    for (auto &e: students1) {
        std::cout << e.first << ": " << e.second << std::endl;
    }
    std::cout << "*********************************" << std::endl;

    std::map<int, std::string> student_map;
    // 插入元素
    student_map[101] = "Alice";
    student_map[102] = "Bob";
    student_map[103] = "Charlie";
    // 遍历 map
    std::cout << "Student IDs and names:" << std::endl;
    for (const auto &pair: student_map) {
        std::cout << "ID: " << pair.first << ", Name: " << pair.second << std::endl;
    }
    // 查找元素
    int id_to_find = 102;
    auto it = student_map.find(id_to_find);
    if (it != student_map.end()) {
        std::cout << "Student with ID " << id_to_find << " is " << it->second << std::endl;
    } else {
        std::cout << "Student with ID " << id_to_find << " not found." << std::endl;
    }
    std::cout << "*********************************" << std::endl;

    std::map<int, std::string> m = {{1, "abc"}, {2, "def"}, {3, "xyz"}};
    std::cout << m[4] << std::endl;
    std::cout << m[3] << std::endl;
    std::map<std::string, int> m2 = {{"abc", 1}, {"def", 2}, {"xyz", 3}};
    std::cout << m2["123"] << std::endl;
    std::cout << m2["abc"] << std::endl;
    std::cout << "*********************************" << std::endl;

    std::map<std::string, int> m3 = {{"abc", 1}, {"def", 2}};
    m3["xyz"] = 3;
    m3.insert({"mnh", 4});
    std::cout << m3["xyz"] << std::endl;
    std::cout << m3["mnh"] << std::endl;
    m3.insert({"abc", 33});
    std::cout << m3["abc"] << std::endl;
    std::cout << "*********************************" << std::endl;

    std::set<int> s = {1, 2, 3, 1, 2, 3, 4, 5, 4};
    std::cout << s.size() << std::endl;
    std::cout << "*********************************" << std::endl;


    std::set<int> unique_numbers = {10, 20, 30, 20, 40, 10};

    std::cout << "Elements in set: ";
    for (int num: unique_numbers) {
        std::cout << num << " "; // 输出 10 20 30 40，自动去重和排序
    }
    std::cout << std::endl;

    // 查找元素
    if (unique_numbers.find(20) != unique_numbers.end()) {
        std::cout << "20 is found in the set." << std::endl;
    } else {
        std::cout << "20 is not found in the set." << std::endl;
    }
    std::cout << "*********************************" << std::endl;

    std::map<MyClass, int> scores;
    MyClass m4 = {.id = 101, .name = "abc"};
    scores[m4] = 99;
    std::cout << "*********************************" << std::endl;

    int a = 9;
    int b = 6;
    double a1 = 9.1;
    double b1 = 6.1;
    std::string a2 = "abc";
    std::string b2 = "def";
    std::cout << add<int>(a, b) << std::endl;
    std::cout << add(a1, b1) << std::endl;
    std::cout << add(a2, b2) << std::endl;
    std::cout << "*********************************" << std::endl;

    int a3 = 5, b3 = 10;
    std::cout << "Max of " << a3 << " and " << b3 << " is: " << max(a3, b3) << std::endl;
    double c3 = 3.14, d3 = 2.71;
    std::cout << "Max of " << c3 << " and " << d3 << " is: " << max(c3, d3) << std::endl;
    std::cout << "*********************************" << std::endl;

    Complex c1 = {.real = 1, .imag = 2};
    Complex c2 = {.real = 3, .imag = 4};
    std::cout << add(c1, c2) << std::endl;

    std::cout << "*********************************" << std::endl;

    MyArray<int> intArray(5);
    intArray.set(0, 10);
    std::cout << "Value at index 0: " << intArray.get(0) << std::endl;

    MyArray<double> doubleArray(3);
    doubleArray.set(1, 3.14);
    std::cout << "Value at index 1: " << doubleArray.get(1) << std::endl;

    return 0;
}
