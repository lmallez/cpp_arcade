cmake_minimum_required(VERSION 3.9)
project(cpp_arcade)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wextra -std=c++17")

### STD CLASS ###

set(
        STD_FILE
        src/std/Vertex.cpp
        src/std/Vertex.hpp
        src/std/Rect.cpp
        src/std/Rect.hpp
)

### GRAPHICS LIBS ###

add_library(
        NCArcade
        ${STD_FILE}
)

target_link_libraries(NCArcade nurses)

add_library(
        SFArcade SHARED
        ${STD_FILE}
)

target_link_libraries(SFArcade smfl-graphics smfl-window sfml-system)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets)

add_library(
        QTArcade WIN32
        ${STD_FILE}
)

target_link_libraries(QTArcade Qt5::Widgets)

### GAMES LIBS ###

### CORE BUILD ###

add_executable(
        arcade
        ${STD_FILE}
        src/core/main.cpp)

target_link_libraries(arcade dl)