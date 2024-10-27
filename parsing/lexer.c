/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:19:16 by filferna          #+#    #+#             */
/*   Updated: 2024/10/27 19:01:21 by filferna         ###   ########.fr       */
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

void	lexer(t_args **mshh, char **line)
{
	int		j;
	t_args	*msh;

	j = -1;
	msh = *mshh;
	msh = (t_args *)malloc(sizeof(t_args));
	*mshh = msh;
	if(!msh)
		return ;
	while(line[++j])
	{
		msh->next = (t_args *)malloc(sizeof(t_args));
		msh->token = line[j];
		if(j == 0)
			msh->type = CMD;
		else
			ft_get_type(&msh, line[j]);
		if (!msh->type)
			msh->type = ARG;
		if (msh->type == '|')
			msh->next->type = CMD;
		if (!line[j + 1])
		{
			msh->next = NULL;
			break ;
		}
		msh = msh->next;
	}
}
