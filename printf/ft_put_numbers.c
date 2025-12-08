/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 18:34:26 by jmangeot          #+#    #+#             */
/*   Updated: 2025/12/08 15:10:13 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
output in STDOUT channel the signed long int passed in argument based on 
entered digits.
*/
ssize_t	ft_put_lsigned(signed long int number,
	signed long int base_size, char *digits)
{
	ssize_t	print_size;

	print_size = 0;
	if (number > base_size - 1 || number < (base_size * -1) + 1)
		print_size += ft_put_lsigned(number / base_size, base_size, digits);
	else if (number < 0)
		print_size += ft_put_char('-');
	if (number < 0)
		number = (number % base_size) * -1;
	return (print_size + ft_put_char(digits[number % base_size]));
}

/*
output in STDOUT channel the unsigned long int passed in argument based on 
entered digits.
*/
ssize_t	ft_put_lunsigned(unsigned long int number,
	unsigned long int base_size, char *digits)
{
	ssize_t	print_size;

	print_size = 0;
	if (number > base_size - 1)
		print_size += ft_put_lunsigned(number / base_size, base_size, digits);
	return (print_size + ft_put_char(digits[number % base_size]));
}

/*
output in STDOUT channel the signed long long int passed in argument based on 
entered digits.
*/
ssize_t	ft_put_llsigned(signed long long int number,
	signed long long int base_size, char *digits)
{
	ssize_t	print_size;

	print_size = 0;
	if (number > base_size - 1 || number < (base_size * -1) + 1)
		print_size += ft_put_llsigned(number / base_size, base_size, digits);
	else if (number < 0)
		print_size += ft_put_char('-');
	if (number < 0)
		number = (number % base_size) * -1;
	return (print_size + ft_put_char(digits[number % base_size]));
}

/*
output in STDOUT channel the unsigned long long int passed in argument based on 
entered digits.
*/
ssize_t	ft_put_llunsigned(unsigned long long int number,
	unsigned long long int base_size, char *digits)
{
	ssize_t	print_size;

	print_size = 0;
	if (number > base_size - 1)
		print_size += ft_put_llunsigned(number / base_size, base_size, digits);
	return (print_size + ft_put_char(digits[number % base_size]));
}
