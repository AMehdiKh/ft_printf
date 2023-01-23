NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MAN_DIR = Mandatory

SRCS = ft_printf.c print_spec.c

OBJS = ${SRCS:%.c=$(MAN_DIR)/%.o}

BONUS_DIR = Bonus

BSRCS = ft_printf_bonus.c print_str.c print_hex.c print_nbr.c

BOBJS = ${BSRCS:%.c=$(BONUS_DIR)/%.o}

.PHONY: clean
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) rcs $@ $?

bonus: $(BOBJS)
	$(AR) rcs $(NAME) $?

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all