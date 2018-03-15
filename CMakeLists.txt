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
        src/graphic/IDraw.hpp
        src/exception/Exception.cpp
        src/exception/Exception.hpp
        src/graphic/ADraw.cpp
        src/graphic/ADraw.hpp
        src/std/Color.cpp
        src/std/Color.hpp
        src/std/Texture.cpp
        src/std/Texture.hpp)

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
        src/core/shape/ShapeText.hpp
        src/core/shape/ShapeLoader.cpp
        src/core/shape/ShapeLoader.hpp)

### GRAPHICS LIBS ###

set(
        NC_FILES
        ${STD_FILES}
        ${SHAPE}
)

add_library(
        NCArcade
        ${NC_FILES}
)

target_link_libraries(NCArcade nurses)

set(
        SF_FILES
        ${STD_FILES}
        src/graphic/sfml/operator.cpp
        src/graphic/sfml/operator.hpp
        src/graphic/sfml/SFGraphic.cpp
        src/graphic/sfml/SFGraphic.hpp
        src/graphic/sfml/draw/SFDraw.cpp
        src/graphic/sfml/draw/SFDraw.hpp
        src/graphic/sfml/draw/SFDrawRect.cpp
        src/graphic/sfml/draw/SFDrawRect.hpp
        src/graphic/sfml/draw/SFDrawRect.hpp
        src/graphic/sfml/draw/SFDrawCircle.cpp
        src/graphic/sfml/draw/SFDrawCircle.hpp
        src/graphic/sfml/draw/SFDrawText.cpp
        src/graphic/sfml/draw/SFDrawText.hpp
)

add_library(
        SFArcade SHARED
        ${SF_FILES}
)

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