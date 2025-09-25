/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blxee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:12:18 by blxee             #+#    #+#             */
/*   Updated: 2025/09/19 18:23:43 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#include "str_utils.h"
#include "mem_tracker.h"

typedef enum e_specifier {
	STRING,
	CHAR,
	DECIMAL = 10,
	HEXADECIMAL = 16,
	OCTAL = 8,
	BINARY = 2,
	FLOAT,
}	t_specifier;

typedef enum e_length {
	BYTE,
	UNSIGNED_BYTE,
	SHORT,
	UNSIGNED_SHORT,
	INT,
	UNSIGNED_INT,
	LONG,
	UNSIGNED_LONG,
	LONG_LONG,
	UNSIGNED_LONG_LONG,
}	t_length;

typedef enum e_falg {
	MINUS = '-',
	PLUS  = '+',
	ZERO  = '0',
	SPACE = ' ',
	HASH  = '#',
}	t_flag;

typedef struct s_format {
	t_flag			flags[32];
	unsigned int	width;
	unsigned int	precision;
	t_length		length;
	t_specifier		specifier;
}	t_format;

int ft_print_format(t_string *const buffer, const char *const format, va_list *const args);
int ft_printf(char *format, ...);

#endif
