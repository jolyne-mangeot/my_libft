/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 20:46:47 by jmangeot          #+#    #+#             */
/*   Updated: 2026/01/23 13:30:26 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FPRINTF_H
# define FT_FPRINTF_H
# include <stdarg.h>
# include <unistd.h>

//*			Module callable function

ssize_t	ft_fprintf(int fd, const char *format, ...);

//*			Variables printing

ssize_t	ft_fput_char(int fd, char c);
ssize_t	ft_fput_str(int fd, char *s);
ssize_t	ft_fput_ptr(int fd, unsigned long int ptr);
ssize_t	ft_fput_signed(int fd, signed int number,
			signed int base_size, char *digits);
ssize_t	ft_fput_unsigned(int fd, unsigned int number,
			unsigned int base_size, char *digits);
ssize_t	ft_fput_lsigned(int fd, signed long int number,
			signed long int base_size, char *digits);
ssize_t	ft_fput_lunsigned(int fd, unsigned long int number,
			unsigned long int base_size, char *digits);
ssize_t	ft_fput_llsigned(int fd, signed long long int number,
			signed long long int base_size, char *digits);
ssize_t	ft_fput_llunsigned(int fd, unsigned long long int number,
			unsigned long long int base_size, char *digits);

#endif
