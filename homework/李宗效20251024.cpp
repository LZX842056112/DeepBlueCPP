#include <iostream>

int main() {
    int n = 0;
    int avg = 0;
    std::cout << "输入一个整数: " << std::endl;
    std::cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        std::cout << "输入第" << i + 1 << "个整数: " << std::endl;
        std::cin >> arr[i];
        avg += arr[i];
    }
    avg /= n;
    std::cout << "平均值: " << avg << std::endl;
    delete[] arr;
    arr = nullptr;
    return 0;
}
