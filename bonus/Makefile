SRCS = ./source/main.c \
		./source/utils.c \
		./source/error.c \
		./source/parse.c \
		./source/process.c \
		./source/nav_funcs.c 
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
