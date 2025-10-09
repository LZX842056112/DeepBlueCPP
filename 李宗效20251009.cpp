#include <iostream>

double conversion_f(double f) {
    return (f - 32) * 5 / 9;
}

double conversion_c(double c) {
    return c * 9 / 5 + 32;
}

int main() {
    int num;
    double f, c;
    std::cout << "请选择转换类型 (1. 华氏转摄氏, 2. 摄氏转华氏)：";
    std::cin >> num;
    switch (num) {
        case 1:
            std::cout << "请输入华氏温度：";
            std::cin >> f;
            std::cout << "对应的摄氏温度为：" << conversion_f(f) << " 摄氏度" << std::endl;
            break;
        case 2:
            std::cout << "请输入摄氏温度：";
            std::cin >> c;
            std::cout << "对应的华氏温度为：" << conversion_c(c) << " 华氏度" << std::endl;
            break;
        default:
            std::cout << "请重新输入!(1. 华氏转摄氏, 2. 摄氏转华氏)";
    }
}
