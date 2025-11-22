
NAME=PmergeMe
CC=c++
FLAG=-Wall -Werror -Wextra -std=c++98 -g3

SRC=main.cpp \
	PmergeMe.cpp

OBJ=$(patsubst %.cpp, %.o,$(SRC))

all:$(NAME)

$(NAME):$(OBJ)
	$(CC) $(FLAG) -o $(NAME) $(OBJ)

%.o:%.cpp
	$(CC) $(FLAG) -c $< -o $@

clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re:fclean all

.PHONY: all clean fclean re