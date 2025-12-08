#include <atomic>
#include <mutex>

class S {
public:
    static S* instance() {
        S* p = ptr_.load(std::memory_order_acquire);
        if (!p) {
            std::lock_guard<std::mutex> lk(m_);
            p = ptr_.load(std::memory_order_relaxed);
            if (!p) {
                p = new S();
                ptr_.store(p, std::memory_order_release);
            }
        }
        return p;
    }

    S(const S&) = delete;
    S& operator=(const S&) = delete;

private:
    S() = default;
    ~S() = default; // 通常不回收，可能有“有意泄漏”以避免析构次序问题

    static std::atomic<S*> ptr_;
    static std::mutex m_;
};

std::atomic<S*> S::ptr_{nullptr};
std::mutex S::m_;