/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printhex.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/19 16:43:36 by username         #+#    #+#              */
/*   Updated: 2026/11/21 13:57:21 by username        ###   ########.fr        */
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
