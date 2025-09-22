cmake_minimum_required(VERSION 3.20)

include(ExternalProject)

set(FreeImage_SRC_DIR       ${CMAKE_BINARY_DIR}/freeimage-src)
set(FreeImage_BUILD_DIR     ${CMAKE_BINARY_DIR}/freeimage-build)
set(FreeImage_INSTALL_DIR   ${CMAKE_BINARY_DIR}/freeimage-install)


ExternalProject_Add(FreeImage
    GIT_REPOSITORY      https://github.com/danoli3/FreeImage.git
    GIT_TAG             3.19.10
    GIT_SHALLOW         TRUE
    GIT_PROGRESS        TRUE
    SOURCE_DIR          ${FreeImage_SRC_DIR}
    BINARY_DIR          ${FreeImage_BUILD_DIR}
    UPDATE_DISCONNECTED TRUE
    CMAKE_ARGS
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -DBUILD_SHARED_LIBS=ON
        -DCMAKE_INSTALL_PREFIX=${FreeImage_INSTALL_DIR}
    BUILD_ALWAYS        TRUE
    STEP_TARGETS        install
)
