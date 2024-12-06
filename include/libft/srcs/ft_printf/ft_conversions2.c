/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:03:26 by fgranger          #+#    #+#             */
/*   Updated: 2022/12/03 21:15:25 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_x(va_list args)
{
	int	print;

	print = 0;
	ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef", 16, &print);
	return (print);
}

int	ft_xucase(va_list args)
{
	int	print;

	print = 0;
	ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF", 16, &print);
	return (print);
}

int	ft_mod(va_list args)
{
	(void)args;
	ft_putchar_fd('%', 1);
	return (1);
}

int	ft_d(va_list args)
{
	int	print;

	print = 0;
	ft_putnbr(va_arg(args, int), &print);
	return (print);
}
