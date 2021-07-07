cmake_minimum_required(VERSION 3.10)

project(Sandbox)

add_executable(sandbox src/SandboxApp.cpp)

target_link_libraries(sandbox PUBLIC JetQuark)
