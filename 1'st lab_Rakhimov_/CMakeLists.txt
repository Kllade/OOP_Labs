cmake_minimum_required(VERSION 3.10)
project(oop_labs)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

add_executable(lab1 main.cpp src/divisible.cpp)
target_include_directories(lab1 PUBLIC include)

add_executable(tests tests/tests01.cpp src/divisible.cpp)
target_include_directories(tests PUBLIC include)
target_link_libraries(tests GTest::gtest_main Threads::Threads)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
