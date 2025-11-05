#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class Person {
public:
    Person(const std::string &name, int age) : name_(name), age_(age) {
    }

    const std::string &getName() const { return name_; }
    int getAge() const { return age_; }

    void print() const {
        std::cout << name_ << " (" << age_ << " years)" << std::endl;
    }

private:
    std::string name_;
    int age_;
};

int main() {
    // 使用Lambda对整数向量进行排序
    std::vector<int> numbers = {5, 2, 8, 1, 9, 3};
    std::cout << "Original numbers: ";
    for (int num: numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 升序排序numbers
    std::sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return a < b;
    });
    std::cout << "Sorted in ascending order: ";
    for (int num: numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 降序排序
    std::sort(numbers.begin(), numbers.end(), [](int a, int b) {
        return a > b;
    });
    std::cout << "Sorted in descending order: ";
    for (int num: numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 使用Lambda对Person对象进行排序
    std::vector<Person> people = {
        Person("Alice", 25),
        Person("Bob", 30),
        Person("Charlie", 20),
        Person("David", 35)
    };

    std::cout << "\nOriginal people:" << std::endl;
    for (const auto &person: people) {
        person.print();
    }

    // 按年龄排序
    std::sort(people.begin(), people.end(), [](Person p1, Person p2) {
        return p1.getAge() > p2.getAge();
    });
    std::cout << "\nPeople sorted by age:" << std::endl;
    for (const auto &person: people) {
        person.print();
    }

    // 按姓名排序
    std::sort(people.begin(), people.end(), [](const Person &p1, const Person &p2) {
        return p1.getName() > p2.getName();
    });
    std::cout << "\nPeople sorted by name:" << std::endl;
    for (const auto &person: people) {
        person.print();
    }

    // 使用Lambda和std::find_if找到年纪大于 30 的人
    auto it = std::find_if(people.begin(), people.end(), [](const Person &p) {
        return p.getAge() > 30;
    });
    if (it != people.end()) {
        std::cout << "\nFirst person over 30: ";
        it->print();
    }

    // 使用Lambda和std::count_if统计年纪大于等于 25 的人数
    auto count = std::count_if(people.begin(), people.end(), [](const Person &p) {
        return p.getAge() > 25;
    });
    std::cout << "\nNumber of people aged 25 or over: " << count << std::endl;

    // 使用Lambda和std::for_each打印所有的信息
    std::cout << "\nPrinting people with Lambda:" << std::endl;
    std::for_each(people.begin(), people.end(), [](const Person &p) {
        p.print();
    });

    return 0;
}
