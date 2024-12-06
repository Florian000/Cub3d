/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:11:47 by fgranger          #+#    #+#             */
/*   Updated: 2022/11/12 17:01:14 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
   Function name ft_strtrim
   Prototype char *ft_strtrim(char const *s1, char const *set);
   Fichiers de rendu -
   Paramètres  s1: La chaîne de caractères à trimmer.
set: Le set de référence de caractères à trimmer.
Valeur de retour La chaîne de caractères trimmée. NULL si l’allocation échoue.
Fonctions externes autorisées malloc
Description Alloue (avec malloc(3)) et retourne une copie de la chaîne ’s1’, 
sans les caractères spécifiés dans ’set’ au début et à la fin de la 
chaîne de caractères.
*/

#include "../../includes/libft.h"

static int	ft_is_set(char c, char const *set)
{
	int	i;

	i = -1;
	while (set[++i])
		if (set[i] == c)
			return (1);
	return (0);
}

static int	ft_size(char const *s1, char const *set)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (ft_is_set(s1[i], set) && s1[i])
		i++;
	while (s1[i])
	{
		i++;
		len++;
	}
	while (ft_is_set(s1[--i], set) && len > 0)
		len--;
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		i;
	int		size;
	int		j;

	if (!s1 || !set)
		return (NULL);
	size = ft_size(s1, set);
	new = NULL;
	new = ft_calloc(size + 1, sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (ft_is_set(s1[i], set) && s1[i])
		i++;
	j = 0;
	while (j < size)
	{
		new[j] = s1[i];
		i++;
		j++;
	}
	return (new);
}
