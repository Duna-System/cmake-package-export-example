#include <thread_pool/thread_pool.h>
#include <iostream>

void myfunc()
{
    std::cout << "HEY!\n\n\n\n";
}
int main()
{
    ThreadPool abyy;
    abyy.start();

    abyy.addTask(myfunc);
    return 0;
}