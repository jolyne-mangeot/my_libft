/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:16:22 by jmangeot          #+#    #+#             */
/*   Updated: 2025/12/05 15:32:43 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_atoll(const char *nptr)
{
	long long int	result;
	char			sign;

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
