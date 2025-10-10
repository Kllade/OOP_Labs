cmake_minimum_required(VERSION 3.10)
project(oop_labs)

find_package(GTest REQUIRED)

add_executable(lab2 main.cpp src/Eleven.cpp)
target_include_directories(lab2 PUBLIC include)

add_executable(tests tests/test_eleven.cpp src/Eleven.cpp)
target_include_directories(tests PUBLIC include)
target_link_libraries(tests GTest::gtest_main)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
