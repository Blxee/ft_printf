CC = cc
NAME = libftprintf.a
LIBFT_DIR = ./libft
LIBFT= $(LIBFT_DIR)/libft.a
INCLUDE_DIR = ./include
CFLAGS = -Wall -Werror -Wextra -I$(INCLUDE_DIR)
SRC_DIR = ./src
SRC_FILES = ft_apply_hash.c ft_apply_precision.c ft_apply_sign.c ft_apply_space.c \
			ft_pad_space_after.c ft_pad_space_before.c ft_pad_zero.c \
			ft_parse_flags.c ft_parse_fmt.c ft_parse_precision.c \
			ft_parse_specifier.c ft_parse_width.c ft_print_char.c ft_print_decimal.c \
			ft_printf.c ft_print_hex_lower.c ft_print_hex_upper.c ft_print_percent.c \
			ft_print_pointer.c ft_print_str.c ft_print_unsigned.c ft_putnstr_fd.c nbr_utils.c
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(SRCS:.c=.o)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar -rcs $@ $(OBJS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

all: $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
