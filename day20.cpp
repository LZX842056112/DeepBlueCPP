#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <thread>
#include <chrono>
#include <ratio>
#include <functional>
#include <unistd.h>
#include <map>

class MyClass {
public:
    MyClass() {
        ptr = new int(9);
    }

    MyClass(const MyClass &other) {
        ptr = new int(*other.ptr);
    }

    MyClass(MyClass &&other) {
        ptr = other.ptr;
        other.ptr = nullptr;
    }

    int *ptr;
};

class Resource {
public:
    Resource() {
        std::cout << "Resource acquired" << std::endl;
    }

    Resource(int id) : id_(id) {
        std::cout << "Resource " << id_ << " acquired" << std::endl;
    }

    ~Resource() {
        std::cout << "Resource " << id_ << " destroyed" << std::endl;
    }

    int getId() const { return id_; }

    void doSomething() {
        std::cout << "Resource " << id_ << " is doing something" << std::endl;
    }

private:
    int id_;
};

void processResource(std::unique_ptr<Resource> res) {
    res->doSomething();
    // res在这里自动销毁，Resource也被自动释放
}

void useResource(std::shared_ptr<Resource> res, int duration) {
    std::cout << "Thread using resource " << res->getId() << " for " << duration << " seconds" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(duration));
    res->doSomething();
    std::cout << "Thread finished using resource " << res->getId() << std::endl;
}

void hello() {
    std::cout << "Hello, concurrent world!" << std::endl;
}

