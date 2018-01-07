##
## Makefile for  in /home/munoz_d/cpp_arcade/src/graphics/sdl
##
## Made by David Munoz
## Login   <david.munoz@epitech.eu>
##
## Started on  Sun Apr  2 15:26:36 2017 David Munoz
## Last update Sun Apr  9 23:15:42 2017 Adrien Missioux
##

TARGET	 = ../../../games/lib_arcade_snake.so

CC	 = g++

SRC      = snakeGame.cpp	\
	   Food_obj.cpp		\
	   Map.cpp		\
	   Position.cpp		\
	   Snake_obj.cpp	\
	   Game_collision.cpp	\
	   libGra.cpp		\

CFLAGS   = -W -Werror -Wall -ansi -Iinclude -fPIC -ldl -std=gnu++11

LDFLAGS	 = -shared -Wl,--no-undefined

SRCDIR	 = src
OBJDIR	 = obj
MENUDIR	 = menu
SNAKEDIR = snake

SOURCES  := $(addprefix src/, $(SRC))

OBJECTS  := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

rm       = rm -rf
mkdir    = mkdir -p

$(TARGET): $(OBJECTS)
	@$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(CFLAGS) $(LDFLAGS)
	@echo $(TARGET)" compiled !"
$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(mkdir) $(OBJDIR)
	@$(mkdir) $(OBJDIR)/$(MENUDIR)
	@$(mkdir) $(OBJDIR)/$(SNAKEDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

all     : $(TARGET)

clean   :
	@$(rm) $(OBJDIR)
	@echo "Binary files deleted"

fclean  : clean
	@$(rm) $(TARGET) $(LINK)
	@echo "Binary and executable files are deleted"

re      : fclean all

.PHONY: all clean fclean re
