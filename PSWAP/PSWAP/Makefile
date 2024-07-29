# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 23:18:34 by bmatos-d          #+#    #+#              #
#    Updated: 2024/07/15 21:32:34 by bmatos-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

REMOVE	  = rm -rf
CC	  	  = gcc
CFLAGS	  =-Wall -Werror -Wextra -g
NAME	  = push_swap
CHECKER	  = checker_linux
MOVE_PATH = ./_______MOVEMENTS
MOVE_SRCS = Move_Push.c			\
			Move_Rev_Rotate.c	\
			Move_Rotate.c		\
			Move_Swap.c
FUNC_PATH = ./_______FUNCTIONS
FUNC_SRCS = My_Exit.c			\
			Sort_Functions.c	\
			Stack_Functions.c	\
			Stack_Functions_2.c \
			Stack_Init.c
CORE_PATH = ./_______CORE
CORE_SRCS = MAIN.c
SOURCES  := $(addprefix $(MOVE_PATH)/,$(MOVE_SRCS)) \
			$(addprefix $(FUNC_PATH)/,$(FUNC_SRCS)) \
			$(addprefix $(CORE_PATH)/,$(CORE_SRCS))

OBJECTS	  = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@ $(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	@ echo "Compiled"

$(CHECKER):
	@ wget https://cdn.intra.42.fr/document/document/26228/checker_linux

clean:
	@ $(REMOVE) $(OBJECTS)

fclean: clean
	@ $(REMOVE) $(NAME) checker_linux

re: fclean $(NAME)

.PHONY : clean re fclean all
