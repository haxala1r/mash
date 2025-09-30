cmake_minimum_required(VERSION 3.16)
project(lispy_stuff)

set(HEADER_FILES src/include/lex.hpp)
set(SOURCE_FILES src/main.cpp)


add_executable(main ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(main PRIVATE src/include/)