CC = clang++

CFLAGS = -Wall -Werror -Wextra

NAME = ft_retro

# SRC = Objects.cpp Player.cpp main.cpp
SRC = *.cpp

all:
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) -lncurses
fclean:
	rm -f $(NAME)

re: fclean all