/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 14:34:36 by jmangeot          #+#    #+#             */
/*   Updated: 2026/02/09 14:34:38 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
compare two strings until characters differ, returning the 
difference of value of char1 - char2, otherwise 0.
*/
int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
		if (*s1++ != *s2++)
			return ((unsigned char)*(s1 - 1) - (unsigned char)*(s2 - 1));
	return (0);
}
