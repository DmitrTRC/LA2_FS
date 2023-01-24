cmake_minimum_required(VERSION 3.24)
project(LA2_FS)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include_directories(include)


add_executable(LA2_FS App/main.cpp
               src/Shell.cpp
               )
