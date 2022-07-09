cmake_minimum_required(VERSION 3.22)
project(nitros_basic_thing)

set(CMAKE_CXX_STANDARD 17)

include_directories(thirdparty lib tests)

add_subdirectory(tests)

