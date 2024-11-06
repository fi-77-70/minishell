#include "../minishell.h"

void	ft_get_type(t_args **mshh, t_menu *menu, char *token)
{
	t_args	*msh;

	msh = *mshh;
	if (!ft_strcmp(token, "|"))
		msh->type = PIPE;
	else if (!ft_strcmp(token, "~"))
	{
		(*mshh)->token = menu->til;
		msh->type = ARG;
	}
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

t_args	*lexer(t_args **mshh, char **line, t_menu *menu)
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
		else if (!msh->type)
			ft_get_type(&msh, menu, line[j]);
		if (!msh->type)
			msh->type = ARG;
		if (!line[j + 1])
		{
			msh->next = NULL;
			break ;
		}
    	msh->next = (t_args *)malloc(sizeof(t_args));
		if (!msh->next)
			return (*mshh = temp);
		if (msh->type == PIPE)
			msh->next->type = CMD;
		else
			msh->next->type = 0;
		msh = msh->next;
	}
	*mshh = temp;
	return (temp);
}
