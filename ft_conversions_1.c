/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:10:12 by hawild            #+#    #+#             */
/*   Updated: 2024/01/25 17:37:15 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c, int *count)
{
	write(1, &c, 1);
	(*count)++;
	return (*count);
}

int	ft_print_percent(int *count)
{
	write(1, "%", 1);
	(*count)++;
	return (*count);
}

int	ft_print_str(char *str, int *count)
{
	int	index;

	index = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		(*count) += 6;
		return (*count);
	}
	while (str[index] != '\0')
	{
		write(1, &str[index], 1);
		index++;
		(*count)++;
	}
	return (*count);
}

int	ft_print_num(int n, int *count)
{
	char	*num_str;
	int		index;

	index = 0;
	num_str = ft_itoa(n);
	if (!num_str)
		
	while (num_str[index] != '\0')
	{
		write(1, &num_str[index], 1);
		(*count)++;
		index++;
	}
	free(num_str);
	return (*count);
}

int	ft_print_unsigned(unsigned int u, int *count)
{
	if (u >= 10)
		ft_print_unsigned(u / 10, count);
	ft_print_char(u % 10 + '0', count);
	return (*count);
}
