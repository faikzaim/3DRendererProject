cmake_minimum_required(VERSION 3.22.1)
project(3DRenderer)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)
set(SDL2_PATH "C:/SDL2-2.30.3/x86_64-w64-mingw32")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(3DRenderer main.cpp
        Screen.cpp
        Screen.h
        SDLManager.cpp
        SDLManager.h
)

target_link_libraries(3DRenderer ${SDL2_LIBRARY})


