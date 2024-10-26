#ifndef MINISHELL_H
# define MINISHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libs/libft/libft.h"
#include "libs/ft_printf/ft_printf.h"

#define	BUILT 0
#define CMD 1
#define ARG 2
#define	PIPE 3 

typedef struct s_args{
	char 			*token;
	int				type;
	struct	s_args	*next;
	char			*text;
}	t_args;

int	lexer(char *token);
int	is_cmd(char *str);
void	echo(t_args *args);

#endif