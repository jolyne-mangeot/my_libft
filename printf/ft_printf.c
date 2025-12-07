/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 14:52:46 by jmangeot          #+#    #+#             */
/*   Updated: 2025/12/07 18:52:32 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_flag(const char *c)
{
	char	*flags;

	flags = "cspdiuxX%";
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

static ssize_t	call_l_prints(const char *flag, va_list args,
	ssize_t *print_size)
{
	flag++;
	if (*flag == 'd' || *flag == 'u')
	{
		if (*flag == 'd')
			ft_put_lsigned(va_arg(args, signed long int), 10,
				"0123456789", print_size);
		else if (*flag == 'u')
			ft_put_lunsigned(va_arg(args, unsigned long int), 10,
				"0123456789", print_size);
		return (2);
	}
	flag++;
	if (*flag == 'd')
		ft_put_llsigned(va_arg(args, signed long long int), 10,
			"0123456789", print_size);
	else if (*flag == 'u')
		ft_put_llunsigned(va_arg(args, unsigned long long int), 10,
			"0123456789", print_size);
	return (3);
}

static ssize_t	call_prints(const char *flag, va_list args, ssize_t *print_size)
{
	if (*flag == 'c')
		ft_put_char(va_arg(args, int), print_size);
	else if (*flag == 's')
		ft_put_str(va_arg(args, char *), print_size);
	else if (*flag == 'p')
		ft_put_ptr(va_arg(args, unsigned long int), print_size);
	else if (*flag == 'd' || *flag == 'i')
		ft_put_signed(va_arg(args, signed int), 10,
			"0123456789", print_size);
	else if (*flag == 'u')
		ft_put_unsigned(va_arg(args, unsigned int), 10,
			"0123456789", print_size);
	else if (*flag == 'x')
		ft_put_unsigned(va_arg(args, unsigned int), 16,
			"0123456789abcdef", print_size);
	else if (*flag == 'X')
		ft_put_unsigned(va_arg(args, unsigned int), 16,
			"0123456789ABCDEF", print_size);
	else if (*flag == 'l')
		return (call_l_prints(flag, args, print_size));
	return (1);
}

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
		while (*format && !(*format == '%' && is_flag(format + 1)))
		{
			format++;
			w_len++;
		}
		print_size += write(1, format - w_len, w_len);
		if (*format++ == '%')
			format += call_prints(format, args, &print_size);
		else
			format--;
	}
	va_end(args);
	return (print_size);
}
