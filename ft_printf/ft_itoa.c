/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvalogne <gvalogne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:54:30 by gvalogne          #+#    #+#             */
/*   Updated: 2023/12/05 14:54:56 by gvalogne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_howmany(int n)
{
	int	count;

	count = 0;
	if (count < 0)
		n *= -1;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*numb;
	size_t		i;
	long int	num;
	size_t		count;

	num = n;
	count = ft_howmany(num);
	i = 0;
	if (num < 0 || count == 0)
		count++;
	numb = malloc(sizeof(char) * (count + 1));
	if (!numb)
		return (NULL);
	if (num < 0)
	{
		num *= -1;
		numb[i++] = '-';
	}
	numb[count] = '\0';
	while (count-- > i)
	{
		numb[count] = (num % 10) + '0';
		num /= 10;
	}
	return (numb);
}

// int	main(void)
// {
// 	int	test;

// 	test = 51562;
// 	printf("%s", ft_itoa(test));
// }