/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvittoz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 04:17:40 by jvittoz           #+#    #+#             */
/*   Updated: 2023/12/08 11:15:48 by jvittoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (2147483647 / count < size)
		return (0);
	res = malloc(count * size);
	if (res == 0)
		return (0);
	ft_bzero(res, count * size);
	return (res);
}
