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

$(LIB_DIR):
	$(MKDIR) $@
$(GAMES_DIR):
	$(MKDIR) $@
$(BUILD_DIR):
	$(MKDIR) $@

clean:
	$(RM) -r $(BUILD_DIR)

fclean:	clean
	$(RM) $(CORE_NAME)
	$(RM) -r $(LIB_DIR) $(GAMES_DIR)

re:	fclean all

.PHONY:	all cmake clean fclean re core
