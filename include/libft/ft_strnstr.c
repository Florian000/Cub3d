/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvittoz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:02:55 by jvittoz           #+#    #+#             */
/*   Updated: 2023/12/08 11:22:05 by jvittoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	size;

	i = 0;
	size = 0;
	while (small[size])
		size++;
	if (size == 0)
		return ((char *)(big));
	while (i < n && big[i])
	{
		j = 0;
		while (i + j < n && big[i + j] && big[i + j] == small[j])
			j++;
		if (j == size)
			return ((char *)(big + i));
		i++;
	}
	return (0);
}
