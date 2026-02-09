/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fput_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:40:04 by jmangeot          #+#    #+#             */
/*   Updated: 2026/01/23 13:22:31 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

/*
output in STDOUT channel the character passed in argument.
*/
ssize_t	ft_fput_char(int fd, char c)
{
	return (write(fd, &c, 1));
}

/*
output in STDOUT channel the string of characters passed in argument.
*/
ssize_t	ft_fput_str(int fd, char *s)
{
	size_t	len;

	if (!s)
	{
		return (write(fd, "(null)", 6));
	}
	len = 0;
	while (s[len])
		len++;
	return (write(fd, s, len));
}

/*
output in STDOUT channel the pointer passed in argument, in format 
"0xhexadecimal".
*/
ssize_t	ft_fput_ptr(int fd, unsigned long int ptr)
{
	if (!ptr)
	{
		return (ft_fput_str(fd, "(nil)"));
	}
	return (ft_fput_str(fd, "0x")
		+ ft_fput_lunsigned(fd, ptr, 16, "0123456789abcdef"));
}

/*
output in STDOUT channel the signed int passed in argument based on entered 
digits.
*/
ssize_t	ft_fput_signed(int fd, signed int number, signed int base_size,
	char *digits)
{
	ssize_t	print_size;

	print_size = 0;
	if (number > base_size - 1 || number < (base_size * -1) + 1)
		print_size += ft_fput_signed(fd, number / base_size, base_size, digits);
	else if (number < 0)
		print_size += ft_fput_char(fd, '-');
	if (number < 0)
		number = (number % base_size) * -1;
	return (print_size + ft_fput_char(fd, digits[number % base_size]));
}

/*
output in STDOUT channel the unsigned int passed in argument based on entered 
digits.
*/
ssize_t	ft_fput_unsigned(int fd, unsigned int number, unsigned int base_size,
	char *digits)
{
	ssize_t	print_size;

	print_size = 0;
	if (number > base_size - 1)
		print_size
			+= ft_fput_unsigned(fd, number / base_size, base_size, digits);
	return (print_size + ft_fput_char(fd, digits[number % base_size]));
}
