cmake_minimum_required(VERSION 3.10)


set(CMAKE_CXX_STANDARD 17)
project(tomu)

add_compile_options(-g -fsanitize=address)
add_link_options(-g -fsanitize=address)

file(GLOB SRC ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(tomu main.cpp ${SRC})
target_include_directories(tomu PUBLIC ${PROJECT_SOURCE_DIR}/src)
target_include_directories(tomu PUBLIC ${PROJECT_SOURCE_DIR}/raylib/src/include)
target_link_libraries(tomu PUBLIC ${PROJECT_SOURCE_DIR}/raylib/src/libraylib.so)
target_precompile_headers(tomu PUBLIC ${PROJECT_SOURCE_DIR}/src/stdafx.h)


