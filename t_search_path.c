#include "mini.h"

extern char **environ;

int		bin_search(char *path, char *prog, int n)
{
	struct dirent	*bins;
	DIR 			*path_to_bin;
	char			location[n + 1];

	ft_strncpy(location, path, n);
	location[n] = 0;
	ft_putendl(location);
	path_to_bin = opendir(location);
	if (path_to_bin == NULL)
		return (-1);
	while ((bins = readdir(path_to_bin)) != NULL)
	{
		if (ft_strcmp(bins->d_name, prog) == 0)
		{
			closedir(path_to_bin);
			return (1);
		}
		bins++;		
	}
	closedir(path_to_bin);
	return (0);
}

int		main(int ac, char *av[])
{
	int		i;
	char	**ep;
	char	*start;
	char	*dp;
	int		len;
	int		search;

	i = 0;
	ep = environ;
	len = 0;
	search = 0;
	while (*ep)
	{
		if (ft_strstr(*ep, "PATH"))
			break ;
		ep++;
	}
	start = ft_strchr(*ep, '=');
	start += 1;
	dp = ft_strchr(start, ':');
	len = dp - start;
	if ((search = bin_search(start, av[1], len)) == 1)
		ft_putendl("Found the bin");
	while (search == 0)
	{
		start = dp;
		start += 1;
		if (!(dp = ft_strchr(start, ':')))
		{
			len = ft_strlen(start);
			if (len == 0)
			{
				ft_putendl("bin not found");
				return (0);
			}
			search = bin_search(start, av[1], len);
			if (search == 1)
			{
				ft_putendl("found bin");
				return (0);
			}
			else
			{
				ft_putendl("bin not found");
				return (0);
			}	
		}	
		len = dp - start;
		search = bin_search(start, av[1], len);
		if (search == 1)
		{
			ft_putendl("found bin");
			return (0);
		}
	}
	return (0);
}