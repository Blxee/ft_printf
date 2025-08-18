CC := cc
INCLUDE_DIR := include
CFLAGS := -Wall -Werror -Wextra -I $(INCLUDE_DIR)

SRC_DIR := src
NAME := libftprintf.a
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(SRCS:.c=.o)

TEST_CFLAGS := -L . -l ftprintf
TEST_DIR := tests
TEST_NAME := test_runner
TEST_SRCS := $(wildcard $(TEST_DIR)/*.c)
TEST_OBJS := $(TEST_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

$(TEST_NAME): $(NAME) $(TEST_OBJS)
	$(CC) -o $@ $(TEST_OBJS) $(TEST_CFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

test: $(TEST_NAME)
	./$(TEST_NAME)

clean:
	rm -f $(OBJS) $(TEST_OBJS)

fclean: clean
	rm -f $(NAME) $(TEST_NAME)

re: fclean all

.PHONY: all test clean fclean re
