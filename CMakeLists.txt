cmake_minimum_required(VERSION 3.6)
project(cpp_happy_fun_time)

# turn off RVO ( return value optimization ). We want all of the constructors called ( copy, assignment )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fno-elide-constructors")

set(SOURCE_FILES session_02/main.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

add_subdirectory(session_04)

add_executable(session05_secret
        session_05/main.cpp
        session_05/templatesEg.hpp)

add_executable(session06 session_06/main.cpp
        session_06/Person.cpp
        session_06/Person.hpp
       )

add_executable( personBetter
                session_06/mainBetter.cpp
                session_06/PersonBetter.cpp
                session_06/PersonBetter.hpp
                )

add_executable( sharedPtrMain
                session_06/sharedPtrMain.cpp
                session_06/SharedPtr.hpp)

add_executable(PersonSharedPtr
                session_06/personSharedPtrMain.cpp
                session_06/PersonSharedPtr.hpp )
