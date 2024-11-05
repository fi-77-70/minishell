/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:16:21 by filferna          #+#    #+#             */
/*   Updated: 2024/11/05 15:40:22 by filferna         ###   ########.fr       */
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
void	free_line(char **line)
{
	int	j;
	
	j = -1;
	while(line[++j])
	{
		free(line[j]);
	}
	free(line);
}

void	free_list(t_args **mshh)
{
	t_args	*temp;

	while (*mshh)
	{
		temp = (*mshh)->next;
		free(*mshh);
		*mshh = temp;
	}
	free(*mshh);
	free(mshh);
}

void	init_struct(t_menu **menu)
{
	t_menu *temp;

	temp = *menu;
	temp = (t_menu *)malloc(sizeof(t_menu));
	temp->mshh = NULL;
	temp->til = getenv("HOME");
	*menu = temp;
}

int	main(void)
{
	char	*str;
	char	**line;
	t_menu	*menu;
	t_args	*msh;
	t_args	*temp;
	
	msh = NULL;
	init_struct(&menu);
	while(1)
	{
		menu->mshh = (t_args **)malloc(sizeof(t_args *));
		*(menu->mshh) = msh;
		str = readline("minishell: ");
		add_history(str);
		line = ft_splot(str);
		if (!line[0])
			continue;
		msh = lexer(menu->mshh, line, menu);
		*(menu->mshh) = msh;
		expand(menu->mshh);
		temp = msh;
		if (ft_input_check(menu->mshh))
		{
		while (temp)
		{
			printf("token --> [%s]\n", temp->token);
			printf("type  --> [%d]\n", temp->type);
			temp = temp->next;
		}
		}
		else
			printf("ERROR IN PARSING\n");
		*(menu->mshh) = msh;
		free_list(menu->mshh);
		free_line(line);
	}
}
