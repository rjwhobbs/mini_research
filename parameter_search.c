#include "mini.h"

static char	*bin_search(char *path, char *arg, int n)
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
		if (ft_strcmp(bins->d_name, arg) == 0)
		{
			closedir(path_to_bin);
			return(ft_strdup(location));
		}
		bins++;		
	}
	closedir(path_to_bin);
	return (NULL);
}

static char *path_search(char *arg, char *start, char *end, char c)
{
	char	*path;

	if ((path = bin_search(start, arg, end - start)))
		return (ft_strdup(path));
	while (!path)
	{
		start = end;
		if (*start == 0)
			return (NULL);
		start += 1;
		if (!(end = ft_strchr(start, c)))
			end = ft_strchr(start, 0);
		path = bin_search(start, arg, end - start);
		if (path)
			return(path);
	}
	return (NULL);
}

static char *path_start(char *var, char *arg, char c)
{
	char	*start;
	char	*end;

	start = ft_strchr(var, '=');
	if (start)
	{
		if (!(end = ft_strchr(start + 1, c)))
			end = ft_strchr(start, 0);
		return (path_search(arg, start + 1, end, c));
	}
	return (NULL);
}

static char	*env_search(char **env, char *arg, char c, int flag)
{
	char *var;

	while (*env)
	{
		var = ft_strstr(*env++, arg);
		if (var && !flag)
			return (var);
		else if (var && flag)
			return(path_start(var, arg, c));
	}
	return (*env);
}

char		*param_search(char **env, char *arg, char c, int flag)
{
	if (!env || !*env || !arg || !*arg)
		return (NULL);
	return (env_search(env, arg, c, flag));
}