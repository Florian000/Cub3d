/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvittoz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:27:26 by jvittoz           #+#    #+#             */
/*   Updated: 2023/12/11 07:31:32 by jvittoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_count_int(int i)
{
	if (i == -2147483648)
		return (11);
	if (i < 0)
		return (1 + ft_count_int(i * -1));
	if (i > 0)
	{
		if (i / 10 > 0)
			return (1 + ft_count_int(i / 10));
	}
	return (1);
}

int	ft_count_unsigned(unsigned int i)
{
	if (i > 0)
	{
		if (i / 10 > 0)
			return (1 + ft_count_unsigned(i / 10));
	}
	return (1);
}

int	ft_count_base(unsigned int i)
{
	if (i / 16 > 0)
		return (1 + ft_count_base(i / 16));
	return (1);
}

int	ft_count_ptr(void *p)
{
	unsigned long long	n;
	int					res;

	res = 2;
	n = (unsigned long long)p;
	if (p == 0)
		return (5);
	while (n > 0)
	{
		n = n / 16;
		res++;
	}
	return (res);
}
