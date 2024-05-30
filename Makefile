NAME = pipex

MANDATORY_SRCS = $(wildcard mandatory/*.c)
BONUS_SRCS = $(wildcard bonus/*.c)

MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror

ifdef BONUS
	OBJS = $(BONUS_OBJS)
else
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
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus