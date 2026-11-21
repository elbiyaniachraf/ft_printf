/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printptr.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: ael-biya <ael-biya@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/19 16:49:58 by ael-biya         #+#    #+#              */
/*   Updated: 2026/11/19 17:11:07 by ael-biya        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr(void *p)
{
	unsigned long	addr;
	int				i;
	int				tmp;

	addr = (unsigned long) p;
	if (addr == 0)
		return (ft_printstr("(nil)"));
	i = ft_printstr("0x");
	if (i == -1)
		return (-1);
	tmp = ft_printhex(addr, "0123456789abcdef");
	if (tmp == -1)
		return (-1);
	return (i + tmp);
}
