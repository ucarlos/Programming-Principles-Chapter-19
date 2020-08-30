cmake_minimum_required(VERSION 3.15)
project(Chapter19)

set(CMAKE_CXX_STANDARD 17)

#add_executable(Chapter19 main.cpp)
add_executable(Chapter19_Drill Chapter19_Drill.cc)
add_executable(Chapter19_01 Chapter19_01.cc)
add_executable(Chapter19_02 Chapter19_02.cc)
add_executable(Chapter19_03 Chapter19_03.cc)
add_executable(Chapter19_04 Chapter19_04.cc)
add_executable(Chapter19_05 Chapter19_05.cc)
add_executable(Chapter19_06 Chapter19_06.cc)
add_executable(Chapter19_07 Chapter19_07.cc)
add_executable(Chapter19_08 Chapter19_08.cc)
add_executable(Chapter19_11 Chapter19_11.cc)
add_executable(Chapter19_12 Chapter19_12.cc)
# For Boost only
#target_link_libraries(Chapter19_12 boost_system boost_filesystem)
#target_link_libraries(Chapter19_12 stdc++fs)

add_executable(Test_vector_d Test_vector_d.cc vector_d_allocator.cc)
add_executable(Chapter19_13 Chapter19_13.cc)

