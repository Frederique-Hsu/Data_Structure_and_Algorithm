cmake_minimum_required(VERSION 3.10)

set(CURRENT_PROJECT_NAME Sequential_String)

project(${CURRENT_PROJECT_NAME})


file(GLOB_RECURSE sources "*.c")
file(GLOB_RECURSE headers "*.h")

add_executable(${CURRENT_PROJECT_NAME}
    ${sources}
    ${headers}
    ../main.c)
set_target_properties(${CURRENT_PROJECT_NAME} PROPERTIES
    C_STANDARD              11
    C_EXTENSIONS            NO
    C_STANDARD_REQUIRED     YES)
target_compile_options(${CURRENT_PROJECT_NAME} PUBLIC
    ${COMPILE_OPTIONS})
target_compile_definitions(${CURRENT_PROJECT_NAME} PUBLIC
    "ENABLE_SEQUENTIAL_STRING")
target_link_libraries(${CURRENT_PROJECT_NAME} PUBLIC unity)


enable_testing()
add_test(NAME UTest_${CURRENT_PROJECT_NAME}
    COMMAND valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes
            $<TARGET_FILE:${CURRENT_PROJECT_NAME}> -v)
