# @file lCMakeLists.txt
# @license MIT
# @date 24-07-2024
# @author Zofia Kuriata


cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)
project(traffic-lights CXX)


# Add Google Test
enable_testing()
find_package(GTest REQUIRED)
# find_package(GMock REQUIRED)
# set(CMAKE_FIND_DEBUG_MODE ON)
# find_package(GTest CONFIG REQUIRED COMPONENTS GTest GMock)
# set(CMAKE_FIND_DEBUG_MODE OFF)

# Create a static library for common sources
add_library(traffic_lights_lib STATIC
    src/density.hpp
    src/density.cpp
    src/file_access.hpp
    src/file_access.cpp
    src/in.hpp
    src/light.hpp
    src/light.cpp
)

target_include_directories(traffic_lights_lib
    PUBLIC
    src/
)

# Main executable
add_executable(input
    src/test_input.cpp
)
target_link_libraries(input
    PRIVATE
    traffic_lights_lib
)
target_include_directories(input
    PRIVATE
    src/
)

# Test executable
add_executable(tests
    tests/test.cpp
)

 target_link_libraries(tests
    PRIVATE
    GTest::gtest_main
    GTest::gtest
    GTest::gmock
    GTest::gmock_main
    pthread
    traffic_lights_lib
)

target_include_directories(tests
    PRIVATE
    src/
)

# Register tests
include(GoogleTest)
gtest_discover_tests(tests)
