cmake_minimum_required(VERSION 3.16)
project(lispy_stuff)

# we'll use catch2 as testing library.
include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.8.1
)
FetchContent_MakeAvailable(Catch2)
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(Catch)

set(HEADER_FILES src/include/lex.hpp)
set(SOURCE_FILES src/lex.cpp)

# we're not actually shipping a library yet,
# this is so we don't have to compile twice for main and tests.
add_library(libmash STATIC ${SOURCE_FILES} ${HEADER_FILES})
target_include_directories(libmash PUBLIC src/include/)

# Main target
add_executable(main src/main.cpp)
target_link_libraries(main libmash)

# tests
add_executable(test src/tests/test.cpp)
target_link_libraries(test PRIVATE libmash Catch2::Catch2WithMain)

