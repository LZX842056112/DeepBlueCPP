#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <forward_list>
#include <utility>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <exception>
#include <iomanip>
#include <fstream>

template<typename T>
class MyContainer {
private:
    T value;

public:
    MyContainer(T value) : value(value) {
    }

    template<typename U>
    void printWith(U prefix) {
        std::cout << prefix << ": " << value << std::endl;
    }
};

template<typename T>
struct MyStack {
    MyStack() {
    }

    void push(const T &t) {
        stack_inside_.push_back(t);
    }

    T top() {
        return stack_inside_.back();
    }

    void pop() {
        return stack_inside_.pop_back();
    }

    bool empty() {
        return stack_inside_.empty();
    }

    std::vector<T> stack_inside_;
};

int main() {
    MyContainer<int> intContainer(10);
    intContainer.printWith<const char *>("Integer");

    MyContainer<double> doubleContainer(3.14);
    doubleContainer.printWith<const char *>("Double");
    doubleContainer.printWith<std::string>("Double");
    doubleContainer.printWith<int>(132);
    std::cout << "*********************************" << std::endl;

    std::vector<int> vecs = {1, 2, 3, 4};
    // std::vector<int>::iterator iter = vecs.begin();
    for (auto iter = vecs.begin(); iter != vecs.end(); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
    std::list<int> vecs2 = {1, 2, 3, 4};
    for (auto iter = vecs.begin(); iter != vecs.end(); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
    std::cout << "*********************************" << std::endl;

    std::map<int, std::string> vecs3 = {{1, "abc"}, {2, "def"}, {3, "xyx"}};
    for (auto iter = vecs3.begin(); iter != vecs3.end(); ++iter) {
        std::cout << (*iter).first << ":" << iter->second << std::endl;
    }
    std::cout << "*********************************" << std::endl;

    std::vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    auto iter = numbers.begin();
    iter += 2;
    std::cout << *iter << std::endl;
    ++iter;
    numbers.insert(iter, 100);
    std::cout << *iter << std::endl;
    std::cout << "*********************************" << std::endl;

    std::list<int> numbers2;
    numbers2.push_back(1);
    numbers2.push_back(2);
    numbers2.push_back(3);
    auto iter2 = numbers2.begin();
    std::cout << *iter2 << std::endl;
    ++iter2;
    ++iter2;
    // numbers2.erase(iter2);
    numbers2.insert(iter2, 100);
    std::cout << *iter2 << std::endl;
    std::cout << "*********************************" << std::endl;

    std::vector<int> numbers3 = {1, 2, 3, 4, 5};
    auto it = std::find(numbers3.begin(), numbers3.end(), 3);
    if (it != numbers3.end()) {
        std::cout << "Found 3 at index: " << std::distance(numbers3.begin(), it) << std::endl;
    } else {
        std::cout << "3 not found." << std::endl;
    }
    std::cout << "*********************************" << std::endl;

    std::list<int> numbers4;
    numbers4.push_back(1);
    numbers4.push_back(2);
    numbers4.push_back(3);
    auto iter3 = numbers4.begin();
    std::advance(iter3, 2);
    std::cout << *iter3 << std::endl;
    std::cout << "*********************************" << std::endl;

    std::list<int> numbers5;
    numbers5.push_back(1);
    numbers5.push_back(2);
    numbers5.push_back(3);
    numbers5.push_back(2);
    numbers5.push_back(4);
    numbers5.remove(2);
    std::cout << numbers5.size() << std::endl;
    std::cout << "*********************************" << std::endl;

    std::deque<int> numbers6 = {2, 3};
    numbers6.push_front(1);
    for (std::deque<int>::iterator it = numbers6.begin(); it != numbers6.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "*********************************" << std::endl;

    std::queue<int> numbers7;
    numbers7.push(1);
    numbers7.push(2);
    numbers7.push(3);

    while (!numbers7.empty()) {
        std::cout << numbers7.front() << " ";
        numbers7.pop();
    }
    std::cout << std::endl;
    std::cout << "*********************************" << std::endl;

    std::map<std::string, int> ages;
    ages.insert(std::pair<std::string, int>("Alice", 25));
    ages["Bob"] = 30;
    for (std::map<std::string, int>::iterator it = ages.begin(); it != ages.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }
    std::cout << "*********************************" << std::endl;

    MyStack<int> stack;
    stack.push(1);
    stack.push(2);
    if (!stack.empty()) {
        std::cout << stack.top() << std::endl;
    }
    stack.pop();
    std::cout << "*********************************" << std::endl;

    std::vector<int> vec = {2, 4, 6, 8, 10};
    bool all_even = std::all_of(vec.begin(), vec.end(), [](int i) { return i % 2 == 0; });
    std::cout << (all_even ? "All elements are even" : "Not all elements are even") << std::endl;

    vec = {1, 3, 5, 7, 8};
    bool has_even = std::any_of(vec.begin(), vec.end(), [](int i) { return i % 2 == 0; });
    std::cout << (has_even ? "There is at least one even element" : "All elements are odd") << std::endl;

    vec = {1, 3, 5, 7};
    bool none_even = std::none_of(vec.begin(), vec.end(), [](int i) { return i % 2 == 0; });
    std::cout << (none_even ? "None of the elements are even" : "There is at least one even element") << std::endl;
    std::cout << "*********************************" << std::endl;

    std::for_each(vec.begin(), vec.end(), [](int &n) { n *= n; });
    for (const auto &n: vec) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    std::cout << "*********************************" << std::endl;

    vec = {1, 2, 3, 4, 5};
    std::vector<int> result(vec.size());
    std::transform(vec.begin(), vec.end(), result.begin(), [](int v) { return v * v; });
    for (const auto &v: vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
    std::cout << "*********************************" << std::endl;

    std::vector<int> destination(vec.size());
    std::copy(vec.begin(), vec.end(), destination.begin());
    for (const auto &v: destination) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
    std::cout << "*********************************" << std::endl;

    std::vector<int> vec2 = {1, 2, 3, 2, 4, 2, 5};
    std::replace(vec2.begin(), vec2.end(), 2, 10);
    for (const auto &v: vec2) {
        std::cout << v << " ";
    }
    std::cout << std::endl;


    return 0;
}
