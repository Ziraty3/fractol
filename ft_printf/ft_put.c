/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvalogne <gvalogne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:14:11 by gvalogne          #+#    #+#             */
/*   Updated: 2023/12/07 14:13:42 by gvalogne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *printed_len)
{
	(*printed_len)++;
	write (1, &c, 1);
}

void	ft_putstr(char *s, int *printed_len)
{
	unsigned int	i;

	i = 0;
	if (!s)
	{
		ft_putstr("(null)", printed_len);
		return ;
	}
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
	*printed_len += i;
}
