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

TESTS_SRCS	= \
		  tests/exception.cpp \

CTESTEDFLAGS	= -Wall -Wextra -fprofile-arcs -ftest-coverage

%.o: %.cpp
	$(CC) $(CTESTEDFLAGS) -c $< -o $@
%.test.o: %.cpp
	$(CC) -I. -c $< -o $@

TESTED_OBJS	= $(patsubst %.cpp, %.o, $(TESTED_SRCS))
TESTED_GCNO	= $(patsubst %.cpp, %.gcno, $(TESTED_SRCS))
TESTED_GCDA	= $(patsubst %.cpp, %.gcda, $(TESTED_SRCS))
TESTS_OBJS	= $(patsubst %.cpp, %.test.o, $(TESTS_SRCS))

tests_run: $(TESTS_OBJS) $(TESTED_OBJS)
	g++ $(TESTED_OBJS) $(TESTS_OBJS) -lcriterion --coverage -o $@
	./$@

$(LIB_DIR):
	$(MKDIR) $@
$(GAMES_DIR):
	$(MKDIR) $@
$(BUILD_DIR):
	$(MKDIR) $@

clean:
	$(RM) -r $(BUILD_DIR)
	$(RM) $(TESTS_OBJS) $(TESTED_OBJS) $(TESTED_GCNO) $(TESTED_GCDA)
	$(RM) *.gcov

fclean:	clean
	$(RM) $(CORE_NAME) tests_run
	$(RM) -r $(LIB_DIR) $(GAMES_DIR)

re:	fclean all

.PHONY:	all cmake clean fclean re core
