#include "../../minishell.h"

void	echo_shell(t_args *args)
{

	int first_arg;
	
	first_arg = 1;
	while (args && args->next)
	{
		args = args->next;
		if (first_arg == 0)
			ft_printf(" ");
		ft_printf("Echo test: -> [%s]", args->token);
		first_arg = 0;
    }
}