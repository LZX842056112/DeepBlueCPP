#include <iostream>

namespace z_y_com{
    static int call_count = 0;

    int add(const int a, const int b) {
        call_count++;
        return a + b;
    }

    void print() {
        std::cout << "call_count: " << call_count << std::endl;
    }
}
