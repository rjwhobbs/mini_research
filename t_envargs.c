#include "../libft/libft.h"
#include "tlpi_hdr.h"

extern char **environ;

int	main(int ac, char *av[])
{
	int j;
	char **ep;

	ft_putnbr(getppid());
	ft_nl();
	ft_putnbr(getpid());
	ft_nl();
	ep = environ;
	j = 0;
	while(j < ac)
	{
		ft_putstr("av ");
		ft_putnbr(j);
		ft_putstr(" ");
		ft_putendl(av[j++]);
	}
	while (*ep != NULL)
	{
		ft_putstr("Environ: ");
		ft_putendl(*ep);
		ep++;
	}
	return (0);
}
