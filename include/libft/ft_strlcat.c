/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvittoz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:02:05 by jvittoz           #+#    #+#             */
/*   Updated: 2024/02/26 19:08:49 by jvittoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen2(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	sized;
	size_t	sizes;

	sized = 0;
	sizes = 0;
	if (dest != 0)
		sized = ft_strlen2(dest);
	sizes = ft_strlen2(src);
	if (sized + 1 < size)
		ft_strlcpy(dest + sized, src, size - sized);
	if (size > sized)
		return (sized + sizes);
	return (size + sizes);
}
