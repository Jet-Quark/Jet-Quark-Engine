cmake_minimum_required(VERSION 3.10)

project(JetQuark)


add_library(JetQuark SHARED src/Application.cpp)

target_include_directories(JetQuark

   INTERFACE
   "${CMAKE_CURRENT_SOURCE_DIR}/include"
   "${CMAKE_CURRENT_SOURCE_DIR}/src"
)
