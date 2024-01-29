/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knarman <knarman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 00:24:25 by knarman           #+#    #+#             */
/*   Updated: 2024/01/29 15:51:51 by knarman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>

int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_putnbr(int nb);
int	ft_putnbr_unsigned(unsigned int nb);
int	ft_puthexadecimal(unsigned long long int k, char x);
int	ft_printf(const char *s, ...);

#endif