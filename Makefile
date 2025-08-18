CC := cc
SRC_DIR := src
INCLUDE_DIR := include
CFLAGS := -Wall -Werror -Wextra -I $(SRC_DIR)
NAME := libft_printf.a
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
