cmake_minimum_required(VERSION 3.14)
project(Index)

set(CMAKE_CXX_STANDARD 14)

add_executable(Index main.cpp lock-free-cuckoo/lock_free_cuckoo.hpp)
find_package(Threads REQUIRED)
target_link_libraries(Index Threads::Threads)