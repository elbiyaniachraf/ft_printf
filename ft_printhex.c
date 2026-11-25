/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printhex.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: ael-biya <ael-biya@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/19 16:43:36 by ael-biya         #+#    #+#              */
/*   Updated: 2026/11/25 19:36:51 by ael-biya        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned long n, const char *base)
{
	int	i;
	int	tmp;

	i = 0;
	if (n >= 16)
	{
		tmp = ft_printhex(n / 16, base);
		if (tmp == -1)
			return (-1);
		i += tmp;
	}
	if (ft_printchar(base[n % 16]) == -1)
		return (-1);
	return (i + 1);
}
