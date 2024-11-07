#include "../minishell.h"

void dup_arrr(char **map, t_menu **menu)
{
	t_menu	*temp;
	int		y;
	
	temp = *menu;
	temp->algo = NULL;
	y = 0;
	while (map[y])
	{
		printf("envp[%d]: %s\n",y, map[y]);
		y++;
	}
	temp->algo = (char **)malloc(sizeof(char *) * (y + 1));
	y = -1;
	while (map[++y])
	{
		temp->algo[y] = ft_strdup(map[y]);
	}
	temp->algo[y] = NULL;
}

int	pid_get(t_menu *menu)
{
	int	i;
	
	i = fork();
	if (i == 0)
	{
		free_all(menu);
		exit(0);
	}
	else
		return (i);
}