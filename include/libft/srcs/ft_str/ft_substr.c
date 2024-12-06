/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:01:30 by fgranger          #+#    #+#             */
/*   Updated: 2022/11/12 17:02:10 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

   Function name       : ft_substr
Prototype           : char *ft_substr(char const *s, unsigned int start, 
size_t len);
Turn in files       : -
Parameters          : #1. The string from which to create the substring.
#2. The start index of the substring in the string ’s’.
#3. The maximum length of the substring.
Return value        : The substring. NULL if the allocation fails.
External functs.    : malloc
Description         : Allocates (with malloc(3)) and returns a substring
from the string ’s’.
The substring begins at index ’start’ and is of
maximum size ’len’.

*/

#include "../../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	int		i;
	int		size;

	size = len;
	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < len + start)
		size = ft_strlen(s) - start;
	if (ft_strlen(s) <= start)
		size = 0;
	sub = ft_calloc(size + 1, sizeof(char));
	if (!sub)
		return (NULL);
	while (s[i] && i < size)
	{
		sub[i] = s[i + start];
		i++;
	}
	return (sub);
}
