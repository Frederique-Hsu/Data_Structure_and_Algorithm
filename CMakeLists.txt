cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(Data_Structure_and_Algorithm)


set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(BUILD_DIR ${ROOT_DIR}/build)


# Git clone the Boost library repository from GitHub
set(Boost_SOURCE_DIR ${BUILD_DIR}/_deps/boost-src)
set(Boost_BINARY_DIR ${BUILD_DIR}/_deps/boost-build)

include(FetchContent)
FetchContent_Declare(Boost
    GIT_REPOSITORY      https://github.com/boostorg/boost.git
    GIT_TAG             master)

FetchContent_GetProperties(Boost)
if (NOT Boost_POPULATED)
    FetchContent_Populate(Boost)
    add_subdirectory(${Boost_SOURCE_DIR} ${Boost_BINARY_DIR})
endif()


#===============================================================================

enable_testing()

add_subdirectory(List)
add_subdirectory(Stack)
add_subdirectory(Trees)
# add_subdirectory(unit_test_framework/Unity)
# add_subdirectory(unit_test_framework/munit)