#include <thread_pool/thread_pool.h>

void ThreadPool::spin()
{
    while(is_running_)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void ThreadPool::addTask(const std::function<void(void)> &func)
{
    threads_.push_back(std::thread(func));
}