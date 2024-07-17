cmake_minimum_required(VERSION 3.20)
project(Refactoring) 

add_subdirectory(../Catch2 Catch2-build)

add_executable(Refactoring Refactoring.cpp shape.cpp shape.h)
target_link_libraries(Refactoring PRIVATE Catch2::Catch2)