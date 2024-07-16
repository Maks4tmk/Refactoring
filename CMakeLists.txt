cmake_minimum_required(VERSION 3.20)
project(Refactoring) 

add_subdirectory(../Catch2 Catch2-build)

set (SOURCES_TEST_EXE main_test.cpp shape.cpp transform.cpp)
set (HEADERS_TEST_EXE shape.h transform.h)

add_executable(Refactoring Refactoring.cpp shape.cpp transform.cpp shape.h transform.h)
target_link_libraries(Refactoring PRIVATE Catch2::Catch2)