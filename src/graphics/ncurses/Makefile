##
## Makefile for  in /home/munoz_d/PSU_2016_malloc
##
## Made by David Munoz
## Login   <david.munoz@epitech.eu>
##
## Started on  Fri Jan 27 11:25:00 2017 David Munoz
## Last update Sun Apr  9 21:11:24 2017 Lucas ONILLON
##

CXX		=	g++
RM		=	rm -f

CXXFLAGS	+=	-std=c++11 -fPIC
CXXFLAGS	+=	-W -Wextra -Wall -Werror
CXXFLAGS	+=	-I../
CXXFLAGS	+=	-I../../common/include/
CXXFLAGS	+=	-I./include/

NAME		=	../../../lib/lib_arcade_ncurses.so
SRCS		+=	getEvent.cpp
SRCS		+=	initLib.cpp
SRCS		+=	menuNcurses.cpp
SRCS		+=	snakeRender.cpp
OBJS		=	$(SRCS:.cpp=.o)

LDFLAGS		+=	-lncurses

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CXX) -shared $(OBJS) -o $(NAME) $(LDFLAGS)

re: 		fclean all

clean:
		$(RM) $(OBJS)

fclean: 	clean
		$(RM) $(NAME)
