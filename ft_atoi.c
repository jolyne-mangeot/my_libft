/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:50:44 by jmangeot          #+#    #+#             */
/*   Updated: 2025/11/14 16:15:06 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		result;
	char	sign;

	while (*nptr && (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13)))
		nptr++;
	sign = 0;
	if (*nptr == '+' || *nptr == '-')
		sign = *nptr++;
	result = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result += *(nptr++) - 48;
		if (ft_isdigit(*nptr))
			result *= 10;
	}
	if (sign == '-')
		result *= -1;
	return (result);
}
