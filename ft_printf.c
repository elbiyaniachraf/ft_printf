/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/20 01:44:01 by username         #+#    #+#              */
/*   Updated: 2026/11/21 12:38:26 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(char c, va_list *args)
{
	if (c == 'c')
		return (ft_printchar(va_arg(*args, int)));
	else if (c == 's')
		return (ft_printstr(va_arg(*args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_printnbr(va_arg(*args, int)));
	else if (c == 'u')
		return (ft_printunbr(va_arg(*args, unsigned int)));
	else if (c == '%')
		return (ft_printchar(c));
	else if (c == 'x')
		return (ft_printhex(va_arg(*args, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_printhex(va_arg(*args, unsigned int), "0123456789ABCDEF"));
	else if (c == 'p')
		return (ft_printptr(va_arg(*args, void *)));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		tmp;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '\0')
			return (va_end(args), -1);
		if (format[i] == '%')
			tmp = ft_format(format[++i], &args);
		else
			tmp = ft_printchar(format[i]);
		if (tmp == -1)
			return (va_end(args), -1);
		count += tmp;
		i++;
	}
	va_end(args);
	return (count);
}
