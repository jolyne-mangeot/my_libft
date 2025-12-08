/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_vars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:40:04 by jmangeot          #+#    #+#             */
/*   Updated: 2025/12/08 15:47:35 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
output in STDOUT channel the character passed in argument.
*/
ssize_t	ft_put_char(char c)
{
	return(write(STDOUT_FILENO, &c, 1));
}

/*
output in STDOUT channel the string of characters passed in argument.
*/
ssize_t	ft_put_str(char *s)
{
	size_t	len;

	if (!s)
	{
		return(write(STDOUT_FILENO, "(null)", 6));
	}
	len = 0;
	while (s[len])
		len++;
	return(write(STDOUT_FILENO, s, len));
}

/*
output in STDOUT channel the pointer passed in argument, in format 
"0xhexadecimal".
*/
ssize_t	ft_put_ptr(unsigned long int ptr)
{
	if (!ptr)
	{
		return (ft_put_str("(nil)"));
	}
	return (ft_put_str("0x") + ft_put_lunsigned(ptr, 16, "0123456789abcdef"));
}

/*
output in STDOUT channel the signed int passed in argument based on entered 
digits.
*/
ssize_t	ft_put_signed(signed int number, signed int base_size,
	char *digits)
{
	ssize_t	print_size;

	print_size = 0;
	if (number > base_size - 1 || number < (base_size * -1) + 1)
		print_size += ft_put_signed(number / base_size, base_size, digits);
	else if (number < 0)
		print_size += ft_put_char('-');
	if (number < 0)
		number = (number % base_size) * -1;
	return (print_size + ft_put_char(digits[number % base_size]));
}

/*
output in STDOUT channel the unsigned int passed in argument based on entered 
digits.
*/
ssize_t	ft_put_unsigned(unsigned int number, unsigned int base_size,
	char *digits)
{
	ssize_t	print_size;

	print_size = 0;
	if (number > base_size - 1)
		print_size += ft_put_unsigned(number / base_size, base_size, digits);
	return (print_size + ft_put_char(digits[number % base_size]));
}
