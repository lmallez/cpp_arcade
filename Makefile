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
		  src/exception/Exception.cpp \
		  src/graphic/shape/AShape.cpp \
		  src/graphic/shape/ShapeCircle.cpp \
		  src/std/Color.cpp \
		  src/std/Rect.cpp \
		  src/std/Texture.cpp \
		  src/std/Vertex.cpp \

TESTS_SRCS	= \
		  tests/exception.cpp \
		  tests/graphics/shape/circle.cpp \
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
	g++ $(TESTED_OBJS) $(TESTS_OBJS) -lcriterion --coverage -o $@
	./$@

tests:	tests_run
	./tests_run
	lcov -d src/ -c -o arcade.lcov
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
