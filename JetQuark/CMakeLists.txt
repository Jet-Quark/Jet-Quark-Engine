cmake_minimum_required(VERSION 3.10)

project(JetQuark)

set(JQ_DEPENCENCIES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/dependencies")

add_subdirectory("${JQ_DEPENCENCIES_DIR}/spdlog")

add_library(JetQuark SHARED src/Application.cpp)

target_link_libraries(JetQuark PUBLIC spdlog_header_only)

target_include_directories(JetQuark
PUBLIC
   "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
