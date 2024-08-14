# @file CMakeLists.txt
# @license MIT
# @date 24-07-2024
# @author Zofia Kuriata


cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)
project(traffic-lights CXX)


# Add Google Test
enable_testing()
find_package(GTest REQUIRED)

# Create a static library for common sources
add_library(traffic_lights_lib STATIC
    src/density.hpp
    src/density.cpp
    src/file_access.hpp
    src/file_access.cpp
    src/in.hpp
    src/light.hpp
    src/crossing.hpp
    src/crossing.cpp
    src/controler.hpp
    src/controler.cpp
    src/set.hpp
    src/constants.hpp
    src/options.hpp
    src/options.cpp
)

target_include_directories(traffic_lights_lib
    PUBLIC
    src/
)

# Main executable
add_executable(main
    src/main.cpp
)
target_link_libraries(main
    PRIVATE
    traffic_lights_lib
)
target_include_directories(main
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

# Add definition to pass CMAKE_SOURCE_DIR to tests
target_compile_definitions(tests PRIVATE CMAKE_SOURCE_DIR="${CMAKE_SOURCE_DIR}")

# Register tests
include(GoogleTest)
gtest_discover_tests(tests)
