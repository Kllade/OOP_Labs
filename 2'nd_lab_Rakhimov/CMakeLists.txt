cmake_minimum_required(VERSION 3.10)
project(oop_labs)

find_package(GTest REQUIRED)
 
set(ELEVEN_SOURCES
    src/Eleven.cpp
    src/ElevenOperations.cpp
    src/ElevenConversion.cpp
)

add_executable(lab2 main.cpp ${ELEVEN_SOURCES})
target_include_directories(lab2 PUBLIC include)

add_executable(tests tests/test_eleven.cpp ${ELEVEN_SOURCES})
target_include_directories(tests PUBLIC include)
target_link_libraries(tests GTest::gtest_main)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
