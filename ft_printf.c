/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knarman <knarman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:57:00 by knarman           #+#    #+#             */
/*   Updated: 2024/01/29 17:45:32 by knarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

static int	check(va_list arglist, char c)
{
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(arglist, int)));
	else if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(arglist, unsigned int)));
	else if (c == 'x')
		return (ft_puthexadecimal(va_arg(arglist, unsigned int), 'a' - 10));
	else if (c == 'X')
		return (ft_puthexadecimal(va_arg(arglist, unsigned int), 'A' - 10));
	else if (c == 'c')
		return (ft_putchar(va_arg(arglist, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(arglist, char *)));
	else if (c == 'p')
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		return (ft_puthexadecimal(va_arg(arglist, unsigned long long int), 'a'
				- 10) + 2);
	}
	else if (c == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	arglist;
	int		len;
	int		i;
	int		tmp;

	len = 0;
	i = 0;
	va_start(arglist, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			tmp = check(arglist, str[i]);
			if (tmp == -1)
				return (-1);
			len += tmp - 1;
		}
		else if (write(1, &str[i], 1) == -1)
			return (-1);
		i++;
		len++;
	}
	va_end(arglist);
	return (len);
}
