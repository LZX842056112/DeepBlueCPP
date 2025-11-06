#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <memory>
#include <numeric>
#include <thread>
#include <type_traits>
#include <complex>
#include <ratio>
#include <bitset>
#include <iomanip>
#include <optional>
#include <any>
#include <variant>

class Resource {
public:
    Resource(const std::string &name) : name_(name) {
        std::cout << "Resource " << name_ << " created" << std::endl;
    }

    ~Resource() {
        std::cout << "Resource " << name_ << " destroyed" << std::endl;
    }

    void use() const {
        std::cout << "Using resource " << name_ << std::endl;
    }

private:
    std::string name_;
};

class DelayedAction {
public:
    template<typename Func>
    DelayedAction(int delayMs, Func &&func)
        : timer_([delayMs, f = std::forward<Func>(func)]() {
            std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
            f();
        }) {
    }

public:
    std::thread timer_;
};

// 基本变量模板
template<typename T>
constexpr T pi = T(3.1415926535897932385L);

template<>
constexpr float pi<float> = 3.1415926535f;

template<>
constexpr double pi<double> = 3.1415926535897932385;

template<>
constexpr long double pi<long double> = 3.1415926535897932385L;

// 复数类型的pi
template<typename T>
constexpr std::complex<T> pi_complex = std::complex<T>(pi<T>, T());

// 其他数学常数
template<typename T>
constexpr T e = T(2.7182818284590452353);

template<typename T>
constexpr T golden_ratio = T(1.6180339887498948482);

// 物理常数
template<typename T>
constexpr T speed_of_light = T(299792458.0); // m/s

template<typename T>
constexpr T planck_constant = T(6.62607015e-34); // J·s

template<typename T>
T circularArea(T r) {
    return pi<T> * r * r;
}

// 使用标准库的ratio
template<typename T, typename Period = std::ratio<1> >
constexpr T frequency_to_angular_velocity(T freq) {
    return T(2) * pi<T> * freq * Period::num / Period::den;
}

// 标记函数为已弃用
[[deprecated("Use newPrint() instead for better performance")]]
void oldPrint(const std::string &message) {
    std::cout << "[OLD] " << message << std::endl;
}

void newPrint(const std::string &message) {
    std::cout << "[NEW] " << message << std::endl;
}

// 标记类为已弃用
class [[deprecated("Use NewContainer instead, which provides better performance")]] OldContainer {
public:
    void add(int item) {
        items_.push_back(item);
    }

    int size() const {
        return items_.size();
    }

private:
    std::vector<int> items_;
};

class NewContainer {
public:
    void add(int item) {
        items_.push_back(item);
    }

    int size() const {
        return items_.size();
    }

    // 新增功能
    void clear() {
        items_.clear();
    }

private:
    std::vector<int> items_;
};

// 标记成员函数为已弃用
class NetworkManager {
public:
    void connect() {
        std::cout << "Connecting to network..." << std::endl;
    }

    [[deprecated("Use connect() with timeout parameter instead")]]
    void connectWithoutTimeout() {
        std::cout << "Connecting to network without timeout..." << std::endl;
    }

    void connect(int timeoutMs) {
        std::cout << "Connecting to network with timeout: " << timeoutMs << "ms" << std::endl;
    }
};

// 标记变量为已弃用
[[deprecated("Use newConfig instead")]]
const std::string oldConfig = "old_config_value";

const std::string newConfig = "new_config_value";

// 标记枚举值为已弃用
enum class Status {
    OK,
    ERROR [[deprecated("Use ERROR_CODE instead")]],
    ERROR_CODE
};

// 标记模板为已弃用
template<typename T>
class [[deprecated("Use SafeVector<T> instead, which provides bounds checking")]] UnsafeVector {
public:
    T &operator[](std::size_t index) {
        return data_[index]; // 无边界检查
    }

private:
    static const std::size_t SIZE = 100;
    T data_[SIZE];
};

template<typename T>
class SafeVector {
public:
    T &operator[](std::size_t index) {
        if (index >= size()) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }

    std::size_t size() const {
        return SIZE;
    }

private:
    static const std::size_t SIZE = 100;
    T data_[SIZE];
};

// C++17
[[nodiscard]] int calculate() {
    return 42;
}

