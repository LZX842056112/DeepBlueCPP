#include <mutex>
#include <memory>
#include <unordered_map>
#include <string>

class Config {
public:
    static Config& instance() {
        std::call_once(init_flag_, [] { inst_.reset(new Config()); });
        return *inst_;
    }

    static void destroy() { // 手动销毁（例如在 main 尾部指定时机）
        inst_.reset();
    }

    void set(std::string key, std::string value) {
        std::lock_guard<std::mutex> lk(mu_);
        kv_[std::move(key)] = std::move(value);
    }

    std::string get(const std::string& key) {
        std::lock_guard<std::mutex> lk(mu_);
        auto it = kv_.find(key);
        return it != kv_.end() ? it->second : "";
    }

    Config(const Config&) = delete;
    Config& operator=(const Config&) = delete;
    Config(Config&&) = delete;
    Config& operator=(Config&&) = delete;
    ~Config() = default;

private:
    Config() = default;

    static std::once_flag init_flag_;
    static std::unique_ptr<Config> inst_;

    std::mutex mu_;
    std::unordered_map<std::string, std::string> kv_;
};

std::once_flag Config::init_flag_;
std::unique_ptr<Config> Config::inst_;

#include <iostream>

int main() {
    auto& C = Config::instance();
    C.set("host", "127.0.0.1");
    std::cout << C.get("host") << std::endl;

    auto& C1 = Config::instance();
    std::cout << &C << std::endl;
    std::cout << &C1 << std::endl;

    Config::destroy(); // 明确收尾
}