/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvittoz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:03:22 by jvittoz           #+#    #+#             */
/*   Updated: 2023/12/08 09:18:00 by jvittoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ischar(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char const	*ft_pre(char const *str, char const *set)
{
	char const	*res;
	int			i;

	i = 0;
	while (str[i] && ft_ischar(str[i], set) == 1)
		i++;
	res = &str[i];
	return (res);
}

int	ft_startend(char const *str, char const *set)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	while (i > 0 && ft_ischar(str[i], set) == 1)
		i--;
	return (i + 1);
}

char	*ft_strtrim(char const *s, char const *set)
{
	char	*temp;
	char	*res;
	int		i;

	i = 0;
	if (s == 0)
		return (0);
	temp = (char *)s;
	if (temp[0] != 0)
		temp = (char *)ft_pre(s, set);
	res = malloc(sizeof(char) * ft_startend(temp, set) + 1);
	if (res == 0)
		return (0);
	if (ft_startend(temp, set) > 0)
	{
		while (temp[i] && i < ft_startend(temp, set))
		{
			res[i] = temp[i];
			i++;
		}
	}
	res[i] = 0;
	return (res);
}
