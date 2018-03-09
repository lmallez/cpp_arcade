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
        src/graphic/IGraphic.hpp
        src/graphic/IDraw.hpp
        src/exception/Exception.cpp
        src/exception/Exception.hpp
)

set(
        SHAPE
        src/core/shape/IShape.hpp
        src/core/shape/ShapeRect.cpp
        src/core/shape/ShapeRect.hpp
        src/core/shape/ShapeCircle.cpp
        src/core/shape/ShapeCircle.hpp
        src/core/shape/AShape.cpp
        src/core/shape/AShape.hpp
        src/core/shape/ShapeText.cpp
        src/core/shape/ShapeText.hpp)

### GRAPHICS LIBS ###

add_library(
        NCArcade
        ${STD_FILE}
        ${SHAPE}
)

target_link_libraries(NCArcade nurses)

add_library(
        SFArcade SHARED
        ${STD_FILE}
        ${SHAPE}
        src/graphic/sfml/SFGraphic.cpp
        src/graphic/sfml/SFGraphic.hpp
        src/graphic/sfml/SFDraw.cpp
        src/graphic/sfml/SFDraw.hpp
        src/graphic/sfml/draw/SFDrawRect.cpp
        src/graphic/sfml/draw/SFDrawRect.hpp)

target_link_libraries(SFArcade smfl-graphics smfl-window sfml-system)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets)

add_library(
        QTArcade
        ${STD_FILE}
        ${SHAPE}
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

target_link_libraries(QTArcade Qt5::Widgets)

### GAMES LIBS ###

### CORE BUILD ###

add_executable(
        arcade
        src/main.cpp
        ${STD_FILE}
        ${SHAPE}
)

target_link_libraries(arcade dl)