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


add_executable(c_${CURRENT_PROJECT_NAME}
    ${csources}
    ${cheaders})
set_target_properties(c_${CURRENT_PROJECT_NAME} PROPERTIES
    C_STANDARD          11
    C_EXTENSIONS        NO
    C_STANDARD_REQUIRED YES)
target_compile_options(c_${CURRENT_PROJECT_NAME} PUBLIC
    "-Wall"
    "-Wextra"
    "-Werror")
target_link_libraries(c_${CURRENT_PROJECT_NAME} PUBLIC unity cgraph)


add_executable(cpp_${CURRENT_PROJECT_NAME}
    ${cppsources}
    ${cppheaders})
set_target_properties(cpp_${CURRENT_PROJECT_NAME} PROPERTIES
    CXX_STANDARD            11
    CXX_EXTENSIONS          NO
    CXX_STANDARD_REQUIRED   YES)
target_compile_options(cpp_${CURRENT_PROJECT_NAME} PUBLIC
    "-Wall"
    "-Wextra"
    "-Werror")
target_link_libraries(cpp_${CURRENT_PROJECT_NAME} PUBLIC Catch2 cppgraph)

enable_testing()
add_test(NAME c_${CURRENT_PROJECT_NAME}
    COMMAND $<TARGET_FILE:c_${CURRENT_PROJECT_NAME}> -v)

add_test(NAME cpp_${CURRENT_PROJECT_NAME}
    COMMAND $<TARGET_FILE:cpp_${CURRENT_PROJECT_NAME}>)