void printMessage(const std::string &message, int times) {
    for (int i = 0; i < times; ++i) {
        std::cout << message << " (" << i + 1 << "/" << times << ")" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void f1() {
    int n = 0;
    for (; n < 10;) {
        std::cout << std::this_thread::get_id() << " n = " << n << std::endl;
        sleep(1);
        n += 2;
    }
}

class Point {
public:
    Point(int x, int y) : x_(x), y_(y) {
    }

    void print() const {
        std::cout << "Point(" << x_ << ", " << y_ << ")" << std::endl;
    }

private:
    int x_, y_;
};

// 传统枚举
enum Color {
    RED = 0,
    GREEN = 1,
    BLUE = 2
};

enum Color1 {
    // RED = 0,
    // GREEN = 1,
    // BLUE = 2
};

// 强类型枚举
enum class Direction {
    NORTH,
    SOUTH,
    EAST,
    WEST
};

enum class Direction2 {
    NORTH,
    SOUTH,
    EAST,
    WEST
};

// 可以指定底层类型
enum class Status : unsigned int {
    OK = 0,
    ERROR = 1,
    PENDING = 2
};

constexpr int squre_int(int a) {
    return a * a;
}

int squre_int1(int a) {
    return a * a;
}

// 简单数值计算
auto multiply(double x, int y) {
    return x * y; // 返回类型推导为 double
}

// 返回复杂类型
auto getVector() {
    return std::vector<int>{1, 2, 3, 4, 5}; // 返回类型推导为 std::vector<int>
}

// 递归函数 - 需要至少一个非递归返回语句来启动推导
auto factorial(int n) {
    if (n <= 1) {
        return 1; // 启动推导，返回类型为 int
    }
    return n * factorial(n - 1); // 递归调用，返回类型必须与启动推导的类型一致
}

// 模板函数与返回类型推导
template<typename Container>
auto getFirstElement(const Container &container) {
    return *container.begin(); // 返回类型推导为容器的值类型
}

// 与 decltype 结合使用
template<typename T, typename U>
auto divide(T t, U u) -> decltype(t / u) {
    return t / u;
}

class Shape {
public:
    virtual ~Shape() = default;

    virtual void draw() const = 0;
};

class Circle : public Shape {
public:
    void draw() const override { std::cout << "Drawing circle" << std::endl; }
};

class Square : public Shape {
public:
    void draw() const override { std::cout << "Drawing square" << std::endl; }
};

// 工厂函数，根据类型创建不同的形状
auto createShape(const std::string &type) -> std::unique_ptr<Shape> {
    if (type == "circle") {
        return std::make_unique<Circle>();
    } else if (type == "square") {
        return std::make_unique<Square>();
    }
    return nullptr;
}

int main() {
    std::unique_ptr<MyClass> ptr = std::make_unique<MyClass>();
    std::unique_ptr<MyClass> ptr1 = std::move(ptr);
    std::cout << "*********************************" << std::endl;

    // 创建unique_ptr
    std::unique_ptr<Resource> res1(new Resource(1));
    res1->doSomething();
    // 使用std::make_unique创建unique_ptr (C++14)
    auto res2 = std::make_unique<Resource>(2);
    res2->doSomething();
    // unique_ptr不能复制，只能移动
    // std::unique_ptr<Resource> res3 = res1;  // 错误！不能复制
    std::unique_ptr<Resource> res4 = std::move(res1); // OK，移动所有权
    // res1现在为空
    // 可以将unique_ptr传递给函数，通过移动语义转移所有权
    processResource(std::move(res4));
    // res4现在为空
    // unique_ptr可以用于管理数组
    std::unique_ptr<int[]> arr(new int[5]{1, 2, 3, 4, 5});
    for (int i = 0; i < 5; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    // unique_ptr在容器中的使用
    std::vector<std::unique_ptr<Resource> > resources;
    resources.push_back(std::make_unique<Resource>(3));
    resources.push_back(std::make_unique<Resource>(4));
    // 当vector被销毁时，所有Resource也会被自动释放
    std::cout << "*********************************" << std::endl;

    // 创建shared_ptr
    std::shared_ptr<Resource> res3(new Resource(1));
    std::cout << "res3 use count: " << res3.use_count() << std::endl;
    // 使用std::make_shared创建shared_ptr（更高效）
    auto res6 = std::make_shared<Resource>(2);
    std::cout << "res6 use count: " << res6.use_count() << std::endl;
    // 复制shared_ptr，增加引用计数
    std::shared_ptr<Resource> res5 = res6;
    std::cout << "res6 use count after copy: " << res6.use_count() << std::endl;
    std::cout << "res5 use count: " << res5.use_count() << std::endl;
    // shared_ptr在容器中的使用
    std::vector<std::shared_ptr<Resource> > resources2;
    resources2.push_back(std::make_shared<Resource>(3));
    resources2.push_back(std::make_shared<Resource>(4));
    resources2.push_back(res6); // res6的引用计数增加
    std::cout << "res5 use count after adding to vector: " << res5.use_count() << std::endl;
    // 使用weak_ptr解决循环引用问题
    std::cout << "\nDemonstrating weak_ptr to avoid circular references:" << std::endl;
    struct Node {
        std::string name;
        std::shared_ptr<Node> next;
        std::weak_ptr<Node> prev; // 使用weak_ptr避免循环引用
        Node(const std::string &n) : name(n) {
            std::cout << "Node " << name << " created" << std::endl;
        }

        ~Node() {
            std::cout << "Node " << name << " destroyed" << std::endl;
        }
    };
    std::shared_ptr<Node> node1 = std::make_shared<Node>("Node1");
    std::shared_ptr<Node> node2 = std::make_shared<Node>("Node2");
    node1->next = node2;
    node2->prev = node1; // 使用weak_ptr，不会增加引用计数
    std::cout << "node1 use count: " << node1.use_count() << std::endl;
    std::cout << "node2 use count: " << node2.use_count() << std::endl;
    // 访问weak_ptr指向的对象
    if (auto locked = node2->prev.lock()) {
        std::cout << "Previous node of node2 is: " << locked->name << std::endl;
    } else {
        std::cout << "Previous node of node2 is expired" << std::endl;
    }
    std::cout << "*********************************" << std::endl;

    // 使用steady_clock测量时间间隔
    std::cout << "Measuring time with steady_clock:" << std::endl;
    auto start = std::chrono::steady_clock::now();
    // 执行一些操作
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Operation took " << duration.count() << " milliseconds" << std::endl;
    // 使用system_clock获取当前时间
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::cout << "\nCurrent time: " << std::ctime(&now_time);
    // 使用high_resolution_clock进行高精度计时
    std::cout << "\nHigh resolution timing:" << std::endl;
    auto hr_start = std::chrono::high_resolution_clock::now();
    // 执行一些操作
    long long sum = 0;
    for (int i = 0; i < 1000000; ++i) {
        sum += i;
    }
    auto hr_end = std::chrono::high_resolution_clock::now();
    auto hr_duration = std::chrono::duration_cast<std::chrono::microseconds>(hr_end - hr_start);
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Calculation took " << hr_duration.count() << " microseconds" << std::endl;
    // 使用自定义时间单位
    std::cout << "\nUsing custom duration units:" << std::endl;
    // 定义一个基于毫秒的duration
    using milliseconds = std::chrono::duration<double, std::milli>;
    // 定义一个基于帧率的duration（60 FPS）
    using frames = std::chrono::duration<double, std::ratio<1, 60> >;
    auto frame_start = std::chrono::steady_clock::now();
    std::this_thread::sleep_for(std::chrono::milliseconds(16)); // 大约一帧的时间
    auto frame_end = std::chrono::steady_clock::now();
    frames frame_duration = frame_end - frame_start;
    milliseconds ms_duration = frame_end - frame_start;
    std::cout << "Frame duration: " << frame_duration.count() << " frames (60 FPS)" << std::endl;
    std::cout << "Frame duration: " << ms_duration.count() << " milliseconds" << std::endl;
    // 时间点的算术运算
    std::cout << "\nTime point arithmetic:" << std::endl;
    auto current_time = std::chrono::system_clock::now();
    auto future_time = current_time + std::chrono::hours(24);
    std::time_t current_c_time = std::chrono::system_clock::to_time_t(current_time);
    std::time_t future_c_time = std::chrono::system_clock::to_time_t(future_time);
    std::cout << "Current time: " << std::ctime(&current_c_time);
    std::cout << "Future time (24 hours later): " << std::ctime(&future_c_time);
    std::cout << "*********************************" << std::endl;

    std::thread t1(f1);
    int j = 0;
    for (; j < 10;) {
        std::cout << std::this_thread::get_id() << " j = " << j << std::endl;
        sleep(2);
        j += 3;
    }
    t1.join();
    std::cout << "*********************************" << std::endl;

    // 创建并启动一个线程
    std::cout << "Starting a thread..." << std::endl;
    std::thread t(hello);
    // 等待线程完成
    t.join();
    std::cout << "Thread finished." << std::endl;
    // 创建带参数的线程
    std::cout << "\nStarting a thread with arguments..." << std::endl;
    std::thread t2(printMessage, "Hello from thread", 3);
    // 分离线程（让它独立运行）
    t2.detach();
    std::cout << "Thread detached." << std::endl;
    // 等待一段时间，以便分离的线程有机会执行
    std::this_thread::sleep_for(std::chrono::seconds(1));
    // 使用lambda表达式创建线程
    std::cout << "\nStarting a thread with lambda..." << std::endl;
    std::thread t3([]() {
        for (int i = 0; i < 5; ++i) {
            std::cout << "Lambda thread: " << i << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
    });
    t3.join();
    std::cout << "Lambda thread finished." << std::endl;
    // 使用成员函数创建线程
    std::cout << "\nStarting a thread with member function..." << std::endl;
    class Worker {
    public:
        void doWork(int id) {
            for (int i = 0; i < 3; ++i) {
                std::cout << "Worker " << id << ": Working... (" << i + 1 << "/3)" << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }
        }
    };
    Worker worker;
    std::thread t4(&Worker::doWork, &worker, 1);
    t4.join();
    std::cout << "Worker thread finished." << std::endl;
    // 线程ID
    std::cout << "\nThread IDs:" << std::endl;
    std::cout << "Main thread ID: " << std::this_thread::get_id() << std::endl;
    std::thread t5([]() {
        std::cout << "New thread ID: " << std::this_thread::get_id() << std::endl;
    });
    t5.join();
    std::cout << "*********************************" << std::endl;

    // 基本类型初始化
    int i{5};
    double d{3.14};
    char c{'A'};
    std::cout << "i = " << i << ", d = " << d << ", c = " << c << std::endl;
    // 数组初始化
    int arr2[]{1, 2, 3, 4, 5};
    std::cout << "Array: ";
    for (const auto &elem: arr2) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    // 容器初始化
    std::vector<int> vec{1, 2, 3, 4, 5};
    std::map<std::string, int> m{{"Alice", 25}, {"Bob", 30}};
    std::cout << "Vector: ";
    for (const auto &elem: vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    std::cout << "Map:" << std::endl;
    for (const auto &pair: m) {
        std::cout << "  " << pair.first << ": " << pair.second << std::endl;
    }
    // 自定义类型初始化
    Point p{10, 20};
    p.print();
    // 动态分配的数组初始化
    int *dynamicArr = new int[5]{1, 2, 3, 4, 5};
    std::cout << "Dynamic array: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << dynamicArr[i] << " ";
    }
    std::cout << std::endl;
    delete[] dynamicArr;
    // 防止窄化转换
    // int x{3.14};  // 错误！窄化转换不允许
    int y = 3.14; // 警告，但允许
    std::cout << "y = " << y << std::endl;
    std::cout << "*********************************" << std::endl;

    // 传统枚举的问题
    Color c1 = RED;
    int i1 = c1; // 隐式转换为int
    std::cout << "Color as int: " << i1 << std::endl;
    // 不同枚举类型的比较
    if (RED == 0) {
        // 允许
        std::cout << "RED equals 0" << std::endl;
    }
    // 强类型枚举的使用
    Direction d1 = Direction::NORTH;
    // 以下代码会导致编译错误
    // int j = d1;  // 错误！不能隐式转换为int
    // if (d == 0) {}  // 错误！不能与整数比较
    // 必须显式转换
    int k = static_cast<int>(d1);
    std::cout << "Direction as int: " << k << std::endl;
    // 不同强类型枚举之间不能比较
    // if (d1 == Direction::NORTH) {}  // OK，相同类型
    // if (d1 == Status::OK) {}  // 错误！不同类型
    // 强类型枚举可以指定底层类型
    Status s = Status::OK;
    unsigned int u = static_cast<unsigned int>(s);
    std::cout << "Status as unsigned int: " << u << std::endl;
    std::cout << "*********************************" << std::endl;

    int result = squre_int(5);
    int result2 = squre_int1(6);
    std::cout << result << std::endl;
    std::cout << result2 << std::endl;
    int n;
    std::cin >> n;
    int result3 = squre_int(n);
    std::cout << result3 << std::endl;
    std::cout << "*********************************" << std::endl;

    // 使用基于范围的for循环遍历数组
    int arr1[] = {1, 2, 3, 4, 5};
    std::cout << "Array elements: ";
    for (int elem: arr1) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    // 使用引用修改元素
    std::cout << "Doubling array elements: ";
    for (int &elem: arr1) {
        elem *= 2;
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    // 使用const引用避免拷贝
    std::cout << "Array elements (const ref): ";
    for (const int &elem: arr1) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    // 遍历vector
    std::vector<std::string> vec1 = {"apple", "banana", "cherry"};
    std::cout << "Vector elements: ";
    for (const auto &fruit: vec1) {
        std::cout << fruit << " ";
    }
    std::cout << std::endl;
    // 遍历map
    std::map<std::string, int> scores = {{"Alice", 90}, {"Bob", 85}, {"Charlie", 95}};
    std::cout << "Map elements:" << std::endl;
    for (const auto &pair: scores) {
        std::cout << "  " << pair.first << ": " << pair.second << std::endl;
    }
    // 遍历std::array
    std::array<double, 3> temperatures = {23.5, 24.1, 22.8};
    std::cout << "Temperatures: ";
    for (const auto &temp: temperatures) {
        std::cout << temp << "°C ";
    }
    std::cout << std::endl;
    // 使用结构化绑定(C++17)简化map遍历
    // 注意：这里需要C++17支持，如果编译器不支持，可以使用传统方式
    std::cout << "Map elements (structured binding):" << std::endl;
    for (const auto &[name, score]: scores) {
        std::cout << "  " << name << ": " << score << std::endl;
    }
    std::cout << "*********************************" << std::endl;

    auto result4 = multiply(3.14, 2);
    std::cout << "Result: " << result4 << std::endl; // 输出 result4: 6.28
    auto vec2 = getVector();
    std::cout << "Vector: ";
    for (const auto &elem: vec2) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    std::cout << "Factorial of 5: " << factorial(5) << std::endl;
    std::map<std::string, int> myMap = {{"one", 1}, {"two", 2}};
    auto first = getFirstElement(myMap);
    std::cout << "First element: " << first.first << " -> " << first.second << std::endl;
    auto divResult = divide(10.0, 3);
    std::cout << "10.0 / 3 = " << divResult << std::endl;
    std::cout << "*********************************" << std::endl;

    return 0;
}