std::pair<int, std::string> getStudent() {
    return {123, "Alice"};
}

std::tuple<int, double, std::string> getPerson() {
    return std::make_tuple(25, 1.75, "Bob");
}

std::optional<int> divide(int a, int b) {
    if (b == 0) {
        return std::nullopt;
    }
    return a / b;
}

std::optional<std::string> getName(bool valid) {
    if (valid) {
        return "Alice";
    } else {
        return std::nullopt;
    }
}

void printString(std::string_view str) {
    std::cout << "String: " << str << std::endl;
    std::cout << "Size: " << str.size() << std::endl;
    std::cout << "First character: " << str[0] << std::endl;
    //str[0] = 'a'; 不要尝试修改, string_view 本身并不拥有数据
}

int main() {
    // 基本泛型 Lambda
    auto genericAdd = [](auto x, auto y) {
        return x + y;
    };
    std::cout << "5 + 3 = " << genericAdd(5, 3) << std::endl; // 输出 8
    std::cout << "2.5 + 1.5 = " << genericAdd(2.5, 1.5) << std::endl; // 输出 4.0
    std::cout << "Hello + world = " << genericAdd(std::string("Hello, "), std::string("world!")) << std::endl;
    // 输出 "Hello, world!"
    // 与STL算法结合使用
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    // 打印所有元素
    std::for_each(numbers.begin(), numbers.end(), [](const auto &n) {
        std::cout << n << " ";
    });
    std::cout << std::endl;
    // 计算所有元素的平方
    std::vector<int> squares;
    std::transform(numbers.begin(), numbers.end(), std::back_inserter(squares),
                   [](auto n) { return n * n; });
    std::cout << "Squares: ";
    for (const auto &sq: squares) {
        std::cout << sq << " ";
    }
    std::cout << std::endl;
    std::cout << "*********************************" << std::endl;

    // 使用泛型Lambda处理不同容器
    auto printContainer = [](const auto &container) {
        for (const auto &elem: container) {
            // 检查元素类型是否为 pair（map 的元素）
            if constexpr (std::is_same_v<decltype(elem), const std::pair<const std::string, int> &>) {
                std::cout << elem.first << ": " << elem.second;
            } else {
                std::cout << elem << " ";
            }
        }
        std::cout << std::endl;
    };
    std::vector<std::string> words = {"Hello", "world", "from", "C++14"};
    std::map<std::string, int> ages = {{"Alice", 25}, {"Bob", 30}};
    std::cout << "Words: ";
    printContainer(words);
    std::cout << "Map elements: ";
    printContainer(ages); // 注意：这里会打印键值对，但格式可能不是我们期望的
    // 更复杂的泛型Lambda - 比较任意类型
    auto compare = [](const auto &a, const auto &b) {
        if (a < b) return -1;
        if (b < a) return 1;
        return 0;
    };
    std::cout << "Compare 5 and 3: " << compare(5, 3) << std::endl;
    std::cout << "Compare \"apple\" and \"banana\": " << compare(std::string("apple"), std::string("banana")) <<
            std::endl;
    // 泛型Lambda与可变参数模板结合
    auto printAll = [](const auto &... args) {
        (std::cout << ... << args) << std::endl; // C++17 折叠表达式
    };
    printAll("Hello", " ", "world", "!", 42);
    std::cout << "*********************************" << std::endl;

    int x = 10;
    auto lambda = [x]() {
        // 只能捕获已存在的变量 x
        return x * 2;
    };
    // 如果需要修改捕获的变量，必须使用可变Lambda
    int y = 5;
    auto mutableLambda = [y]() mutable {
        y *= 2; // 修改的是副本
        return y;
    };
    // 可以创建并初始化新的变量
    auto lambda1 = [x = 10]() {
        return x * 2;
    };
    // 移动捕获
    auto lambda2 = [ptr = std::make_unique<int>(5)]() {
        // 使用 ptr
        return *ptr;
    };
    // 引用捕获并初始化
    auto lambda3 = [&x = y]() {
        // y必须是外部变量
        x *= 2; // 修改的是y的引用
        return x;
    };
    std::cout << "*********************************" << std::endl;

    // 基本初始化捕获
    auto initCapture = [value = 42]() {
        return value;
    };
    std::cout << "Init capture: " << initCapture() << std::endl;
    // 移动捕获
    auto moveCapture = [ptr = std::make_unique<int>(10)]() {
        return *ptr;
    };
    std::cout << "Move capture: " << moveCapture() << std::endl;
    // ptr的所有权已经被移动到lambda表达式内部,所以这里不能再使用ptr
    // 捕获复杂对象
    auto resourceCapture = [res = std::make_shared<Resource>("File")]() {
        res->use();
    };
    resourceCapture();
    // 引用捕获并初始化
    int external = 5;
    auto refCapture = [&x = external]() {
        x *= 2;
        return x;
    };
    std::cout << "Before ref capture: " << external << std::endl;
    std::cout << "Ref capture result: " << refCapture() << std::endl;
    std::cout << "After ref capture: " << external << std::endl;
    // 捕获表达式与泛型Lambda结合
    auto genericCapture = [value = 10](auto x) {
        return x + value;
    };
    std::cout << "Generic capture (int): " << genericCapture(5) << std::endl;
    std::cout << "Generic capture (double): " << genericCapture(3.14) << std::endl;
    // 捕获多个变量并进行初始化
    int multiplier = 2;
    auto multiCapture = [base = 10, &mult = multiplier](auto x) {
        return (x + base) * mult;
    };
    std::cout << "Multi capture: " << multiCapture(5) << std::endl;
    // 捕获表达式与STL算法结合
    std::vector<std::string> words1 = {"Hello", "world", "from", "C++14"};
    std::string prefix = ">> ";
    std::string suffix = " <<";
    std::for_each(words1.begin(), words1.end(),
                  [p = std::move(prefix), s = std::move(suffix)](const std::string &word) {
                      std::cout << p << word << s << std::endl;
                  });
    // 捕获表达式用于延迟计算
    std::map<int, std::string> idToName = {
        {1, "Alice"}, {2, "Bob"}, {3, "Charlie"}
    };
    int id = 2;
    auto lazyLookup = [map = idToName, id = id]() {
        auto it = map.find(id);
        return it != map.end() ? it->second : "Unknown";
    };
    std::cout << "Lazy lookup result: " << lazyLookup() << std::endl;
    // 捕获表达式用于复杂初始化
    std::vector<int> numbers1 = {1, 2, 3, 4, 5};
    auto complexCapture = [sum = std::accumulate(numbers1.begin(), numbers1.end(), 0)]() {
        return sum;
    };
    std::cout << "Complex capture (sum): " << complexCapture() << std::endl;
    std::cout << "*********************************" << std::endl;

    // 使用示例
    DelayedAction action(3000, []() {
        std::cout << "Delayed action executed!" << std::endl;
    });
    action.timer_.join();
    std::cout << "*********************************" << std::endl;

    // 使用不同类型的pi
    std::cout << "Pi (float): " << pi<float> << std::endl;
    std::cout << "Pi (double): " << pi<double> << std::endl;
    std::cout << "Pi (long double): " << pi<long double> << std::endl;
    // 计算圆面积
    std::cout << "Area of circle with radius 5.0 (float): " << circularArea(5.0f) << std::endl;
    std::cout << "Area of circle with radius 5.0 (double): " << circularArea(5.0) << std::endl;
    // 使用复数pi
    auto complex_pi = pi_complex<double>;
    std::cout << "Complex pi: " << complex_pi << std::endl;
    // 使用其他数学常数
    std::cout << "e (double): " << e<double> << std::endl;
    std::cout << "Golden ratio (float): " << golden_ratio<float> << std::endl;
    // 使用物理常数
    std::cout << "Speed of light: " << speed_of_light<double> << " m/s" << std::endl;
    std::cout << "Planck constant: " << planck_constant<double> << " J·s" << std::endl;
    // 使用频率转换函数
    double freq = 50.0; // Hz
    double angular_vel = frequency_to_angular_velocity<double>(freq);
    std::cout << "Angular velocity for " << freq << " Hz: " << angular_vel << " rad/s" << std::endl;
    // 使用毫秒
    double freq_ms = 1000.0; // mHz (millihertz)
    double angular_vel_ms = frequency_to_angular_velocity<double, std::milli>(freq_ms);
    std::cout << "Angular velocity for " << freq_ms << " mHz: " << angular_vel_ms << " rad/s" << std::endl;
    std::cout << "*********************************" << std::endl;

    // 使用已弃用的函数
    // oldPrint("This is an old message");  // 编译器会发出警告
    // 使用新函数
    newPrint("This is a new message");
    // 使用已弃用的类
    OldContainer oldContainer;
    oldContainer.add(1);
    std::cout << "Old container size: " << oldContainer.size() << std::endl;
    // 使用新类
    NewContainer newContainer;
    newContainer.add(1);
    std::cout << "New container size: " << newContainer.size() << std::endl;
    // 使用已弃用的成员函数
    NetworkManager manager;
    // manager.connectWithoutTimeout(); // 编译器会发出警告
    manager.connect(5000);
    // 使用已弃用的变量
    // std::cout << "Old config: " << oldConfig << std::endl; // 编译器会发出警告
    std::cout << "New config: " << newConfig << std::endl;
    // 使用已弃用的枚举值
    Status status = Status::ERROR; // 编译器会发出警告
    status = Status::ERROR_CODE;
    // 使用已弃用的模板
    UnsafeVector<int> unsafeVec;
    unsafeVec[0] = 42; // 编译器会发出警告
    SafeVector<int> safeVec;
    safeVec[0] = 42;
    std::cout << "*********************************" << std::endl;

    calculate(); // 警告：返回值被忽略
    std::cout << "*********************************" << std::endl;

    // 二进制字面量
    int binaryValue = 0b1101; // 二进制表示的 13
    unsigned char flags = 0b10101010; // 位标志
    std::cout << "Binary value 0b1101 = " << binaryValue << std::endl;
    std::cout << "Binary value 0b10101010 = " << static_cast<int>(flags) << std::endl;
    // 使用bitset显示二进制表示
    std::cout << "Binary representation of 13: " << std::bitset<8>(binaryValue) << std::endl;
    std::cout << "Binary representation of flags: " << std::bitset<8>(flags) << std::endl;
    // 数字分隔符 - 整数
    int population = 7'800'000'000; // 世界人口约78亿
    long distanceToSun = 149'597'870'700; // 地球到太阳的距离（米）
    std::cout << "World population: " << population << std::endl;
    std::cout << "Distance to Sun: " << distanceToSun << " meters" << std::endl;
    // 数字分隔符 - 浮点数
    double pi = 3.141'592'653'589'793'238'462;
    double avogadro = 6.022'140'76e23; // 阿伏伽德罗常数
    std::cout << std::setprecision(15);
    std::cout << "Pi: " << pi << std::endl;
    std::cout << "Avogadro's number: " << avogadro << std::endl;
    // 数字分隔符 - 二进制和十六进制
    int binaryWithSeparator = 0b1010'1100'1111'0000;
    int hexWithSeparator = 0xAC'F0;
    std::cout << "Binary with separator: " << binaryWithSeparator
            << " (0b" << std::bitset<16>(binaryWithSeparator) << ")" << std::endl;
    std::cout << "Hex with separator: " << hexWithSeparator
            << " (0x" << std::hex << hexWithSeparator << std::dec << ")" << std::endl;
    // 位操作示例
    unsigned int statusRegister = 0b1100'1010'1111'0101;
    // 提取特定位
    unsigned int errorCode = (statusRegister >> 4) & 0b1111;
    std::cout << "Error code: " << errorCode << std::endl;
    // 设置特定位
    statusRegister |= 0b0000'0000'0000'1000; // 设置第3位
    std::cout << "Status register after setting bit 3: 0b"
            << std::bitset<16>(statusRegister) << std::endl;
    // 清除特定位
    statusRegister &= ~0b0000'0000'0000'1000; // 清除第3位
    std::cout << "Status register after clearing bit 3: 0b"
            << std::bitset<16>(statusRegister) << std::endl;
    // 使用二进制字面量定义位掩码
    const unsigned int READ_FLAG = 0b0000'0001;
    const unsigned int WRITE_FLAG = 0b0000'0010;
    const unsigned int EXECUTE_FLAG = 0b0000'0100;
    unsigned int filePermissions = READ_FLAG | WRITE_FLAG;
    std::cout << "File permissions: 0b" << std::bitset<8>(filePermissions) << std::endl;
    // 检查权限
    if (filePermissions & READ_FLAG) {
        std::cout << "File has read permission" << std::endl;
    }
    if (filePermissions & WRITE_FLAG) {
        std::cout << "File has write permission" << std::endl;
    }
    if (!(filePermissions & EXECUTE_FLAG)) {
        std::cout << "File does not have execute permission" << std::endl;
    }
    std::cout << "*********************************" << std::endl;

    auto student = getStudent();
    int id1 = student.first;
    std::string name = student.second;
    auto [id2, name2] = getStudent(); // 使用结构化绑定
    std::cout << "*********************************" << std::endl;

    auto [age, height, name3] = getPerson();
    std::cout << "Age: " << age << std::endl;
    std::cout << "Height: " << height << std::endl;
    std::cout << "Name: " << name3 << std::endl;
    std::cout << "*********************************" << std::endl;

    std::vector<int> numbers2 = {1, 2, 3, 4, 5};
    // 在 if 语句中初始化并查找元素
    if (auto it = std::find(numbers2.begin(), numbers2.end(), 3); it != numbers.end()) {
        std::cout << "Found at index: " << std::distance(numbers2.begin(), it) << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }
    // 在 switch 语句中初始化状态码
    switch (int status = 0; status) // 这里故意使用分号来表示初始化语句
    {
        case 0:
            std::cout << "Status: OK" << std::endl;
            break;
        case 1:
            std::cout << "Status: Warning" << std::endl;
            break;
        default:
            std::cout << "Status: Error" << std::endl;
    }
    std::cout << "*********************************" << std::endl;

    int a = 9;
    int b = 0;
    auto result = divide(a, b);
    if (result) {
        std::cout << result.value() << std::endl;
    } else {
        std::cout << "Error: Division by zero" << std::endl;
    }
    std::cout << "*********************************" << std::endl;

    auto name1 = getName(true);
    if (name1) {
        std::cout << "Name: " << *name1 << std::endl; // 安全访问
    } else {
        std::cout << "Name not available." << std::endl;
    }
    auto name4 = getName(false);
    if (name4.has_value()) {
        std::cout << "Name: " << name4.value() << std::endl;
    } else {
        std::cout << "Name not available." << std::endl;
    }
    std::cout << "Default name: " << name4.value_or("Default") << std::endl; // 提供默认值
    std::cout << "*********************************" << std::endl;

    std::any value;
    value = 42; // 存储 int
    std::cout << "Int value: " << std::any_cast<int>(value) << std::endl;
    value = std::string("Hello"); // 存储 string
    if (auto p = std::any_cast<std::string>(&value)) {
        std::cout << "String value: " << *p << std::endl; //安全访问
    }
    value = std::vector<int>{1, 2, 3};
    std::cout << "*********************************" << std::endl;

    std::variant<int, double, std::string> myVar;
    myVar = 10; // 现在存储 int
    std::cout << "Int value: " << std::get<int>(myVar) << std::endl;
    myVar = 3.14; // 现在存储 double
    std::cout << "Double value: " << std::get<double>(myVar) << std::endl;
    myVar = "Hello"; // 现在存储 string
    // 访问时需要小心处理异常，或使用 std::get_if
    if (auto p = std::get_if<std::string>(&myVar)) {
        std::cout << "String value: " << *p << std::endl;
    }
    //使用访问者模式
    std::visit([](auto &&arg) {
        std::cout << "Variant value: " << arg << std::endl;
    }, myVar);
    std::cout << "*********************************" << std::endl;

    std::string s = "Hello, world!";
    std::string_view sv1 = s; // 指向 std::string
    std::string_view sv2 = "This is a literal"; // 指向字符串字面量
    const char *cstr = "C-style string";
    std::string_view sv3 = cstr;
    printString(sv1);
    printString(sv2);
    printString(sv3);
    std::cout << "*********************************" << std::endl;

    return 0;
}

// C++17
void function([[maybe_unused]] int param) {
    // 参数未使用，但不会发出警告
    std::cout << "........" << std::endl;
}
