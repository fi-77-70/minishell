#include "../../minishell.h"

void	get_pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);

	if (cwd == NULL)
	{	
		printf("Error to get pwd");
		return ;
	}

	printf("%s\n", cwd);
	free(cwd);
}
