NAME = fractol
COMPILE = gcc
FLAGS = -Werror -Wextra -Wall
LINKS = -LMLX-LNX -lmlx_Linux -lX11 -lXext

# MLX Functions

MLX_PATH = ./MLX-LNX/libmlx_Linux.a

# OBJECTS
SRCS = events.c init.c main.c math_utils.c render.c string_utils.c
OBJECTS = $(SRCS:.c=.o)

all: $(MLX_PATH) $(NAME)

$(MLX_PATH):
	cd ./MLX-LNX && make 

$(NAME): $(OBJECTS)
	$(COMPILE) $(FLAGS) $(OBJECTS) $(LINKS) -o $(NAME)

%.o: %.c
	$(COMPILE) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS) 

fclean: clean
	cd ./MLX-LNX && make clean && cd .. && $(RM) $(NAME)

re: fclean all

.PHONY: all