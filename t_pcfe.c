#include "../libft/libft.h"
#include <unistd.h>

extern char **environ;

int		main(int ac, char *av[])
{
	int		fid;
	char	**ep;
	pid_t	wpid;
	int		status;

	status = 1;
	ep = environ;
	fid = fork();
	if (fid > 0)
	{
		ft_putstr("I am the parent, my pid is: ");
		ft_putnbr(getpid());
		ft_nl();
	}
	else if (fid == 0)
	{
		ft_putstr("I am the child, my pid is: ");
		ft_putnbr(getpid());
		ft_nl();
		ft_putstr("I will now exec: ");
		ft_putendl(av[1]);
		execve(av[1], av, ep);
		ft_nl();
		ft_putendl("Something went wrong.");
		return (EXIT_FAILURE);
	}
	while (status)
	{
		wpid = waitpid(fid, &status, WUNTRACED);
		if (WIFEXITED(status) && WIFSIGNALED(status))
			break;
	}
	ft_putendl("Parent is exiting...");
	return (EXIT_SUCCESS);
}