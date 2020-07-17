# Create RPN-Calculator_test
# ==========================
include_directories(../includes)

# Set name of the binary
# =======================
set(PROJECT_NAME ${CMAKE_PROJECT_NAME}_test)

# Get all sources from the project
# ================================
file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.hpp *.cpp)

# Create binary
# =============
add_executable(${PROJECT_NAME} ${TEST_SOURCES})

# Link libraries
# ==============
target_link_libraries(${PROJECT_NAME} PRIVATE yaml-cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)

# Create test
# ===========
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

# Move binary to bin directory
# ============================
set( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin )
