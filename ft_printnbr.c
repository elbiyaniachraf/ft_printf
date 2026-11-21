/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printnbr.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: ael-biya <ael-biya@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/19 14:05:31 by ael-biya         #+#    #+#              */
/*   Updated: 2026/11/19 14:42:58 by ael-biya        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(long n)
{
	int	i;
	int	tmp;

	i = 0;
	if (n < 0)
	{
		if (ft_printchar('-') == -1)
			return (-1);
		i++;
		n = -n;
	}
	if (n > 9)
	{
		tmp = ft_printnbr(n / 10);
		if (tmp == -1)
			return (-1);
		i += tmp;
	}
	if (ft_printchar(n % 10 + '0') == -1)
		return (-1);
	return (i + 1);
}
