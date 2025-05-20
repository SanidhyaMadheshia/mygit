cmake_minimum_required(VERSION 3.14)
project(mygit)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(mygit
    src/main.cpp
    src/init.cpp
)

target_include_directories(mygit PRIVATE src)
