cmake_minimum_required(VERSION 3.16)
project(lispy_stuff)
# we'll use catch2 as testing library.
# Catch2 version 3 or above needs to be installed on your system.
find_package(Catch2 3 REQUIRED)

# we'll use a recent c++ standard.
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(HEADER_FILES src/include/lex.hpp)
set(SOURCE_FILES src/lex.cpp)
set(CXX_WARNING_FLAGS -Wall -Wextra -Wpedantic -pedantic)

# we're not actually shipping a library yet,
# this is so we don't have to compile twice for main and tests.
add_library(libmash STATIC ${SOURCE_FILES} ${HEADER_FILES})
target_include_directories(libmash PUBLIC src/include/)
target_compile_options(libmash PRIVATE ${CXX_WARNING_FLAGS})

# Main target
add_executable(main src/main.cpp)
target_link_libraries(main libmash)
target_compile_options(main PRIVATE ${CXX_WARNING_FLAGS})

# tests
add_executable(test src/tests/test.cpp)
target_link_libraries(test PRIVATE libmash Catch2::Catch2WithMain)
target_compile_options(test PRIVATE ${CXX_WARNING_FLAGS})

