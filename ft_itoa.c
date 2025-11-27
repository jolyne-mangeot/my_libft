/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 23:20:59 by jmangeot          #+#    #+#             */
/*   Updated: 2025/11/21 14:37:28 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	get_int_info(int n, int *int_size)
{
	int	temp_int;

	temp_int = n;
	if (temp_int < 0)
		*int_size = 2;
	while (temp_int >= 10 || temp_int <= -10)
	{
		temp_int /= 10;
		(*int_size)++;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		temp_int;
	int		int_size;

	int_size = 1;
	get_int_info(n, &int_size);
	str = ft_calloc(int_size + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	while (int_size-- && str[int_size] != '-')
	{
		temp_int = n;
		if (temp_int < 0)
			temp_int = (temp_int % 10) * -1;
		str[int_size] = temp_int % 10 + 48;
		n /= 10;
	}
	return (str);
}
