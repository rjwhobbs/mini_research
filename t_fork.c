#include "../libft/libft.h"

int		main(void)
{
	int f; 
	f = fork(); 
	if(!f)
	{
		ft_putendl("I am the child.");
		ft_putnbr(getpid());
		ft_nl();
	}
	else
	{
		ft_putendl("I am the parent...");
		ft_putnbr(getpid());
		ft_nl();
		ft_putstr("fork return = ");
		ft_putnbr(f);
		ft_nl();
	} 
	return (0);
}