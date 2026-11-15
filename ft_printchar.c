/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printchar.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: ael-biya <ael-biya@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/15 21:31:14 by ael-biya         #+#    #+#              */
/*   Updated: 2026/11/15 22:48:29 by ael-biya        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	unsigned char	ch;

	ch = (unsigned char) c;
	if (write(1, &ch, 1) == -1)
		return (-1);
	return (1);
}
