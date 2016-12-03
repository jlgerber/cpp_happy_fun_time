include_directories(src)

file(GLOB cpps src/*.cpp)
file(GLOB hpps src/*.hpp)

add_library(envilib STATIC ${cpps} ${hpps})
add_executable(envi main.cpp)
target_link_libraries(envi envilib)

file(GLOB tests test/*.cpp)
include_directories(test)

add_executable(envitest ${tests} test/catch.hpp)
target_link_libraries(envitest envilib)