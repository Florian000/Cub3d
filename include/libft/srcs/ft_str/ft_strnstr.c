/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:11:28 by fgranger          #+#    #+#             */
/*   Updated: 2022/11/12 17:00:32 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
   NAME

   strnstr - Find the first substring in a length-limited string

   SYNOPSIS

   char * strnstr(const char * s1, const char * s2, size_t len);

   ARGUMENTS

   s1
   The string to be searched

   s2
   The string to search for

   len
   the maximum number of characters to search

   DESCRIPTION

   The strnstr() function locates the	first occurrence of the	null-termi-
   nated string little in the	string big, where not more than	len characters
   are searched.  Characters that appear after a `\0'	character are not
   searched.	Since the strnstr() function is	a FreeBSD specific API,	it
   should only be used when portability is not a concern.

   RETURN VALUES

   If	little is an empty string, big is returned; if little occurs nowhere
   in	big, NULL is returned; otherwise a pointer to the first	character of
   the first occurrence of little is returned.
   */

#include "../../includes/libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if ((!big && len == 0) || (!little && len == 0))
		return (NULL);
	if (!little[i])
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			if (!little[j + 1])
				return ((char *)(big + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
