#include <chrono>
#include <iostream>

int fibnacci(int n) {
    if (n <= 1) return n;
    return fibnacci(n - 1) + fibnacci(n - 2);
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++) {
        fibnacci(20);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << duration.count() << std::endl;// 42262723

    return 0;
}
