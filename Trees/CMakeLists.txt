cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(Trees)


option(BUILD_UT_FRAMEWORK_FROM_SOURCE
    "Git clone the unit test framework repositories and build from source"
    ON)

set(PROJECT_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(PROJECT_BUILD_DIR ${PROJECT_ROOT_DIR}/build)

include(FetchContent)
set(FETCHCONTENT_UPDATES_DISCONNECTED   TRUE)

if (${BUILD_UT_FRAMEWORK_FROM_SOURCE})
    FetchContent_Declare(GTest
        GIT_REPOSITORY  https://github.com/google/googletest.git
        GIT_TAG         main)
    FetchContent_MakeAvailable(GTest)
else()
    find_package(GTest REQUIRED CONFIG)
endif()


if (${BUILD_UT_FRAMEWORK_FROM_SOURCE})
    FetchContent_Declare(unity
        GIT_REPOSITORY  https://github.com/Frederick-Hsu/Unity.git
        GIT_TAG         master)
    FetchContent_MakeAvailable(unity)
endif()

list(APPEND COMMON_COMPILE_OPTIONS
     "-Wall"
     "-Werror"
     "-Wpedantic")

enable_testing()


add_subdirectory(binary_search_tree)
add_subdirectory(Adelson_Velskii_Landis_tree)
add_subdirectory(red_black_tree)