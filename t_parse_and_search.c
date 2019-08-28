#include "mini.h"

char*		bin_search(char *path, char *prog, int n)
{
	struct dirent	*bins;
	DIR 			*path_to_bin;
	char			location[n + 2];

	ft_strncpy(location, path, n);
	location[n] = '/';
	location[n + 1] = 0;
	path_to_bin = opendir(location);
	if (path_to_bin == NULL)
		return (NULL);
	while ((bins = readdir(path_to_bin)) != NULL)
	{
		if (ft_strcmp(bins->d_name, prog) == 0)
		{
			closedir(path_to_bin);
			return(ft_strjoin(location, prog));
		}
		bins++;		
	}
	closedir(path_to_bin);
	return (NULL);
}

int		main(int ac, char *av[], char *env[])
{
	int		i;
	char	**ep;
	char	*start;
	char	*dp;
	int		len;
	char	*path;

	path = NULL;
	i = 0;
	ep = env;
	len = 0;
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
	if ((path = bin_search(start, av[1], len)))
		ft_putendl(path);
	while (!path)
	{
		start = dp;
		if (*start == 0)
			break ;
		start += 1;
		if (!(dp = ft_strchr(start, ':')))
			dp = ft_strchr(start, 0);
		len = dp - start;
		path = bin_search(start, av[1], len);
		if (path)
		{
			ft_putendl(path);
			return (0);
		}
	}
	return (0);
}