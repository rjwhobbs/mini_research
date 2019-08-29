#include "mini.h"

void	put_env(char **ep)
{
	int	i;

	i = 0;	
	while(ep[i])
	{
		ft_putstr("Env: ");
		ft_putendl(ep[i++]);
	}
}

int		main(int ac, char *av[], char *env[])
{
	ft_putendl("I'm the child.");
	put_env(env);	
	return (0);
}