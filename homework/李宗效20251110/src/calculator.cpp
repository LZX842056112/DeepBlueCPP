#include <iostream>

extern double add(double, double);

extern double sub(double, double);

extern double mul(double, double);

extern double div(double, double);

int main() {
    double a = 9.0;
    double b = 6.0;

    std::cout << "a + b = " << add(a, b) << std::endl;
    std::cout << "a - b = " << sub(a, b) << std::endl;
    std::cout << "a * b = " << mul(a, b) << std::endl;
    std::cout << "a / b = " << div(a, b) << std::endl;

    return 0;
}
