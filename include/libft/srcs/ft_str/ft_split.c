/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:09:22 by fgranger          #+#    #+#             */
/*   Updated: 2022/11/12 16:52:20 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
   Function name       : ft_split
Prototype           : char **ft_split(char const *s, char c);
Turn in files       : -
Parameters          : #1. The string to be split.
#2. The delimiter character.
Return value        : The array of new strings resulting from the split.
NULL if the allocation fails.
External functs.    : malloc, free
Description         : Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must be
ended by a NULL pointer.
*/

#include "../../includes/libft.h"

static size_t	ft_subend(const char *s, int index, char c)
{
	size_t	len;

	len = index;
	while (s[len] && s[len] != c)
		len++;
	return (len - index);
}

static int	ft_size(const char *s, char c)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c && s[i])
			i++;
		size++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	strs = (char **) malloc(sizeof(char *) * (ft_size(s, c) + 1));
	if (strs == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (s[j] == c && s[j])
		j++;
	while (++i < ft_size(s, c))
	{
		strs[i] = ft_substr(s, j, ft_subend(s, j, c));
		if (strs[i] == NULL)
			return (NULL);
		while (s[j] != c && s[j])
			j++;
		while (s[j] == c && s[j])
			j++;
	}
	strs[i] = 0;
	return (strs);
}
