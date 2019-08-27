#include "../libft/libft.h"

int		main(void)
{
	int i;

	i = 0;
	int f; 
	f = fork(); 
	if(!f)
	{
		ft_putendl("I am the child.");
		ft_putnbr(getpid());
		ft_nl();
		ft_putstr("fork return = ");
		ft_putnbr(f);
		ft_nl();
		while (i++ < 10)
		{
			ft_putendl("Biscuits");
			sleep(1);
		}
	}
	else
	{
		ft_putendl("I am the parent...");
		ft_putnbr(getpid());
		ft_nl();
		ft_putstr("fork return = ");
		ft_putnbr(f);
		ft_nl();
		while (i++ < 10)
		{
			ft_putendl("Ice cream");
			sleep(1);
		}
	} 
	return (0);
}