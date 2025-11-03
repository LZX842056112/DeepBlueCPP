#include <iostream>
#include <string>
#include "day19_add_int.cpp"
#include "day19_add_string.cpp"
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include <numeric>

namespace MySpace {
    int count = 5;

    void print() {
        std::cout << "Hello from MySpace" << std::endl;
    }
}

namespace z_y_com {
    extern int add(int, int);

    extern void print();
}

namespace x_y_com {
    extern std::string add(const std::string &, const std::string &);

    extern void print();
}

namespace Math {
    const double PI = 3.14159;

    double add(double a, double b) {
        return a + b;
    }

    class Calculator {
    public:
        double multiply(double x, double y) {
            return x * y;
        }
    };
}

namespace Outer {
    int value = 10;

    namespace Inner {
        int value = 20;

        void show() {
            std::cout << "Inner value: " << value << std::endl;
        }
    }
}

namespace VeryLongNamespaceName {
    void func() { std::cout << "Hello!" << std::endl; }
}

// 创建别名
namespace VLNN = VeryLongNamespaceName;

// 基本类型推导
auto i = 42; // i是int
auto d = 3.14; // d是double
auto c = 'a'; // c是char
auto p = &i; // p是int*
auto str = "Hello"; // str是const char*,

// 引用和const/volatile限定符
const int ci = 10;
auto cai = ci; // cai是int（const被丢弃）
auto &ccri = ci; // ccri是const int&（保留const）
auto *pci = &ci; // pci是const int*（保留const）

// 复杂类型推导
std::vector<int> vec = {1, 2, 3, 4, 5};
auto it = vec.begin(); // it是std::vector<int>::iterator
auto rit = vec.rbegin(); // rit是std::vector<int>::reverse_iterator

// 使用auto简化函数模板返回类型
template<typename T, typename U>
auto add(T t, U u) -> decltype(t + u) {
    return t + u;
}

// C++14中可以直接使用auto推导返回类型
template<typename T, typename U>
auto multiply(T t, U u) {
    return t * u;
}

auto lambda = [](int x, int y) { return x + y; };

void print(int x) {
    std::cout << x << std::endl;
}

class Student {
public:
    Student(const std::string &name, int age, double gpa) : name(name), age(age), gpa(gpa) {
    }

    std::string getName() const { return name; }
    int getAge() const { return age; }
    double getGpa() const { return gpa; }

    void print() const {
        std::cout << "Name: " << name << ", Age: " << age << ", GPA: " << gpa << std::endl;
    }

private:
    std::string name;
    int age;
    double gpa;
};

class MyClass {
public:
    MyClass() {
        ptr = new int(9);
    }

    MyClass(const MyClass &other) {
        ptr = new int(*other.ptr);
    }

    MyClass(MyClass &&other) {
        ptr = other.ptr;
        other.ptr = nullptr;
    }

    int *ptr;
};

