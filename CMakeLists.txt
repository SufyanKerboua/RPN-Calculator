cmake_minimum_required(VERSION 3.8)

# Name of the project
project(RPN-Calculator VERSION 1.0.0 LANGUAGES CXX)

# Configure C++ standard
# ======================


set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (APPLE AND CMAKE_CXX_COMPILER_ID STREQUAL Clang)
    add_compile_options("-stdlib=libc++")
endif ()

set(CMAKE_CXX_STANDARD 17)


set(CMAKE_CXX_FLAGS "-Wall -Wextra -g")
#set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

enable_testing()
add_subdirectory(src)
add_subdirectory(tests)