
NAME=ex01
CC=c++
FLAG=-Wall -Werror -Wextra -std=c++98

SRC=main.cpp \
	Bureaucrat.cpp \
	ShrubberyCreationForm.cpp \
	RobotomyRequestForm.cpp \
	PresidentialPardonForm.cpp

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