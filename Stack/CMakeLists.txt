cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(Stack LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD_REQUIRED ON)


set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(BUILD_DIR ${ROOT_DIR}/build)

set(Unity_SOURCE_DIR ${BUILD_DIR}/_deps/unity-src)
set(Unity_BINARY_DIR ${BUILD_DIR}/_deps/unity-build)

if(ON)
    include(FetchContent)
    FetchContent_Declare(unity
        GIT_REPOSITORY      https://github.com/Frederick-Hsu/Unity.git
        GIT_TAG             master)

    FetchContent_GetProperties(unity)
    if(NOT unity_POPULATED)
        FetchContent_Populate(unity)
        add_subdirectory(${Unity_SOURCE_DIR} ${Unity_BINARY_DIR})
    endif()
else()
    find_package(unity REQUIRED CONFIG)
endif()

file(GLOB_RECURSE sources *.c)
file(GLOB_RECURSE headers *.h)

add_executable(${PROJECT_NAME}
    main.c)
target_link_libraries(${PROJECT_NAME} PRIVATE unity)


#===============================================================================

enable_testing()

add_test(NAME UTest_${PROJECT_NAME}
    COMMAND $<TARGET_FILE:${PROJECT_NAME}> -v)