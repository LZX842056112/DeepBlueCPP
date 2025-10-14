#include <iostream>

int main() {
    int arr[4] = {3, 4, 5, 6};
    int num = 0;
    int *ptr = arr;

    while (true) {
        if (num++ > std::size(arr)) {
            break;
        }
        if (*ptr % 2) {
            *ptr += 1;
        } else {
            *ptr += 2;
        }
        ptr++;
    }
    for (int i: arr) {
        std::cout << i << std::endl;
    }
}
