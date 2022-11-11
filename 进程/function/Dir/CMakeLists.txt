cmake_minimum_required(VERSION 3.0)

project(Dir)

add_library(Dir_lib STATIC src/is_file.c  src/read_Dir.c)

target_include_directories(Dir_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(Dir main.c)

target_link_libraries(Dir PRIVATE Dir_lib)