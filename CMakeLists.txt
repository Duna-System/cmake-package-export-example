cmake_minimum_required(VERSION 3.15)
project(thread-pool)


option(BUILD_TESTS "Build Test Programs" OFF)

add_library(${PROJECT_NAME} SHARED
src/thread_pool.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
$<INSTALL_INTERFACE:include>
)

if(BUILD_TESTS)
    find_package(GTest)
    enable_testing()
    
    add_executable(test_${PROJECT_NAME} 
    tst/test_thread_pool.cpp)

    target_link_libraries(test_${PROJECT_NAME} 
    ${PROJECT_NAME}
    GTest::gtest_main
    )

    gtest_discover_tests(test_${PROJECT_NAME})
endif()

## Installation ##

# Include install dir definitions (lib, inc, ...)
include(GNUInstallDirs)

# Install binaries.
install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}-targets
LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

# Install headers
install (
    DIRECTORY ${CMAKE_SOURCE_DIR}/include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Not needed?
# export(EXPORT ${PROJECT_NAME}-targets
# FILE "${CMAKE_CURRENT_BINARY_DIR}/ClimbingStats/ClimbingStatsConfig.cmake"
# )

# Install targets.
install(EXPORT ${PROJECT_NAME}-targets
DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
# NAMESPACE thread-pool:: # Optional
)

# Transform *-cmake.in -> *-cmake. Replaces @VAR@.
configure_file(cmake/thread-pool.cmake.in
  ${PROJECT_NAME}-config.cmake
  @ONLY
)

# Install the newly configured *-config.cmake
install(
    FILES
    ${CMAKE_BINARY_DIR}/${PROJECT_NAME}-config.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
)