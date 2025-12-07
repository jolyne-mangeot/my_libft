/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:23:11 by jmangeot          #+#    #+#             */
/*   Updated: 2025/12/07 13:51:46 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
check if argument is a digit and returns a boolean value.
*/
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
