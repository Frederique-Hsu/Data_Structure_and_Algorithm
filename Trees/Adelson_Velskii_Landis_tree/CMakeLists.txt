cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

set(CURRENT_PROJECT_NAME Adelson_Velskii_Landis_tree)
project(${CURRENT_PROJECT_NAME})

set(CURRENT_PROJECT_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB_RECURSE cpp_sources "*.cpp")
file(GLOB_RECURSE cpp_headers "*.hpp")
file(GLOB_RECURSE c_sources "*.c")
file(GLOB_RECURSE c_headers "*.h")

#===============================================================================

set(CURRENT_C_PROJECT_NAME ${CURRENT_PROJECT_NAME}_c)
add_executable(${CURRENT_C_PROJECT_NAME} "")
target_sources(${CURRENT_C_PROJECT_NAME} PRIVATE
    ../main.c
    ${c_sources}
    ${c_headers})
target_compile_options(${CURRENT_C_PROJECT_NAME} PUBLIC
    ${COMMON_COMPILE_OPTIONS})
set_target_properties(${CURRENT_C_PROJECT_NAME} PROPERTIES
    C_STANDARD              11
    C_STANDARD_EXTENSIONS   OFF
    C_STANDARD_REQUIRED     ON)
target_link_libraries(${CURRENT_C_PROJECT_NAME} PRIVATE unity)

#===============================================================================

set(CURRENT_CPP_PROJECT_NAME ${CURRENT_PROJECT_NAME}_cpp)
add_executable(${CURRENT_CPP_PROJECT_NAME} "")
target_sources(${CURRENT_CPP_PROJECT_NAME} PRIVATE
    ../main.cpp
    ${cpp_sources}
    ${cpp_headers})
target_compile_options(${CURRENT_CPP_PROJECT_NAME} PUBLIC
    ${COMMON_COMPILE_OPTIONS})
set_target_properties(${CURRENT_CPP_PROJECT_NAME} PROPERTIES
    CXX_STANDARD                14
    CXX_STANDARD_EXTENSIONS     OFF
    CXX_STANDARD_REQUIRED       ON)
target_link_libraries(${CURRENT_CPP_PROJECT_NAME} PRIVATE gtest)

#===============================================================================

add_test(NAME UTest_${CURRENT_C_PROJECT_NAME}
    COMMAND valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose 
            $<TARGET_FILE:${CURRENT_C_PROJECT_NAME}> -v)

add_test(NAME UTest_${CURRENT_CPP_PROJECT_NAME}
    COMMAND valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose 
            $<TARGET_FILE:${CURRENT_CPP_PROJECT_NAME}>)