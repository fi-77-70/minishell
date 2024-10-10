# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: filferna <filferna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/10 14:22:41 by filferna          #+#    #+#              #
#    Updated: 2024/10/10 15:46:52 by filferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = main.c 

LIBS = ./libs/libft/libft.a	./libs/ft_printf/libftprintf.a

CC = cc -Wall -Werror -Wextra -lreadline

all: $(NAME)

$(NAME): $(SRC) $(LIBS)
		$(CC) $(SRC) $(LIBS) -o $(NAME) 

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
