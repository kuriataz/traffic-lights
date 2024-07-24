cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_BUILD_TYPE Debug)
project(traffic-lights CXX)

add_executable(input
    "input/density.cpp"
    "input/test_input.cpp"
)
target_compile_options(input
    PRIVATE
    # -ftime-trace
)
target_include_directories(input
    PRIVATE
    "input/"
)
