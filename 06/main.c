#include <stdio.h>

// day06
// ******************************************************
int add_int(int a, int b) {
    return a + b;
}

double add_double(double a, double b) {
    return a + b;
}

int main(void) {
    int a = 9;
    int b = 6;
    double c = 9.0;
    double d = 6.0;
    printf("%d\n", add_int(a, b));
    printf("%f\n", add_double(c, d));
    return 0;
}
