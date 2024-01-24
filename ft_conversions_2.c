/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:10:25 by hawild            #+#    #+#             */
/*   Updated: 2024/01/23 14:06:22 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int num, int *count, char c)
{
	if (num >= 16)
	{
		ft_print_hex(num / 16, count, c);
		ft_print_hex(num % 16, count, c);
	}
	else
	{
		if (num < 10)
			ft_print_char(num + '0', count);
		else
		{
			if (c == 'x' || c == 'p')
				ft_print_char(num - 10 + 'a', count);
			else if (c == 'X')
				ft_print_char(num - 10 + 'A', count);
		}
	}
	return (*count);
}

static int	ft_put_ptr(unsigned long int num, int *count, char c)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16, count, c);
		ft_put_ptr(num % 16, count, c);
	}
	else
	{
		if (num < 10)
			ft_print_char(num + '0', count);
		else
			ft_print_char(num - 10 + 'a', count);
	}
	return (*count);
}

int	ft_print_ptr(unsigned long int nbr, int *count, int c)
{
	if (nbr == 0)
		ft_print_str("(nil)", count);
	else
	{
		write(1, "0x", 2);
		(*count) += 2;
		ft_put_ptr(nbr, count, c);
	}
	return (*count);
}
