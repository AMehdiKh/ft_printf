NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -c

SRCS = ft_printf.c print_str.c print_hex.c print_nbr.c

OBJS = ${SRCS:.c=.o}

.PHONY: clean
all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS)
	$(AR) rcs $@ $?

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all