/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvittoz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:03:30 by jvittoz           #+#    #+#             */
/*   Updated: 2024/02/25 14:50:45 by jvittoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*res;

	if (s == 0)
		return (0);
	if (start >= (unsigned int)ft_strlen2(s))
		len = 0;
	else if (len >= (unsigned int)ft_strlen2((s + start)))
		len = (unsigned int)ft_strlen2((s + start));
	res = malloc(sizeof(char) * (len + 1));
	if (res == 0)
		return (NULL);
	i = 0;
	while (i < len && s[i + start])
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = 0;
	return (res);
}
