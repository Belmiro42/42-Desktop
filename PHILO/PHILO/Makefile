# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/13 23:05:42 by bmatos-d          #+#    #+#              #
#    Updated: 2024/07/16 08:18:38 by bmatos-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

REMOVE	= 	rm -rf

#TODO: cc or gcc?
CC	  	=	cc

CFLAGS	=	-Wall -Werror -Wextra -g -fsanitize=thread

NAME	=	philosophers

S_PATH 	=	./SRC

SRCS	=	_CREATE_THREADS.c	\
			_INITIALISE.c		\
			_LIBERATION.c		\
			_PARSE.c			\
			_PHILOSOPHER.c		\
			_SPLIT.c			\
			_UTILS.c			\
			MAIN.c

SOURCES  := $(addprefix $(S_PATH)/,$(SRCS))

OBJECTS	  = $(SOURCES:.c=.o)

all:		$(NAME)

$(NAME): 	$(OBJECTS)
	@ $(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	@ echo "Compiled"

thread: $(OBJECTS)
	@ $(CC) -fsanitize=thread $(CFLAGS) $(OBJECTS) -o $(NAME)
	@ echo "Compiled"

clean:
	@ $(REMOVE) $(OBJECTS)

fclean: clean
	@ $(REMOVE) $(NAME)

re: fclean all

.PHONY : clean re fclean all