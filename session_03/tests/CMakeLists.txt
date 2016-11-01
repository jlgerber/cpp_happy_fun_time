include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# add files
file(GLOB tests_cpp
        *.cpp
        )

# add project name
add_executable(${PROJECT_NAME} ${tests_cpp})

target_link_libraries(${PROJECT_NAME} gtest gtest_main)
target_link_libraries(${PROJECT_NAME} vector)