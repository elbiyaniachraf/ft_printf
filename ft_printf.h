/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: ael-biya <ael-biya@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/19 14:41:20 by ael-biya         #+#    #+#              */
/*   Updated: 2026/11/25 20:40:54 by ael-biya        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_printchar(int c);
int	ft_printstr(const char *s);
int	ft_printnbr(long n);
int	ft_printunbr(unsigned long n);
int	ft_printhex(unsigned long n, const char *base);
int	ft_printptr(void *p);

#endif
