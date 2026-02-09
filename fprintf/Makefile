# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/18 17:35:48 by jmangeot          #+#    #+#              #
#    Updated: 2026/01/23 13:31:15 by jmangeot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_fprintf.c ft_fput_vars.c ft_fput_numbers.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror
NAME = libftfprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	cc $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
