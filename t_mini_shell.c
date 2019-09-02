#include "mini.h"

void	print_env(char **ep);
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

char	*get_path(char **args, char **env)
{
	char	*start;
	char	*dp;
	int		len;
	char	*path;

	path = NULL;
	len = 0;
	while (*env)
	{
		if (ft_strstr(*env, "PATH"))
			break ;
		env++;
	}
	start = ft_strchr(*env, '=');
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

int		ft_setenv(void)
{

	*g_environ_vars = ft_strdup("XXxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
	// void **v;
	// *v = s;
	// free(s);
	// ft_putendl(s);
	return (1);
}

int		run_exec(char **args, char **env)
{
	char	*path;
	pid_t	pid;
	int		status;

	if (ft_strcmp(*args, "exit") == 0)
		return (0);
	else if (ft_strcmp(*args, "setenv") == 0)
	 	return (ft_setenv());
	else if (ft_strcmp(*args, "./a.out") == 0)
	 	execve("./a.out", args, env);
	status = 1;
	path = get_path(args, env);
	pid = fork();
	if (pid == 0)
	{
		if ((ft_strcmp(*args, "./print_mem") == 0))
			execve("./print_mem", args, env);
		else
		{
			execve(path, args, env);
			ft_putstr("Error opening: ");
			ft_putendl(*args);
		}
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

void	msh_read(char **env)
{
	char	*input;
	char	**args;
	int		status;
	int		gnl_status;

	qprint_env(env);
	status = 1;
	input = NULL;
	while (status)
	{
		ft_putstr("msh > "); // why does cat's output interfere here?
		gnl_status = get_next_line(STDIN_FILENO, &input);
		if (gnl_status == -1)
			ft_putendl("error reading stdin.");
		args = ft_strsplit(input, ' ');
		status = run_exec(args, env);
	}
}

size_t		arr_size(char **arr)
{
	size_t i;

	i = 0;
	if (arr)
		while (arr[i])
			i++;
	return (i);
}

char	**arrdup(char **arr)
{
	char	**dup;
	char	**dup_z;
	size_t	len;

	if (!(len = arr_size(arr)))
		return (NULL);
	dup = (char**)malloc(sizeof(char*) *(len + 1));
	dup_z = dup;
	dup[len] = NULL;
	while(len--)
		*dup++ = ft_strdup(*arr++);
	return (dup_z);
}

void	print_env(char **ep)
{
	int	i;

	i = 0;	
	while(ep[i])
		ft_putendl(ep[i++]);
}

int		main(int ac, char *av[], char *env[])  // We can do this as we are getting out env vars from extern char **environ
{
	g_environ_vars = arrdup(env);
	msh_read(g_environ_vars);
	ft_putendl("-----------------thank you for testing msh---------------");
	exit (EXIT_SUCCESS);
}