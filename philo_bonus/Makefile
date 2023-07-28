SRCS = ./main.c \
		./utils.c \
		./error.c \
		./parse.c \
		./process.c \
		./nav_funcs.c
NAME = philo_bonus
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
LIBC = ar -rcs

all: ${NAME}

$(NAME): $(SRCS)
	@gcc $(CFLAGS) $(SRCS) -o $(NAME)

fclean:
	@${RM} $(NAME)

re: fclean all

.PHONY: all bonus fclean re
