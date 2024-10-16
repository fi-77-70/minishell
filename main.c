/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:16:21 by filferna          #+#    #+#             */
/*   Updated: 2024/10/16 12:16:55 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// t_args	*arg_set(char *str)
// {
// 	t_args *new_set;
	
// 	new_set = (t_args *)malloc(sizeof(t_args));
// 	if (!new_set)
// 		return (NULL);
// 	new_set->token = str;
// 	new_set->next = NULL;
// 	return (new_set);
// }

// int	is_cmd(t_args **input)
// {
// 	char	*cmd;
// 	int		result;

// 	cmd = (*input)->token;
// 	result = 0;
// 	if(!strncmp(cmd, "echo", 4))
// 		result = 1;
// 	if(!strncmp(cmd, "cd", 2))
// 		result = 1;
// 	if(!strncmp(cmd, "pwd", 3))
// 		result = 1;
// 	if(!strncmp(cmd, "export", 6))
// 		result = 1;
// 	if(!strncmp(cmd, "unset", 5))
// 		result = 1;
// 	if(!strncmp(cmd, "env", 3))
// 		result = 1;
// 	if(!strncmp(cmd, "exit", 4))
// 		result = 1;
// 	return (result);
// }

// t_args	**create_list(char **matrix)
// {
// 	int		i;
// 	t_args	**input;

// 	i = -1;
// 	input = (t_args **)malloc(sizeof(t_args *));
// 	*input = arg_set(matrix[0]);
// 	while(matrix[++i])
// 	{
// 		(*input)->next = arg_set(matrix[i]);
// 		(*input) = (*input)->next;
// 	}
// 	return (input);
// }

int	main(void)
{
	char	*str;
	char	**line;
	int		j;
	// t_args	**input;
	while(1)
	{
		j = -1;
		str = readline("minishell: ");
		add_history(str);
		line = ft_splot(str);
		if (!line)
			return (0);
		// input = create_list(line);
		// if (is_cmd(input))
		// 	printf("%s is a command\n", (*input)->token);
		// else
		// 	printf("%s is not a command\n", (*input)->token);
		while(line[++j])
		{
			printf("token %d -- > [%s]\n", j, line[j]);
			free(line[j]);
		}
		free(line);
	}
}