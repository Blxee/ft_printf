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
