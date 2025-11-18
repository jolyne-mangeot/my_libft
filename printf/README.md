*This project has been created as part of the 42 curriculum by jmangeot*

## Description

This repository contains files composing an autonomously working *ft_printf* library, based on a simplified version of the standard C library. Buffer limitations were ignored as well as formatting other than writing simple variables. For now, this includes the format flags `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x` and `%X`, for ASCII characters and signed and unsigned numbers in decimal or hexadecimal bases. This is an attempt at recoding a portable library and increasing one's comprehension of the basic C functions.

## Instructions

This library is compilated using the `-Wall -Wextra -Werror` flags, outputting an archive `.a` file.

Every file is situated in the project's root, meaning no directory or hierarchy needs to be handled other than keeping the library together.

A Makefile is included along a header file making compilation as simple as make or make all. Other necessary make rules namely `$(NAME)` `clean` `fclean` and `re` are included. This printf library can be added and used in its own directory in other projects by calling its Makefile within a dedicated rule such as below :

```Makefile
$(NAME): $(OBJ) libftprintf.a
	$(CC) $(CFLAGS) $(OBJ) -Lftprintf -lftprintf -o $(NAME)

libftprintf.a:
	cd ftprintf && make
```

## Project's structure

This ft_printf project is divided between 4 files : `ft_printf.c`, `ft_printf.h`, `ft_put_vars.c` and a `Makefile`. While the header and Makefile's purpose are typical, functions are naturally divided between the other 2 C files.

#### ft_printf.c

Contains 3 functions for the main processing of the to-be-formatted string, writing characters out of flags and detecting said flags to call variable-printing functions.

#### ft_put_vars.c

Contains 5 functions for putting out different types of variables. `ft_put_char`, `ft_put_str` and `ft_put_ptr` handle variables according to their names, while `ft_put_signed` and `ft_put_unsigned`, which also take as argument an `int base` and a `char *digits`, put out numeric values based on those informations.

The low amount of functions didn't call for a complex project structure, though it was thought to group the 'put' functions in a dedicated folder, before they were reduced in number.

## Ressources

No AI was used in the making of this project.

Instructions on functions' behavior came from the project's subject, internet researches and forums (StackOverflow mainly) and peer-learning.

Programs used to test functions can be found below.

- [printfTester by Tripouille](https://github.com/Tripouille/printfTester)

Knowledge on the arg library came from websites listed below.

- [Tutorialspoint on macro va_start](https://www.tutorialspoint.com/c_standard_library/c_macro_va_start.htm)
