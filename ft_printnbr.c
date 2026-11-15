/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printnbr.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: ael-biya <ael-biya@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/15 21:49:32 by ael-biya         #+#    #+#              */
/*   Updated: 2026/11/15 21:52:21 by ael-biya        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(long nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		if (ft_printchar('-') == -1)
			return (-1);
		count++;
		nbr = -nbr;
	}
	count += ft_printbase((unsigned long) nbr, "0123456789");
	return (count);
}
