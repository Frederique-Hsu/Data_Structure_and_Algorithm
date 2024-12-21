cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(Stack LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD_REQUIRED ON)


set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(BUILD_DIR ${ROOT_DIR}/build)


if(ON)
    include(FetchContent)
    set(FETCHCONTENT_UPDATES_DISCONNECTED   TRUE)
    
    FetchContent_Declare(unity
        GIT_REPOSITORY      https://github.com/Frederick-Hsu/Unity.git
        GIT_TAG             master)

    FetchContent_MakeAvailable(unity)
else()
    find_package(unity REQUIRED CONFIG)
endif()

file(GLOB_RECURSE sources *.c)
file(GLOB_RECURSE headers *.h)
list(FILTER sources EXCLUDE REGEX "${BUILD_DIR}/*")
list(FILTER headers EXCLUDE REGEX "${BUILD_DIR}/*")

add_executable(${PROJECT_NAME}
    ${sources}
    ${headers})
target_link_libraries(${PROJECT_NAME} PRIVATE unity)


#===============================================================================

enable_testing()

add_test(NAME UTest_${PROJECT_NAME}
    COMMAND valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose 
            $<TARGET_FILE:${PROJECT_NAME}> -v)