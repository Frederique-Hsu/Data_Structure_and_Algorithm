cmake_minimum_required(VERSION 3.20)

project(algorithms_challenge)

set(CURRENT_CPPPROJECT_NAME cpp_algorithms_challenge)
set(CURRENT_CPROJECT_NAME c_algorithms_challenge)

#===============================================================================

set(CURRENT_PROJECT_ROOT_DIR    ${CMAKE_CURRENT_SOURCE_DIR})
set(CURRENT_PROJECT_BUILD_DIR   ${CMAKE_CURRENT_BINARY_DIR})

#===============================================================================

file(GLOB_RECURSE cppsources    *.cpp)
file(GLOB_RECURSE cppheaders    *.hpp)
file(GLOB_RECURSE csources      *.c)
file(GLOB_RECURSE cheaders      *.h)
list(FILTER cppsources EXCLUDE REGEX "${CURRENT_PROJECT_BUILD_DIR}/*")
list(FILTER cppheaders EXCLUDE REGEX "${CURRENT_PROJECT_BUILD_DIR}/*")
list(FILTER csources EXCLUDE REGEX "${CURRENT_PROJECT_BUILD_DIR}/*")
list(FILTER cheaders EXCLUDE REGEX "${CURRENT_PROJECT_BUILD_DIR}/*")

#===============================================================================

include(FetchContent)
set(FETCHCONTENT_UPDATES_DISCONNECTED   TRUE)

option(BUILD_UT_FROM_SOURCE
       "Git clone the repository of Unit Test framework from GitHub, and build them from source"
       ON)

if (${BUILD_UT_FROM_SOURCE})
    FetchContent_Declare(GTest
        GIT_REPOSITORY  https://github.com/google/googletest.git
        GIT_TAG         main)
    FetchContent_MakeAvailable(GTest)

    FetchContent_Declare(Unity
        GIT_REPOSITORY  https://github.com/Frederick-Hsu/Unity.git
        GIT_TAG         master)
    FetchContent_MakeAvailable(Unity)
elseif()
    find_package(GTest REQUIRED CONFIG)
    find_package(Unity REQUIRED CONFIG)
endif()

#===============================================================================

add_executable(${CURRENT_CPPPROJECT_NAME}
    ${cppsources}
    ${cppheaders})
set_target_properties(${CURRENT_CPPPROJECT_NAME} PROPERTIES
    CXX_STANDARD            17
    CXX_EXTENSIONS          NO
    CXX_STANDARD_REQUIRED   YES)
target_link_libraries(${CURRENT_CPPPROJECT_NAME} PUBLIC gtest)

#===============================================================================

add_executable(${CURRENT_CPROJECT_NAME}
    ${csources}
    ${cheaders})
set_target_properties(${CURRENT_CPROJECT_NAME} PROPERTIES
    C_STANDARD              17
    C_EXTENSIONS            NO
    C_STANDARD_REQUIRED     YES)
target_link_libraries(${CURRENT_CPROJECT_NAME} PUBLIC unity pthread)

#===============================================================================

enable_testing()

add_test(NAME UTest_${CURRENT_CPPPROJECT_NAME}
    COMMAND $<TARGET_FILE:${CURRENT_CPPPROJECT_NAME}>)
if (NOT ${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    include(GoogleTest)
    gtest_discover_tests(${CURRENT_CPPPROJECT_NAME})
endif()

#===============================================================================

add_test(NAME UTest_${CURRENT_CPROJECT_NAME}
    COMMAND $<TARGET_FILE:${CURRENT_CPROJECT_NAME}> -v)

#===============================================================================

if (NOT ${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    find_package(PythonInterp REQUIRED)
    add_test(NAME PyUTest_algorithms_challenge
        COMMAND ${PYTHON_EXECUTABLE} ${CURRENT_PROJECT_ROOT_DIR}/run_tests.py)
endif()