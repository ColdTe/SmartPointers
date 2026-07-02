CMAKE_MINIMUM_REQUIRED(VERSION 4.0)
PROJECT(myCPP)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(weak_ptr src/weak_ptr.cpp)
add_executable(shared_ptr src/shared_ptr.cpp)
add_executable(unique_ptr src/unique_ptr.cpp)
