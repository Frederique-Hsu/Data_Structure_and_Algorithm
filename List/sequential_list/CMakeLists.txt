cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

set(CURRENT_PROJECT_NAME sequential_list)

project(${CURRENT_PROJECT_NAME} LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD_REQUIRED ON)

file(GLOB_RECURSE sources *.c)
file(GLOB_RECURSE headers *.h)

add_executable(${CURRENT_PROJECT_NAME}
    ../main.c
    ${sources}
    ${headers})
target_compile_options(${CURRENT_PROJECT_NAME} PUBLIC ${COMPILE_OPTIONS})
target_compile_definitions(${CURRENT_PROJECT_NAME} PRIVATE "ENABLE_SEQUENTIAL_LIST")
target_link_libraries(${CURRENT_PROJECT_NAME} PRIVATE unity)


add_test(NAME UTest_${CURRENT_PROJECT_NAME}
    COMMAND $<TARGET_FILE:${CURRENT_PROJECT_NAME}> -v)