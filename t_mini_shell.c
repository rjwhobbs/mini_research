#include "mini.h"

char	*bin_search(char *path, char *prog, int n)
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

char	*get_path(char **args, char **ep)
{
	char	*start;
	char	*dp;
	int		len;
	char	*path;

	path = NULL;
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
	if ((path = bin_search(start, args[0], len)))
		return (path);
	while (!path)
	{
		start = dp;
		if (*start == 0)
			break ;
		start += 1;
		if (!(dp = ft_strchr(start, ':')))
			dp = ft_strchr(start, 0);
		len = dp - start;
		path = bin_search(start, args[0], len);
		if (path)
			return(path);
	}
	return (path);
}

int		run_exec(char **args, char **ep)
{
	char	*path;
	pid_t	pid;
	int		status;

	if (ft_strcmp(*args, "exit") == 0)
		return (0);
	status = 1;
	path = get_path(args, ep);
	pid = fork();
	if (pid == 0)
	{
		execve(path, args, ep);
		ft_putstr("Error opening: ");
		ft_putendl(path);
		return (1);
	}
	//else if (pid > 0)
	 while (status)
	{
		waitpid(pid, &status, WUNTRACED);
		if (WIFEXITED(status) || WIFSIGNALED(status))
			break ;
		// wait(NULL);
	}
	return (1);
}

void	msh_read(char **ep)
{
	char	*input;
	char	**args;
	int		status;
	int		gnl_status;

	status = 1;
	input = NULL;
	while (status)
	{
		ft_putstr("msh > ");
		gnl_status = get_next_line(STDIN_FILENO, &input);
		if (gnl_status == -1)
			ft_putendl("error reading stdin.");
		args = ft_strsplit(input, ' ');
		status = run_exec(args, ep);
	}
}

int		main(int ac, char *av[], char *env[])
{
	msh_read(env);
	ft_putendl("--------------------exiting msh---------------");
	return (0);
}