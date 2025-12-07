/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:22:50 by jmangeot          #+#    #+#             */
/*   Updated: 2025/12/07 13:57:45 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
apply an input function on every character of a source string, no return value.
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	string_len;

	if (s && f)
	{
		string_len = ft_strlen(s);
		while (string_len--)
			f(string_len, s + string_len);
	}
}
