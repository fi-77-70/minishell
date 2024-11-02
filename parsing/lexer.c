/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:19:16 by filferna          #+#    #+#             */
/*   Updated: 2024/10/28 16:10:49 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_get_type(t_args **mshh, char *token)
{
	t_args	*msh;

	msh = *mshh;
	if (!ft_strcmp(token, "|"))
		msh->type = PIPE;
	else if (!ft_strcmp(token, ">"))
		msh->type = RED_OUT;
	else if (!ft_strcmp(token, ">>"))
		msh->type = APP_OUT;
	else if (!ft_strcmp(token, "<"))
		msh->type = RED_IN;
	else if (!ft_strcmp(token, "<<"))
		msh->type = HERE_DOC;
	else
		msh->type = 0;
}

t_args	*lexer(t_args **mshh, char **line)
{
	int		j;
	t_args	*msh;
	t_args	*temp;
	
	j = -1;
	msh = *mshh;
	msh = (t_args *)malloc(sizeof(t_args));
	temp = msh;
	if(!msh)
		return (NULL);
	while(line[++j])
	{
		msh->token = line[j];
		if(j == 0)
			msh->type = CMD;
		else
			ft_get_type(&msh, line[j]);
		if (!msh->type)
			msh->type = ARG;
		if (!line[j + 1])
		{
			msh->next = NULL;
			break ;
		}
    msh->next = (t_args *)malloc(sizeof(t_args));
    if (msh->type == PIPE)
      msh->next->type = CMD;
		msh = msh->next;
	}
	*mshh = temp;
	return (temp);
}
