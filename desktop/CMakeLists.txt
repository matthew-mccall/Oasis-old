cmake_minimum_required(VERSION 3.24)
project(OasisDesktop)

find_package(wxWidgets REQUIRED COMPONENTS core base webview)
include(${wxWidgets_USE_FILE})

set(CMAKE_CXX_STANDARD 17)

add_executable(OasisDesktop main.cpp views/Arithmetic/Arithmetic.cpp views/Arithmetic/Arithmetic.hpp components/KeypadButton/KeypadButton.cpp components/KeypadButton/KeypadButton.hpp views/BaseConverter/BaseConverter.cpp views/BaseConverter/BaseConverter.hpp views/TruthTable/TruthTable.cpp views/TruthTable/TruthTable.hpp components/Menubar/Menubar.cpp components/Menubar/Menubar.hpp)

target_precompile_headers(OasisDesktop PRIVATE pch.hpp)
target_link_libraries(OasisDesktop PRIVATE Oasis::Oasis spdlog::spdlog ${wxWidgets_LIBRARIES})
target_include_directories(OasisDesktop PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
