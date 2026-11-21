/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printunbr.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: ael-biya <ael-biya@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/20 01:39:30 by ael-biya         #+#    #+#              */
/*   Updated: 2026/11/20 01:41:09 by ael-biya        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printunbr(unsigned long n)
{
	int	i;
	int	tmp;

	i = 0;
	if (n > 9)
	{
		tmp = ft_printunbr(n / 10);
		if (tmp == -1)
			return (-1);
		i += tmp;
	}
	if (ft_printchar(n % 10 + '0') == -1)
		return (-1);
	return (i + 1);
}
