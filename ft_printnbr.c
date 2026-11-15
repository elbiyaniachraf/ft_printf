/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printnbr.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: ael-biya <ael-biya@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/15 21:49:32 by ael-biya         #+#    #+#              */
/*   Updated: 2026/11/15 22:49:25 by ael-biya        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(long nbr)
{
	int	count;
	int	result;

	count = 0;
	if (nbr < 0)
	{
		if (ft_printchar('-') == -1)
			return (-1);
		count++;
		nbr = -nbr;
	}
	result = ft_printbase((unsigned long) nbr, "0123456789");
	if (result == -1)
		return (-1);
	return (count + result);
}
