COMPILE = gcc
FLAGS   = -Wall -Wextra -Werror
ARCHIVE = ar rcs
RM      = rm -f
NAME    = libft.a
HEADER  = libft.h
SOURCE  = ft_atoi.c			   \
		  ft_bzero.c           \
          ft_calloc.c          \
          ft_isalnum.c         \
          ft_isalpha.c         \
          ft_isascii.c         \
          ft_isdigit.c         \
          ft_isprint.c         \
          ft_itoa.c            \
          ft_memchr.c          \
          ft_memcmp.c          \
          ft_memcpy.c          \
          ft_memmove.c         \
          ft_memset.c          \
          ft_putchar_fd.c      \
          ft_putendl_fd.c      \
          ft_putnbr_fd.c       \
          ft_putstr_fd.c       \
          ft_split.c           \
          ft_strchr.c          \
          ft_strdup.c          \
          ft_striteri.c        \
          ft_strjoin.c         \
          ft_strlcat.c         \
          ft_strlcpy.c         \
          ft_strlen.c          \
          ft_strmapi.c         \
          ft_strncmp.c         \
          ft_strnstr.c         \
          ft_strrchr.c         \
          ft_strtrim.c         \
          ft_substr.c          \
          ft_toupper.c         \
          ft_tolower.c

BSOURCE = ft_lstadd_back_bonus.c \
          ft_lstadd_front_bonus.c    \
          ft_lstclear_bonus.c        \
          ft_lstdelone_bonus.c   \
          ft_lstiter_bonus.c     \
          ft_lstlast_bonus.c     \
          ft_lstmap_bonus.c      \
          ft_lstnew_bonus.c      \
          ft_lstsize_bonus.c     

OBJECTS   = $(SOURCE:.c=.o)
BOBJECTS  = $(BSOURCE:.c=.o)
WHAT_ARE_WE_COMPILING = $(OBJECTS)

all: $(WHAT_ARE_WE_COMPILING)
	@$(MAKE) $(NAME) WHAT_ARE_WE_COMPILING="$(WHAT_ARE_WE_COMPILING)" 

bonus: WHAT_ARE_WE_COMPILING = $(BOBJECTS)
bonus: $(WHAT_ARE_WE_COMPILING) 
	@$(MAKE) $(NAME) WHAT_ARE_WE_COMPILING="$(WHAT_ARE_WE_COMPILING)"

$(NAME): $(WHAT_ARE_WE_COMPILING)
	$(ARCHIVE) $(NAME) $(WHAT_ARE_WE_COMPILING)

.c.o:
	$(COMPILE) $(FLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJECTS) $(BOBJECTS)

fclean: clean
	$(RM) $(NAME)
 
re: fclean all
	.PHONY: all clean fclean re bonus


##############################################\
BONUS_FLAG :=\
\
ifdef BONUS\
	BONUS_FLAG := $(BOBJECTS)\
endif\
\
all: $(NAME)\
\
$(NAME): $(OBJECTS) $(BONUS_FLAG)\
	$(ARCHIVE) $(NAME) $(OBJECTS) $(BONUS_FLAG)\
\
%.o: %.c $(HEADER)\
	$(COMPILE) $(FLAGS) -c -o $@ $<\
\
clean:\
	$(REMOVE) $(OBJECTS) $(BOBJECTS)\
\
fclean: clean\
	$(REMOVE) $(NAME)\
\
re: fclean all\
\
bonus:\
	$(MAKE) BONUS=1 all\
##############################################\
##############################################\
all: $(call $(NAME), $(OBJECTS))\
\
bonus: $(call $(NAME), $(BOBJECTS))\
\
\
$(NAME): $(1) $(HEADER)\
	$(ARCHIVE) $(NAME) $(1)\
\
%.o: %.c\
	$(COMPILE) $(FLAGS) -c -o $@ $<\
clean:\
	$(RM) $(OBJECTS) $(BOBJECTS)\
\
fclean: clean\
	$(RM) $(NAME)\
\
re: fclean all\
\
rebonus: fclean bonus\
\
.PHONY: all clean fclean re bonus rebonus\
##############################################\