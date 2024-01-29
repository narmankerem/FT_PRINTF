/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knarman <knarman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:57:55 by knarman           #+#    #+#             */
/*   Updated: 2024/01/29 15:54:43 by knarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr(int nb)
{
	long	n;
	int		len;
	int		tmp;

	len = 0;
	n = nb;
	if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		n = -n;
		len++;
	}
	if (n > 9)
	{
		tmp = ft_putnbr(n / 10);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (ft_putchar(n % 10 + 48) == -1)
		return (-1);
	return (++len);
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	int	len;
	int	tmp;

	len = 0;
	if (nb > 9)
	{
		tmp = ft_putnbr_unsigned(nb / 10);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (ft_putchar(nb % 10 + 48) == -1)
		return (-1);
	return (++len);
}

int	ft_puthexadecimal(unsigned long long int number, char format)
{
	int	len;
	int	tmp;

	len = 0;
	if (number > 15)
	{
		tmp = ft_puthexadecimal(number / 16, format);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (number % 16 < 10)
	{
		if (ft_putchar((number % 16) + '0') == -1)
			return (-1);
	}
	else if (ft_putchar((number % 16) + format) == -1)
		return (-1);
	return (++len);
}

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (*str)
	{
		if (write(1, *(&str), 1) == -1)
			return (-1);
		str++;
		len++;
	}
	return (len);
}
