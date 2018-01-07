##
## Makefile for  in /home/munoz_d/cpp_arcade/src/graphics/sdl
## 
## Made by David Munoz
## Login   <david.munoz@epitech.eu>
## 
## Started on  Sun Apr  2 15:26:36 2017 David Munoz
## Last update Sun Apr  9 23:08:29 2017 Adrien Missioux
##

TARGET	 = ../../../lib/lib_arcade_sdl.so

CC	 = g++

SRC      = menu/menuSdl.cpp		\
	 snake/Game.cpp		\
	 snake/Game_render.cpp	\
	 snake/LTexture.cpp		\
	 snake/Snake.cpp		\
	 snake/Food.cpp		\
	 snake/Map.cpp		\
	 snake/Object.cpp		\

CFLAGS	 = -W -Werror -Wall -ansi -L./lib -I./include -fPIC -shared -Wl,--no-undefined -std=gnu++11

LDFLAGS	 = -lSDL2_image -lSDL2_ttf -lSDL2-2.0

SRCDIR	 = src
OBJDIR	 = obj
MENUDIR	 = menu
SNAKEDIR	 = snake

SOURCES  := $(addprefix src/, $(SRC))

OBJECTS  := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

rm       = rm -rf
mkdir    = mkdir -p

$(TARGET): $(OBJECTS)
	@$(CC) $(OBJECTS) $(CFLAGS) $(LDFLAGS) -o $@
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
