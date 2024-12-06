/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 19:02:41 by fgranger          #+#    #+#             */
/*   Updated: 2022/12/03 21:13:37 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_c(va_list args)
{
	ft_putchar_fd(va_arg(args, int), 1);
	return (1);
}

int	ft_s(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_p(va_list args)
{
	unsigned long long	p;
	void				*test;
	int					print;

	print = 0;
	test = va_arg(args, void *);
	p = (unsigned long long)test;
	if (p == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	ft_putnbr_base(p, "0123456789abcdef", 16, &print);
	return (print + 2);
}

int	ft_i(va_list args)
{
	int	print;

	print = 0;
	ft_putnbr(va_arg(args, int), &print);
	return (print);
}

int	ft_u(va_list args)
{
	int	print;

	print = 0;
	ft_putnbr_base(va_arg(args, unsigned int), "0123456789", 10, &print);
	return (print);
}
