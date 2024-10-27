#include "../minishell.h"

char	*ft_final_expand(char *str, char *var, char *var_name)
{
	int		i;
	int		j;
	int		a;
	int		expanded;
	char	*final;

	i = 0;
	expanded = 0;
	if(var)
		i = ft_strlen(var);
	final = (char *)malloc(sizeof(char) * (ft_strlen(str) + i - ft_strlen(var_name)) + 1);
	i = -1;
	j = 0;
	a = 0;
	while (str[++i])
	{
		if (str[i] == '$' && expanded == 0)
		{
			if(str[i] == '$')
				i++;
			while (str[i] != ' ' && str[i] != '"' && str[i] != '$' && str[i] != 39 && str[i])
				i++;
			if(!var)
				break;
			while (var[a])
				final[j++] = var[a++];
			expanded = 1;
		}
		final[j++] = str[i];
	}
	return (free(var_name), free(str), final);
}

char	*get_var_name(char *env_var)
{
	int		i;
	char	*var;

	if(!env_var)
		return(NULL);
	i = 0;
	while(env_var[i] != ' ' && env_var[i] != '"' && env_var[i] != 39 && env_var[i] != '$' && env_var[i])
		i++;
	var = (char *)malloc(sizeof(char) * i + 1);
	if (!var)
		return (NULL);
	i = 0;
	while(env_var[i] != ' ' && env_var[i] != '"' && env_var[i] != 39 && env_var[i] != '$' && env_var[i])
	{
		var[i] = env_var[i];
		i++;
	}
	var[i] = 0;
	return (var);
}

char	*ft_expander(char *str)
{
	int		i;
	char	*var_name;
	char	*expanded;

	i = 0;
	while (str[i] != '$' && str[i])
		i++;
	i++;
	var_name = get_var_name(str + i);
	expanded = getenv(var_name);
	return (ft_final_expand(str, expanded, var_name));
}

void	expand(t_args **args)
{
	int		i;
	int		quoted;
	t_args	*temp;

	temp = *args;
	quoted = -1;
	while(temp)
	{
		i = -1;
		while(temp->token[++i])
		{
			if(temp->token[i] == '"')
				quoted *= -1;
			if (temp->token[i] == 39 && quoted == -1)
			{
				i++;
				while (temp->token[i] != 39 && temp->token[i])
					i++;
			}
			if (temp->token[i] == '$')
				temp->token = ft_expander(temp->token);
		}
		temp = temp->next;
	}
}