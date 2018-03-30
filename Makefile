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

cmake:	$(BUILD_DIR)
	(cd $(BUILD_DIR) && cmake ..)

$(CORE_NAME): cmake
	make -C $(BUILD_DIR) $(CORE_NAME)
	cp $(BUILD_DIR)/$(CORE_NAME) .

core:	$(CORE_NAME)

games:	cmake | $(GAMES_DIR)
	make -C $(BUILD_DIR) GAME_BasicGame
	cp build/libGAME_BasicGame.so games/

graphicals: cmake | $(LIB_DIR)
	make -C $(BUILD_DIR) GRAPHIC_SFML
	make -C $(BUILD_DIR) GRAPHIC_Caca
	cp build/libGRAPHIC_SFML.so build/libGRAPHIC_Caca.so lib/

TESTED_SRCS	= \
		  src/core/corebuild/CoreBuild.cpp \
		  src/core/corebuild/CoreClock.cpp \
		  src/core/loader/GameLoader.cpp \
		  src/core/loader/LibLoader.cpp \
		  src/events/EventHandler.cpp \
		  src/events/KeyEvent.cpp \
		  src/events/MouseEvent.cpp \
		  src/exception/Exception.cpp \
		  src/graphic/AShapeLoader.cpp \
		  src/graphic/libcaca/CacaGraphic.cpp \
		  src/graphic/libcaca/CacaMainWindow.cpp \
		  src/graphic/libcaca/CacaShape.cpp \
		  src/graphic/libcaca/CacaShapeLoader.cpp \
		  src/graphic/libcaca/draw/CacaShapeCircle.cpp \
		  src/graphic/libcaca/draw/CacaShapeRect.cpp \
		  src/graphic/libcaca/draw/CacaShapeText.cpp \
		  src/graphic/sfml/SFGraphic.cpp \
		  src/graphic/sfml/SFMainWindow.cpp \
		  src/graphic/sfml/SFShape.cpp \
		  src/graphic/sfml/SFShapeLoader.cpp \
		  src/graphic/sfml/draw/SFShapeCircle.cpp \
		  src/graphic/sfml/draw/SFShapeRect.cpp \
		  src/graphic/sfml/draw/SFShapeText.cpp \
		  src/graphic/shape/AShape.cpp \
		  src/graphic/shape/ShapeCircle.cpp \
		  src/graphic/shape/ShapeRect.cpp \
		  src/graphic/shape/ShapeText.cpp \
		  src/std/Color.cpp \
		  src/std/Rect.cpp \
		  src/std/Texture.cpp \
		  src/std/Vertex.cpp \

TESTS_SRCS	= \
		  tests/exception.cpp \
		  tests/graphics/shape/circle.cpp \
		  tests/graphics/shape/rect.cpp \
		  tests/graphics/shape/text.cpp \
		  tests/std/color.cpp \
		  tests/std/rectd.cpp \
		  tests/std/rectf.cpp \
		  tests/std/recti.cpp \
		  tests/std/rects.cpp \
		  tests/std/texture.cpp \
		  tests/std/vertd.cpp \
		  tests/std/vertf.cpp \
		  tests/std/verti.cpp \
		  tests/std/verts.cpp \

CTESTEDFLAGS	= -Wall -Wextra -fprofile-arcs -ftest-coverage

%.o: %.cpp
	$(CC) -I. $(CTESTEDFLAGS) -c $< -o $@
%.test.o: %.cpp
	$(CC) -I. -c $< -o $@

TESTED_OBJS	= $(patsubst %.cpp, %.o, $(TESTED_SRCS))
TESTED_GCNO	= $(patsubst %.cpp, %.gcno, $(TESTED_SRCS))
TESTED_GCDA	= $(patsubst %.cpp, %.gcda, $(TESTED_SRCS))
TESTS_OBJS	= $(patsubst %.cpp, %.test.o, $(TESTS_SRCS))

tests_run: $(TESTS_OBJS) $(TESTED_OBJS)
	g++ $(TESTED_OBJS) $(TESTS_OBJS) -ldl -lcaca -lsfml-graphics -lsfml-window -lsfml-system -lcriterion --coverage -o $@
	./$@

tests:	tests_run
	./$<
	lcov -d src/ -c -o arcade.lcov
	lcov -r arcade.lcov '/usr/include/*' -o arcade.lcov
	genhtml arcade.lcov -o www
	surf www/index.html &

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
