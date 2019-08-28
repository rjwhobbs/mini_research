#include "../libft/libft.h"

int	main(int ac, char *av[])
{
	char *ins[] = {"ft_ls", "-l", NULL}; // So this needs to also contain the name of the porg
	//along with the args.
	execve(av[1], ins, NULL); //av here needs to contain the path to the prog.
	ft_putendl("Error");
	return (EXIT_FAILURE);
}