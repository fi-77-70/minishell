#ifndef MINISHELL_H
# define MINISHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libs/libft/libft.h"
#include "libs/ft_printf/ft_printf.h"

#define	BUILT		1
#define CMD			2
#define ARG			3
#define	PIPE		4
#define RED_OUT		5
#define APP_OUT		6
#define	RED_IN		7
#define	HERE_DOC	8

typedef struct s_args{
	char 			*token;
	int				type;
	struct	s_args	*next;
	int bob;
	char o;
	float construtor;
}	t_args;


typedef struct s_menu{
	char	*til;
	t_args	**mshh;
}	t_menu;

t_args	*lexer(t_args **mshh, char **line, t_menu *menu);
void	echo_shell(t_args *args);
int		is_cmd(char *str);
void	expand(t_args **args);
char	*ft_expander(char *str, int i);
char	*get_var_name(char *env_var);
char	*ft_final_expand(char *str, char *var, char *var_name, int n);
int 	ft_input_check(t_args **mshh);

#endif
