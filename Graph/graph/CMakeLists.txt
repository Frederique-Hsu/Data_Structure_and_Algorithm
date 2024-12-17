cmake_minimum_required(VERSION 3.20)

set(CURRENT_PROJECT_NAME    graph)
project(${CURRENT_PROJECT_NAME})


file(GLOB_RECURSE csources "*.c")
file(GLOB_RECURSE cheaders "*.h")

add_library(c${CURRENT_PROJECT_NAME} OBJECT
    ${csources}
    ${cheaders})
set_target_properties(c${CURRENT_PROJECT_NAME} PROPERTIES
    POSITION_INDEPENDENT_CODE   1
    C_STANDARD              11
    C_EXTENSIONS            NO
    C_STANDARD_REQUIRED     YES)
target_compile_options(c${CURRENT_PROJECT_NAME} PUBLIC
    "-Wall"
    "-Wextra"
    "-Werror")

add_library(c${CURRENT_PROJECT_NAME}-static STATIC
    $<TARGET_OBJECTS:c${CURRENT_PROJECT_NAME}>)
set_target_properties(c${CURRENT_PROJECT_NAME}-static PROPERTIES
    OUTPUT_NAME "c${CURRENT_PROJECT_NAME}")

add_library(c${CURRENT_PROJECT_NAME}-shared SHARED
    $<TARGET_OBJECTS:c${CURRENT_PROJECT_NAME}>)
set_target_properties(c${CURRENT_PROJECT_NAME}-shared PROPERTIES
    OUTPUT_NAME "c${CURRENT_PROJECT_NAME}")

#===============================================================================

file(GLOB_RECURSE cppsources "*.cpp")
file(GLOB_RECURSE cppheaders "*.hpp")

add_library(cpp${CURRENT_PROJECT_NAME} OBJECT
    ${cppsources}
    ${cppheaders})
set_target_properties(cpp${CURRENT_PROJECT_NAME} PROPERTIES
    POSITION_INDEPENDENT_CODE   TRUE
    CXX_STANDARD            11
    CXX_EXTENSIONS          NO
    CXX_STANDARD_REQUIRED   YES)
target_compile_options(cpp${CURRENT_PROJECT_NAME} PUBLIC
    "-Wall"
    "-Wextra"
    "-Werror")

add_library(cpp${CURRENT_PROJECT_NAME}-static STATIC
    $<TARGET_OBJECTS:cpp${CURRENT_PROJECT_NAME}>)
set_target_properties(cpp${CURRENT_PROJECT_NAME}-static PROPERTIES
    OUTPUT_NAME "cpp${CURRENT_PROJECT_NAME}")

add_library(cpp${CURRENT_PROJECT_NAME}-shared SHARED
    $<TARGET_OBJECTS:cpp${CURRENT_PROJECT_NAME}>)
set_target_properties(cpp${CURRENT_PROJECT_NAME}-shared PROPERTIES
    OUTPUT_NAME "cpp${CURRENT_PROJECT_NAME}")
