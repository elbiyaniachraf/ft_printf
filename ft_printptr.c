/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printptr.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: ael-biya <ael-biya@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/15 21:49:56 by ael-biya         #+#    #+#              */
/*   Updated: 2026/11/15 21:52:23 by ael-biya        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr(void *ptr)
{
	int	count;

	if (!ptr)
		return (ft_printstr("(nil)"));
	count = ft_printstr("0x");
	if (count == -1)
		return (-1);
	return (count + ft_printbase((unsigned long) ptr, "0123456789abcdef"));
}
