cmake_minimum_required(VERSION 3.9)
project(cpp_arcade)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wall -Wextra -std=c++17")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

### STD CLASS ###

set(
        STD_FILES
        src/games/utils/ScoreHandler.cpp
        src/games/utils/ScoreHandler.hpp
        src/std/Vertex.cpp
        src/std/Vertex.hpp
        src/std/Rect.cpp
        src/std/Rect.hpp
        src/graphic/IGraphic.hpp
        src/exception/Exception.cpp
        src/exception/Exception.hpp
        src/std/Color.cpp
        src/std/Color.hpp
        src/std/Texture.cpp
        src/std/Texture.hpp
        src/games/IGame.hpp
        src/events/EventHandler.cpp
        src/events/EventHandler.hpp
        src/std/DirectoryReader.cpp
        src/std/DirectoryReader.hpp
        src/events/KeyEvent.cpp
        src/events/KeyEvent.hpp
        src/events/MouseEvent.cpp
        src/events/MouseEvent.hpp
        src/events/GameEvent.cpp
        src/events/GameEvent.cpp
        src/events/GameEvent.hpp
        src/games/utils/Controller/SystemController.cpp
        src/games/utils/Controller/SystemController.hpp
        src/std/Direction.cpp
        src/std/Direction.hpp
)

set(
        SHAPE_FILES
        src/graphic/IShape.hpp
        src/graphic/shape/AShape.cpp
        src/graphic/shape/AShape.hpp
        src/graphic/shape/ShapeRect.cpp
        src/graphic/shape/ShapeRect.hpp
        src/graphic/shape/ShapeCircle.cpp
        src/graphic/shape/ShapeCircle.hpp
        src/graphic/IShapeLoader.hpp
        src/graphic/shape/ShapeText.cpp
        src/graphic/shape/ShapeText.hpp
        src/graphic/AShapeLoader.cpp
        src/graphic/AShapeLoader.hpp
        src/graphic/shape/ShapeContainer.cpp
        src/graphic/shape/ShapeContainer.hpp
)

### MENU ###

set(
        MENU
        src/games/Menu/MainMenu.cpp
        src/games/Menu/MainMenu.hpp
)

### GRAPHICS LIBS ###

set(
        GRAPHIC_SFML
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
        src/graphic/sfml/SFMainWindow.cpp
        src/graphic/sfml/SFMainWindow.hpp
)

add_library(_arcade_sfml SHARED ${GRAPHIC_SFML} ${STD_FILES} ${SHAPE_FILES}
        src/graphic/sfml/extern.cpp
        )
target_link_libraries(_arcade_sfml sfml-graphics sfml-window sfml-system)

set(
        GRAPHIC_Caca
        src/graphic/libcaca/CacaGraphic.cpp
        src/graphic/libcaca/CacaGraphic.hpp
        src/graphic/libcaca/CacaImage.cpp
        src/graphic/libcaca/CacaImage.hpp
        src/graphic/libcaca/CacaShape.cpp
        src/graphic/libcaca/CacaShape.hpp
        src/graphic/libcaca/CacaShapeLoader.cpp
        src/graphic/libcaca/CacaShapeLoader.hpp
        src/graphic/libcaca/draw/CacaShapeCircle.cpp
        src/graphic/libcaca/draw/CacaShapeCircle.hpp
        src/graphic/libcaca/draw/CacaShapeRect.cpp
        src/graphic/libcaca/draw/CacaShapeRect.hpp
        src/graphic/libcaca/draw/CacaShapeText.cpp
        src/graphic/libcaca/draw/CacaShapeText.hpp
        src/graphic/libcaca/CacaMainWindow.cpp
        src/graphic/libcaca/CacaMainWindow.hpp
)

add_library(_arcade_caca SHARED ${GRAPHIC_Caca} ${STD_FILES} ${SHAPE_FILES}
        src/graphic/libcaca/extern.cpp
        )
target_link_libraries(_arcade_caca caca Imlib2)

#set(
#        GRAPHIC_GLU)
#
#add_library(GRAPHIC_GLU SHARED ${GRAPHIC_GLU} ${STD_FILES} ${SHAPE_FILES})
#target_link_libraries(GRAPHIC_GLU GLU GL)

### GAMES LIBS ###

set(
        STD_GAME
        src/games/utils/IObject.hpp
        src/games/utils/Animated/AnimatedContainer.cpp
        src/games/utils/Animated/AnimatedContainer.hpp
)

set(
        GAME_BASICGAME
        src/games/BasicGame/BasicGame.cpp
        src/games/BasicGame/BasicGame.hpp
        src/games/utils/Controller/PlayerController.cpp
        src/games/utils/Controller/PlayerController.hpp
        src/games/utils/Animated/AnimatedShape.cpp
        src/games/utils/Animated/AnimatedShape.hpp
        src/games/utils/Animated/AnimatedObject.cpp
        src/games/utils/Animated/AnimatedObject.hpp
)

