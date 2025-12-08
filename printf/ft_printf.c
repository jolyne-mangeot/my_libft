/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 14:52:46 by jmangeot          #+#    #+#             */
/*   Updated: 2025/12/08 15:46:55 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_flag(const char *c)
{
	char	*flags;

	flags = "cspdiuoxXl%";
	while (*flags)
		if (*flags++ == *c)
			return (1);
	if (*c == 'l')
	{
		if (*(c + 1) == 'd' || *(c + 1) == 'u')
			return (1);
		else if (*(c + 1) == 'l')
			if (*(c + 2) == 'd' || *(c + 2) == 'u')
				return (1);
	}
	return (0);
}

static ssize_t	call_ll_prints(const char *flag, va_list args,
	ssize_t *print)
{
	flag++;
	if (*flag == 'd' || *flag == 'i')
		*print += ft_put_llsigned(va_arg(args, signed long long int), 10,
			"0123456789");
	else if (*flag == 'u')
		*print += ft_put_llunsigned(va_arg(args, unsigned long long int), 10,
			"0123456789");
	else if (*flag == 'o')
		*print += ft_put_llunsigned(va_arg(args, unsigned long long int), 8,
			"01234567");
	else if (*flag == 'x')
		*print += ft_put_llunsigned(va_arg(args, unsigned long long int), 16,
			"0123456789abcdef");
	else if (*flag == 'X')
		*print += ft_put_llunsigned(va_arg(args, unsigned long long int), 16,
			"0123456789ABCDEF");
	else
		return (*print += ft_put_char('%'), 2);
	return (3);
}

static ssize_t	call_l_prints(const char *flag, va_list args,
	ssize_t *print)
{
	flag++;
	if (*flag == 'd' || *flag == 'i')
		*print += ft_put_lsigned(va_arg(args, signed long int), 10,
			"0123456789");
	else if (*flag == 'u')
		*print += ft_put_lunsigned(va_arg(args, unsigned long int), 10,
			"0123456789");
	else if (*flag == 'o')
		*print += ft_put_lunsigned(va_arg(args, unsigned long int), 8,
			"01234567");
	else if (*flag == 'x')
		*print += ft_put_lunsigned(va_arg(args, unsigned long int), 16,
			"0123456789abcdef");
	else if (*flag == 'X')
		*print += ft_put_lunsigned(va_arg(args, unsigned long int), 16,
			"0123456789ABCDEF");
	else if (*flag == 'l')
		return (call_ll_prints(flag, args, print));
	else
		return (*print += ft_put_char('%'), 1);
	return (2);
}

static ssize_t	call_prints(const char *flag, va_list args, ssize_t *print)
{
	if (*flag == 'c')
		*print += ft_put_char(va_arg(args, int));
	else if (*flag == '%')
		*print += ft_put_char('%');
	else if (*flag == 's')
		*print += ft_put_str(va_arg(args, char *));
	else if (*flag == 'p')
		*print += ft_put_ptr(va_arg(args, unsigned long int));
	else if (*flag == 'd' || *flag == 'i')
		*print += ft_put_signed(va_arg(args, signed int), 10, "0123456789");
	else if (*flag == 'u')
		*print += ft_put_unsigned(va_arg(args, unsigned int), 10, "0123456789");
	else if (*flag == 'o')
		*print += ft_put_unsigned(va_arg(args, unsigned int), 8, "01234567");
	else if (*flag == 'x')
		*print += ft_put_unsigned(va_arg(args, unsigned int), 16,
			"0123456789abcdef");
	else if (*flag == 'X')
		*print += ft_put_unsigned(va_arg(args, unsigned int), 16,
			"0123456789ABCDEF");
	else if (*flag == 'l')
		return (call_l_prints(flag, args, print));
	else
		*print += ft_put_char('%');
	return (1);
}
/*
output in STDOUT channel formatted arguments following printf behavior as 
declared in stdio.h, does not support error throwing nor numeral or string 
justifying.
*/
ssize_t	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	w_len;
	ssize_t	print_size;

	if (!format)
		return (0);
	print_size = 0;
	va_start(args, format);
	while (*format)
	{
		w_len = 0;
		while (*format && !(*format == '%'))
		{
			format++;
			w_len++;
		}
		print_size += write(STDOUT_FILENO, format - w_len, w_len);
		if (*format++ == '%')
			format += call_prints(format, args, &print_size);
		else
			format--;
	}
	va_end(args);
	return (print_size);
}
