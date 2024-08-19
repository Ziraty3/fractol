/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvalogne <gvalogne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:18:57 by gvalogne          #+#    #+#             */
/*   Updated: 2023/12/07 14:51:06 by gvalogne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <inttypes.h>
# include <stdlib.h>
# include <stdio.h>

void	ft_print_nbr(int nbr, int *printed_len);
void	ft_print_unsigned(unsigned int n, int *printed_len);
void	ft_putchar(char c, int *printed_len);
void	ft_putstr(char *s, int *printed_len);
void	ft_print_ptr(long long num, int *printed_len);
void	ft_print_hex(unsigned long num, int *printed_len, char f);
char	*ft_itoa(int n);
int		ft_printf(const char *str, ...);

#endif