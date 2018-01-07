##
## Makefile for Makefile in /Users/adrienmissioux/Documents/Epitech/cpp_arcade/
##
## Made by Adrien Missioux
## Login   <adrien.missioux@epitech.eu@epitech.eu>
##
## Started on  Thu Mar 16 14:41:29 2017 Adrien Missioux
## Last update Fri Apr  7 11:41:45 2017 Adrien Missioux
##

CC	= g++

RM	= rm -f

SRCNCURSES = ./src/menuNcurses.cpp

SRC = ./src/main.cpp \
			./src/ALib.cpp \
			./src/GetLib.cpp \

OBJ     = $(SRC:.cpp=.o)
OBJNCURSES     = $(SRCNCURSES:.cpp=.o)

LIBNCURSES = -shared -fPIC -o ./lib/lib_arcade_ncurse.so

CXXFLAGS = -I./src/include -W -Wall -Wextra -Werror -std=c++11

NAME	= arcade

NAMENCURSES = ./lib/lib_arcade_ncurse.so

$(NAME):	 $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -ldl

$(LIBNCURSES): 	$(OBJNCURSES)
	$(CC) -shared $(SRCNCURSES) -fPIC -o $(NAMENCURSES) -lncurses


all:    $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all
