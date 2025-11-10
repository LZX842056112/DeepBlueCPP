#include <iostream>

double add(double a, double b) {
    return a + b;
}

double sub(double a, double b) {
    return a - b;
}

double mul(double a, double b) {
    return a * b;
}

double div(double a, double b) {
    if (b == 0) {
        std::cout << "Error: Division by zero" << std::endl;
        return 0;
    }
    return a / b;
}
