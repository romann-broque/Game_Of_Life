###############
#### SHELL ####
###############

SHELL   = /bin/bash

##############
#### SRCS ####
##############

PATH_SRCS       += srcs/

### srcs/

SRCS    += Cell.cpp
SRCS    += Config.cpp
SRCS    += KeyHandler.cpp
SRCS    += Grid.cpp
SRCS    += main.cpp

vpath %.cpp $(PATH_SRCS)

##############
#### OBJS ####
##############

PATH_OBJS		+= objs/
OBJS			+= $(patsubst %.cpp, $(PATH_OBJS)/%.o, $(SRCS))

##################
#### INCLUDES ####
##################

HEADERS			+= Cell.hpp
HEADERS			+= Config.hpp
HEADERS			+= Defines.hpp
HEADERS			+= KeyHandler.hpp
HEADERS			+= Grid.hpp

PATH_INC		+= -I dependencies/
PATH_INC		+= -I /opt/homebrew/Cellar/sfml/2.6.1/include/
INCLUDES		+= $(PATH_INC)

PATH_LIB		+= -L /opt/homebrew/Cellar/sfml/2.6.1/lib/
LIB				+= $(PATH_LIB)

vpath %.hpp $(PATH_INC)

#####################
#### COMPILATION ####
#####################

CC      =       c++

CFLAGS  +=      -Wall
CFLAGS  +=      -Wextra
CFLAGS  +=      -std=c++11

ifeq ($(analysis), true)
	CFLAGS	+=		-pg
endif

ifneq ($(no_error), true)
CFLAGS  +=      -Werror
endif

ifeq ($(debug), true)
CFLAGS  += -fsanitize=undefined,thread
endif

ifeq ($(print_debug), false)
CFLAGS  += -D PRINT_DEBUG=false
endif

LINKS	+= -lsfml-window
LINKS	+= -lsfml-system
LINKS	+= -lsfml-graphics

##############
#### NAME ####
##############

NAME    += Simulation

#################
#### DISPLAY ####
#################

RED='\033[0;31m'
GREEN='\033[1;32m'
ORANGE='\033[0;33m'
YELLOW='\033[1;33m'
BLUE='\033[1;36m'
NC='\033[0m' # No Color

ifndef ECHO
T := $(words $(SRCS))
N := x
C = $(words $N)$(eval N := x $N)

ECHOC = echo -ne "\r\033[2K"
ECHO = $(ECHOC) $(ORANGE) "[`expr $C '*' 100 / $T`%]"
endif

###############
#### RULES ####
###############

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(INCLUDES) $(LIB) $(LINKS)
	$(ECHOC) $(GREEN) "--> $(NAME) COMPILED !"$(NC)"\n\n"

$(OBJS) : $(PATH_OBJS)/%.o: %.cpp Makefile $(HEADERS)
	$(ECHO) $(ORANGE) "Compiling $<"
	mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

run : all
	$(ECHOC) $(GREEN) "RUNNING $(NAME)"$(NC)"\n\n"
	./$(NAME)

clean   :
	$(RM) -r $(PATH_OBJS)
	$(ECHOC) $(GREEN) "--> .o files deleted !"$(NC)"\n"

fclean  :       clean
	$(ECHOC) $(YELLOW) "Cleaning up $(NAME)..." $(NC)
	$(RM) $(NAME)
	$(ECHOC) $(GREEN) "--> $(NAME) deleted !"$(NC)"\n"

re      : fclean
	echo -e $(YELLOW) "\nRebuilding..." $(NC)
	$(MAKE) -s

.PHONY  : all run clean fclean re
.SILENT :
