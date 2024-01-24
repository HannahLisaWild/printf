/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:33:33 by hawild            #+#    #+#             */
/*   Updated: 2024/01/24 16:11:06 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_convertions(va_list *args, int *count, char c)
{
	if (c == '%')
		ft_print_percent(count);
	else if (c == 'd' || c == 'i')
		ft_print_num(va_arg(*args, int), count);
	else if (c == 'u')
		ft_print_unsigned(va_arg(*args, unsigned int), count);
	else if (c == 'X' || c == 'x')
		ft_print_hex(va_arg(*args, unsigned long long), count, c);
	else if (c == 's')
		ft_print_str(va_arg(*args, char *), count);
	else if (c == 'c')
		ft_print_char(va_arg(*args, int), count);
	else if (c == 'p')
		ft_print_ptr(va_arg(*args, unsigned long int), count, c);
	return (*count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			ft_type_convertions(&args, &count, format[i]);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			i++;
			count++;
		}
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	char	*test;

// 	test = NULL;
// 	printf("PRINTF:\n");
// 	printf("RETURN VALUE: %d\n\n", printf("%c||%s||%d||%i||%u||%x||%X||%p||%%",
// 			0, test, 0, 0, 42, 42, 0, (void *)0));
// 	printf("FT_PRINTF:\n");
// 	ft_printf("RETURN VALUE: %d\n\n",
// 		ft_printf("%c||%s||%d||%i||%u||%x||%X||%p||%%", 0, test, 0, 0, 42, 42,
// 			0, (void *)0));
// }

// int	main(void)
// {
// 	int	x;
// 	int	*ptr;

// 	// CHARS
// 	ft_printf("my printf: single char: 123456%c89\n", 'K');
// 	printf("og printf: single char: 123456%c89\n", 'K');
// 	ft_printf("my printf: two chars: 123456%c8%c\n", 'K', 'l');
// 	printf("og printf: two chars: 123456%c8%c\n", 'K', 'l');
// 	// STRINGS
// 	ft_printf("my printf: single string: blabla%sblabla\n", "HELLO");
// 	printf("og printf: single string: blabla%sblabla\n", "HELLO");
// 	ft_printf("my printf: two strings: blabla%sblab%sla\n", "HELLO", "123");
// 	printf("og printf: two strings: blabla%sblab%sla\n", "HELLO", "123");
// 	// PERCENT
// 	ft_printf("my printf: print percent: 1234%%1234\n");
// 	printf("og printf: print percent: 1234%%1234\n");
// 	ft_printf("my printf: print two times percent: 1234%%1234%%\n");
// 	printf("og printf: print two times percent: 1234%%1234%%\n");
// 	// NUMBERS
// 	ft_printf("my printf: unsigned (4294967295): %u\n", 4294967295);
// 	printf("og printf: unsigned (4294967295): %lu\n", 4294967295);
// 	ft_printf("my printf: smallest signed (-2147483648): %d\n", -2147483648);
// 	printf("og printf: smallest signed (-2147483648): %ld\n", -2147483648);
// 	ft_printf("my printf: biggest signed (2147483647): %d\n", 2147483647);
// 	printf("og printf: biggest signed (2147483647): %d\n", 2147483647);
// 	ft_printf("my printf: (0): %i\n ", 0);
// 	printf("og printf: (0): %i\n ", 0);
// 	ft_printf("my printf: (-37585): %i\n", -37585);
// 	printf("og printf: (-37585): %i\n", -37585);
// 	// HEX VALUE
// 	ft_printf("my_printf: hex value X (2ED): %X\n", 749);
// 	printf("og printf: hex value X (2ED): %X\n", 749);
// 	ft_printf("my_printf: hex value x (2ed): %x\n", 749);
// 	printf("og printf: hex value x (2ed)): %x\n", 749);
// 	// POINTER
// 	x = 4288;
// 	ptr = &x;
// 	ft_printf("my_printf: pointer value : %p\n", ptr);
// 	printf("og printf: pointer value: %p\n", ptr);
// 	return (0);
// }

// int	main(void)
// {
// 	int	result;
// 	int	my_result;
// 	int	x;
// 	int	*ptr;

// 	x = 42;
// 	ptr = &x;
// 	my_result = ft_printf("my_printf: hex value x (2ed): %x\n", 749);
// 	result = printf("my_printf: hex value x (2ed): %x\n", 749);
// 	ft_printf("my printf result: %d\n", my_result);
// 	printf("og printf result: %d\n", result);
// }
