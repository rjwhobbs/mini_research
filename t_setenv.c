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
	int 		i;
	pid_t		pid;
	int			status;

	status = 0;
	i = 0;
	put_env(env);
	**env = 'A';
	pid = fork();
	if (pid == 0)
	{	
		execve("/bin/zsh", av, env);
	}
	else if (pid > 0)
	{
		ft_putendl("waiting...");
		wait(&status);
		ft_putnbr(status);
		ft_nl();
		ft_putendl("exiting parent");
	}
	return (0);
}