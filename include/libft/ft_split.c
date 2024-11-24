/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvittoz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:01:18 by jvittoz           #+#    #+#             */
/*   Updated: 2023/12/08 10:42:29 by jvittoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count(const char *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	word;

	i = 0;
	count = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c && word == 0)
		{
			word = 1;
			count++;
		}
		if (s[i] == c && word == 1)
			word = 0;
		i++;
	}
	return (count);
}

void	free_all(char **tres, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(tres[i]);
		i++;
	}
	free(tres);
}

int	ft_init(char **tres, size_t length, size_t j)
{
	tres[j] = malloc(sizeof(char) * (length + 1));
	if (tres[j] == 0)
	{
		free_all(tres, j);
		return (1);
	}
	return (0);
}

int	ft_pre_split(char **tres, const char *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		k = i;
		while (s[k] && s[k] != c)
			k++;
		if (k > i)
		{
			if (ft_init(tres, k - i, j) == 1)
				return (0);
			k = 0;
			while (s[i] && s[i] != c)
				tres[j][k++] = s[i++];
			tres[j++][k] = 0;
		}
	}
	return (j);
}

char	**ft_split(const char *s, char c)
{
	char	**tres;
	size_t	j;

	j = 0;
	if (s == 0)
		return (0);
	tres = malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (tres == 0)
		return (0);
	if (ft_count(s, c) == 0)
		tres[0] = 0;
	else
	{
		j = ft_pre_split(tres, s, c);
		if (j == 0)
			return (0);
	}
	tres[j] = 0;
	return (tres);
}
