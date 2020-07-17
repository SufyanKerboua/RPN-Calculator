# Create RPN-Calculator
# =====================
include_directories(../includes)

include_directories(../lib/yaml-cpp/include)

# Set name of the binary
# ======================
set(PROJECT_NAME ${CMAKE_PROJECT_NAME})

# Get all sources from the project
# ================================
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.hpp *.cpp)

#set(SOURCES ${SOURCES})

# Generate binary
# ===============
add_executable(${PROJECT_NAME} ${SOURCES})

# Link libraries
# ==============
target_link_libraries(${PROJECT_NAME} PRIVATE yaml-cpp)

# Create libraries
# ================
add_library(${PROJECT_NAME}_lib STATIC ${SOURCES})

# Move binary to bin directory
# ============================
set( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin )