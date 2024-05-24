NAME = libft.a

SRCS = $(wildcard Mandatory/**/*.c) $(wildcard get_next_line/*.c)
BONUS_SRCS = $(wildcard BONUS/*.c)

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = cc
CFLAGS = -c -Wall -Wextra -Werror

ifdef WITH_BONUS
	OBJ_FILES = $(OBJS) $(BONUS_OBJS)
else
	OBJ_FILES = $(OBJS)
endif

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	ar -rcs $(NAME) $(OBJ_FILES)

bonus :
	make WITH_BONUS=1

%.o : %.c
	$(CC) $(CFLAGS) $^ -o $@

clean :
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus
