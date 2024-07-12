COMPILE = cc
FLAGS   = -Wall -Wextra -Werror
ARCHIVE = ar rc
RM      = rm -f
NAME    = libftprintf.a
HEADER  = ft_printf.h
SOURCE  = ft_printf.c do_c.c do_i.c	do_n.c do_u.c do_p.c do_s.c	do_x.c
OBJECTS   = $(SOURCE:.c=.o)
WHAT_ARE_WE_COMPILING = $(OBJECTS)

all: $(WHAT_ARE_WE_COMPILING)
	@$(MAKE) $(NAME) WHAT_ARE_WE_COMPILING="$(WHAT_ARE_WE_COMPILING)" 

$(NAME): $(WHAT_ARE_WE_COMPILING)
	$(ARCHIVE) $(NAME) $(WHAT_ARE_WE_COMPILING)

.c.o:
	$(COMPILE) $(FLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)
 
re: fclean all

.PHONY: all clean fclean re bonus
