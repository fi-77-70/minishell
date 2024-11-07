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
		if (line[j])
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

void	init_struct(t_menu **menu, char **envp)
{
	t_menu *temp;

	temp = *menu;
	temp = (t_menu *)malloc(sizeof(t_menu));
	dup_arrr(envp, &temp);
	temp->mshh = NULL;
	temp->til = getenv("HOME");
	*menu = temp;
}

void	free_cmds(t_cmds **cmds)
{
	t_cmds	*temp;
	t_args	*del;

	temp = *cmds;
	while(temp)
	{
		if (temp->args)
			free(temp->args);
		if (temp->redir)
		{
			while (temp->redir)
			{
				del = temp->redir->next;
				free(temp->redir);
				temp->redir = del;
			}
		}
		*cmds = temp->next;
		free (temp);
		temp = *cmds;
	}
	free(cmds);
}

void	free_all(t_menu *menu)
{
	free_line(menu->line);
	// free_line(menu->penv);
	free_cmds(menu->cmds);
	free_list(menu->mshh);
}

int	main(int ac, char **av, char **envp)
{
	char	*str;
	t_menu	*menu;
	t_args	*msh;
	t_args	*temp;
	(void)ac;
	(void)av;

	msh = NULL;
	menu = NULL;
	init_struct(&menu, envp);
	while(1)
	{
		menu->mshh = (t_args **)malloc(sizeof(t_args *));
		*(menu->mshh) = msh;
		str = readline("minishell: ");
		add_history(str);
		menu->line = ft_splot(str);
		if (!menu->line[0])
			continue;
		msh = lexer(menu->mshh, menu->line, menu);
		*(menu->mshh) = msh;
		expand(menu->mshh, menu->line, menu);
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
		menu->cmds = ft_cmd_div(msh);
		process_handler(menu);
		*(menu->mshh) = msh;
		free_all(menu);
	}
}
