cmake_minimum_required(VERSION 3.16)
project(lab6 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Sources
file(GLOB LAB6_HEADERS CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp
)

file(GLOB LAB6_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

# Remove main.cpp from library sources if exists
list(REMOVE_ITEM LAB6_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

# Main executable
add_executable(lab6_app ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp ${LAB6_SOURCES})
target_include_directories(lab6_app PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Tests
option(LAB6_ENABLE_TESTS "Enable lab6 tests" ON)
if(LAB6_ENABLE_TESTS)
  include(FetchContent)
  set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
  set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
  FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
  )
  FetchContent_MakeAvailable(googletest)

  enable_testing()
  file(GLOB LAB6_TESTS CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/tests/*_test.cpp)
  if(LAB6_TESTS)
    add_executable(lab6_tests ${LAB6_TESTS} ${LAB6_SOURCES})
    target_include_directories(lab6_tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
    target_link_libraries(lab6_tests PRIVATE GTest::gtest_main)
    include(GoogleTest)
    gtest_discover_tests(lab6_tests)
  endif()
endif()

