cmake_minimum_required(VERSION  3.20)

set(CURRENT_PROJECT_NAME    unit_tests)
project(${CURRENT_PROJECT_NAME})


file(GLOB_RECURSE csources "*.c")
file(GLOB_RECURSE cheaders "*.h")
file(GLOB_RECURSE cppsources "*.cpp")
file(GLOB_RECURSE cppheaders "*.hpp")


include(FetchContent)
set(FETCHCONTENT_UPDATES_DISCONNECTED   TRUE)

option(BUILD_UT_FROM_SRC
       "Git clone the repository of unit test framework from GitHub, and built it from source"
       ON)
if(${BUILD_UT_FROM_SRC})
    FetchContent_Declare(Catch2
        GIT_REPOSITORY      https://github.com/catchorg/Catch2.git
        GIT_TAG             devel)
    FetchContent_MakeAvailable(Catch2)

    FetchContent_Declare(Unity
        GIT_REPOSITORY      https://github.com/Frederique-Hsu/Unity.git
        GIT_TAG             master)
    FetchContent_MakeAvailable(Unity)
endif()

#===============================================================================

add_executable(utest_graph_adjacent_matrix
    main.c
    test_graph_adjacent_matrix.c)
set_target_properties(utest_graph_adjacent_matrix PROPERTIES
    C_STANDARD          11
    C_EXTENSIONS        NO
    C_STANDARD_REQUIRED YES)
target_compile_options(utest_graph_adjacent_matrix PUBLIC
    "-Wall"
    "-Wextra"
    "-Werror")
target_compile_definitions(utest_graph_adjacent_matrix PUBLIC "GRAPH_ADJACENT_MATRIX")
target_link_libraries(utest_graph_adjacent_matrix PUBLIC
    unity
    graph_adjacent_matrix)

#===============================================================================

add_executable(utest_graph_adjacent_list
    main.c
    test_graph_adjacent_list.c)
set_target_properties(utest_graph_adjacent_list PROPERTIES
    C_STANDARD          11
    C_EXTENSIONS        NO
    C_STANDARD_REQUIRED YES)
target_compile_options(utest_graph_adjacent_list PUBLIC
    "-Wall"
    "-Wextra"
    "-Werror"
    "-Wno-unused-function")
target_compile_definitions(utest_graph_adjacent_list PUBLIC "GRAPH_ADJACENT_LIST")
target_link_libraries(utest_graph_adjacent_list PUBLIC
    unity
    graph_adjacent_list)

#===============================================================================

add_executable(utest_cpp_graph
    ${cppsources}
    ${cppheaders})
set_target_properties(utest_cpp_graph PROPERTIES
    CXX_STANDARD            11
    CXX_EXTENSIONS          NO
    CXX_STANDARD_REQUIRED   YES)
target_compile_options(utest_cpp_graph PUBLIC
    "-Wall"
    "-Wextra"
    "-Werror")
target_link_libraries(utest_cpp_graph PUBLIC
    Catch2
    cppgraph)

#===============================================================================

enable_testing()

add_test(NAME utest_graph_adjacent_matrix
    COMMAND valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes 
            $<TARGET_FILE:utest_graph_adjacent_matrix> -v)

add_test(NAME utest_graph_adjacent_list
    COMMAND valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes 
            $<TARGET_FILE:utest_graph_adjacent_list> -v)

add_test(NAME utest_cpp_graph
    COMMAND valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes 
            $<TARGET_FILE:utest_cpp_graph> -s)
