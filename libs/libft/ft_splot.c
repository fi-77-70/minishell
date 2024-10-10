/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filferna <filferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:38:58 by filferna          #+#    #+#             */
/*   Updated: 2024/10/10 19:07:57 by filferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	jump(char *str, int *j)
{
	while (str[*j] && str[*j] == ' ')
		*j += 1;
}

void	ft_quote(char *str, int *i, char sep)
{
	*i += 1;
	while(str[*i] && str[*i] != sep)
		*i += 1;
}

int	cut_count(char *str)
{
	int	i;
	int	j;
	
	i = 0;
	j = 1;
	while(str[i])
	{
		if (str[i] == '"')
			ft_quote(str, &i, '"');
		if (str[i] == 39)
			ft_quote(str, &i, 39);
		if (str[i] == ' ')
			j++;
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] == 0)
			break ;
		i++;
	}
	return (j);
}

char	*ft_space(char *str, int *j, int *i)
{
	int		a;
	char	*matrix;

	a = 0;
	if (str[*i + 1] == 0)
		*i += 1;
	matrix = (char *)malloc(sizeof(char) * (*i - *j) + 1);
	while (*j < *i)
	{
		matrix[a] = str[*j];
		*j += 1;
		a++;
	}
	matrix[a] = 0;
	return (matrix);
}

char	**ft_splot(char *str)
{
	char	**matrix;
	int		i;
	int		j;
	int		a;

	matrix = (char **)malloc(sizeof(char *) * (cut_count(str) + 2));
	if (!matrix)
		return (NULL);
	i = -1;
	j = 0;
	a = -1;
	while(str[++i])
	{
		if (str[j] == ' ')
			jump(str, &j);
		if (str[i] == 39)
			ft_quote(str, &i, 39);
		if (str[i] == '"')
			ft_quote(str, &i, '"');
		if (str[i] == ' ' || str[i + 1] == 0)
			matrix[++a] = ft_space(str, &j, &i);
		if (str[i] == 0)
			break ;
	}
	matrix[a + 1] = NULL;
	return (matrix);
}
