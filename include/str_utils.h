#ifndef STR_UTILS_H
#define STR_UTILS_H

#include <stdarg.h>

#define STRING_INIT_CAPACITY (128)

typedef struct s_string {
  char  *str;
  int   capacity;
  int   length;
} t_string;

typedef struct s_format t_format;

t_string *ft_str_create(void);
void ft_str_extend(t_string *const buf, const char *const str, const int n);
void ft_str_add_char(t_string *const buf, t_format *format, va_list *list);
void ft_str_add_str(t_string *const buf, t_format *format, va_list *list);
void ft_str_add_nbr_base(t_string *const buf, t_format *format, va_list *list);
void ft_str_add_float(t_string *const buf, t_format *format, va_list *list);
void ft_str_add_scientific_notation(t_string *const buf, t_format *format, va_list *list);
void ft_str_free(t_string **buf);
// char *ft_itoa_base(unsigned long long nbr, int is_positive, unsigned int base, int upper);

void ft_putstr(char *str);

#endif
