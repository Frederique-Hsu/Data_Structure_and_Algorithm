cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME String)
project(${PROJECT_NAME})

list(APPEND COMPILE_OPTIONS
    "-Wall"
    "-Wextra"
    "-Wpedantic"
    "-Werror")

set(PROJECT_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(PROJECT_BUILD_DIR ${PROJECT_ROOT_DIR}/build)


option(BUILD_UTFRAMEWORK_FROM_SOURCE
    "Git clone the unit test framework from github, and build from source"
    ON)

include(FetchContent)
set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)

if (${BUILD_UTFRAMEWORK_FROM_SOURCE})
    set(Unity_SOURCE_DIR ${PROJECT_BUILD_DIR}/_deps/unity-src)
    set(Unity_BUILD_DIR ${PROJECT_BUILD_DIR}/_deps/unity-build)
    
    FetchContent_Declare(unity
        GIT_REPOSITORY      https://github.com/Frederick-Hsu/Unity.git
        GIT_TAG             master)
    
    FetchContent_GetProperties(unity)
    if (NOT unity_POPULATED)
        FetchContent_Populate(unity)
        add_subdirectory(${Unity_SOURCE_DIR} ${Unity_BUILD_DIR})
    endif()
endif()


enable_testing()

add_subdirectory(Sequential_String)
