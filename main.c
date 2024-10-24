/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:16:21 by filferna          #+#    #+#             */
/*   Updated: 2024/10/24 17:50:09 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_cmd(char *str)
{
	char	*cmd;
	int		result;

	cmd = str;
	result = 0;
	if(!strncmp(cmd, "echo", 4))
		result = 1;
	if(!strncmp(cmd, "cd", 2))
		result = 1;
	if(!strncmp(cmd, "pwd", 3))
		result = 1;
	if(!strncmp(cmd, "export", 6))
		result = 1;
	if(!strncmp(cmd, "unset", 5))
		result = 1;
	if(!strncmp(cmd, "env", 3))
		result = 1;
	if(!strncmp(cmd, "exit", 4))
		result = 1;
	return (result);
}

void	free_list(t_args **mshh)
{
	t_args	*node;
	t_args	*temp;

	node = *mshh;
	while (node->next)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
	free(mshh);
}

int	main(void)
{
	char	*str;
	char	**line;
	int		j;
	t_args	**mshh;
	t_args	*msh;
	j = -1;
	while(1)
	{
		mshh = (t_args **)malloc(sizeof(t_args *));
		msh = (t_args *)malloc(sizeof(t_args));
		*mshh = msh;
		j = -1;
		str = readline("minishell: ");
		add_history(str);
		line = ft_splot(str);
		while(line[++j])
		{
			msh->token = line[j];
			if(j == 0)
				msh->type = CMD;
			else if(!ft_strcmp(line[j], "|"))
				msh->type = PIPE;
			msh->next = (t_args *)malloc(sizeof(t_args));
			if (!line[j + 1])
			{
				msh->next = NULL;
				break ;
			}
			if(msh->type == PIPE)
				msh->next->type = CMD;
			else
				msh->next->type = ARG;
			msh = msh->next;
		}
		msh = *mshh;
		while (msh)
		{
			printf("token --> [%s]\n", msh->token);
			printf("type  --> [%d]\n", msh->type);
			msh = msh->next;
		}
		free_list(mshh);
	}
}