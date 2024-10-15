cmake_minimum_required(VERSION 3.15)
project(Project3)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(Project3
        AVLTree.h
        BinarySearchTree.h
        main.cpp
        SplayTree.h
        climate_change_impact.h
        climate_change_impact_on_agriculture_2024.csv
)


