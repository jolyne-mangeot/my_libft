# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/26 22:06:43 by jmangeot          #+#    #+#              #
#    Updated: 2025/12/07 17:49:57 by jmangeot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	// LIBFT VARIABLES //
#*		Classification functions
SRC =		ft_isalpha.c			ft_isdigit.c			ft_isalnum.c	\
			ft_isascii.c			ft_isprint.c			

#*		Variable conversion and modification
SRC +=		ft_itoa.c				ft_ltoa.c				ft_lltoa.c		\
			ft_atoi.c				ft_atol.c				ft_atoll.c		\
			ft_toupper.c			ft_tolower.c			

#*		String and memory iteration and comparison
SRC +=		ft_memcmp.c				ft_memchr.c				ft_strlen.c		\
			ft_strncmp.c			ft_strchr.c				ft_strrchr.c	\
			ft_strnstr.c			ft_striteri.c			

#*		String and memory copy and concatenation
SRC +=		ft_bzero.c				ft_memset.c				ft_memcpy.c		\
			ft_memmove.c			ft_strlcpy.c			ft_strlcat.c

#*		String and memory allocation, duplication and manipulation
SRC +=		ft_calloc.c				ft_strdup.c				ft_substr.c		\
			ft_strtrim.c			ft_split.c				ft_strjoin.c	\
			ft_strmapi.c

#*		Content reading and printing in given file descriptor
SRC +=		ft_putchar_fd.c			ft_putstr_fd.c			ft_putendl_fd.c	\
			ft_putnbr_fd.c			get_next_line.c			

#*		Chained list creation, manipulation and deletion
SRC +=		ft_lstnew.c				ft_lstsize.c			ft_lstlast.c	\
			ft_lstadd_front.c		ft_lstadd_back.c		ft_lstjoin.c	\
			ft_lstiter.c			ft_lstmap.c				ft_lstclear.c	\
			ft_lstdelone.c

#*		Directories
OBJDIR =			obj/

#*		Code and object files
OBJ =				$(SRC:.c=.o)

#*		Flags and name
CFLAGS =			-Wall -Wextra -Werror
NAME =				libft.a
#	// LIBFT VARIABLES //


#	// PRINTF VARIABLES //
#*		Sources
PTFSRC =	ft_printf.c				ft_put_vars.c			ft_put_numbers.c

#*		Directories
PTFDIR =		printf/
OBJPTFDIR =		$(addprefix $(OBJDIR),$(PTFDIR))

#*		Code and object files
PTFSRC :=		$(addprefix $(PTFDIR),$(PTFSRC))
OBJ +=			$(PTFSRC:.c=.o)
#	// PRINTF VARIABLES //


#	// MAKEFILE RULES //
#*		Mandatories
all:			$(NAME)

clean:
	rm -f $(addprefix $(OBJDIR),$(OBJ))
	rm -fd $(OBJPTFDIR) $(OBJDIR)

fclean:			clean
	rm -f $(NAME)

re:			fclean all

#*		Compilation
$(NAME):		$(OBJDIR) $(OBJPTFDIR) $(OBJ)
	ar rc $(NAME) $(addprefix $(OBJDIR),$(OBJ))

%.o:			%.c
	cc $(CFLAGS) -c $^ -o $(addprefix $(OBJDIR),$@)

#*		Directories
$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJPTFDIR):	$(OBJDIR)
	mkdir -p $(OBJPTFDIR)

.PHONY:			all, clean, fclean, re
