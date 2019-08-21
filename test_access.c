#include <unistd.h>
#include "../libft/libft.h"

int	main(int ac, char *av[])
{
	ft_putendl(av[1]);
	if ((access(av[1], F_OK) == 0))
		ft_putendl("exists");
	if ((access(av[1], W_OK) == 0))
		ft_putendl("can be written");
	if ((access(av[1], R_OK) == 0))
		ft_putendl("can be read");
	if ((access(av[1], X_OK) == 0))
		ft_putendl("can be executed");
	return (0);
}
