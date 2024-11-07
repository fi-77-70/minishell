#include "../minishell.h"

char	*get_env_value(char *str)
{
	int		a;
	int		i;
	char	*final;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	final = (char *)malloc(sizeof(char) * ft_strlen(str + i));
	if (!final)
		return (NULL);
	a = 0;
	while (str[++i])
		final[a++] = str[i];
	final[a] = 0;
	return (final);
}

int	strclen(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	*env_get(char *name, t_menu *menu)
{
	int		i;
	int		bytes;
	char	**temp;

	if (!name)
		return (NULL);
	i = -1;
	temp = menu->algo;
	while(temp[++i])
	{
		bytes = ft_strclen(temp[i], '=');
		if (!ft_strncmp(temp[i], name, bytes -1))
			return (get_env_value(temp[i]));
	}
	return (NULL);
}