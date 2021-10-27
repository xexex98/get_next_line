NAME = libtest.a\

HEADER = test.h\

SRC = test.c ft_strlen.c 1.c\

OBJS = $(SRC:.c=.o)

CC = gcc

RM = rm -f

FLAGS = -c -Wall -Wextra -Werror

# OBJECTS = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	ar rcs $(NAME) $?

%.o: %.c
	$(CC) $(FLAGS) $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re