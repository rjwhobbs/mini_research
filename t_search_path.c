#include "../libft/libft.h"

extern char **environ;

void	print_loc(char *path, int n)
{
	char location[n];

	ft_strncpy(location, path, n);
	ft_putendl(location);
}

int		main(int ac, char *av[])
{
	int		i;
	char	**ep;
	char	*equ_sign;
	char	*dp;
	int		len;

	i = 0;
	ep = environ;
	len = 0;
	while (*ep)
	{
		if (ft_strstr(*ep, "PATH"))
			break ;
		ep++;
	}
	equ_sign = ft_strchr(*ep, '=');
	equ_sign += 1;
	dp = ft_strchr(equ_sign + 1, ':');
	len = dp - equ_sign;
	print_loc(equ_sign, len);

	return (0);
}