/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvittoz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:01:52 by jvittoz           #+#    #+#             */
/*   Updated: 2024/02/25 14:49:30 by jvittoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	size1;
	size_t	size2;
	size_t	size3;
	char	*res;

	if (s1 == 0 && s2 == 0)
		return (ft_strdup(""));
	if (s1 == 0)
		return (ft_strdup(s2));
	if (s2 == 0)
		return (ft_strdup(s1));
	size1 = ft_strlen2(s1);
	size2 = ft_strlen2(s2);
	size3 = size1 + size2;
	res = malloc(sizeof(char) * size3 + 1);
	if (res == 0)
		return (0);
	ft_memmove(res, s1, size1);
	ft_memmove((res + size1), s2, size2);
	res[size3] = 0;
	return (res);
}
