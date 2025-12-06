/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 14:52:46 by jmangeot          #+#    #+#             */
/*   Updated: 2025/12/06 18:56:04 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_flag(char c)
{
	char	*flags;

	flags = "cspdiulxX%";
	while (*flags)
		if (*flags++ == c)
			return (1);
	return (0);
}

static int	call_l_prints(const char *flag, va_list args)
{
	if (*flag == 'l' && *(flag + 1) == 'd')
		return (ft_put_lsigned(
				va_arg(args, signed long int), 10, "0123456789"));
	else if (*flag == 'l' && *(flag + 1) == 'u')
		return (ft_put_lunsigned(
				va_arg(args, unsigned long int), 10, "0123456789"));
	else if (*flag == 'l' && *(flag + 1) == 'l' && *(flag + 2) == 'd')
		return (ft_put_llsigned(
				va_arg(args, signed long long int), 10, "0123456789"));
	else if (*flag == 'l' && *(flag + 1) == 'l' && *(flag + 2) == 'u')
		return (ft_put_llunsigned(
				va_arg(args, unsigned long long int), 10, "0123456789"));
	return (ft_put_str("%l"));
}

static int	call_prints(const char *flag, va_list args)
{
	if (*flag == 'c')
		return (ft_put_char(va_arg(args, int)));
	else if (*flag == 's')
		return (ft_put_str(va_arg(args, char *)));
	else if (*flag == 'd' || *flag == 'i')
		return (ft_put_signed(va_arg(args, signed int), 10, "0123456789"));
	else if (*flag == 'u')
		return (ft_put_unsigned(va_arg(args, unsigned int), 10, "0123456789"));
	else if (*flag == 'p')
		return (ft_put_ptr(va_arg(args, unsigned long int)));
	else if (*flag == 'x')
		return (ft_put_unsigned(
				va_arg(args, unsigned int), 16, "0123456789abcdef"));
	else if (*flag == 'X')
		return (ft_put_unsigned(
				va_arg(args, unsigned int), 16, "0123456789ABCDEF"));
	else if (*flag == 'l')
		return (call_l_prints(flag, args));
	return (ft_put_char('%'));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	w_len;
	int		print_size;

	if (!format)
		return (0);
	print_size = 0;
	va_start(args, format);
	while (*format)
	{
		w_len = 0;
		while (*format && !(*format == '%' && is_flag(*(format + 1))))
		{
			format++;
			w_len++;
		}
		print_size += write(1, format - w_len, w_len);
		if (*format++ == '%')
			print_size += call_prints(format++, args);
		else
			format--;
	}
	va_end(args);
	return (print_size);
}
