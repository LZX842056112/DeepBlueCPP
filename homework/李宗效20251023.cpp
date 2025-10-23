#include <iostream>
#include <string>

class MyData {
public:
    int *data;
    int size;

    MyData(const int s) : size(s) {
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = i;
        }
    }

    MyData(const MyData &other) {
        std::cout << "MyData construct" << std::endl;
        data = new int(*other.data);
    }


    ~MyData() {
        std::cout << "MyData deconstruct" << std::endl;
        delete[] data;
        data = nullptr;
    }
};

int main() {
    MyData my_data(5);
    MyData my_data2(my_data);
    std::cout << my_data.data << std::endl;
    std::cout << my_data2.data << std::endl;

    return 0;
}
