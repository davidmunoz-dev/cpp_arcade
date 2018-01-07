##
## Makefile for  in /home/munoz_d/PSU_2016_malloc
##
## Made by David Munoz
## Login   <david.munoz@epitech.eu>
##
## Started on  Fri Jan 27 11:25:00 2017 David Munoz
## Last update Sun Apr  9 21:02:36 2017 David Munoz
##

TARGET	 = ../../../games/lib_arcade_pacman.so

CC	 = g++

SRC      =	Player.cpp	\
		Map.cpp			\
		Func.cpp		\
		Pacman.cpp

CFLAGS   = -W -Wall -ansi -std=c++11 -I./include -fPIC -shared

SRCDIR   = src
OBJDIR   = obj

SOURCES  := $(addprefix src/, $(SRC))

OBJECTS  := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

rm       = rm -rf
mkdir    = mkdir -p

$(TARGET): $(OBJECTS)
	@$(CC) $(CFLAGS) -o $@ $(OBJECTS)
	@echo $(TARGET)" compiled !"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(mkdir) $(OBJDIR)
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
