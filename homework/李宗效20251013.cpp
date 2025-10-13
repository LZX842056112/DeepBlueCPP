#include <iostream>

bool isLeapYear(int year) {
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

int main() {
    if (isLeapYear(2024)) {
        std::cout << "是闰年" << std::endl;
    } else {
        std::cout << "不是闰年" << std::endl;
    }

    return 0;
}
