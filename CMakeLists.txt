cmake_minimum_required(VERSION 3.10)
project(SearchEngine)

set(CMAKE_CXX_STANDARD 14)

add_executable(SearchEngine main.cpp AVLTree.h AVLTree.cpp SearchEngine.cpp SearchEngine.h)