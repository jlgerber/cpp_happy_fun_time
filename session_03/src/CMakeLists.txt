project(vector)

file(GLOB  cpps *.cpp
        )

file(GLOB hpps *.hpp
        )

add_library(vector SHARED ${cpps} ${hpps})