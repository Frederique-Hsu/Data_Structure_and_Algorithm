cmake_minimum_required(VERSION 3.20)

if (NOT ${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    include(ExternalProject)

    set(VALGRIND_SRC_DIR        ${CMAKE_BINARY_DIR}/valgrind-src)
    set(VALGRIND_BUILD_DIR      ${CMAKE_BINARY_DIR}/valgrind-build)
    set(VALGRIND_INSTALL_DIR    ${CMAKE_BINARY_DIR}/valgrind-install)


    ExternalProject_Add(Valgrind
        GIT_REPOSITORY          https://sourceware.org/git/valgrind.git
        GIT_TAG                 VALGRIND_3_25_1
        GIT_SHALLOW             TRUE
        GIT_PROGRESS            TRUE
        SOURCE_DIR              ${VALGRIND_SRC_DIR}
        BINARY_DIR              ${VALGRIND_BUILD_DIR}
        DOWNLOAD_DIR            ${VALGRIND_DOWNLOAD_DIR}
        CONFIGURE_COMMAND       ${VALGRIND_SRC_DIR}/autogen.sh && ${VALGRIND_SRC_DIR}/configure --prefix=${VALGRIND_INSTALL_DIR}
        BUILD_COMMAND           make -j 8
        INSTALL_COMMAND         make install
        STEP_TARGETS            install)
endif()
