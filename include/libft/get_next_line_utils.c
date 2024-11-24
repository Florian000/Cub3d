/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvittoz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 03:33:26 by jvittoz           #+#    #+#             */
/*   Updated: 2024/03/18 04:09:19 by jvittoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*ft_join(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*res;

	res = malloc((ft_strlen2(s1) + ft_strlen2(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = 0;
	return (res);
}

int	ft_fnl(char *str)
{
	int	res;

	if (str == NULL)
		return (-1);
	res = 0;
	while (str[res] && str[res] != '\n')
		res++;
	if (str[res] == '\n')
		return (res);
	return (-1);
}
