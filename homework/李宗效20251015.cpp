#include <stdio.h>

// 在这里补充三个函数的实现
inline int sum(int a, int &res) {
    res += a;
    return res;
}

inline int product(int a, int &res) {
    if (res == 0) {
        res = 1;
    }
    res *= a;
    return res;
}

inline int calculate(int arr[], int len, int (*func)(int, int &)) {
    int res = 0;
    for (int i = 0; i < len; i++) {
        func(arr[i], res);
    }
    return res;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int len = sizeof(arr) / sizeof(arr[0]);

    // 计算数组元素的和
    int sum_result = calculate(arr, len, sum);
    printf("Sum: %d\n", sum_result);

    // 计算数组元素的积
    int product_result = calculate(arr, len, product);
    printf("Product: %d\n", product_result);

    return 0;
}
