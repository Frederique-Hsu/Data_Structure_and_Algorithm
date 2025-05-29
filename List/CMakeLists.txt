cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(List)


option(ENABLE_BUILD_UNITY_FROM_SOURCE 
    "Enable the Unity test framework, git clone down the repo., and build libunity.a from source"
    ON)

if(ENABLE_BUILD_UNITY_FROM_SOURCE)
    include(FetchContent)
    set(FETCHCONTENT_UPDATES_DISCONNECTED   TRUE)
    
    FetchContent_Declare(unity
        GIT_REPOSITORY      https://github.com/Frederick-Hsu/Unity.git
        GIT_TAG             master)
    FetchContent_MakeAvailable(unity)
else()
    find_package(unity REQUIRED CONFIG)
endif()

list(APPEND COMPILE_OPTIONS
    "-Wall"
    "-Werror")


enable_testing()

add_subdirectory(sequential_list)
add_subdirectory(linked_list)