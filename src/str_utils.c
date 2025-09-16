#include "ft_printf.h"

t_string *ft_str_create(void)
{
	t_string *result;

	result = mem_alloc(sizeof(t_string));
	if (result == NULL)
		return (NULL);
	*result = (t_string){.capacity = STRING_INIT_CAPACITY, .length = 0};
	result->str = mem_alloc(result->capacity);
	if (result->str == NULL)
	{
		mem_free(result);
		return (NULL);
	}
	return (result);
}

void ft_str_extend(t_string *const buf, const char *const str, const int n)
{
	char *new_buf;
	int i;
	int j;

	i = 0;
	while ((n == -1 || i < n) && str[i])
	{
		if (buf->capacity - 1 <= buf->length)
		{
			buf->capacity *= 2;
			new_buf = mem_alloc(buf->capacity);
			j = 0;
			while (j < buf->length)
			{
				new_buf[j] = buf->str[j];
				j++;
			}
			mem_free(buf->str);
			buf->str = new_buf;
		}
		buf->str[buf->length++] = str[i++];
	}
	buf->str[buf->length] = '\0';
}

void ft_str_add_char(t_string *const buf, t_format *format, va_list *list)
{
	(void)format;
	ft_str_extend(buf, &(char){va_arg(*list, int)}, -1);
}

void ft_str_add_str(t_string *const buf, t_format *format, va_list *list)
{
	(void)format;
	ft_str_extend(buf, va_arg(*list, char *), -1);
}

void ft_str_free(t_string **buf)
{
	mem_free((*buf)->str);
	mem_free(*buf);
	*buf = NULL;
}

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

char *ft_itoa_base(unsigned long long nbr, int is_positive, unsigned int base, int upper)
{
	char *buf;

	buf = mem_alloc(34);

	(void)base;
	(void)upper;
	if (is_positive)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	return buf;
}
