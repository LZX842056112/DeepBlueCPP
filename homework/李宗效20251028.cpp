#include <iostream>
#include <chrono>

template<typename T>
T sum(T a, T b) {
    return a + b;
}

int add(int a, int b) {
    return a + b;
}

int main() {
    int a = 10, b = 20;
    double a1 = 10.5, b1 = 20.5;
    std::string a2 = "10", b2 = "20";

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++) {
        sum(a, b);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << duration.count() << std::endl; // 790

    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++) {
        sum(a1, b1);
    }
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << duration.count() << std::endl; // 1070

    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++) {
        sum(a2, b2);
    }
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << duration.count() << std::endl; // 45471

    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++) {
        add(a, b);
    }
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << duration.count() << std::endl; // 935

    return 0;
}
