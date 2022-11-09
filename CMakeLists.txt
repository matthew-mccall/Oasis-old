cmake_minimum_required(VERSION 3.24)
project(Oasis)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(CMAKE_CXX_STANDARD 17)

include(CTest)
include(AddOasisTest)

add_subdirectory(lib/GSL)
add_subdirectory(lib/spdlog)

add_library(Oasis include/Oasis/Expression.hpp src/Real.cpp include/Oasis/Real.hpp src/BinaryExpressionNode.cpp include/Oasis/Utility/BinaryExpressionNode.hpp include/Oasis/Utility/Types.hpp src/Blank.cpp include/Oasis/Blank.hpp src/Add.cpp include/Oasis/Add.hpp)
add_library(Oasis::Oasis ALIAS Oasis)

target_include_directories(Oasis PUBLIC include)
target_link_libraries(Oasis PUBLIC Microsoft.GSL::GSL)

add_subdirectory(desktop)

AddOasisTest(AddTest)
