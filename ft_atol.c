/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:16:22 by jmangeot          #+#    #+#             */
/*   Updated: 2025/12/03 14:17:19 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atol(const char *nptr)
{
	long int	result;
	char		sign;

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
