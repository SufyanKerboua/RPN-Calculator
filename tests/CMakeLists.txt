include_directories(../includes)

set(PROJECT_NAME ${CMAKE_PROJECT_NAME}_test)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.hpp *.cpp)

set(SOURCES ${TEST_SOURCES})

add_executable(${PROJECT_NAME} ${TEST_SOURCES})

## Linked libraries
## ----------------------------------------------------------------------

target_link_libraries(${PROJECT_NAME} PRIVATE yaml-cpp)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)

set( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin )
