cmake_minimum_required(VERSION 3.24)
project(Oasis)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(CMAKE_CXX_STANDARD 17)

include(CTest)
include(AddOasisTest)

add_subdirectory(lib/GSL)
add_subdirectory(lib/spdlog)
add_subdirectory(lib/wxWidgets)

add_library(Oasis include/Oasis/Expression.hpp src/Real.cpp include/Oasis/Real.hpp src/BinaryExpressionNode.cpp include/Oasis/Utility/BinaryExpressionNode.hpp include/Oasis/Utility/Types.hpp src/Blank.cpp include/Oasis/Blank.hpp src/Add.cpp include/Oasis/Add.hpp include/Oasis/Subtract.hpp src/Subtract.cpp src/Multiply.cpp include/Oasis/Multiply.hpp src/Divide.cpp include/Oasis/Divide.hpp src/Exponent.cpp include/Oasis/Exponent.hpp src/Variable.cpp include/Oasis/Variable.hpp src/Substitute.cpp include/Oasis/Substitute.hpp)
add_library(Oasis::Oasis ALIAS Oasis)

target_include_directories(Oasis PUBLIC include)
target_link_libraries(Oasis PUBLIC Microsoft.GSL::GSL)

add_subdirectory(desktop EXCLUDE_FROM_ALL)

AddOasisTest(AddTest)
AddOasisTest(SubtractTest)
AddOasisTest(MultiplyTest)
AddOasisTest(DivideTest)
AddOasisTest(ExponentTest)
AddOasisTest(VariableTest)
AddOasisTest(CopyTest)