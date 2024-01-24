/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hawild <hawild@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:39:50 by hawild            #+#    #+#             */
/*   Updated: 2024/01/23 14:11:38 by hawild           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_type_convertions(va_list *args, int *count, char c);
int		ft_print_char(int c, int *count);
int		ft_print_percent(int *count);
int		ft_print_str(char *str, int *count);
int		ft_print_num(int n, int *count);
int		ft_print_unsigned(unsigned int u, int *count);
int		ft_print_hex(unsigned int num, int *count, char c);
int		ft_print_ptr(unsigned long int num, int *count, int c);
char	*ft_itoa(int n);

#endif