#ifndef MINISHELL_H
# define MINISHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libs/libft/libft.h"
#include "libs/ft_printf/ft_printf.h"

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
}	t_args;

typedef	struct s_cmds{
	char			*cmd;
	char			**args;
	t_args			*redir;
	char			*here_doc;
	struct	s_cmds	*next;
} t_cmds;

typedef struct s_menu{
	char	*til;
	t_args	**mshh;
	t_cmds	**cmds;
}	t_menu;

t_cmds	**ft_cmd_div(t_args *msh);
t_args	*lexer(t_args **mshh, char **line, t_menu *menu);
void	echo_shell(t_args *args);
int		is_cmd(char *str);
void	expand(t_args **args);
char	*ft_expander(char *str, int i);
char	*get_var_name(char *env_var);
char	*ft_final_expand(char *str, char *var, char *var_name, int n);
int 	ft_input_check(t_args **mshh);
void	get_pwd(void);

#endif
