#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

/**
给定一个整数列表 `numbers`，请你完成以下操作：
1. 找出列表中的最小值和最大值分别输出。std::max_element, std::min_element
2. 计算总和以及平均值分别输出。
3. 分别输出所有的奇数和偶数。
4. 将列表中的每个数奇数加 5，偶数减5，并按升序排序输出.
   numbers = {-57, -83, 177, 8, 11, 78, -94, 123, -26, 143, -58, 12, 66, 42, 55, -18, -35, 155, -63, 131}
 */
int main() {
    std::vector<int> numbers = {
        -57, -83, 177, 8, 11, 78, -94, 123, -26, 143, -58, 12, 66, 42, 55, -18, -35, 155, -63, 131
    };
    auto max = std::max_element(numbers.begin(), numbers.end());
    std::cout << *max << std::endl;

    auto min = std::min_element(numbers.begin(), numbers.end());
    std::cout << *min << std::endl;

    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    std::cout << sum << std::endl;

    std::cout << sum / numbers.size() << std::endl;

    std::for_each(numbers.begin(), numbers.end(), [&](int i) {
        if (i % 2) {
            std::cout << i << " ";
        }
    });

    std::cout << std::endl;
    std::for_each(numbers.begin(), numbers.end(), [](int &i) {
        if (i % 2 == 0) {
            std::cout << i << " ";
        }
    });

    std::cout << std::endl;
    std::for_each(numbers.begin(), numbers.end(), [](int &i) {
        if (i % 2) {
            i += 5;
        } else {
            i -= 5;
        }
    });
    std::sort(numbers.begin(), numbers.end());
    std::for_each(numbers.begin(), numbers.end(), [](int &n) {
        std::cout << n << " ";
    });

    return 0;
}
