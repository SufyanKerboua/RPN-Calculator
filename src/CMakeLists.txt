include_directories(../includes)

include_directories(../lib/yaml-cpp/include)

set(PROJECT_NAME ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.hpp *.cpp)

set(SOURCES ${SOURCES})

add_executable(${PROJECT_NAME} ${SOURCES})

## Linked libraries
## ----------------------------------------------------------------------

target_link_libraries(${PROJECT_NAME} PRIVATE yaml-cpp)

add_library(${PROJECT_NAME}_lib STATIC ${SOURCES})

set( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin )