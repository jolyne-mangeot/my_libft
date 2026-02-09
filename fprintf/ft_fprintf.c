/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 14:52:46 by jmangeot          #+#    #+#             */
/*   Updated: 2026/02/09 14:38:37 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

static ssize_t	call_ll_fprints(int fd, const char *flag, va_list args,
	ssize_t *print)
{
	flag++;
	if (*flag == 'd' || *flag == 'i')
		*print += ft_fput_llsigned(fd, va_arg(args, signed long long int),
				10, "0123456789");
	else if (*flag == 'u')
		*print += ft_fput_llunsigned(fd, va_arg(args, unsigned long long int),
				10, "0123456789");
	else if (*flag == 'o')
		*print += ft_fput_llunsigned(fd, va_arg(args, unsigned long long int),
				8, "01234567");
	else if (*flag == 'x')
		*print += ft_fput_llunsigned(fd, va_arg(args, unsigned long long int),
				16, "0123456789abcdef");
	else if (*flag == 'X')
		*print += ft_fput_llunsigned(fd, va_arg(args, unsigned long long int),
				16, "0123456789ABCDEF");
	else
		return (*print += ft_fput_char(fd, '%'), 2);
	return (3);
}

static ssize_t	call_l_fprints(int fd, const char *flag, va_list args,
	ssize_t *print)
{
	flag++;
	if (*flag == 'd' || *flag == 'i')
		*print += ft_fput_lsigned(fd, va_arg(args, signed long int), 10,
				"0123456789");
	else if (*flag == 'u')
		*print += ft_fput_lunsigned(fd, va_arg(args, unsigned long int), 10,
				"0123456789");
	else if (*flag == 'o')
		*print += ft_fput_lunsigned(fd, va_arg(args, unsigned long int), 8,
				"01234567");
	else if (*flag == 'x')
		*print += ft_fput_lunsigned(fd, va_arg(args, unsigned long int), 16,
				"0123456789abcdef");
	else if (*flag == 'X')
		*print += ft_fput_lunsigned(fd, va_arg(args, unsigned long int), 16,
				"0123456789ABCDEF");
	else if (*flag == 'l')
		return (call_ll_fprints(fd, flag, args, print));
	else
		return (*print += ft_fput_char(fd, '%'), 1);
	return (2);
}

static ssize_t	call_fprints(int fd, const char *flag,
					va_list args, ssize_t *print)
{
	if (*flag == 'c')
		*print += ft_fput_char(fd, va_arg(args, int));
	else if (*flag == '%')
		*print += ft_fput_char(fd, '%');
	else if (*flag == 's')
		*print += ft_fput_str(fd, va_arg(args, char *));
	else if (*flag == 'p')
		*print += ft_fput_ptr(fd, va_arg(args, unsigned long int));
	else if (*flag == 'd' || *flag == 'i')
		*print += ft_fput_signed(fd, va_arg(args, int), 10, "0123456789");
	else if (*flag == 'u')
		*print += ft_fput_unsigned(fd, va_arg(args, unsigned int), 10,
				"0123456789");
	else if (*flag == 'o')
		*print += ft_fput_unsigned(fd, va_arg(args, unsigned int), 8,
				"01234567");
	else if (*flag == 'x')
		*print += ft_fput_unsigned(fd, va_arg(args, unsigned int), 16,
				"0123456789abcdef");
	else if (*flag == 'X')
		*print += ft_fput_unsigned(fd, va_arg(args, unsigned int), 16,
				"0123456789ABCDEF");
	else if (*flag == 'l')
		return (call_l_fprints(fd, flag, args, print));
	else
		*print += ft_fput_char(fd, '%');
	return (1);
}

/*
output in the provided file descriptor formatted arguments following printf 
behavior as declared in stdio.h, does not support error throwing nor numeral 
or string justifying.
*/
ssize_t	ft_fprintf(int fd, const char *format, ...)
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
		print_size += write(fd, format - w_len, w_len);
		if (*format++ == '%')
			format += call_fprints(fd, format, args, &print_size);
		else
			format--;
	}
	va_end(args);
	return (print_size);
}
