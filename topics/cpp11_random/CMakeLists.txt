include_directories(src)

file(GLOB cpps src/*.cpp)
file(GLOB hpps src/*.hpp)

add_executable(random main.cpp ${cpps} ${hpps})