#include "ft_printf.h"

void ft_putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}

int ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void ft_putstr(char *str)
{
	write(STDOUT_FILENO, str, ft_strlen(str));
}

void ft_putnstr(char *str, int n)
{
	write(STDOUT_FILENO, str, n);
}

void ft_putnbr(long long nbr)
{

	// if (nbr == -9223372036854775808)
	// {
	// 	ft_putstr("-9223372036854775808");
	// 	return ;
	// }
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr / 10 > 0)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + '0');
}
