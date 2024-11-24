/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvittoz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:09:40 by jvittoz           #+#    #+#             */
/*   Updated: 2023/12/08 08:54:37 by jvittoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s1, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	if (s1 == 0)
		return (0);
	res = ft_strdup(s1);
	if (res == 0)
		return (0);
	i = 0;
	while (s1[i])
	{
		res[i] = (*f)(i, s1[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}
