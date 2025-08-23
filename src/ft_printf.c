#include "ft_printf.h"

int ft_count_tokens(char *str)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			count++;
		if (str[i + 1] == '%')
			i++;
		i++;
	}
	return (count);
}

t_token *ft_parse_conversion(char *str)
{
	t_token *result;
	static char *specifier_keys = "sSpdDioOuUxXcC";
	static t_specifier specifier_values[] = {STRING, STRING, CHAR, CHAR, DECIMAL, DECIMAL};
	int i;
	
	result = malloc(sizeof(*result));
	i = 0;
	while (specifier_keys[i])
	{
		if (str[1] == specifier_keys[i])
		{
			result->specifier = specifier_values[i];
			break ;
		}
		i++;
	}
	return (result);
}

t_token **ft_parse_tokens(char *str)
{
	t_token **result;
	int count;
	int i;
	int j;

	count = count_tokens(str);
	result = malloc(sizeof(*result) * (count + 1));
	i = 0;
	j = 0;
	while (i < count)
	{
		while (str[j] && str[j] != '%')
		{
			j++;
		}
		if (j > 0)
		{
			result[i] = ft_parse_conversion(str + i);
			str[i + j] = '\0';
		}
		i++;
	}
	result
}

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
