MANDATORY_NAME = pipex
# BONUS_NAME = checker

MANDATORY_SRCS = $(wildcard mandatory/*.c)
BONUS_SRCS = $(wildcard bonus/*.c)

MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror

ifdef BONUS
	NAME = $(BONUS_NAME)
	OBJS = $(BONUS_OBJS)
else
	NAME = $(MANDATORY_NAME)
	OBJS = $(MANDATORY_OBJS)
endif

all : $(NAME)

bonus :
	make BONUS=1

$(NAME) : $(OBJS)
	make -C libft all
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) libft/libft.a

%.o : %.c
	$(CC) $(FLAGS) -c $^ -o $@

clean :
	make -C libft clean
	rm -f $(MANDATORY_OBJS) $(BONUS_OBJS)

fclean : clean
	make -C libft fclean
	rm -f $(MANDATORY_NAME) $(BONUS_NAME)

re : fclean all

.PHONY: all clean fclean re bonus