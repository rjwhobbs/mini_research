#include "../libft/libft.h"
#include <stdio.h>

int		main(void)
{
	int a;

	a = 0;
	if (fork() == 0) 
	{ 
	    a = a + 5; 
	    printf("Child   %d, %p\n", a, &a); 
	} 
	else 
	{ 
	    a = a - 5; 
	    printf("Parent %d, %p\n", a, &a); 
	} 
}