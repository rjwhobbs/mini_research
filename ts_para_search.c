#include "mini.h"

int		main(int ac, char *av[], char *env[])
{
	char *env_var;

	(void)ac;
	env_var = param_search(env, "PATH", av[1], SEARCH_ON);
	ft_putendl(env_var);
	return (0);
}