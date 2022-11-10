cmake_minimum_required(VERSION 3.24)
project(OasisDesktop)

set(CMAKE_CXX_STANDARD 17)

add_executable(OasisDesktop main.cpp views/SimpleView.cpp views/SimpleView.hpp components/KeypadButton.cpp components/KeypadButton.hpp)

target_precompile_headers(OasisDesktop PRIVATE pch.hpp)
target_link_libraries(OasisDesktop Oasis::Oasis wx::core wx::base spdlog::spdlog)
