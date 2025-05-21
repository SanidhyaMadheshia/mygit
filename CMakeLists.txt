cmake_minimum_required(VERSION 3.14)
project(mygit)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define source files
add_executable(mygit
    src/main.cpp
    src/definitions/hash-file.cpp
    src/definitions/init.cpp
)

# Include the headers directory
target_include_directories(mygit PRIVATE src/headers)

# Link OpenSSL
find_package(OpenSSL REQUIRED)
target_link_libraries(mygit OpenSSL::Crypto)
