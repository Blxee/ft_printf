/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blxee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:12:18 by blxee             #+#    #+#             */
/*   Updated: 2025/09/06 16:22:34 by blxee            ###   ########.fr       */
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

typedef enum e_align {
	RIGHT,
	LEFT,
	CENTER,
}	t_align;

typedef struct s_token {
	char		*str;
	t_specifier	specifier;
	t_length	length;
	int			pad_len;
	char		pad_char;
	t_align		align;
}	t_token;

int ft_count_tokens(char *str);
t_token *ft_parse_tokens(char *str);
int ft_printf(char *format, ...);

#endif
