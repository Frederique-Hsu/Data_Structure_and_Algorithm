cmake_minimum_required(VERSION 3.10)

set(CURRENT_PROJECT_NAME Sorting)
project(${CURRENT_PROJECT_NAME})


set(CURRENT_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(CURRENT_BUILD_DIR ${CURRENT_ROOT_DIR}/build)

file(GLOB_RECURSE csources 
    *.c
    external_libs/librandom/src/*.c)
file(GLOB_RECURSE cheaders 
    *.h
    external_libs/librandom/src/*.h)
list(FILTER csources EXCLUDE REGEX "${CURRENT_BUILD_DIR}/*")
list(FILTER csources EXCLUDE REGEX "${CURRENT_ROOT_DIR}/external_libs/librandom/tests/*")
list(FILTER cheaders EXCLUDE REGEX "${CURRENT_BUILD_DIR}/*")
list(FILTER cheaders EXCLUDE REGEX "${CURRENT_ROOT_DIR}/external_libs/librandom/tests/*")

file(GLOB_RECURSE cppsources *.cpp)
file(GLOB_RECURSE cppheaders *.hpp)
list(FILTER cppsources EXCLUDE REGEX "${CURRENT_BUILD_DIR}/*")
list(FILTER cppheaders EXCLUDE REGEX "${CURRENT_BUILD_DIR}/*")


option(BUILD_UTFRAMEWORK_FROM_SOURCE
    "Git clone the unit test framework repositories from GitHub, and build from source"
    ON)

include(FetchContent)
set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)

if (${BUILD_UTFRAMEWORK_FROM_SOURCE})
    set(GTest_SOURCE_DIR ${CURRENT_BUILD_DIR}/_deps/gtest-src)
    set(GTest_BUILD_DIR  ${CURRENT_BUILD_DIR}/_deps/gtest-build)

    FetchContent_Declare(GTest
        GIT_REPOSITORY          https://github.com/google/googletest.git
        GIT_TAG                 main)
    FetchContent_GetProperties(GTest)
    if (NOT GTest_POPULATED)
        FetchContent_Populate(GTest)
        add_subdirectory(${GTest_SOURCE_DIR} ${GTest_BUILD_DIR})
    endif()
else()
    find_package(GTest REQUIRED CONFIG)
endif()


if (${BUILD_UTFRAMEWORK_FROM_SOURCE})
    set(Unity_SOURCE_DIR ${CURRENT_BUILD_DIR}/_deps/unity-src)
    set(Unity_BUILD_DIR  ${CURRENT_BUILD_DIR}/_deps/unity-build)

    FetchContent_Declare(Unity
        GIT_REPOSITORY          https://github.com/Frederick-Hsu/Unity.git
        GIT_TAG                 master)
    FetchContent_GetProperties(Unity)
    if (NOT Unity_POPULATED)
        FetchContent_Populate(Unity)
        add_subdirectory(${Unity_SOURCE_DIR} ${Unity_BUILD_DIR})
    endif()
else()
    find_package(Unity REQUIRED CONFIG)
endif()

add_executable(C_${CURRENT_PROJECT_NAME}
    ${csources}
    ${cheaders})
set_target_properties(C_${CURRENT_PROJECT_NAME} PROPERTIES
    C_STANDARD              17
    C_EXTENSIONS            NO
    C_STANDARD_REQUIRED     YES)
target_link_libraries(C_${CURRENT_PROJECT_NAME} PUBLIC unity m)


add_executable(CPP_${CURRENT_PROJECT_NAME}
    ${cppsources}
    ${cppheaders})
set_target_properties(CPP_${CURRENT_PROJECT_NAME} PROPERTIES
    CXX_STANDARD            17
    CXX_EXTENSIONS          NO
    CXX_STANDARD_REQUIRED   YES)
target_link_libraries(CPP_${CURRENT_PROJECT_NAME} PUBLIC gtest)


enable_testing()
add_test(NAME UTEST_CPP_SORTING
    COMMAND $<TARGET_FILE:CPP_${CURRENT_PROJECT_NAME}>)

add_test(NAME UTEST_C_SORTING
    COMMAND $<TARGET_FILE:C_${CURRENT_PROJECT_NAME}> -v)