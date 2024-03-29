##
## EPITECH PROJECT, 2018
## Arcade
## File description:
## Global Makefile
##

CORE_NAME	= arcade

BUILD_DIR	= build
LIB_DIR		= lib/
GAMES_DIR	= games/

RM		= rm -f
MKDIR		= mkdir -p

all:	$(CORE_NAME) graphicals games

cmake:	| $(BUILD_DIR)
	(cd $(BUILD_DIR) && cmake ..)

$(CORE_NAME): cmake
	make -C $(BUILD_DIR) $(CORE_NAME)
	cp $(BUILD_DIR)/$(CORE_NAME) .

core:	$(CORE_NAME)

games:	cmake | $(GAMES_DIR)
	make -C $(BUILD_DIR) _arcade_basic_game
	make -C $(BUILD_DIR) _arcade_nibbler
	make -C $(BUILD_DIR) _arcade_solarfox
	make -C $(BUILD_DIR) _arcade_wolf3D
	make -C $(BUILD_DIR) _arcade_tamagotchi
	cp build/lib_arcade_basic_game.so build/lib_arcade_nibbler.so \
		build/lib_arcade_solarfox.so build/lib_arcade_wolf3D.so \
		build/lib_arcade_tamagotchi.so games/

graphicals: cmake | $(LIB_DIR)
	make -C $(BUILD_DIR) _arcade_sfml
	make -C $(BUILD_DIR) _arcade_caca
	make -C $(BUILD_DIR) _arcade_sdl
	cp build/lib_arcade_sfml.so build/lib_arcade_caca.so build/lib_arcade_sdl.so lib/

TESTED_SRCS	= \
		  src/core/corebuild/CoreBuild.cpp \
		  src/core/corebuild/CoreClock.cpp \
		  src/core/loader/GameLoader.cpp \
		  src/core/loader/LibLoader.cpp \
		  src/events/EventHandler.cpp \
		  src/events/GameEvent.cpp \
		  src/events/KeyEvent.cpp \
		  src/events/MouseEvent.cpp \
		  src/exception/Exception.cpp \
		  src/games/Menu/MainMenu.cpp \
		  src/games/utils/Controller/PlayerController.cpp \
		  src/games/utils/Controller/SystemController.cpp \
		  src/games/utils/ScoreHandler.cpp \
		  src/games/utils/mapReader/MapReader.cpp \
		  src/graphic/AShapeLoader.cpp \
		  src/graphic/shape/AShape.cpp \
		  src/graphic/shape/ShapeCircle.cpp \
		  src/graphic/shape/ShapeContainer.cpp \
		  src/graphic/shape/ShapeRect.cpp \
		  src/graphic/shape/ShapeText.cpp \
		  src/std/Color.cpp \
		  src/std/Direction.cpp \
		  src/std/DirectoryReader.cpp \
		  src/std/Rect.cpp \
		  src/std/Texture.cpp \
		  src/std/Vertex.cpp \

TESTS_SRCS	= \
		  tests/core/corebuild/coreclock.cpp \
		  tests/core/loader/gameloader.cpp \
		  tests/core/loader/libloader.cpp \
		  tests/events/keyevent.cpp \
		  tests/events/mouseevent.cpp \
		  tests/exception.cpp \
		  tests/games/utils/scorehandler.cpp \
		  tests/graphics/shape/circle.cpp \
		  tests/graphics/shape/rect.cpp \
		  tests/graphics/shape/text.cpp \
		  tests/std/color.cpp \
		  tests/std/directoryreader.cpp \
		  tests/std/rectd.cpp \
		  tests/std/rectf.cpp \
		  tests/std/recti.cpp \
		  tests/std/rects.cpp \
		  tests/std/texture.cpp \
		  tests/std/vertd.cpp \
		  tests/std/vertf.cpp \
		  tests/std/verti.cpp \
		  tests/std/verts.cpp \

CTESTEDFLAGS	= -W -Wall -Wextra -fprofile-arcs -ftest-coverage -std=c++17

%.o: %.cpp
	$(CC) -I. $(CTESTEDFLAGS) -c $< -o $@
%.test.o: %.cpp
	$(CC) -I. -W -Wall -Wextra -std=c++17 -c $< -o $@

TESTED_OBJS	= $(patsubst %.cpp, %.o, $(TESTED_SRCS))
TESTED_GCNO	= $(patsubst %.cpp, %.gcno, $(TESTED_SRCS))
TESTED_GCDA	= $(patsubst %.cpp, %.gcda, $(TESTED_SRCS))
TESTS_OBJS	= $(patsubst %.cpp, %.test.o, $(TESTS_SRCS))

tests_run: $(TESTS_OBJS) $(TESTED_OBJS) games graphicals
	g++ $(TESTED_OBJS) $(TESTS_OBJS) -ldl -lImlib2 -lcaca -lsfml-graphics -lsfml-window -lsfml-system -lcriterion --coverage -o $@
	./$@

tests:	tests_run
	./$<
	lcov -d src/ -c -o arcade.lcov
	lcov -r arcade.lcov '/usr/include/*' -o arcade.lcov
	genhtml arcade.lcov -o www
	surf www/index.html &
	$(RM) ./.scores.arcade/tests*

$(LIB_DIR):
	$(MKDIR) $@
$(GAMES_DIR):
	$(MKDIR) $@
$(BUILD_DIR):
	$(MKDIR) $@

clean:
	$(RM) -r $(BUILD_DIR)
	$(RM) $(TESTS_OBJS) $(TESTED_OBJS) $(TESTED_GCNO) $(TESTED_GCDA)
	$(RM) *.gcov arcade.lcov
	$(RM) -r www

fclean:	clean
	$(RM) $(CORE_NAME) tests_run
	$(RM) -r $(LIB_DIR) $(GAMES_DIR)

re:	fclean all

.PHONY:	all cmake clean fclean re core
