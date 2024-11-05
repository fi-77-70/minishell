NAME = minishell

SRC = main.c ./parsing/lexer.c ./parsing/expander.c ./parsing/input_parsing.c ./builtin/echo/echo.c

LIBS = ./libs/libft/libft.a	./libs/ft_printf/libftprintf.a

CC = cc -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): $(SRC) $(LIBS)
		$(CC) $(SRC) $(LIBS) -lreadline -o $(NAME)

re: fclean all

$(LIBS):
		make -C ./libs/libft
		make -C ./libs/ft_printf

clean:
		make clean -C ./libs/libft
		make clean -C ./libs/ft_printf
fclean:
		make fclean -C ./libs/libft
		make fclean -C ./libs/ft_printf
		rm -f minishell
