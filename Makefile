CC = cc
NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra       -g
LIBFT_DIR = libft
SRCS = ft_printf.c
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/libft.a $@
	ar -rcs $@ $(OBJS)

%.o: %.c
	$(CC) -c $(CFLAGS) $^ -o $@

all: $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
