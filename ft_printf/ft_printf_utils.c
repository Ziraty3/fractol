/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziratya <ziratya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:19:00 by gvalogne          #+#    #+#             */
/*   Updated: 2024/05/23 15:56:20 by ziratya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_nbr(int nbr, int *printed_len)
{
	char	*result;

	result = ft_itoa(nbr);
	ft_putstr(result, printed_len);
	free(result);
}

void	ft_print_hex(unsigned long num, char f)
{
	char	*base;

	base = "0123456789abcdef";
	if (f == 'X')
		base = "0123456789ABCDEF";
	if (num / 16 != 0)
		ft_print_hex(num / 16, printed_len, f);
	ft_putchar(base[num % 16], printed_len);
}

void	ft_print_ptr(long long num, int *printed_len)
{
	if (num)
	{
		ft_putstr("0x", printed_len);
		ft_print_hex(num, printed_len, 'x');
	}
	else
	{
		ft_putstr("(nil)", printed_len);
	}
}
