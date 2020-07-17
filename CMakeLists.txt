# CMakeList RPN-Calculator
# ========================
cmake_minimum_required(VERSION 3.8)

# Name of the project
# ===================
project(RPN-Calculator VERSION 1.0.0 LANGUAGES CXX)

# Configure C++ standard
# ======================
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (APPLE AND CMAKE_CXX_COMPILER_ID STREQUAL Clang)
    add_compile_options("-stdlib=libc++")
endif ()

# Flag de compilation
# ===================
set(CMAKE_CXX_FLAGS "-Wall -Wextra -g")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

# Copy du fichier de configuration
# ================================
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/config.yml
        DESTINATION ${PROJECT_BINARY_DIR}/)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/config.yml
        DESTINATION ${PROJECT_BINARY_DIR}/bin)

enable_testing()
add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(tests)