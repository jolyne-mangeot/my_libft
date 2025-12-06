/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 18:34:26 by jmangeot          #+#    #+#             */
/*   Updated: 2025/12/06 18:38:53 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_lsigned(signed long int number,
	signed long int base, char *digits)
{
int	print_size;

print_size = 0;
if (number > base - 1 || number < (base * -1) + 1)
print_size += ft_put_lsigned(number / base, base, digits);
else if (number < 0)
print_size = ft_put_char('-');
if (number < 0)
number = (number % base) * -1;
return (print_size + write(1, &digits[number % base], 1));
}

int	ft_put_lunsigned(unsigned long int number,
		unsigned long int base, char *digits)
{
int	print_size;

print_size = 0;
if (number > base - 1)
print_size += ft_put_lunsigned(number / base, base, digits);
return (print_size + write(1, &digits[number % base], 1));
}

int	ft_put_llsigned(signed long long int number,
	signed long long int base, char *digits)
{
int	print_size;

print_size = 0;
if (number > base - 1 || number < (base * -1) + 1)
print_size += ft_put_llsigned(number / base, base, digits);
else if (number < 0)
print_size = ft_put_char('-');
if (number < 0)
number = (number % base) * -1;
return (print_size + write(1, &digits[number % base], 1));
}

int	ft_put_llunsigned(unsigned long long int number,
		unsigned long long int base, char *digits)
{
int	print_size;

print_size = 0;
if (number > base - 1)
print_size += ft_put_llunsigned(number / base, base, digits);
return (print_size + write(1, &digits[number % base], 1));
}
