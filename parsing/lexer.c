#include "../minishell.h"

int	lexer(char *token)
{
	if(is_cmd(token))
		return(ARG);
	else
		return (0);
}