# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/26 22:06:43 by jmangeot          #+#    #+#              #
#    Updated: 2025/11/26 22:12:08 by jmangeot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_isalpha.c		ft_isdigit.c	ft_isalnum.c	ft_isascii.c		\
	  ft_isprint.c		ft_strlen.c		ft_memset.c		ft_bzero.c			\
	  ft_memcpy.c		ft_memmove.c	ft_strlcpy.c	ft_strlcat.c		\
	  ft_toupper.c		ft_tolower.c	ft_strchr.c		ft_strrchr.c		\
	  ft_strncmp.c		ft_memchr.c		ft_memcmp.c		ft_strnstr.c		\
	  ft_atoi.c			ft_strdup.c		ft_calloc.c		ft_substr.c			\
	  ft_strtrim.c		ft_itoa.c		ft_strmapi.c	ft_striteri.c		\
	  ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c		\
	  ft_split.c		ft_strjoin.c	ft_lstnew.c		ft_lstadd_front.c	\
	  ft_lstsize.c		ft_lstlast.c	ft_lstdelone.c	ft_lstadd_back.c	\
	  ft_lstclear.c		ft_lstiter.c	ft_lstmap.c

PRINTF_SRC = 			printf/ft_printf.c				printf/ft_put_vars.c

OBJ = $(SRC:.c=.o)
PRINTF_OBJ = $(PRINTF_SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

PRINTFDIR = printf/

all: $(NAME)

$(NAME): $(PRINTF_OBJ) $(OBJ)
	ar rc $(NAME) $(OBJ) $(PRINTF_OBJ)

%.o: %.c
	cc $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJ)
	cd $(PRINTFDIR) && make clean

fclean: clean
	rm -f $(NAME)
	cd $(PRINTFDIR) && make fclean

re: fclean all
