cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(Trees)


option(BUILD_UT_FRAMEWORK_FROM_SOURCE
    "Git clone the unit test framework repositories and build from source"
    ON)

set(PROJECT_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(PROJECT_BUILD_DIR ${PROJECT_ROOT_DIR}/build)


# Git clone the GoogleTest repo. and build
set(GTest_SOURCE_DIR ${PROJECT_BUILD_DIR}/_deps/gtest-src)
set(GTest_BINARY_DIR ${PROJECT_BUILD_DIR}/_deps/gtest-build)

include(FetchContent)
if (${BUILD_UT_FRAMEWORK_FROM_SOURCE})
    FetchContent_Declare(GTest
        GIT_REPOSITORY  https://github.com/google/googletest.git
        GIT_TAG         main)
    
    FetchContent_GetProperties(GTest)
    
    if (NOT GTest_POPULATED)
        FetchContent_Populate(GTest)
        add_subdirectory(${GTest_SOURCE_DIR} ${GTest_BINARY_DIR})
    endif()
else()
    find_package(GTest REQUIRED CONFIG)
endif()


# Git clone the Unity framework repo. and build
set(UNITY_SOURCE_DIR ${PROJECT_BUILD_DIR}/_deps/unity-src)
set(UNITY_BINARY_DIR ${PROJECT_BUILD_DIR}/_deps/unity-build)

if (${BUILD_UT_FRAMEWORK_FROM_SOURCE})
    FetchContent_Declare(unity
        GIT_REPOSITORY  https://github.com/Frederick-Hsu/Unity.git
        GIT_TAG         master)
        
    FetchContent_GetProperties(unity)
    if (NOT unity_POPULATED)
        FetchContent_Populate(unity)
        add_subdirectory(${UNITY_SOURCE_DIR} ${UNITY_BINARY_DIR})
    endif()
endif()

list(APPEND COMMON_COMPILE_OPTIONS
     "-Wall"
     "-Werror"
     "-Wpedantic")

enable_testing()


add_subdirectory(binary_search_tree)
add_subdirectory(Adelson_Velskii_Landis_tree)
add_subdirectory(red_black_tree)