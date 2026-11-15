/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: ael-biya <ael-biya@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/13 11:23:44 by ael-biya         #+#    #+#              */
/*   Updated: 2026/11/15 21:52:16 by ael-biya        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(char c, va_list *args)
{
	if (c == 'c')
		return (ft_printchar(va_arg(*args, int)));
	else if (c == 's')
		return (ft_printstr(va_arg(*args, char *)));
	else if (c == 'p')
		return (ft_printptr(va_arg(*args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_printnbr(va_arg(*args, int)));
	else if (c == 'u')
		return (ft_printbase(va_arg(*args, unsigned int), "0123456789"));
	else if (c == 'x')
		return (ft_printbase(va_arg(*args, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_printbase(va_arg(*args, unsigned int), "0123456789ABCDEF"));
	else if (c == '%')
		return (ft_printchar('%'));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		result;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			result = print_format(format[i], &args);
		}
		else if (format[i] == '%')
			result = -1;
		else
			result = ft_printchar(format[i]);
		if (result == -1)
			return (va_end(args), -1);
		count += result;
		i++;
	}
	va_end(args);
	return (count);
}
