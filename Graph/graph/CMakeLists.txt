cmake_minimum_required(VERSION 3.20)

set(CURRENT_PROJECT_NAME    graph)
project(${CURRENT_PROJECT_NAME})


add_library(graph_adjacent_matrix SHARED
    graph_adjacent_matrix.h
    graph_adjacent_matrix.c)
set_target_properties(graph_adjacent_matrix PROPERTIES
    POSITION_INDEPENDENT_CODE   1
    C_STANDARD              11
    C_EXTENSIONS            NO
    C_STANDARD_REQUIRED     YES)
target_compile_options(graph_adjacent_matrix PUBLIC
    "-Wall"
    "-Wextra"
    "-Werror")

#===============================================================================

add_library(graph_adjacent_list SHARED
    graph_adjacent_list.h
    graph_adjacent_list.c)
set_target_properties(graph_adjacent_list PROPERTIES
    POSITION_INDEPENDENT_CODE   1
    C_STANDARD              11
    C_EXTENSIONS            NO
    C_STANDARD_REQUIRED     YES)
target_compile_options(graph_adjacent_list PUBLIC
    "-Wall"
    "-Wextra"
    "-Werror"
    "-Wno-unused-function")

#===============================================================================

file(GLOB_RECURSE cppsources "*.cpp")
file(GLOB_RECURSE cppheaders "*.hpp")

add_library(cpp${CURRENT_PROJECT_NAME} SHARED
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
