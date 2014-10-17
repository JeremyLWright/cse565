project(hw1)

include(ExternalProject)
ExternalProject_Add(
    GTest 
    URL http://googletest.googlecode.com/files/gtest-1.7.0.zip
    INSTALL_COMMAND ""
    )

ExternalProject_Get_Property(GTest source_dir)
include_directories(${source_dir}/include)


ExternalProject_Get_Property(GTest binary_dir)
link_directories(${binary_dir})


set(CMAKE_CXX_FLAGS "-O3 -std=gnu++11")
add_executable(hw1 main.cpp)
add_executable(test test.cpp)
add_dependencies(test GTest)
target_link_libraries(test gtest gtest_main pthread rt)
