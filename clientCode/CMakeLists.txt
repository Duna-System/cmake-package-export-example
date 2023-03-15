cmake_minimum_required(VERSION 3.15)
project(client-of-thread-pool)


set (CMAKE_PREFIX_PATH "/home/marcus/workspace/cpp/myPackage/build/install")
find_package(thread-pool REQUIRED)

add_executable(client client.cpp)

target_link_libraries(client thread-pool)