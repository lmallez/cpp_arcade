##
## EPITECH PROJECT, 2018
## Arcade
## File description:
## Global Makefile
##

CORE_NAME	= arcade

BUILD_DIR	= build

RM		= rm -f
MKDIR		= mkdir -p

all:	$(BUILD_DIR) $(CORE_NAME)

cmake:
	(cd $(BUILD_DIR) && cmake ..)

$(CORE_NAME): cmake
	make -C $(BUILD_DIR) $(CORE_NAME)
	cp $(BUILD_DIR)/$(CORE_NAME) .

$(BUILD_DIR):
	$(MKDIR) $(BUILD_DIR)

clean:
	$(RM) -r $(BUILD_DIR)

fclean:	clean
	$(RM) $(CORE_NAME)

re:	fclean all

.PHONY:	all cmake clean fclean re
