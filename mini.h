#ifndef MINI_H
# define MINI_H
# include "../libft/libft.h"
# include <dirent.h>

#define SEARCH_OFF	0
#define SEARCH_ON	1

char		*param_search(char **env, char *arg, char c, int flag);
//char		**g_environ_vars; 
//extern char **environ;

#endif