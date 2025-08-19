#include "ft_printf.h"

int ft_printf(char *format, ...)
{
	va_list args;

	va_start(args, format);
	va_arg(args, char);
	ft_putstr(format);
	va_end(args);
	return (0);
}
