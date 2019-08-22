#include "../libft/libft.h"
#include "tlpi_hdr.h"
#include <unistd.h>

int	main(int ac, char *av[])
{
	char *arr[10];
	char *enV[] = {"GREET=Wazup", "whatsup?", NULL};

	ft_putnbr(getppid());
	ft_nl();
	ft_putnbr(getpid());
	ft_nl();

	arr[0] = ft_strrchr(av[1], '/');
	if (arr[0] != NULL)
		arr[0]++;
	else 
		arr[0] = av[1];
	arr[1] = "hello world";
	arr[2] = "goodbye";
	arr[3] = NULL;
	execve(av[1], arr, enV);
	ft_putendl("Error on exit.");
	return (0);
}