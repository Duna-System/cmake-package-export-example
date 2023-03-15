#include <gtest/gtest.h>
#include <thread_pool/thread_pool.h>

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

void someFunc()
{
    std::cout << "someFunc\n";
}

TEST(Test0, Test_0)
{
    ThreadPool a(5);

    a.start();

    a.addTask(someFunc);

    // a.spin();
}