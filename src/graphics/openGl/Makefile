##
## Makefile for  in /home/munoz_d/PSU_2016_malloc
## 
## Made by David Munoz
## Login   <david.munoz@epitech.eu>
## 
## Started on  Fri Jan 27 11:25:00 2017 David Munoz
## Last update Sun Apr  9 23:08:02 2017 Adrien Missioux
##

TARGET	 = ../../../lib/lib_arcade_opengl.so

CC	 = g++

SRC      = GL_Handler.cpp	\
	   GL_Utils.cpp

LDFLAGS   = -L/usr/X11R6/lib

LIBS	+= -lGL -lGLU -lglut

CFLAGS   = -W -Werror -Wall -ansi -pedantic -fPIC $(LIBS)

SRCDIR   = src
OBJDIR   = obj

SOURCES  := $(addprefix src/, $(SRC))

OBJECTS  := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

rm       = rm -rf
mkdir    = mkdir -p

$(TARGET): LDFLAGS += -shared -Wl,--no-undefined
$(TARGET): $(OBJECTS)
	@$(CC) $(LDFLAGS) -o $@ $(OBJECTS) ${LIBS}
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
