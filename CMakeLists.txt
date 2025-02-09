cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(Data_Structure_and_Algorithm)


set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(BUILD_DIR ${ROOT_DIR}/build)


#===============================================================================

enable_testing()

add_subdirectory(List)
add_subdirectory(Stack)
add_subdirectory(Trees)
add_subdirectory(Graph)
add_subdirectory(algorithms_challenge)
add_subdirectory(Sorting)