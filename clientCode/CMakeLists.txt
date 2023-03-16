cmake_minimum_required(VERSION 3.15)
project(client-of-thread-pool)

# Add library package to cmake path.
list (APPEND CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/../build/install )

find_package(thread-pool REQUIRED)
add_executable(client client.cpp)
target_link_libraries(client thread-pool)