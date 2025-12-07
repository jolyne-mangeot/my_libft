*This project has been created as part of the 42 curriculum*

## Description

This repository contains pre-selected functions from the standard C library as an attempt to create our own usable library in the future. It contains functions -namely described under- regarding character classification, string and memory manipulation, duplication and comparison, simple characters terminal printing as well as basic through advanced linked list handling.

## Instructions

Every file is situated in the project's root, meaning no directory or hierarchy needs to be handled other than keeping the library together. A Makefile is included along a header file making compilation as simple as `make` or `make all`. Other necessary make rules namely `$(NAME)` `clean` `fclean` and `re` are included. This libft can be added and used in its own directory in other projects by calling its Makefile within a `libft.a` rule such as below :
```Makefile
$(NAME): $(OBJ) libft.a
    $(CC) $(CFLAGS) $(OBJ) -LLibft -lft -o $(NAME)

libft.a:
    cd libft && make
```

## Detailed list

This library consists of 43 functions that you can find a description of below, classed by purpose and notions.

| Functions name | Description and return type |
| --- | --- |
| | **Classification functions** |
| `ft_isalpha` | check if argument is an alphabetic character and returns a boolean value. |
| `ft_isdigit` | check if argument is a digit and returns a boolean value. |
| `ft_isalnum` | check if argument is an alphanumeric character and returns a boolean value. |
| `ft_isascii` | check if argument is an ASCII character (0 to 127) and returns a boolean value. |
| `ft_isprint` | check if argument is any printable character (32 to 126) and returns a boolean value. |
| | **Variable conversion and modification** |
| `ft_itoa` | return a string created from an int value literally transcribed to ASCII characters, covers all possible int values. |
| `ft_ltoa` | return a string created from a long int value literally transcribed to ASCII characters, covers all possible long int values. |
| `ft_lltoa` | return a string created from a long long int value literally transcribed to ASCII characters, covers all possible long long int values. |
| `ft_atoi` | return an int equivalent of an input string of characters by following set rules, covers all possible int values. |
| `ft_atol` | return a long int equivalent of an input string of characters by following set rules, covers all possible long int values. |
| `ft_atoll` | return a long long int equivalent of an input string of characters by following set rules, covers all possible long long int values. |
| `ft_toupper` | return argument as uppercase if possible, otherwise argument doesn't change. |
| `ft_tolower` | return argument as lowercase if possible, otherwise argument doesn't change. |
| | **String and memory iteration and comparison** |
| `ft_memcmp` | compare two memory areas on an input length until bytes differ, returning the difference of value of byte1 - byte2, otherwise 0. |
| `ft_memchr` | locate and return a pointer to the first occurence of a character in a memory area, otherwise NULL. |
| `ft_strlen` | count and return input string length. |
| `ft_strncmp` | compare two strings on an input length until characters differ, returning the difference of value of char1 - char2, otherwise 0. |
| `ft_strchr` | locate and return a pointer to the first occurence of a character in a string, otherwise NULL. |
| `ft_strrchr` | locate and return a pointer to the last occurence of a character in a string, otherwise NULL. |
| `ft_strnstr` | locate a substring in a string and return its pointer within the source, otherwise NULL. |
| `ft_striteri` | apply an input function on every character of a source string, no return value. |
| | **String and memory copy and concatenation** |
| `ft_bzero` | replace input amount of bytes by zeroes, no return value. |
| `ft_memset` | replace input amount of bytes by argument and returns pointer to result. |
| `ft_memcpy` | copy an input length of memory from a source to a destination, regardless of memory overlap, returns pointer to destination. |
| `ft_memmove` | copy an input length of memory from a source to a destination, making sure memory overlap doesn't duplicate or erase data, returns pointer to destination. |
| `ft_strlcpy` | copy on an input maximum length a string of characters from a source to a destination and returns the amount of concerned bytes. |
| `ft_strlcat` | concatenate a source at the end of a destination, only covering an input maximum length, returns the amount of concerned bytes. |
| | **String and memory allocationm duplication and manipulation** |
| `ft_calloc` | allocate an input length of memory and set all its bytes to 0, returning its pointer. |
| `ft_strdup` | creates a string of characters by duplicating an input source, returning an allocated pointer to the destination. |
| `ft_substr` | return a string of characters copied from a source from an index start and on a maximum input length. |
| `ft_strtrim` | create and return a string consisting of a source trimmed of a set of characters from its beginning and its end. |
| `ft_split` | split a source string into an array of smaller string based on a separator added as argument. |
| `ft_strjoin` | return a string of characters created from the concatenation of two input sources. |
| `ft_strmapi` | create and return a string of characters from the result of an input function applied to every characters of a source string. |
| | **Content reading and printing in given file descriptor** |
| `ft_putchar_fd` | output using write function a single character to a file descriptor. |
| `ft_putstr_fd` | output using write function a string of characters to a file descriptor. |
| `ft_putendl_fd` | output using write function a tring of characters to a file descriptor, followed by a new line. |
| `ft_putnbr_fd` | output using write function an int value with its possible negative sign to a file descriptor. |
| `get_next_line` | read and returns a single line from a fiLe descriptor, either ending with a `\n` or the last character of the file. |
| | **Linked list creation, manipulation and deletion**  |
| `ft_lstnew` | create and return the pointer of a new structure usable as a chained list element. |
| `ft_lstsize` | count the number of elements in a pointed chained list, returning the result. |
| `ft_lstlast` | find and return the pointer of the last element of a pointed chained list. |
| `ft_lstadd_front` | add a chained list element to the front of a pointed source list. |
| `ft_lstadd_back` | add a chained list element to the back of a pointed source list. |
| `ft_lstjoin` | create a table of pointers regrouping all given list's content in an allocated memory area, if second argument is different from 0, also delete list. |
| `ft_lstiter` | apply an input function on every content of a pointed chained list, no return value. |
| `ft_lstmap` | return a chained list created from the result of an input function applied to every content of a source list. |
| `ft_lstdelone` | delete a single pointed to structure's content using a function added as argument and free the node itself. |
| `ft_lstclear` | delete a chained list elements' content and free their allocated memory, no return value. |

## Ressources

No AI was used in the making of this project. Instructions on functions' behavior came from the project's subject, linux' manual and peer-learning. Programs used to test functions can be found below :

- [libftTester by Tripouille](https://github.com/Tripouille/libftTester)
- [Libftest by jtoty](https://github.com/jtoty/Libftest)
- [libfterator by Blaeste](https://github.com/Blaeste/libfterator)
