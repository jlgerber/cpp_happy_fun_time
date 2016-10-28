cmake_minimum_required(VERSION 3.6)
project(cpp_happy_fun_time)

# turn off RVO ( return value optimization ). We want all of the constructors called ( copy, assignment )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fno-elide-constructors")

set(SOURCE_FILES session_02/main.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
add_executable(session05 session_05/main.cpp session_05/Person.cpp session_05/Person.hpp)