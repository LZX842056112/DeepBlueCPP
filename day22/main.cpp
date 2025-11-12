#include <iostream>

#include "./sub_module/sub.h"
#include "./add_module/add.h"

int main() {
    int a = 9;
    int b = 6;
    int add_result = add(a, b);
    int sub_result = sub(a, b);
    std::cout << "add_result = " << add_result << std::endl;
    std::cout << "sub_result = " << sub_result << std::endl;

    return 0;
}