NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror -lreadline -I /usr/include -I /usr/local/include
RM = rm -f
OBJ = minishell.o

all: $(NAME) $(OBJ)
$(NAME): $(OBJ)
	@echo "Compiling $(NAME)..."
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re