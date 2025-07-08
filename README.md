# ft_printf

A custom implementation of the standard C `printf` function, created as part of the 42 curriculum. This project involves recreating the functionality of `printf` to format and print data to the standard output.

---

## 📌 Subject Summary

- Reimplement the `printf` function to handle various format specifiers.
- Support conversion specifiers such as `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`.
- Handle flags, width, precision, and length modifiers.
- Manage variable argument lists using `stdarg.h`.
- Write a fully functioning formatted output function without using the standard `printf`.

🧠 Learning Outcomes

    Mastery of variadic functions and stdarg macros

    Deep understanding of format parsing

    Working with different data types and conversions

    Memory management and buffer handling in C

    Implementing a widely used C standard library function from scratch
    
---

## 📦 How to Compile

Use the provided Makefile to compile the project:

```bash
make

🚀 Usage

Include the libftprintf.a library in your project and use the function as you would with the standard printf.

Example:

#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s! Number: %d\n", "world", 42);
    return 0;
}

📚 Supported Format Specifiers

    %c — print a single character

    %s — print a string

    %p — print a pointer address

    %d, %i — print a signed integer

    %u — print an unsigned integer

    %x, %X — print a number in hexadecimal (lowercase and uppercase)

    %% — print a percent sign
