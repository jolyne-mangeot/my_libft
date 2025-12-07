/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 10:35:06 by jmangeot          #+#    #+#             */
/*   Updated: 2025/12/07 13:52:45 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
check if argument is any printable character (32 to 126) and returns a boolean 
value.
*/
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
