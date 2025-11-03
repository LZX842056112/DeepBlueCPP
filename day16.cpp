#include <iostream>
#include <string>
#include <stdexcept> // 需要包含这个头文件来处理异常
#include <vector>
#include <forward_list>
#include <utility>
#include <algorithm>
#include <numeric>
#include <exception>
#include <iomanip>
#include <fstream>

class Order {
public:
    int order_lit;

    Order() {
        order_lit = 0;
    }

    Order(const int i) {
        order_lit = i;
    }

    Order operator+(const Order &other) const {
        return {this->order_lit + other.order_lit};
    }
};

class MyClass {
public:
    MyClass() {
    }

    MyClass operator++() {
    }
};

std::ostream &operator<<(std::ostream &, const MyClass &order) {
}

struct Person {
    std::string name;
    int age;
};

bool compare_by_age(const Person &a, const Person &b) {
    return a.age < b.age;
}

bool operator==(const Person &a, const Person &b) {
    return a.age == b.age;
}

bool operator<(const Person &a, const Person &b) {
    return a.age < b.age;
}

struct Result {
    int real_value;
    bool divide_by_zero;
};

Result divide(int a, int b) {
    if (b == 0) {
        return Result{-1, true};
    }
    return Result{a / b, false};
}

struct MyError {
    std::string message;

    MyError() : message("error") {
    }
};

int divide2(int a, int b) {
    if (b == 0) {
        throw MyError();
    }
    return a / b;
}

int divide3(int a, int b) {
    if (b == 0) {
        throw 100;
    }
    return a / b;
}

class MyException : public std::exception {
public:
    const char *what() noexcept {
        return "MyException";
    }
};

class FileOpenError : public std::runtime_error {
public:
    FileOpenError(const std::string &filename) : std::runtime_error("Failed to open file: " + filename),
                                                 filename_(filename) {
    }

    const std::string &getFilename() const {
        return filename_;
    }

private:
    std::string filename_;
};

void function2() {
    throw 1;
}

void function1() {
    function2();
}

void function() {
    function1();
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    int sum = std::accumulate(vec.begin(), vec.end(), 0);
    std::cout << "Sum: " << sum << std::endl;

    std::vector<Order> vec2 = {Order{1}, Order{2}, Order{3}};
    Order sum2 = std::accumulate(vec2.begin(), vec2.end(), Order());
    std::cout << "Sum2: " << sum2.order_lit << std::endl;
    std::cout << "*********************************" << std::endl;


    std::vector<int> vec3(5);
    std::iota(vec3.begin(), vec3.end(), 3);
    for (const auto &v: vec3) {
        std::cout << v << " ";
    }
    std::cout << std::endl;


    // std::vector<MyClass> vec4(5);
    // std::iota(vec4.begin(), vec4.end(), MyClass());
    // for (const auto &v: vec4) {
    //     std::cout << v << " ";
    // }
    std::cout << std::endl;
    std::cout << "*********************************" << std::endl;


    std::vector<int> vec5 = {3, 1, 4, 1, 5, 9, 2};
    std::sort(vec5.begin(), vec5.end());
    for (const auto &v: vec5) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
    std::cout << "*********************************" << std::endl;

    std::vector<Person> people = {
        {"Bob", 20},
        {"Bob2", 20},
        {"Bob3", 20},
        {"Bob4", 20},
        {"Charlie", 30},
        {"Charlie2", 30},
        {"Charlie3", 30},
        {"Charlie4", 30},
        {"Charlie5", 30},
        {"Charlie6", 30},
        {"Charlie7", 30},
        {"Charlie8", 30},
        {"Alice1", 30},
        {"Alice2", 40},
        {"Alice3", 30},
        {"Alice4", 30},
        {"Alice5", 30},
        {"Alice6", 30},
        {"Dave", 20},
        {"Dave2", 20},
        {"Dave3", 20},
        {"Dave4", 20},
    };
    std::vector<Person> people2 = people;
    std::vector<Person> people3 = people;
    std::sort(people.begin(), people.end(), compare_by_age);
    for (const auto &person: people) {
        std::cout << person.name << " (" << person.age << ")" << std::endl;
    }
    std::cout << "*********************************" << std::endl;

    std::stable_sort(people2.begin(), people2.end(), compare_by_age);
    for (const auto &person: people2) {
        std::cout << person.name << " (" << person.age << ")" << std::endl;
    }
    std::cout << "*********************************" << std::endl;

    std::vector<int> vec6 = {9, 3, 7, 1, 3, 6, 5, 8, 2, 4};
    std::partial_sort(vec6.begin(), vec6.begin() + 5, vec6.end());
    for (const auto &v: vec6) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
    std::cout << "*********************************" << std::endl;

    std::vector<int> vec7 = {9, 1, 8, 3, 7, 2, 6, 4, 5};
    std::nth_element(vec7.begin(), vec7.begin() + 4, vec7.end());
    std::cout << "Element at index 4: " << vec7[4] << std::endl;
    std::cout << "Array after nth_element: ";
    for (const auto &v: vec7) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
    std::cout << "*********************************" << std::endl;

    std::sort(people3.begin(), people3.end(), compare_by_age);
    auto iter = std::lower_bound(people3.begin(), people3.end(), Person{.name = "abc", .age = 40});
    std::cout << iter->name << std::endl;
    std::cout << "*********************************" << std::endl;

    std::vector<int> vec8 = {1, 2, 3, 3, 3, 4, 5};
    auto range = std::equal_range(vec8.begin(), vec8.end(), 3);
    std::cout << "First occurrence of 3 at position: " << std::distance(vec8.begin(), range.first) << std::endl;
    std::cout << "Last occurrence of 3 at position: " << std::distance(vec8.begin(), range.second) - 1 << std::endl;
    std::cout << "*********************************" << std::endl;

    int a;
    int b;
    std::cout << "请输入 a" << std::endl;
    std::cin >> a;
    std::cout << "请输入 b" << std::endl;
    std::cin >> b;
    Result result = divide(a, b);
    if (result.divide_by_zero) {
        std::cout << "divide by zero, fatal action" << std::endl;
    } else {
        std::cout << result.real_value << std::endl;
    }

    try {
        int res = divide2(a, b);
    } catch (const MyError &e) {
        std::cout << e.message << std::endl;
    } catch (int e) {
        std::cout << e << std::endl;
    }

    try {
        int res = divide3(a, b);
    } catch (const MyError &e) {
        std::cout << e.message << std::endl;
    } catch (int e) {
        std::cout << e << std::endl;
    }
    std::cout << "*********************************" << std::endl;

    std::vector<int> vecs = {1, 2, 3};
    try {
        std::cout << vecs.at(3) << std::endl;
    } catch (const std::out_of_range &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "*********************************" << std::endl;

    try {
        std::string filename = "important_data.txt";
        // 模拟文件打开失败的情况
        if (true) {
            throw FileOpenError(filename);
        }
        // ... 其他文件操作 ...
    } catch (const FileOpenError &e) {
        std::cerr << "File error: " << e.what() << std::endl;
        std::cerr << "Filename: " << e.getFilename() << std::endl;
    } catch (const std::runtime_error &e) {
        std::cerr << "Runtime error: " << e.what() << std::endl;
    }
    std::cout << "*********************************" << std::endl;

    try {
        function();
    } catch (int &e) {
        std::cout << e << std::endl;
    }

    return 0;
}
