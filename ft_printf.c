/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: ael-biya <ael-biya@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/20 01:44:01 by ael-biya         #+#    #+#              */
/*   Updated: 2026/11/26 09:04:28 by ael-biya        ###   ########.fr        */
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

static int	check_format(char c)
{
	return (c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == 'p' || c == '%');
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
	while (count != -1 && format[i])
	{
		if (format[i] == '%' && check_format(format[i + 1]))
			tmp = ft_format(format[++i], &args);
		else
			tmp = ft_printchar(format[i]);
		if (tmp == -1)
			count = -1;
		else
			count += tmp;
		i++;
	}
	va_end(args);
	return (count);
}
