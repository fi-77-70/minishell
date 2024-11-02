/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:16:21 by filferna          #+#    #+#             */
/*   Updated: 2024/10/28 16:47:18 by filferna         ###   ########.fr       */
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
	t_args	*temp;

	while (*mshh)
	{
		temp = (*mshh)->next;
		free((*mshh)->token);
		free(*mshh);
		*mshh = temp;
	}
	free(*mshh);
	free(mshh);
}

int	main(void)
{
	char	*str;
	char	**line;
	t_args	**mshh;
	t_args	*msh;
	t_args	*temp;
	
	mshh = NULL;
	msh = NULL;
	temp = NULL;
	while(1)
	{
		mshh = (t_args **)malloc(sizeof(t_args *));
		if(!mshh)
			return (0);
		*mshh = msh;
		str = readline("minishell: ");
		add_history(str);
		line = ft_splot(str);
		msh = lexer(mshh, line);
    *mshh = msh;
		expand(mshh);
		temp = msh;
    if (ft_input_check(mshh))
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
		*mshh = msh;
		free_list(mshh);
    free(line);
  }
}
