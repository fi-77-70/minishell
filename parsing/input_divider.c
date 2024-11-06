#include "../minishell.h"

char	**get_args(t_args *msh, char **args)
{
	int		i;
	int		size;
	t_args	*temp;

	i = 0;
	size = 0;
	temp = msh;
	while (msh)
	{
		if (msh->type == RED_IN || msh->type == HERE_DOC || msh->type == APP_OUT || msh->type == RED_OUT)
			msh = msh->next->next;
		if (msh && msh->type == ARG)
			size++;
		if (msh)
			msh = msh->next;
	}
	if (!args)
		args = (char **)malloc(sizeof(char *) * size + 1);
	else
		while (args[i])
			i++;
	if (!args)
		return (NULL);
	while (temp && temp->type == ARG)
	{
		args[i] = temp->token;
		temp = temp->next;
		i++;
	}
	args[i] = 0;
	return (args);
}

t_args	*get_redir(t_args *msh)
{
	t_args	*redir;

	redir = (t_args *)malloc(sizeof(t_args));
	redir->type = msh->type;
	if (msh->next)
		redir->token = msh->next->token;
	redir->next = NULL;
	return (redir);
}


void	init_cmds(t_cmds **cmds)
{
	*cmds = (t_cmds *)malloc(sizeof(t_cmds));
	(*cmds)->cmd = NULL;
	(*cmds)->args = NULL;
	(*cmds)->redir = NULL;
	(*cmds)->here_doc = NULL;
	(*cmds)->next =NULL;
}

void	ft_div(t_cmds **cmds, t_args *msh)
{
	t_cmds	*cmd;
	t_args	*temp;

	if (!*cmds)
		init_cmds(cmds);
	cmd = *cmds;
	while (cmd->next && cmd->cmd)
		cmd = cmd->next;
	if (!cmd->next && cmd->cmd)
		init_cmds(&cmd->next);
	if (cmd->next)
		cmd = cmd->next;
	cmd->cmd = msh->token;
	msh = msh->next;
	temp = NULL;
	cmd->redir = temp;
	while (msh && msh->type != PIPE)
	{
		if (msh->type == RED_IN || msh->type == RED_OUT || msh->type == APP_OUT)
		{
			if (temp)
			{
				temp->next = get_redir(msh);
				temp = temp->next;
			}
			else
			{
				temp = get_redir(msh);
				cmd->redir = temp;
			}
			msh = msh->next->next;
		}
		else if (msh && msh->type == HERE_DOC)
		{
			msh = msh->next;
			cmd->here_doc = msh->token;
			msh = msh->next;
		}
		else if (msh && msh->type == ARG)
		{
			cmd->args = get_args(msh, cmd->args);
			while (msh && msh->type == ARG)
				msh = msh->next;
		}
	}
}

t_cmds	**ft_cmd_div(t_args *msh)
{
	t_cmds	**cmds;
	t_cmds	*test;
	t_args	*re_test;
	int		i;

	cmds = (t_cmds **)malloc(sizeof(t_cmds *));
	*cmds = NULL;
	if (!cmds)
		return (NULL);
	while (msh)
	{
		if (msh->type == CMD)
			ft_div(cmds, msh);
		while (msh && msh->type != PIPE)
			msh = msh->next;
		if (msh && msh->type == PIPE)
			msh = msh->next;
	}
	test = *cmds;
	while (test)
	{
		i = 0;
		re_test = test->redir;
		printf("=====================================================\n");
		printf("process cmd: %s\n", test->cmd);
		while (test->args && test->args[i])
			printf("process args: %s\n", test->args[i++]);
		printf("process here_doc: %s\n", test->here_doc);
		while (re_test)
		{
			printf("process redir: type-> %d, file-> %s\n", re_test->type, re_test->token);
			re_test = re_test->next;
		}
		printf("=====================================================\n");
		test = test->next;
	}
	return (cmds);
}