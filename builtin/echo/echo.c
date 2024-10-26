#include "../../minishell.h"

void	echo(t_args *args)
{

	while (args && args->next != PIPE)
	{
		ft_printf("%S", args->text);
		args = args->next;
	}
}