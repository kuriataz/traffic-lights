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
    src/light_set.hpp
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

# file_access tests
add_executable(file_access_tests
    tests/file_access_test.cpp
)

 target_link_libraries(file_access_tests
    PRIVATE
    GTest::gtest_main
    GTest::gtest
    GTest::gmock
    GTest::gmock_main
    pthread
    traffic_lights_lib
)

target_include_directories(file_access_tests
    PRIVATE
    src/
)

# light_set tests
add_executable(light_set_tests
    tests/light_set_test.cpp
)

 target_link_libraries(light_set_tests
    PRIVATE
    GTest::gtest_main
    GTest::gtest
    GTest::gmock
    GTest::gmock_main
    pthread
    traffic_lights_lib
)

target_include_directories(light_set_tests
    PRIVATE
    src/
)

# density tests
add_executable(density_tests
    tests/density_test.cpp
)

 target_link_libraries(density_tests
    PRIVATE
    GTest::gtest_main
    GTest::gtest
    GTest::gmock
    GTest::gmock_main
    pthread
    traffic_lights_lib
)

target_include_directories(density_tests
    PRIVATE
    src/
)

# crossing tests
add_executable(crossing_tests
    tests/crossing_test.cpp
)

 target_link_libraries(crossing_tests
    PRIVATE
    GTest::gtest_main
    GTest::gtest
    GTest::gmock
    GTest::gmock_main
    pthread
    traffic_lights_lib
)

target_include_directories(crossing_tests
    PRIVATE
    src/
)

# controler tests
add_executable(controler_tests
    tests/controler_test.cpp
)

 target_link_libraries(controler_tests
    PRIVATE
    GTest::gtest_main
    GTest::gtest
    GTest::gmock
    GTest::gmock_main
    pthread
    traffic_lights_lib
)

target_include_directories(controler_tests
    PRIVATE
    src/
)


# Register tests
include(GoogleTest)
gtest_discover_tests(file_access_tests)
gtest_discover_tests(light_set_tests)
gtest_discover_tests(density_tests)
gtest_discover_tests(crossing_tests)
gtest_discover_tests(controler_tests)
