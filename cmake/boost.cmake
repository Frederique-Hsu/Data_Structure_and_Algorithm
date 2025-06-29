cmake_minimum_required(VERSION 3.20)

include(ExternalProject)


set(BOOST_SRC_DIR       ${CMAKE_BINARY_DIR}/boost-src)
set(BOOST_BUILD_DIR     ${CMAKE_BINARY_DIR}/boost-build)
set(BOOST_INSTALL_DIR   ${CMAKE_BINARY_DIR}/boost-install)
set(BOOST_DOWNLOAD_DIR  ${CMAKE_BINARY_DIR}/boost-download)

ExternalProject_Add(Boost
    GIT_REPOSITORY      https://github.com/boostorg/boost.git
    GIT_TAG             master
    GIT_SHALLOW         TRUE
    GIT_PROGRESS        TRUE
    SOURCE_DIR          ${BOOST_SRC_DIR}
    BINARY_DIR          ${BOOST_BUILD_DIR}
    DOWNLOAD_DIR        ${BOOST_DOWNLOAD_DIR}
    UPDATE_DISCONNECTED TRUE
    CMAKE_ARGS
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DBUILD_SHARED_LIBS=ON
        -DCMAKE_INSTALL_PREFIX=${BOOST_INSTALL_DIR}
    BUILD_ALWAYS        FALSE
    STEP_TARGETS        install)
