/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:27:03 by jmangeot          #+#    #+#             */
/*   Updated: 2025/11/14 18:06:33 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_power(size_t size)
{
	size_t	result;

	result = 1;
	while (size--)
		result *= 10;
	return (result);
}

static int	get_int_info(int n, int *sign)
{
	int	int_size;

	if (n < 0)
		*sign = 1;
	int_size = 1;
	while (n >= 10 || n <= -10)
	{
		n /= 10;
		int_size++;
	}
	return (int_size);
}

char	*ft_itoa(int n)
{
	char	*string;
	int		int_size;
	int		int_sign;
	size_t	string_size;

	int_sign = 0;
	int_size = get_int_info(n, &int_sign);
	string_size = int_sign + int_size;
	string = (char *)ft_calloc(string_size + 1, 1);
	if (!string)
		return (NULL);
	if (int_sign)
		string++[0] = '-';
	while (int_size)
	{
		int_sign = ((n / get_power(int_size-- - 1)) % 10);
		if (int_sign < 0)
			int_sign *= -1;
		*string++ = int_sign + 48;
	}
	return (string - string_size);
}
