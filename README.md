*This project has been created as part of the 42 curriculum by ael-biya.*

# ft_printf

## Description

**ft_printf** is a recode of the C function `printf()`. The goal of the project is to learn how to write a **variadic function**, a function that accepts a variable number of arguments.

The project produces a static library, `libftprintf.a`, which contains the function:

```c
int ft_printf(const char *format, ...);
```

It prints the formatted text on the standard output and returns the number of characters printed, or `-1` if an error occurs (for example when `write` fails).

### Handled conversions

| Conversion | Prints |
|---|---|
| `%c` | a single character |
| `%s` | a string (`(null)` if the pointer is NULL) |
| `%p` | a pointer in hexadecimal (`(nil)` if the pointer is NULL) |
| `%d` | a decimal (base 10) number |
| `%i` | an integer in base 10 |
| `%u` | an unsigned decimal (base 10) number |
| `%x` | a number in hexadecimal, lowercase |
| `%X` | a number in hexadecimal, uppercase |
| `%%` | a percent sign |

As required by the subject, the buffer management of the original `printf()` is **not** implemented: every character is written directly with `write`.

### Project structure

| File | Role |
|---|---|
| `ft_printf.h` | header: includes and prototypes |
| `ft_printf.c` | `ft_printf()` and `ft_format()` (chooses the right function for each conversion) |
| `ft_printchar.c` | prints one character |
| `ft_printstr.c` | prints a string |
| `ft_printnbr.c` | prints a signed number (`%d`, `%i`) |
| `ft_printunbr.c` | prints an unsigned number (`%u`) |
| `ft_printhex.c` | prints a number in hexadecimal (`%x`, `%X`) |
| `ft_printptr.c` | prints a pointer (`%p`) |
| `Makefile` | builds `libftprintf.a` |

## Instructions

### Compilation

The library is compiled with `cc` and the flags `-Wall -Wextra -Werror`, and created with `ar`.

```
make        # builds libftprintf.a at the root of the repository
make clean  # removes the object files
make fclean # removes the object files and libftprintf.a
make re     # fclean, then all
```

### Usage

Include the header in your code:

```c
#include "ft_printf.h"

int main(void)
{
	int	count;

	count = ft_printf("Hello %s, you are %d years old\n", "42", 42);
	ft_printf("%d characters were printed\n", count);
	return (0);
}
```

Compile your program with the library:

```
cc main.c libftprintf.a -o test
./test
```

## Technical choices and algorithm

### Variable number of arguments

`ft_printf()` uses the macros of `<stdarg.h>`:

- `va_start` starts reading the arguments after `format`.
- `va_arg` gets the next argument, with the type we ask for.
- `va_end` ends the reading.

### Main loop

`ft_printf()` reads the format string one character at a time:

- If the character is not `%`, it is printed directly.
- If it is `%`, the next character is given to `ft_format()`, which calls the right function for the conversion (`c`, `s`, `d`, `i`, `u`, `x`, `X`, `p` or `%`).

The `va_list` is passed **by pointer** (`va_list *`) to `ft_format()`, so that when `va_arg` is called there, the main function continues with the next argument.

### Counting and error handling

Every print function returns the number of characters it wrote, or `-1` if `write` failed. `ft_printf()` adds these values to a counter. As soon as one of them is `-1`, the loop stops and `ft_printf()` returns `-1`. This is why the return value of every `write` is checked.

### Printing numbers with recursion

To print a number, we need its digits from left to right, but the operations `n % 10` and `n / 10` give the digits from right to left. The solution is **recursion**:

1. If the number has more than one digit, call the function on `n / 10` first (this prints all the digits on the left).
2. Then print the last digit with `n % 10 + '0'`.

The same idea is used in all the number functions:

- `ft_printnbr` (`%d`, `%i`): if the number is negative, it prints `-` first and makes the number positive. It takes a `long`, so the value `INT_MIN` can be made positive without overflow.
- `ft_printunbr` (`%u`): same algorithm, with an `unsigned long`, and no sign.
- `ft_printhex` (`%x`, `%X`): same algorithm with `n / 16` and `n % 16`. The digit is taken from a **base string** given as a parameter (`"0123456789abcdef"` or `"0123456789ABCDEF"`). Using a base string allows one single function for lowercase and uppercase.

### Pointers

`ft_printptr` (`%p`) converts the pointer to an `unsigned long`, prints `0x`, then prints the address with `ft_printhex` in lowercase. If the pointer is NULL, it prints `(nil)`, like the original `printf()` on Linux.

### Why these choices

- **Recursion** gives short and simple functions, with no array and no memory allocation: the project does not use `malloc`, so there is no memory to free and no leak.
- **One print function per conversion** keeps the code easy to read and to extend with a new conversion.
- **No data structure** is needed: the format string is read with an index, and a counter keeps the number of printed characters.

## Resources

### References

- `man 3 printf`: description of the original function and its conversions
- `man 3 stdarg`: `va_start`, `va_arg`, `va_end`
- `man 2 write`: the system call used to print
- `man ar`: creation of a static library
- GNU Make documentation: https://www.gnu.org/software/make/manual/
- 42 subject of the project: `ft_printf` (version 12.1)

### Use of AI

AI was used as a learning tool during this project:
 
* To understand C concepts and how the original `printf()` works.
* To go deeper into variadic functions (registers, stack, `va_list`, `va_arg`) and understand how `printf()` works.
* To check possible test cases and edge cases.
* To review parts of the code and understand possible errors.

All explanations and suggestions were reviewed to improve my understanding of the functions and their implementation.