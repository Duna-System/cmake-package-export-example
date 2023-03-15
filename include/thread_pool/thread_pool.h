#pragma once
#include <thread>
#include <functional>

class ThreadPool
{
public:
    ThreadPool() = default;
    ThreadPool(unsigned int n_threads) : n_threads_(n_threads) {}
    virtual ~ThreadPool() {
        // Make sure all threads are finished?
        for (auto& thread : threads_)
        {
            thread.join();
        }
    };

    void start() { is_running_ = true; }
    void stop() { is_running_ = false; }
    void spin();
    void addTask(const std::function<void(void)> &func);

    unsigned int getNumberThreads() const
    {
        return n_threads_;
    }

private:
    unsigned int n_threads_ = 2;
    std::vector<std::thread> threads_;
    bool is_running_ = false;
};