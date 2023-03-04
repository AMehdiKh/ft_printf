NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -MMD

M_DIR = Mandatory
SRCS = ft_printf.c print_spec.c
OBJS = ${SRCS:%.c=$(M_DIR)/%.o}
M_DEP = $(SRCS:%.c=$(M_DIR)/%.d)

B_DIR = Bonus
BSRCS = ft_printf_bonus.c print_str.c print_hex.c print_nbr.c
BOBJS = ${BSRCS:%.c=$(B_DIR)/%.o}
B_DEP = $(BSRCS:%.c=$(B_DIR)/%.d)

.PHONY: clean
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) rcs $@ $?

bonus: $(BOBJS)
	$(AR) rcs $(NAME) $?

sinclude $(M_DEP) $(B_DEP)

clean:
	rm -f $(OBJS) $(BOBJS) $(M_DEP) $(B_DEP)

fclean: clean
	rm -f $(NAME)

re: fclean all