add_library(_arcade_basic_game SHARED ${STD_GAME} ${GAME_BASICGAME} ${STD_FILES} ${SHAPE_FILES}
        src/games/BasicGame/extern.cpp
        )

set(
        GAME_SNAKE
        src/games/Snake/SnakeGame.cpp
        src/games/Snake/SnakeGame.hpp
        src/games/utils/Controller/PlayerController.cpp
        src/games/utils/Controller/PlayerController.hpp
        src/games/Snake/Snake.cpp
        src/games/Snake/Snake.hpp
        src/core/corebuild/CoreClock.cpp
        src/core/corebuild/CoreClock.hpp
        src/games/utils/mapReader/MapReader.cpp
        src/games/utils/mapReader/MapReader.hpp
        src/games/utils/IGameObject.hpp
)

add_library(_arcade_nibbler SHARED ${STD_GAME} ${GAME_SNAKE} ${STD_FILES} ${SHAPE_FILES}
        src/games/Snake/extern.cpp
        )

set(
        GAME_SOLAR_FOX
        src/games/utils/Controller/PlayerController.cpp
        src/games/utils/Controller/PlayerController.hpp
        src/games/SolarFox/SolarFoxGame.cpp
        src/games/SolarFox/SolarFoxGame.hpp
        src/games/SolarFox/Ship.cpp
        src/games/SolarFox/Ship.hpp
        src/games/SolarFox/Monster.cpp
        src/games/SolarFox/Monster.hpp
        src/core/corebuild/CoreClock.cpp
        src/core/corebuild/CoreClock.hpp
        src/games/SolarFox/AMissile.cpp
        src/games/SolarFox/AMissile.hpp
        src/games/SolarFox/MonsterMissile.cpp
        src/games/SolarFox/MonsterMissile.hpp
        src/games/SolarFox/ShipMissile.cpp
        src/games/SolarFox/ShipMissile.hpp
        src/games/utils/mapReader/MapReader.cpp
        src/games/utils/mapReader/MapReader.hpp
        src/games/utils/IGameObject.hpp
        src/games/SolarFox/MapManager.cpp
        src/games/SolarFox/MapManager.hpp
        src/games/SolarFox/AObject.cpp
        src/games/SolarFox/AObject.hpp
        src/games/SolarFox/BasicMob.cpp
        src/games/SolarFox/BasicMob.hpp
)

add_library(_arcade_solarfox SHARED ${STD_GAME} ${GAME_SOLAR_FOX} ${STD_FILES} ${SHAPE_FILES}
        src/games/SolarFox/extern.cpp
        )

### CORE BUILD ###

set(
        CORE
        src/core/loader/LibLoader.cpp
        src/core/loader/LibLoader.hpp
        src/core/loader/GameLoader.cpp
        src/core/loader/GameLoader.hpp
        src/events/MouseEvent.cpp
        src/events/MouseEvent.hpp
        src/events/KeyEvent.cpp
        src/events/KeyEvent.hpp
        src/core/corebuild/CoreBuild.cpp
        src/core/corebuild/CoreBuild.hpp
        src/core/corebuild/CoreClock.cpp
        src/core/corebuild/CoreClock.hpp
)


add_executable(
        arcade
        src/main.cpp
        ${CORE}
        ${STD_FILES}
        ${SHAPE_FILES}
        ${MENU}
)

target_link_libraries(arcade dl)

### TESTING ###

#add_executable(
#        test_sfml_shape
#        ${GRAPHIC_SFML}
#        ${SHAPE_FILES}
#        ${STD_FILES}
#        tests/mainTests/test_sfml_shape.cpp
#)
#target_link_libraries(test_sfml_shape sfml-graphics sfml-window sfml-system)
#
#add_executable(
#        test_basic_game ${STD_FILES} ${SHAPE_FILES} ${STD_GAME} ${GAME_BASICGAME} ${GRAPHIC_SFML}
#        tests/mainTests/test_basic_game.cpp
#)
#target_link_libraries(test_basic_game sfml-graphics sfml-window sfml-system)
#
#add_executable(
#        test_basic_loader_graphic ${STD_FILES} ${SHAPE_FILES} ${STD_GAME} ${GAME_BASICGAME} ${CORE}
#        tests/mainTests/test_basic_loader_graphic.cpp
#)
#target_link_libraries(test_basic_loader_graphic dl)
#
#add_executable(
#        test_basic_loader_game ${STD_FILES} ${SHAPE_FILES} ${CORE} ${GRAPHIC_SFML}
#        tests/mainTests/tests_basic_loader_game.cpp
#)
#target_link_libraries(test_basic_loader_game dl sfml-graphics sfml-window sfml-system)
