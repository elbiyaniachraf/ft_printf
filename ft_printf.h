/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/19 14:41:20 by username         #+#    #+#              */
/*   Updated: 2026/11/21 13:57:20 by username        ###   ########.fr        */
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
