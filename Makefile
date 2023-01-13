NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_utils.c

OBJS = ${SRCS:.c=.o}

.PHONY: all clean fclean re
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) rcs $@ $?

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all