/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fput_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 18:34:26 by jmangeot          #+#    #+#             */
/*   Updated: 2026/01/23 13:22:32 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

/*
output in the provided file descriptor the signed long int passed in argument 
based on entered digits.
*/
ssize_t	ft_fput_lsigned(int fd, signed long int number,
	signed long int base_size, char *digits)
{
	ssize_t	print_size;

	print_size = 0;
	if (number > base_size - 1 || number < (base_size * -1) + 1)
		print_size
			+= ft_fput_lsigned(fd, number / base_size, base_size, digits);
	else if (number < 0)
		print_size += ft_fput_char(fd, '-');
	if (number < 0)
		number = (number % base_size) * -1;
	return (print_size + ft_fput_char(fd, digits[number % base_size]));
}

/*
output in the provided file descriptor the unsigned long int passed in argument 
based on entered digits.
*/
ssize_t	ft_fput_lunsigned(int fd, unsigned long int number,
	unsigned long int base_size, char *digits)
{
	ssize_t	print_size;

	print_size = 0;
	if (number > base_size - 1)
		print_size
			+= ft_fput_lunsigned(fd, number / base_size, base_size, digits);
	return (print_size + ft_fput_char(fd, digits[number % base_size]));
}

/*
output in the provided file descriptor the signed long long int passed in 
argument based on entered digits.
*/
ssize_t	ft_fput_llsigned(int fd, signed long long int number,
	signed long long int base_size, char *digits)
{
	ssize_t	print_size;

	print_size = 0;
	if (number > base_size - 1 || number < (base_size * -1) + 1)
		print_size
			+= ft_fput_llsigned(fd, number / base_size, base_size, digits);
	else if (number < 0)
		print_size += ft_fput_char(fd, '-');
	if (number < 0)
		number = (number % base_size) * -1;
	return (print_size + ft_fput_char(fd, digits[number % base_size]));
}

/*
output in the provided file descriptor the unsigned long long int passed in 
argument based on entered digits.
*/
ssize_t	ft_fput_llunsigned(int fd, unsigned long long int number,
	unsigned long long int base_size, char *digits)
{
	ssize_t	print_size;

	print_size = 0;
	if (number > base_size - 1)
		print_size
			+= ft_fput_llunsigned(fd, number / base_size, base_size, digits);
	return (print_size + ft_fput_char(fd, digits[number % base_size]));
}
