/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 18:34:26 by jmangeot          #+#    #+#             */
/*   Updated: 2025/12/07 18:47:17 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_lsigned(signed long int number, signed long int base,
	char *digits, ssize_t *print_size)
{
	if (number > base - 1 || number < (base * -1) + 1)
		ft_put_lsigned(number / base, base, digits, print_size);
	else if (number < 0)
		ft_put_char('-', print_size);
	if (number < 0)
		number = (number % base) * -1;
	ft_put_char(digits[number % base], print_size);
}

void	ft_put_lunsigned(unsigned long int number, unsigned long int base,
	char *digits, ssize_t *print_size)
{
	if (number > base - 1)
		ft_put_lunsigned(number / base, base, digits, print_size);
	ft_put_char(digits[number % base], print_size);
}

void	ft_put_llsigned(signed long long int number,
	signed long long int base, char *digits, ssize_t *print_size)
{
	if (number > base - 1 || number < (base * -1) + 1)
		ft_put_llsigned(number / base, base, digits, print_size);
	else if (number < 0)
		ft_put_char('-', print_size);
	if (number < 0)
		number = (number % base) * -1;
	ft_put_char(digits[number % base], print_size);
}

void	ft_put_llunsigned(unsigned long long int number,
	unsigned long long int base, char *digits, ssize_t *print_size)
{
	if (number > base - 1)
		ft_put_llunsigned(number / base, base, digits, print_size);
	ft_put_char(digits[number % base], print_size);
}
