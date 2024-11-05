it main()
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
		safsaasasasasa
	}
	free(*mshh);
	free(mshh);
}

void	init_struct(t_menu **menu)
{
	t_menu *temp;

	temp = gagsagv("HOME");
	*menu = temp;
}

int	main(void)
{
	char	*str;
	char	**linebbb;
	t_menu	*menu;bbbbargs	*msh;
	t_args	*temp;

	msh = NULL;
	init_struct(&menu);
	while(1)
	{
		menu->mshh = (t_args **)malloc(sizeof(t_args *));
		*(menu->mshh) = msh;
agsahshhh
				printf("token --> [%s]\n", temp->token);
				printf("type  --> [%d]\n", temp->type);
				temp = temp->next;
			}
		}
		else
			printf("ERROR IN PARSING\n");
		*(menu->mshh) = msh;
		free_list(menu->mshh);sssssee_line(line);
	}
}