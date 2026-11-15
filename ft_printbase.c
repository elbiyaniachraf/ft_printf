/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printbase.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: ael-biya <ael-biya@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/15 21:48:11 by ael-biya         #+#    #+#              */
/*   Updated: 2026/11/15 22:48:14 by ael-biya        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_digits(unsigned long nbr, char *base, int len)
{
	int	count;
	int	result;

	count = 0;
	if (nbr >= (unsigned long) len)
	{
		result = print_digits(nbr / len, base, len);
		if (result == -1)
			return (-1);
		count += result;
	}
	result = ft_printchar(base[nbr % len]);
	if (result == -1)
		return (-1);
	return (count + result);
}

int	ft_printbase(unsigned long nbr, char *base)
{
	int	len;

	len = 0;
	while (base[len])
		len++;
	if (len < 2)
		return (-1);
	return (print_digits(nbr, base, len));
}
