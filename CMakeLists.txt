cmake_minimum_required(VERSION 3.6)
project(cpp_happy_fun_time)

set(YAMLCPP_PATH /home/jlgerber/lib/yaml-cpp/master)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# turn off RVO ( return value optimization ). We want all of the constructors called ( copy, assignment )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fno-elide-constructors")

set(SOURCE_FILES session_02/main.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

#add_subdirectory(session_04)

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

add_executable(moveSemantics_Eg1
        topics/rvalue_references_move_semantics/main.cpp)

add_executable(moveSemantics_Eg2
        topics/rvalue_references_move_semantics/moveSemantics_eg2.cpp)

add_executable(secret
        topics/mem/main.cpp
        topics/mem/Secret.cpp
        topics/mem/Secret.hpp)


add_subdirectory(topics/cpp11_random)
add_subdirectory(topics/environ)
#add_executable(enviro topics/environ/main.cpp)

add_executable(functional topics/functional.cpp)

include_directories(session_14/external)
add_executable(streams session_14/streams.cpp)


include_directories(${YAMLCPP_PATH}/include)
add_executable(readWriteYaml session_15/main.cpp)
target_link_libraries(readWriteYaml ${YAMLCPP_PATH}/lib/libyaml-cpp.a)