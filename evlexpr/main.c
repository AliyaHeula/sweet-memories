#include "evalexpr.h"
#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write (1, "-", 1);
		nb = 147483648;
	}
	if (nb < 0)
	{
		write (1, "-", 1);
		nb *= -1;
	}
	if (nb > 10)
		ft_putnbr(nb / 10);
	ft_putchar (nb % 10 + '0');
}
	

void	ft_putchar(char c)
{
	write (1, &c, 1);
}
