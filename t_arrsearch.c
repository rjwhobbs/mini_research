#include "mini.h"
#include <stdio.h>

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

int		main(int ac, char *av[], char *env[])
{
	char 	**env_dup;
	char	*test;

	env_dup = arrdup(env);
	test = ft_arrstr(env_dup, "TERM_PROGRAM=iTerm.app");
	printf("%p\n %s\n", test, test);
	printf("%p\n %s\n %p \n", &env_dup[0], env_dup[0]);
}