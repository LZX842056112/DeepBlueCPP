#include <iostream>

int main() {
    int i = 1;
    while (i <= 100) {
        if (i % 2 == 0) {
            std::cout << i << std::endl;
        }
        i++;
    }


    for (int j = 7; j <= 100; j++) {
        if (j % 7 % 2 == 0) {
            std::cout << j << std::endl;
        }
    }

    return 0;
}
