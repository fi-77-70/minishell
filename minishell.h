/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:16:35 by filferna          #+#    #+#             */
/*   Updated: 2024/10/26 16:14:59 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
}	t_args;

int		lexer(char *token);
int		is_cmd(char *str);
void	expand(t_args **args);
char	*ft_expander(char *str);
char	*get_var_name(char *env_var);
char	*ft_final_expand(char *str, char *var, char *var_name);

#endif