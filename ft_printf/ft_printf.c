/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziratya <ziratya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:56:26 by gvalogne          #+#    #+#             */
/*   Updated: 2024/02/11 11:28:42 by ziratya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(const char f, va_list args, int *printed_len)
{
	if (f == 'c')
		ft_putchar(va_arg(args, int), printed_len);
	else if (f == 's')
		ft_putstr(va_arg(args, char *), printed_len);
	else if (f == 'p')
		ft_print_ptr(va_arg(args, unsigned long long), printed_len);
	else if (f == 'd' || f == 'i')
		ft_print_nbr(va_arg(args, int), printed_len);
	else if (f == 'u')
		ft_print_unsigned(va_arg(args, unsigned int), printed_len);
	else if (f == 'x')
		ft_print_hex(va_arg(args, unsigned int), printed_len, f);
	else if (f == 'X')
		ft_print_hex(va_arg(args, unsigned int), printed_len, f);
	else if (f == '%')
	{
		write(1, "%", 1);
		(*printed_len)++;
	}
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		printed_len;

	i = 0;
	printed_len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_format(str[i + 1], args, &printed_len);
			i++;
		}
		else
			ft_putchar(str[i], &printed_len);
		if (!str[i])
			break ;
		i++;
	}
	va_end(args);
	return (printed_len);
}
