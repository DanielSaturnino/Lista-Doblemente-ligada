cmake_minimum_required(VERSION 2.8.9)
project(ListaD)

include_directories(include)

set(SOURCES src/Nodo.cpp src/main.cpp src/ListaD.cpp)

add_executable(ListaD ${SOURCES})