*This project has been created as part of the 42 curriculum by weitwang.*

# Libft

## Description

Libft is my first C library.
The goal of this project is to create a collection of useful C functions and gain a better understanding of how commonly used library functions work internally.
The project works with character, string, memory, function pointers, structures, and linked lists.
The result is a static library called `libft.a`, which can be reused in future C projects.

## Library Content

### Part 1 — Libc Functions
Part 1 consists mainly of reimplementations of commonly used libc functions.

#### Character Checks and Conversions

- `ft_isalpha` — checks whether a character is alphabetic. 
- `ft_isdigit` — checks whether a character is a decimal digit.
- `ft_isalnum` — checks whether a character is a letter or a number.
- `ft_isascii` — checks whether an int lies within the ASCII character set.
- `ft_isprint` — checks whether a character is printable.
- `ft_toupper` — converts a lowercase letter to uppercase.
- `ft_tolower` — converts an uppercase letter to lowercase.


#### String Functions
- `ft_strlen` — returns the length of a string.
- `ft_strchr` — finds the first occurrence of a character in a string.
- `ft_strrchr` — finds the last occurrence of a character in a string.
- `ft_strncmp` — compares the first `n` characters of two strings and returns a negative, zero, or positive value (`- / 0 / +`).
- `ft_strlcpy` — copies a string into a limited-size buffer, and returns the length of `src`.
- `ft_strlcat` — adds `src` to the end of `dst` with a size limit, and returns the total length.
- `ft_strnstr` — searches for a substring within a limited length, and returns a pointer to its position.
- `ft_atoi` — converts a string representation of an integer to an `int`. 

#### Memory Functions

- `ft_memset` — fills memory with a byte value.
- `ft_bzero` — fills memory with zero bytes.
- `ft_memcpy` — copies bytes from one memory area to another. 
- `ft_memmove` — copies bytes, handling overlapping source and destination correctly.
- `ft_memchr` — searches for a byte in memory.
- `ft_memcmp` — compares two memory areas.


#### Memory Allocation

- `ft_calloc` — allocates memory and initializes it to zero.
- `ft_strdup` — creates a dynamically allocated copy of a string.

### Part 2 — Additional Functions
Part 2 introduces additional functions for creating and manipulating strings, converting values, applying functions through function pointers, and writing data to file descriptors.

- `ft_substr` — creates a substring from a string.
- `ft_strjoin` — joins two strings into a newly allocated string.
- `ft_strtrim` — removes specified characters from both ends of a string.
- `ft_split` — splits a string using a delimiter.
- `ft_itoa` — converts an integer into a string.
- `ft_strmapi` — creates a new string by applying a function to every character.
- `ft_striteri` — applies a function directly to each character of a string.
- `ft_putchar_fd` — writes a character to a file descriptor.
- `ft_putstr_fd` — writes a string to a file descriptor.
- `ft_putendl_fd` — writes a string followed by a newline.
- `ft_putnbr_fd` — writes an integer to a file descriptor.


### Part 3 — Linked Lists

Part 3 introduces singly linked lists using the following structure:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

#### Linked List Functions

- `ft_lstnew` — creates a new list node.
- `ft_lstadd_front` — adds a node to the beginning of a list.
- `ft_lstsize` — counts the number of nodes.
- `ft_lstlast` — returns the last node.
- `ft_lstadd_back` — adds a node to the end of a list.
- `ft_lstdelone` — deletes one node using a provided deletion function.
- `ft_lstclear` — deletes and frees an entire list.
- `ft_lstiter` — applies a function to the content of every node.
- `ft_lstmap` — creates a new list by applying a function to every node's content.

## Instructions

### Compilation

Compile the library using:

```bash
make
```

This creates:
```text
libft.a
```

The source files are compiled using:
```bash
cc -Wall -Wextra -Werror
```

### Makefile Rules
```bash
make
make all
make clean
make fclean
make re
```

- `make` / `make all` — compile the library.
- `make clean` — remove `.o` object files.
- `make fclean` — remove `.o` object files and `libft.a`.
- `make re` — rebuild the entire library.


## Using Libft

Include the header: `#include "libft.h"`

Example:
```c
#include "libft.h"

int	main(void)
{
	ft_putstr_fd("Hello!\n", 1);
	return (0);
}
```

Compile the program with `libft.a`:
```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o program
```

Then run: 
```bash
./program
```


## What I Learned

I learned:

- pointers;
- memory and byte-level operations;
- strings and null termination;
- dynamic memory allocation with `malloc` and `free`;
- memory leaks and allocation failure handling;
- file descriptors and `write`;
- function pointers;
- structures;
- linked lists;
- static libraries;
- Makefiles and compilation.

## Resources

The following resources were used during the project:

- The Libft project subject.
- Manual pages available through the `man` command.
- C language documentation and reference materials.
- Compiler error messages.
- Norminette output.
- Books and other learning materials related to C programming.

## AI Usage

AI tools were used to support learning and debugging, mainly to explain C concepts, clarify errors, discuss edge cases, and review my own implementations.
All suggestions were reviewed and understood before use.
