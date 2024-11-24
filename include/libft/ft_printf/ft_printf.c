/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvittoz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 08:58:36 by jvittoz           #+#    #+#             */
/*   Updated: 2024/01/29 10:45:21 by jvittoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_arg(va_list arg, char c)
{
	int	res;

	if (c == 'c')
		res = ft_print_c(va_arg(arg, int));
	if (c == 's')
		res = ft_print_s(va_arg(arg, char *));
	if (c == 'p')
		res = ft_print_p(va_arg(arg, void *));
	if (c == 'd' || c == 'i')
		res = ft_print_d(va_arg(arg, int));
	if (c == 'u')
		res = ft_print_u(va_arg(arg, unsigned int));
	if (c == 'x')
		res = ft_print_x(va_arg(arg, unsigned int));
	if (c == 'X')
		res = ft_print_xup(va_arg(arg, unsigned int));
	if (c == '%')
	{
		res = 1;
		write(1, "%", 1);
	}
	return (res);
}

int	ft_printf(const char *str, ...)
{
	va_list		arg;
	int			i;
	int			res;

	i = 0;
	res = 0;
	if (str == 0)
		return (-1);
	va_start (arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			res += ft_print_arg(arg, str[i + 1]);
			i += 2;
		}
		else
		{
			res++;
			ft_putchar(str[i++]);
		}
	}
	va_end(arg);
	return (res);
}
