cmake_minimum_required(VERSION 2.6)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(.)
include_directories(../includes)
include_directories(../src)

# Locate GTest
#add_subdirectory(lib/googletest-master)
#include_directories(lib/googletest-master/googletest/include)
#include_directories(lib/googletest-master/googlemock/include)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

if (APPLE AND CMAKE_CXX_COMPILER_ID STREQUAL Clang)
    add_compile_options("-stdlib=libc++")
endif ()

####################
#      SOURCES     #
####################


# Set the source files
file(GLOB sources "*.cpp")
file(GLOB headers "*.hpp")
set(testing_sources ${sources} ${headers})
list(REMOVE_ITEM testing_sources ${CMAKE_CURRENT_SOURCE_DIR}/Main.cpp)


# Set the source files
add_executable(${PROJECT_NAME}-Tests ${testing_sources} ${headers})
target_link_libraries(${PROJECT_NAME}-Tests ${GTEST_LIBRARIES} pthread)
set( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin )