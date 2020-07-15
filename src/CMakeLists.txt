set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(.)
include_directories(../includes)

####################
#      SOURCES     #
####################

# Set the source files
set(src-pattern "./*.cpp")
if (CMAKE_VERSION VERSION_GREATER 3.12)
    list(INSERT src-pattern 0 CONFIGURE_DEPENDS)
endif()

file(GLOB Calculator-sources
        ${src-pattern}
        )

# Set the source files
add_executable(${PROJECT_NAME}
        ${Calculator-sources}
        )

set( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin )