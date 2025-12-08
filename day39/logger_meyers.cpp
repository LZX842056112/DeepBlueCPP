#include <iostream>
#include <mutex>
#include <string>

class Logger {
public:
    static Logger& instance() {
        static Logger inst; // C++11 起线程安全
        return inst;
    }

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    Logger(Logger&&) = delete;
    Logger& operator=(Logger&&) = delete;

    void log(const std::string& msg) {
        std::lock_guard<std::mutex> lk(mu_);
        std::cout << msg << std::endl;
    }

private:
    Logger() = default;
    ~Logger() = default;

    std::mutex mu_;
};

int main() {
    auto& L = Logger::instance();
    auto& M = Logger::instance();
    std::cout << &L << std::endl;
    std::cout << &M << std::endl;
    L.log("Hello, Singleton!");
}