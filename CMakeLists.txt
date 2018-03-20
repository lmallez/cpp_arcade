cmake_minimum_required(VERSION 3.9)
project(cpp_arcade)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wextra -std=c++17")

### STD CLASS ###

set(
        STD_FILES
        src/std/Vertex.cpp
        src/std/Vertex.hpp
        src/std/Rect.cpp
        src/std/Rect.hpp
        src/graphic/IGraphic.hpp
        src/graphic/IShape.hpp
        src/exception/Exception.cpp
        src/exception/Exception.hpp
        src/graphic/shape/AShape.cpp
        src/graphic/shape/AShape.hpp
        src/std/Color.cpp
        src/std/Color.hpp
        src/std/Texture.cpp
        src/std/Texture.hpp
)

set(
        SHAPE
        src/graphic/IShape.hpp
        src/graphic/shape/AShape.cpp
        src/graphic/shape/AShape.hpp
        src/graphic/shape/ShapeRect.cpp
        src/graphic/shape/ShapeRect.hpp
        src/graphic/shape/ShapeCircle.cpp
        src/graphic/shape/ShapeCircle.hpp
        src/graphic/IShapeLoader.hpp
        src/graphic/shape/ShapeText.cpp
        src/graphic/shape/ShapeText.hpp)

### GRAPHICS LIBS ###

set(
        NC_FILES
        ${STD_FILES}
        ${SHAPE})

add_library(
        NCArcade
        ${NC_FILES}
)

target_link_libraries(NCArcade nurses)

set(
        SF_FILES
        ${STD_FILES}
        ${SHAPE}
        src/graphic/sfml/SFGraphic.cpp
        src/graphic/sfml/SFGraphic.hpp
        src/graphic/sfml/draw/SFShapeRect.cpp
        src/graphic/sfml/draw/SFShapeRect.hpp
        src/graphic/sfml/SFShape.cpp
        src/graphic/sfml/SFShape.hpp
        src/graphic/sfml/draw/SFShapeCircle.cpp
        src/graphic/sfml/draw/SFShapeCircle.hpp
        src/graphic/sfml/SFShapeLoader.cpp
        src/graphic/sfml/SFShapeLoader.hpp
        src/graphic/sfml/draw/SFShapeText.cpp
        src/graphic/sfml/draw/SFShapeText.hpp
        src/graphic/IMainWindow.hpp
        src/graphic/sfml/SFMainWindow.cpp
        src/graphic/sfml/SFMainWindow.hpp)

add_library(
        SFArcade SHARED
        ${SF_FILES}
        src/graphic/sfml/extern.cpp)

target_link_libraries(SFArcade sfml-graphics sfml-window sfml-system)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets)

set(
        QT_FILES
        ${STD_FILES}
        ${SHAPE}
)

add_library(
        QTArcade
        ${QTFILE}
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

target_link_libraries(QTArcade Qt5::Widgets)

### GAMES LIBS ###

### CORE BUILD ###

add_executable(
        arcade
        src/main.cpp
        src/core/loader/LibLoader.cpp
        src/core/loader/LibLoader.hpp
        ${STD_FILES}
        ${SHAPE}
)

target_link_libraries(arcade dl)

### TESTING ###

add_executable(
        test_sfml_shape
        ${SF_FILES}
        tests/test_sfml_shape.cpp
)
target_link_libraries(test_sfml_shape sfml-graphics sfml-window sfml-system)