int main() {
    std::cout << MySpace::count << std::endl; // 明确指定命名空间
    MySpace::print();
    std::cout << "*********************************" << std::endl;

    int a = 9;
    int b = 6;
    z_y_com::add(a, b);
    z_y_com::print();
    std::string c1 = "abc";
    std::string d1 = "def";
    x_y_com::add(c1, d1);
    x_y_com::print();
    std::cout << "*********************************" << std::endl;

    std::cout << Math::PI << std::endl; // 明确指定命名空间
    Math::Calculator calc;
    std::cout << calc.multiply(3, 4) << std::endl;
    std::cout << "*********************************" << std::endl;

    std::cout << Outer::value << std::endl; // 10
    std::cout << Outer::Inner::value << std::endl; // 20
    Outer::Inner::show(); // "Inner value: 20"
    std::cout << "*********************************" << std::endl;

    VLNN::func(); // 使用别名
    std::cout << "*********************************" << std::endl;

    // 使用auto简化STL容器遍历
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    // 传统方式
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    // 使用auto
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    // 使用auto与范围for循环（后面会讲到）
    for (const auto &num: numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    // 使用auto处理复杂容器
    std::map<std::string, std::vector<int> > studentScores;
    studentScores["Alice"] = {90, 85, 95};
    studentScores["Bob"] = {80, 75, 85};
    // 遍历map
    for (const auto &pair: studentScores) {
        std::cout << pair.first << ": ";
        for (const auto &score: pair.second) {
            std::cout << score << " ";
        }
        std::cout << std::endl;
    }
    // 使用auto与STL算法
    auto it = std::find_if(numbers.begin(), numbers.end(), [](int n) {
        return n > 3;
    });
    if (it != numbers.end()) {
        std::cout << "Found number greater than 3: " << *it << std::endl;
    }
    std::cout << "*********************************" << std::endl;

    std::vector<int> vecs = {1, 2, 3};
    std::vector<int> vecs2 = {4, 5, 6};
    std::for_each(vecs.begin(), vecs.end(), [](int x) { std::cout << x << std::endl; });
    std::for_each(vecs2.begin(), vecs2.end(), [](int x) { std::cout << x << std::endl; });
    std::for_each(vecs.begin(), vecs.end(), print);
    std::for_each(vecs2.begin(), vecs2.end(), print);
    std::cout << "*********************************" << std::endl;

    // 示例1：使用Lambda对容器进行排序
    std::vector<Student> students = {
        Student("Alice", 20, 3.8),
        Student("Bob", 21, 3.5),
        Student("Charlie", 19, 3.9),
        Student("David", 22, 3.2)
    };
    // 按GPA降序排序
    std::sort(students.begin(), students.end(), [](const Student &a, const Student &b) {
        return a.getGpa() > b.getGpa();
    });
    std::cout << "Students sorted by GPA (descending):" << std::endl;
    for (const auto &student: students) {
        student.print();
    }
    std::cout << "*********************************" << std::endl;

    // 示例2：使用Lambda计算统计信息
    numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // 计算偶数的数量
    int evenCount = std::count_if(numbers.begin(), numbers.end(), [](int n) {
        return n % 2 == 0;
    });
    std::cout << "Count of even numbers: " << evenCount << std::endl;
    // 计算所有奇数的和
    int oddSum = 0;
    std::for_each(numbers.begin(), numbers.end(), [&oddSum](int n) {
        if (n % 2 != 0) oddSum += n;
    });
    std::cout << "Sum of odd numbers: " << oddSum << std::endl;
    std::cout << "*********************************" << std::endl;

    // 示例3：使用Lambda和std::transform
    std::vector<std::string> names = {"Alice", "Bob", "Charlie"};
    std::vector<int> nameLengths;
    // 将names中的每个字符串转换为其长度
    std::transform(names.begin(), names.end(), std::back_inserter(nameLengths), [](const std::string &s) {
        return s.length();
    });
    std::cout << "Name lengths: ";
    for (const auto &len: nameLengths) {
        std::cout << len << " ";
    }
    std::cout << std::endl;
    std::cout << "*********************************" << std::endl;

    // 示例4：使用Lambda和std::remove_if
    // 移除所有小于5的数字
    numbers.erase(std::remove_if(numbers.begin(), numbers.end(), [](int n) { return n < 5; }), numbers.end());
    std::cout << "Numbers after removing those less than 5: ";
    for (const auto &num: numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << "*********************************" << std::endl;

    // 示例5：使用Lambda和std::accumulate
    // 连接所有字符串
    std::string concatenated = std::accumulate(names.begin(), names.end(), std::string(),
                                               [](const std::string &a, const std::string &b) {
                                                   return a + " " + b;
                                               });
    std::cout << "Concatenated names: " << concatenated << std::endl;
    std::cout << "*********************************" << std::endl;

    // 示例6：使用Lambda创建自定义比较函数
    std::map<std::string, int, std::function<bool(const std::string &, const std::string &)> > customMap(
        [](const std::string &a, const std::string &b) {
            return a.length() < b.length(); // 按字符串长度排序
        });
    customMap["Alice"] = 20;
    customMap["Bob"] = 25;
    customMap["Charlie"] = 30;
    std::cout << "Map sorted by key length:" << std::endl;
    for (const auto &pair: customMap) {
        std::cout << pair.first << " -> " << pair.second << std::endl;
    }
    std::cout << "*********************************" << std::endl;

    int x = 10;
    auto lambda = [x] mutable {
        x++;
        return x;
    };
    int y = 10;
    auto lambda2 = [](int x)mutable {
        x++;
        return x;
    }(y);
    std::cout << "*********************************" << std::endl;

    int a1 = 9;
    int &ra = a; //左值引用
    int &&r1 = 1; //右值引用
    int &&r2 = add(1, 2); //右值引用
    std::cout << "*********************************" << std::endl;

    MyClass m1;
    MyClass m2(m1);
    MyClass m3(std::move(m1));

    return 0;
}
