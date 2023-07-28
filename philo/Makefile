SRCS = ./main.c \
		./utils.c \
		./error.c \
		./parse.c \
		./process.c
NAME = philo
CC = gcc
CFLAGS = -Wall -Werror -Wextra -lpthread
RM = rm -rf
LIBC = ar -rcs

all: ${NAME}

$(NAME): $(SRCS)
	@gcc $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	@${RM} $(NAME)

fclean:
	@${RM} $(NAME)

re: fclean all

.PHONY: all bonus fclean re
