NAME = convert

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

OBJDIR = obj
SRC = main.cpp ScalarConverter.cpp

OBJ = $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRC))

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR) || true

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
.DEFAULT_GOAL := all
