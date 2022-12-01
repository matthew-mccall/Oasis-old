cmake_minimum_required(VERSION 3.24)
project(OasisDesktop)

find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

set(CMAKE_CXX_STANDARD 17)

add_executable(OasisDesktop main.cpp views/SimpleView.cpp views/SimpleView.hpp components/KeypadButton.cpp components/KeypadButton.hpp)

target_precompile_headers(OasisDesktop PRIVATE pch.hpp)
target_link_libraries(OasisDesktop PRIVATE Oasis::Oasis spdlog::spdlog ${wxWidgets_LIBRARIES})
