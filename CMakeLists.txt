cmake_minimum_required(VERSION 3.0)
project(client)

set(CMAKE_CXX_STANDARD 17)

add_executable(client main.cpp ClientHelper.cpp Settings.cpp)
target_link_libraries(client network)