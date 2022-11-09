cmake_minimum_required(VERSION 3.24)
project(OasisDesktop)

set(CMAKE_CXX_STANDARD 17)

add_executable(OasisDesktop main.cpp)

target_link_libraries(OasisDesktop Oasis::Oasis)
