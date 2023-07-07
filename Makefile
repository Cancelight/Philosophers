SRCS = ./source/main.c \
		./source/utils.c \
		./source/error.c \
		./source/parse.c \
		./source/process.c
NAME = philo
CC = gcc
CFLAGS = -Wall -Werror -Wextra -lpthread -g -fsanitize=thread
RM = rm -rf
LIBC = ar -rcs

all: ${NAME}

$(NAME): $(SRCS)
	@gcc $(CFLAGS) $(SRCS) -o $(NAME)

fclean:
	@${RM} $(NAME)

re: fclean all

.PHONY: all bonus fclean re
