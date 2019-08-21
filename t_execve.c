#include "../libft/libft.h"
#include "tlpi_hdr.h"

int	main(int ac, char *av[])
{
	char *argV[10];
	char *enV[] = {"GREET=Wazup", "whatsup?", NULL};

	argV[0] = ft_strrchr(av[1], '/');
	if (argV[0] != NULL)
		argV[0]++;
	else 
		argV[0] = av[1];
	argV[1] = "hello world";
	argV[2] = "goodbye";
	argV[3] = NULL;
	execve(av[1], argV, enV);
	ft_putendl("Error on exit.");
	return (0);
}