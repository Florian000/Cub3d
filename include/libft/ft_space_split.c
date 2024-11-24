/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvittoz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:12:57 by jvittoz           #+#    #+#             */
/*   Updated: 2024/11/08 13:12:58 by jvittoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v')
		return (1);
	return (0);
}

static int	parts_counter(char const *s)
{
	int	parts;

	parts = 0;
	while (*s)
	{
		while (*s && !ft_isspace(*s))
			s++;
		parts++;
		while (*s && ft_isspace(*s))
			s++;
	}
	return (parts);
}

static int	get_parts(char **tab, char const *s)
{
	int		index;
	size_t	len;
	int		i;

	index = 0;
	i = 0;
	while (s[index])
	{
		len = 0;
		while (s[index + len] && !ft_isspace(s[index + len]))
			len++;
		tab[i] = ft_substr(s, index, len);
		if (!tab[i])
		{
			while (--i >= 0)
				free(tab[i]);
			return (0);
		}
		while (s[index + len] && ft_isspace(s[index + len]))
			len++;
		i++;
		index += len;
	}
	return (1);
}

char	**ft_space_split(char const *s)
{
	char	*cleanstr;
	int		parts;
	char	**tab;

	cleanstr = ft_strtrim(s, " \f\n\r\t\v");
	if (!cleanstr)
		return (NULL);
	parts = parts_counter(cleanstr);
	tab = malloc(parts * sizeof(char *) + sizeof(NULL));
	if (!tab)
	{
		free(cleanstr);
		return (NULL);
	}
	if (!get_parts(tab, cleanstr))
	{
		free(cleanstr);
		free(tab);
		return (NULL);
	}
	tab[parts] = NULL;
	free(cleanstr);
	return (tab);
}
