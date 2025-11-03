#include <iostream>
#include <string>

namespace x_y_com {
    static int count = 0;

    std::string add(const std::string &a, const std::string &b) {
        count++;
        return a + b;
    }


    void print() {
        std::cout << "call count: " << count << std::endl;
    }
}
