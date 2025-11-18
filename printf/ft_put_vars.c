/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_vars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:40:04 by jmangeot          #+#    #+#             */
/*   Updated: 2025/11/18 23:34:14 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_put_str(char *s)
{
	size_t	len;

	if (!s)
		return (write(1, "(null)", 6));
	len = 0;
	while (s[len])
		len++;
	return (write(1, s, len));
}

int	ft_put_ptr(unsigned long int ptr)
{
	if (!ptr)
		return (write(1, "(nil)", 5));
	return (write(1, "0x", 2)
		+ ft_put_unsigned(ptr, 16, "0123456789abcdef"));
}

int	ft_put_signed(signed long int number,
				signed long int base, char *digits)
{
	int	print_size;

	print_size = 0;
	if (number > base - 1 || number < (base * -1) + 1)
		print_size += ft_put_signed(number / base, base, digits);
	else if (number < 0)
		print_size = ft_put_char('-');
	if (number < 0)
		number = (number % base) * -1;
	return (print_size + write(1, &digits[number % base], 1));
}

int	ft_put_unsigned(unsigned long int number,
					unsigned long int base, char *digits)
{
	int	print_size;

	print_size = 0;
	if (number > base - 1)
		print_size += ft_put_unsigned(number / base, base, digits);
	return (print_size + write(1, &digits[number % base], 1));
}
