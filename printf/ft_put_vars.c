/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_vars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 17:40:04 by jmangeot          #+#    #+#             */
/*   Updated: 2025/12/07 18:51:55 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_char(char c, ssize_t *print_size)
{
	*print_size += write(1, &c, 1);
}

void	ft_put_str(char *s, ssize_t *print_size)
{
	size_t	len;

	if (!s)
	{
		*print_size += write(1, "(null)", 6);
		return ;
	}
	len = 0;
	while (s[len])
		len++;
	*print_size += write(1, s, len);
}

void	ft_put_ptr(unsigned long int ptr, ssize_t *print_size)
{
	if (!ptr)
	{
		ft_put_str("(nil)", print_size);
		return ;
	}
	ft_put_str("0x", print_size);
	ft_put_lunsigned(ptr, 16, "0123456789abcdef", print_size);
}

void	ft_put_signed(signed int number, signed int base,
	char *digits, ssize_t *print_size)
{
	if (number > base - 1 || number < (base * -1) + 1)
		ft_put_signed(number / base, base, digits, print_size);
	else if (number < 0)
		ft_put_char('-', print_size);
	if (number < 0)
		number = (number % base) * -1;
	ft_put_char(digits[number % base], print_size);
}

void	ft_put_unsigned(unsigned int number, unsigned int base,
	char *digits, ssize_t *print_size)
{
	if (number > base - 1)
		ft_put_unsigned(number / base, base, digits, print_size);
	ft_put_char(digits[number % base], print_size);
}
