cmake_minimum_required(VERSION 3.20)

set(CURRENT_PROJECT_NAME    test_boost_graph)
project(${CURRENT_PROJECT_NAME})


include(${CMAKE_SOURCE_DIR}/cmake/boost.cmake)

file(GLOB_RECURSE sources "*.c*")
file(GLOB_RECURSE headers "*.h*")
list(FILTER sources EXCLUDE REGEX "build/*")
list(FILTER headers EXCLUDE REGEX "build/*")


add_executable(${CURRENT_PROJECT_NAME}
    ${sources}
    ${headers})
set_target_properties(${CURRENT_PROJECT_NAME} PROPERTIES
    CXX_STANDARD        17
    CXX_EXTENSIONS      NO
    CXX_STANDARD_REQUIRED   YES)
target_compile_options(${CURRENT_PROJECT_NAME} PRIVATE
    "-Wall"
    "-Wextra"
    # "-Werror"
)
target_include_directories(${CURRENT_PROJECT_NAME} PRIVATE
    ${BOOST_INSTALL_DIR}/include)
target_link_directories(${CURRENT_PROJECT_NAME} PRIVATE
    ${BOOST_INSTALL_DIR}/lib)
target_link_libraries(${CURRENT_PROJECT_NAME} PRIVATE
    boost_unit_test_framework)

add_dependencies(${CURRENT_PROJECT_NAME} Boost)

#===============================================================================

enable_testing()

add_test(NAME UTest_${CURRENT_PROJECT_NAME}
    COMMAND $<TARGET_FILE:${CURRENT_PROJECT_NAME}> --log_level=all)
