/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:59:18 by jmangeot          #+#    #+#             */
/*   Updated: 2025/12/07 14:01:48 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
output using write function an int value with its possible negative sign to a 
file descriptor.
*/
void	ft_putnbr_fd(int n, int fd)
{
	if (n >= 10 || n <= -10)
		ft_putnbr_fd(n / 10, fd);
	else if (n < 0)
		ft_putchar_fd('-', fd);
	if (n < 0)
		n = (n % 10) * -1;
	ft_putchar_fd("0123456789"[n % 10], fd);
}
