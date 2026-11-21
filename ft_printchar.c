/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printchar.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/19 13:57:23 by username         #+#    #+#              */
/*   Updated: 2026/11/21 12:39:29 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	unsigned char	ch;

	ch = (unsigned char) c;
	return (write(1, &ch, 1));
}
