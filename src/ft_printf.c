#include "ft_printf.h"

int ft_printf(char *format, ...)
{
	va_list args;

	va_start(args, format);
	ft_putstr(format);
	int num1 = va_arg(args, int);
	int num2 = va_arg(args, int);
	ft_putnbr(num1);
	ft_putnbr(num2);
	va_end(args);
	return (0);
}
