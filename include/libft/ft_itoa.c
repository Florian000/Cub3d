/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvittoz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:59:39 by jvittoz           #+#    #+#             */
/*   Updated: 2023/12/08 10:02:55 by jvittoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	size_of_nb(long i)
{
	long	res;

	res = 0;
	if (i == 0)
		return (1);
	if (i < 0)
	{
		i = (-1) * i;
		res++;
	}
	while (i > 0)
	{
		i = i / 10;
		res++;
	}
	return (res);
}

char	*ft_itoa(int i)
{
	long	temp;
	char	*res;
	long	size;

	temp = (long)i;
	size = size_of_nb(temp);
	res = malloc(sizeof(char) * size + 1);
	if (res == 0)
		return (0);
	if (temp < 0)
	{
		temp = temp * -1;
		res[0] = '-';
	}
	while (temp > 9)
	{
		res[-1 + size--] = (temp % 10) + 48;
		temp = temp / 10;
	}
	res[size - 1] = temp + 48;
	res[size_of_nb((long)i)] = 0;
	return (res);
}
