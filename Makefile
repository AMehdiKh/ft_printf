NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c utils.c print_hex.c ft_litoa.c

OBJS = ${SRCS:.c=.o}

.PHONY: all clean fclean re
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) rcs $@ $?

bonus: all

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all