#include "../libft/libft.h"
#include <signal.h>

void handler(int num)
{
	ft_putendl_fd("I can't die!", STDOUT_FILENO);
}

int	main(void)
{
	signal(SIGINT, handler);
	signal(SIGTERM, handler);

	while (1)
	{
		ft_putendl_fd("Loop de loop!", STDOUT_FILENO);
		ft_putnbr(getpid());
		sleep(1);
		ft_nl();
	}
	return (0);
}