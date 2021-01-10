#include "libft.h"

void ft_putchar(char c)
{
    write (1, &c, 1);    
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write (1, "-", 1);
		write (1, "2", 1);
		nb = 147483648;
	}
	if (nb < 0)
	{
		write (1, "-", 1);
		nb = nb * -1;
	}
	if (nb >= 10)
	{
		ft_putnbr (nb / 10);
		ft_putchar (nb % 10 + '0');
	}
	else
	    ft_putchar (nb + '0');
}
