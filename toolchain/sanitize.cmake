# We're assuming clang or gcc as the compiler.
# feel free to change if you're using msvc or something else
set(SANITIZERS_FLAGS "-fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fno-omit-frame-pointer")
set(CMAKE_CXX_FLAGS_INIT "${SANITIZERS_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS_INIT "${SANITIZERS_FLAGS}")