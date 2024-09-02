cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(List)


option(ENABLE_BUILD_UNITY_FROM_SOURCE 
    "Enable the Unity test framework, git clone down the repo., and build libunity.a from source"
    ON)

set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(BUILD_DIR ${ROOT_DIR}/build)

if(ENABLE_BUILD_UNITY_FROM_SOURCE)
    set(Unity_SOURCE_DIR ${BUILD_DIR}/_deps/unity-src)
    set(Unity_BINARY_DIR ${BUILD_DIR}/_deps/unity-build)

    include(FetchContent)
    FetchContent_Declare(unity
        GIT_REPOSITORY      https://github.com/Frederick-Hsu/Unity.git
        GIT_TAG             master)
    
    FetchContent_GetProperties(unity)
    if(NOT unit_POPULATED)
        FetchContent_Populate(unity)
        add_subdirectory(${Unity_SOURCE_DIR} ${Unity_BINARY_DIR})
    endif()
else()
    find_package(unity REQUIRED CONFIG)
endif()

list(APPEND COMPILE_OPTIONS
    "-Wall"
    "-Werror")


enable_testing()

add_subdirectory(sequential_list)
add_subdirectory(linked_list)